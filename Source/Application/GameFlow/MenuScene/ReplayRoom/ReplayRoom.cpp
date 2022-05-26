#include "ReplayRoom.h"
#include <string>
#include "../../Source/library/AppManager/AppManager.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/library/Graphics/String/StringDX.h"
#include "../../Source/Resource/SoundData/SoundData.h"
#include "../../Source/Resource/GUI/MenuUIImage/MenuUIImage.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"
#include "../../Source/SystemProp/SceneProp.h"
#include "../../Source/Application/Sound/Sound.h"
#include "../../Source/Application/Key/Key.h"
#include "../../Source/Application/Replayer/Replayer.h"

#pragma warning(disable : 4996)

//不具合
//セーブが終わってゲーム画面に戻る時に、Xキーで戻れてしまう。(戻った後ボムが発動してしまう)
namespace app {
	ReplayRoom::ReplayRoom():
		m_Select_num(0)
	{
		for (int i = 0; i < 20; i++) {
			for (int i2 = 0; i2 < 20; i2++)m_TitleList[i].title[i2] = '-';
			m_TitleList[i].title[20] = '\0';
			m_TitleList[i].diff = -1;
			m_TitleList[i].score = 0;
			m_TitleList[i].year = 0;
			m_TitleList[i].month = 0;
			m_TitleList[i].day = 0;
		}
		importTitleList();
	}
	ReplayRoom::~ReplayRoom() {
		int a = 0;
	}
	int ReplayRoom::update() {
		setSceneState(SCENE_TYPE::REPLAY);
		const int select_num = 20;
		if (sceneCoolDown(10)) {
			//リプレイの再生
			if (m_State == REPLAY_ROOM::READ_STATE) {
				up(select_num);
				down(select_num);
				select();
				cancel();
				m_Select_num = getHorizontal();
			}
			//リプレイの保存
			if (m_State == REPLAY_ROOM::WRITE_STATE) {
				if (!m_TextInputer.isFlag() && !m_Select_YN.isFlag()) {
					up(select_num);
					down(select_num);
					select();
					cancel();
					m_Select_num = getHorizontal();
					//入力を完了したとき
					if (m_TextInputer.getInputResult() == KeyboardResult::INPUT_END) {
						//名前を付けて書きだす。
						m_Is_wrote = true;
						for (int i = 0; i < 20; i++)m_TitleList[m_Select_num].title[i] = m_TextInputer.getCharText()[i];
						Replayer::GameRecorder.dataExport(m_Select_num);
						auto when = lib::AppManager::getDateTime();
						m_TitleList[m_Select_num].score = Replayer::GameRecorder.getScore();
						m_TitleList[m_Select_num].diff = Replayer::GameRecorder.getDifficulty();
						m_TitleList[m_Select_num].day = when.day;
						m_TitleList[m_Select_num].month = when.mon;
						m_TitleList[m_Select_num].year = when.year;
						exportTitleList();
					}
					//「やーめた」を選択
					if (m_Select_YN.getState() == SELECT_LR::LEFT_STATE) {
						//ゲーム画面に戻る
						Sound::sound.playSE(res::SE::SELECT_CANCEL);
						setSceneState(SCENE_TYPE::GAME_MAIN);
						m_Select_YN.selectReset();
					}
				}
				m_TextInputer.update();
				m_Select_YN.update();
			}
		}
		else {
			m_Select_num = 0;
			setHorizontal(0);
			m_Is_wrote = false;
		}
		return getSceneState();
	}
	void ReplayRoom::draw() {
		lib::Graphics2D::drawRota(480 * 2, 360 * 2, 1.0, 0.0, res::MenuUIImage::menu_ui.title.back, true);
		char title[60];
		for (int i = 0; i < 20; i++) {
			int add_x = 0;
			int color = lib::StringDX::color(55, 55, 55);
			if (i == m_Select_num) {
				add_x = 50;
				color = lib::StringDX::color(255, 255, 255);
			}
			std::string diff="Level";
			if (m_TitleList[i].diff == 0)diff = "Easy";
			if (m_TitleList[i].diff == 1)diff = "Normal";
			if (m_TitleList[i].diff == 2)diff = "Hard";
			if (m_TitleList[i].diff == 3)diff = "Lunatic";
			if (m_TitleList[i].diff == 4)diff = "Extra";
			//9999999999
			auto num = std::to_string(m_TitleList[i].score);
			std::string score;
			if (num.length() != 11) {
				for (int i2 = 0; i2 < 11 - num.length(); i2++) {
					score += "0";
				}
			}
			score += std::to_string(m_TitleList[i].score);
			sprintf(
				title, "%s score:%s %s <%d/%d/%d>\0",
				m_TitleList[i].title,
				score.data(),
				diff.data(),
				m_TitleList[i].year,
				m_TitleList[i].month,
				m_TitleList[i].day
			);
			lib::StringDX::draw(
				450- add_x,
				300 + i * 50,
				title,
				color,
				res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]
			);
		}
		//リプレイの再生
		if (m_State == REPLAY_ROOM::READ_STATE) {
			std::string text = "再生するデータを選んでください";
			auto font = res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT];
			lib::StringDX::draw(
				(1920 / 2) - (lib::StringDX::getFontTextWidth(text.data(), text.length(), font) / 2),
				100,
				text.data(),
				lib::StringDX::color(255, 255, 255),
				font
			);
		}
		//リプレイの保存
		if (m_State == REPLAY_ROOM::WRITE_STATE) {
			std::string text = "保存する場所を選んでください";
			if (!m_TextInputer.isFlag() && !m_Select_YN.isFlag()) {
				auto font = res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT];
				lib::StringDX::draw(
					(1920 / 2) - (lib::StringDX::getFontTextWidth(text.data(), text.length(), font) / 2),
					100,
					text.data(),
					lib::StringDX::color(255, 255, 255),
					font
				);
			}
			m_TextInputer.draw("タイトルを入力しでくださいまし。");
			m_Select_YN.draw("リプレイを諦めますか?", lib::StringDX::color(255, 255, 255), "やーめた", "ちょっとまって");
		}
	}
	void ReplayRoom::select() {
		if (Key::Pad.checkInput(Key::KEY_TYPE::SHOT) == 1) {
			//リプレイの再生
			if (m_State == REPLAY_ROOM::READ_STATE) {
				Replayer::GameRecorder.setReplayMode(true);
				m_Is_wrote = false;
				if (Replayer::GameRecorder.dataInput(m_Select_num)) {
					resetCoolDown();
					Sound::sound.playSE(res::SE::SELECT_OK);
					setSceneState(SCENE_TYPE::GAME_MAIN);
				}
				else Replayer::GameRecorder.setReplayMode(false);
			}
			//リプレイの保存
			if (m_State == REPLAY_ROOM::WRITE_STATE) {
				Sound::sound.playSE(res::SE::SELECT_OK);
				m_TextInputer.initialize();
			}
		}
	}
	void ReplayRoom::cancel() {
		if (Key::Pad.checkInput(Key::KEY_TYPE::BOM) == 1 || Key::Pad.checkInput(Key::KEY_TYPE::BOM) == 1) {
			//タイトルに戻る
			if (m_State == REPLAY_ROOM::READ_STATE) {
				resetCoolDown();
				Replayer::GameRecorder.setReplayMode(false);
				Sound::sound.playSE(res::SE::SELECT_CANCEL);
				setSceneState(SCENE_TYPE::TITLE);
			}
			//ゲーム画面に戻る
			if (m_State == REPLAY_ROOM::WRITE_STATE) {//[menu]キーを押したらリプレイの保存をやめる
				//やめるかどうかの選択肢を表示
				if (m_Is_wrote) {//ゲーム画面に戻る
					m_Is_wrote = false;
					resetCoolDown();
					Sound::sound.playSE(res::SE::SELECT_CANCEL);
					setSceneState(SCENE_TYPE::GAME_MAIN);
				}
				else m_Select_YN.initialize(SELECT_LR::RIGHT_STATE);
			}
		}
	}
	void ReplayRoom::importTitleList() {
		FILE* fp = fopen("./replay/datalist.history", "r");
		if (fp == nullptr) {
			return;
		}
		TitleList data[20];
		fread(&data, sizeof(TitleList), 20, fp);
		for (int i = 0; i < 20; i++)m_TitleList[i] = data[i];
		fclose(fp);
	}
	void ReplayRoom::exportTitleList() {
		FILE* fp = fopen("./replay/datalist.history", "w");
		fwrite(&m_TitleList, sizeof(TitleList), 20, fp);
		fclose(fp);
	}
	void ReplayRoom::setState(int state) {
		m_State = state;
	}
	int ReplayRoom::getState() {
		return m_State;
	}
}