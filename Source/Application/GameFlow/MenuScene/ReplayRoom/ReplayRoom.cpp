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

//�s�
//�Z�[�u���I����ăQ�[����ʂɖ߂鎞�ɁAX�L�[�Ŗ߂�Ă��܂��B(�߂�����{�����������Ă��܂�)
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
			//���v���C�̍Đ�
			if (m_State == REPLAY_ROOM::READ_STATE) {
				up(select_num);
				down(select_num);
				select();
				cancel();
				m_Select_num = getHorizontal();
			}
			//���v���C�̕ۑ�
			if (m_State == REPLAY_ROOM::WRITE_STATE) {
				if (!m_TextInputer.isFlag() && !m_Select_YN.isFlag()) {
					up(select_num);
					down(select_num);
					select();
					cancel();
					m_Select_num = getHorizontal();
					//���͂����������Ƃ�
					if (m_TextInputer.getInputResult() == KeyboardResult::INPUT_END) {
						//���O��t���ď��������B
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
					//�u��[�߂��v��I��
					if (m_Select_YN.getState() == SELECT_LR::LEFT_STATE) {
						//�Q�[����ʂɖ߂�
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
		//���v���C�̍Đ�
		if (m_State == REPLAY_ROOM::READ_STATE) {
			std::string text = "�Đ�����f�[�^��I��ł�������";
			auto font = res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT];
			lib::StringDX::draw(
				(1920 / 2) - (lib::StringDX::getFontTextWidth(text.data(), text.length(), font) / 2),
				100,
				text.data(),
				lib::StringDX::color(255, 255, 255),
				font
			);
		}
		//���v���C�̕ۑ�
		if (m_State == REPLAY_ROOM::WRITE_STATE) {
			std::string text = "�ۑ�����ꏊ��I��ł�������";
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
			m_TextInputer.draw("�^�C�g������͂��ł��������܂��B");
			m_Select_YN.draw("���v���C����߂܂���?", lib::StringDX::color(255, 255, 255), "��[�߂�", "������Ƃ܂���");
		}
	}
	void ReplayRoom::select() {
		if (Key::Pad.checkInput(Key::KEY_TYPE::SHOT) == 1) {
			//���v���C�̍Đ�
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
			//���v���C�̕ۑ�
			if (m_State == REPLAY_ROOM::WRITE_STATE) {
				Sound::sound.playSE(res::SE::SELECT_OK);
				m_TextInputer.initialize();
			}
		}
	}
	void ReplayRoom::cancel() {
		if (Key::Pad.checkInput(Key::KEY_TYPE::BOM) == 1 || Key::Pad.checkInput(Key::KEY_TYPE::BOM) == 1) {
			//�^�C�g���ɖ߂�
			if (m_State == REPLAY_ROOM::READ_STATE) {
				resetCoolDown();
				Replayer::GameRecorder.setReplayMode(false);
				Sound::sound.playSE(res::SE::SELECT_CANCEL);
				setSceneState(SCENE_TYPE::TITLE);
			}
			//�Q�[����ʂɖ߂�
			if (m_State == REPLAY_ROOM::WRITE_STATE) {//[menu]�L�[���������烊�v���C�̕ۑ�����߂�
				//��߂邩�ǂ����̑I������\��
				if (m_Is_wrote) {//�Q�[����ʂɖ߂�
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