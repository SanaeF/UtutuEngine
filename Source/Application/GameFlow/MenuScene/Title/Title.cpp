#include "Title.h"

#include "../../Source/Application/Key/Key.h"
#include "../../Source/Application/Sound/Sound.h"
#include "../../Source/Application/Replayer/Replayer.h"
#include "../../Source/Helper/Helper.h"
#include "../../Source/SystemProp/SceneProp.h"
#include "../../Source/SystemProp/AliceProp/AliceProp.h"
#include "../../Source/SystemProp/GameSceneProp/GameSceneProp.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/library/Graphics/String/StringDX.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"
#include "../../Source/Resource/GUI/MenuUIImage/MenuUIImage.h"
#include "../../Source/Resource/SoundData/SoundData.h"
#include "../../Source/Resource/SaveData/SaveData.h"

namespace app {
	void Title::draw() {
		lib::Graphics2D::setBright(255, 255, 255);
		lib::Graphics2D::drawRota(480 * 2, 360 * 2, 1.0, 0.0, res::MenuUIImage::menu_ui.title.back, true);
		if (m_Count > 0) {
			lib::Graphics2D::setBright(m_Count * 5, m_Count * 5, m_Count * 5);
			lib::Graphics2D::drawRota(480 * 2, 360 * 2, 1.0, 0.0, res::MenuUIImage::menu_ui.title.main_chara, true);//タイトルのキャラ表示
		}
		if (m_Count > 51) {
			lib::Graphics2D::setBright(55 + (m_Count - 51) * 5, (m_Count - 51) * 5, (m_Count - 51) * 5);
			lib::Graphics2D::drawRota(480 * 2, 360 * 2, 1.0, 0.0, res::MenuUIImage::menu_ui.title.text, true);//タイトル名表示
		}
		if (m_Count > 102 && (m_Count <= 1200)) {
			if (res::SaveData::save_data.clear.clear_story_num < 5)m_Title_gui[1] = m_Extra_gui[0];
			else m_Title_gui[1] = m_Extra_gui[1];
			for (int i = 0; i < m_Title_menu; i++) { // メニュー項目を描画
				if (i == getHorizontal()) {
					lib::StringDX::draw(
						m_Title_gui[i].x - 20 * 2,
						m_Title_gui[i].y,
						m_Title_gui[i].name,
						lib::StringDX::color(233, 233, 233),
						res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]
					);
				}
				else {
					lib::StringDX::draw(
						m_Title_gui[i].x,
						m_Title_gui[i].y,
						m_Title_gui[i].name,
						lib::StringDX::color(120, 120, 120),
						res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]
					);
				}
			}
			//Exクリアスタンプ
			if (res::SaveData::save_data.clear.difficulty[4]) {
				int add_x = 0;
				if (getHorizontal()==1)add_x = -20 * 2;
				lib::Graphics2D::drawRota(m_Title_gui[1].x + 90 + add_x, m_Title_gui[1].y + 70, 1, 0.0, res::MenuUIImage::menu_ui.icon.clearStamp, true);
			}
			lib::StringDX::draw(
				10,
				1400,
				"3.07c",
				lib::StringDX::color(255, 255, 255),
				res::TextUIImage::text_ui.font[res::FONT::FONT_TITLE_NEWS]
			);
			//ちょっとした操作説明
			scrollText(0, "ヒント:[z]で決定(ショット)、[x]でキャンセル(ボム)、[esc]メニュー、[方向キー]選択(移動)");
			scrollText(-1920, "【ニュース！】アリスモードは、レベルを上げると特別なストーリーが追加されます。");
		}
	}

	int Title::update() {
		setSceneState(SCENE_TYPE::TITLE);
		AliceProp::invalid();//if (AliceProp::Alice.flag)
		if (m_Count > 1200) {
			m_Count = 102;
		}

		if (m_Count > 102 && (m_Count <= 1200)) {
			up(m_Title_menu);
			down(m_Title_menu);
			select();
			cancel();
		}
		if (m_Count < 1200)m_Count++;
		m_Text_count = (m_Text_count - 2) % (1920 * 2);
		return getSceneState();
	}

	void Title::select() {
		if (Key::Pad.checkInput(Key::KEY_TYPE::SHOT) == 1) {
			Sound::sound.playSE(res::SE::SELECT_OK);
			switch (getHorizontal()) {
			case 0:
				setSceneState(SCENE_TYPE::DIFFICULTY_SELECT);
				break;
			case 1:
				if (res::SaveData::save_data.clear.clear_story_num < 5)break;
				GameSceneProp::is_extra = true;
				GameSceneProp::difficulty = 4;
				setSceneState(SCENE_TYPE::SELECT_CHARA);
				break;
			case 2:
				GameSceneProp::is_practice = true;
				setSceneState(SCENE_TYPE::STORY_SELECT);
				break;
			case 3:
				setSceneState(SCENE_TYPE::REPLAY_READ_MODE);
				break;
			case 4:
				setSceneState(SCENE_TYPE::DRESS_UP);
				break;
			case 5:
				setSceneState(SCENE_TYPE::MUSIC);
				break;
			case 6:
				setSceneState(SCENE_TYPE::HELP);
				break;
			case 7:
				setSceneState(SCENE_TYPE::CONFIG);
				break;
			case 8:
				exit(1);
				break;
			default:
				break;
			}
		}
	}

	void Title::cancel() {
		if (Key::Pad.checkInput(app::Key::KEY_TYPE::MENU) == 1) {
			Sound::sound.playSE(res::SE::SELECT_CANCEL);
			setHorizontal(m_Title_menu - 1);
		}
	}
	void Title::scrollText(int x, std::string text) {
		lib::StringDX::draw(
			x + m_Text_count + 1920 * 2,
			50,
			text.data(),
			lib::StringDX::color(255, 255, 155),
			res::TextUIImage::text_ui.font[res::FONT::FONT_TITLE_NEWS]
		);
		lib::StringDX::draw(
			x + m_Text_count,
			50,
			text.data(),
			lib::StringDX::color(255, 255, 155),
			res::TextUIImage::text_ui.font[res::FONT::FONT_TITLE_NEWS]
		);
	}
	Title::Title():
		m_Count(0),
		m_Text_count(0)
	{
	}
	Title::~Title() {

	}
}