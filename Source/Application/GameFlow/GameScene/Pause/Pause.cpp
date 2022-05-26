#include "Pause.h"

#include "../../Source/Helper/Helper.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include"../../Source/library/Graphics/String/StringDX.h"
#include "../../Source/Resource/GUI/GameUIImage/GameUIImage.h"
#include "../../Source/Resource/GUI/MenuUIImage/MenuUIImage.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"
#include "../../Source/Resource/SoundData/SoundData.h"
#include "../../Source/Application/Key/Key.h"
#include "../../Source/Application/Sound/Sound.h"
#include "../../Source/Application/Replayer/Replayer.h"
#include "../../Source/Object/Player/Player.h"
#include "../../Source/Object/Player/Item/ItemStack.h"

namespace app {
	Pause Pause::Menu;
	void Pause::draw() {
		if (!m_Scene_flag)return;
		if (m_Type == PauseMenu::PUT_START || m_Type == PauseMenu::NO_LIFE) {
			lib::Graphics2D::draw(0, 0, res::GameUIImage::game_ui.pause[res::PAUSE_TYPE::NORMAL_PAUSE],true);
			const int menu_num = 5;

			GameMenu_t pose[menu_num] = {
				{ 170, 640, "再開" },
				{ 170, 740, "死に戻り(キャンプから)"},
				{ 170, 840, "リトライ" },
				{ 170, 940, "ココから帰る??"},
				{ 170, 1040, "リプレイを保存"}
			};
			for (int i = 0; i < menu_num; i++) { // メニュー項目を描画
				if (i == getHorizontal() % menu_num) {
					lib::StringDX::draw(pose[i].x - 20, pose[i].y, pose[i].menu, lib::StringDX::color(285, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]);
				}
				else {
					lib::StringDX::draw(pose[i].x, pose[i].y, pose[i].menu, lib::StringDX::color(29, 29, 29), res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]);
				}
			}
		}
		if (m_Type == PauseMenu::GAME_OVER) {
			lib::Graphics2D::draw(0, 0, res::GameUIImage::game_ui.pause[res::PAUSE_TYPE::GAMEOVER_PAUSE], true);
			const int menu_num = 4;

			GameMenu_t pose[menu_num] = {
				{ 170, 740, "死に戻り(キャンプから)"},
				{ 170, 840, "リトライ" },
				{ 170, 940, "ココから帰る??"},
				{ 170, 1040, "リプレイを保存"}
			};
			for (int i = 0; i < menu_num; i++) { // メニュー項目を描画
				if (i == getHorizontal() % menu_num) {
					lib::StringDX::draw(pose[i].x - 20, pose[i].y, pose[i].menu, lib::StringDX::color(285, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]);
				}
				else {
					lib::StringDX::draw(pose[i].x, pose[i].y, pose[i].menu, lib::StringDX::color(29, 29, 29), res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]);
				}
			}
		}
		if (m_Type == PauseMenu::STAGE_CLEAR) {
			//lib::Graphics.draw(281, 0, resource::game_ui.pause[resource::PauseType::NORMAL_PAUSE], true);
			const int menu_num = 3;
			GameMenu_t pose[menu_num] = {
				{ 450, 640, "先へ進む!" },
				{ 450, 760, "リトライ" },
				{ 450, 880, "帰る??"},
			};
			for (int i = 0; i < menu_num; i++) { // メニュー項目を描画
				if (i == getHorizontal() % menu_num) {
					lib::StringDX::draw(pose[i].x - 20, pose[i].y, pose[i].menu, lib::StringDX::color(285, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]);
				}
				else {
					lib::StringDX::draw(pose[i].x, pose[i].y, pose[i].menu, lib::StringDX::color(29, 29, 29), res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]);
				}
			}
		}
		if (m_Type == PauseMenu::REPLAY) {
			lib::Graphics2D::draw(0, 0, res::GameUIImage::game_ui.pause[res::PAUSE_TYPE::NORMAL_PAUSE], true);
			const int menu_num = 3;
			GameMenu_t pose[menu_num] = {
				{ 450, 640, "再生" },
				{ 450, 760, "最初から再生" },
				{ 450, 880, "メニューに戻る"},
			};
			for (int i = 0; i < menu_num; i++) { // メニュー項目を描画
				if (i == getHorizontal() % menu_num) {
					lib::StringDX::draw(pose[i].x - 20, pose[i].y, pose[i].menu, lib::StringDX::color(285, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]);
				}
				else {
					lib::StringDX::draw(pose[i].x, pose[i].y, pose[i].menu, lib::StringDX::color(29, 29, 29), res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]);
				}
			}
		}
		if (m_Type == PauseMenu::REPLAY_END) {
			lib::Graphics2D::draw(0, 0, res::GameUIImage::game_ui.pause[res::PAUSE_TYPE::NORMAL_PAUSE], true);
			const int menu_num = 2;
			GameMenu_t pose[menu_num] = {
				{ 450, 760, "最初から再生" },
				{ 450, 880, "メニューに戻る"},
			};
			for (int i = 0; i < menu_num; i++) { // メニュー項目を描画
				if (i == getHorizontal() % menu_num) {
					lib::StringDX::draw(pose[i].x - 20, pose[i].y, pose[i].menu, lib::StringDX::color(285, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]);
				}
				else {
					lib::StringDX::draw(pose[i].x, pose[i].y, pose[i].menu, lib::StringDX::color(29, 29, 29), res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]);
				}
			}
		}
	}
	int Pause::update() {
		if (m_Scene_flag && sceneCoolDown(10)) {
			if (m_Type == PauseMenu::PUT_START) {
				up(5);
				down(5);
				cancel();
			}
			if (m_Type == PauseMenu::STAGE_CLEAR) {
				up(3);
				down(3);
			}
			if (m_Type == PauseMenu::NO_LIFE) {
				up(4);
				down(4);
			}
			if (m_Type == PauseMenu::GAME_OVER) {
				up(3);
				down(3);
			}
			if (m_Type == PauseMenu::REPLAY) {
				up(3);
				down(3);
			}
			if (m_Type == PauseMenu::REPLAY_END) {
				up(2);
				down(2);
			}
			select();
		}
		else {
			checkPauseMode();
		}
		return -1;
	}

	void Pause::select() {
		if (Key::Pad.checkInput(Key::KEY_TYPE::SHOT) == 1) {
			Sound::sound.playSE(res::SELECT_OK);
			if (m_Type == PauseMenu::PUT_START || m_Type == PauseMenu::NO_LIFE) {
				switch (getHorizontal() % 5) {
				case 0:
					if(m_Type != PauseMenu::NO_LIFE)finalize();
					else return;
					break;
				case 1:
					if (m_Is_Camp_setted) {
						m_State = CAMP;
					}
					else return;
					break;
				case 2:
					m_State = RETRY;
					break;
				case 3:
					m_State = GAME_END;
					break;
				case 4:
					m_State = SET_SAVE_REPLAY_MODE;
					break;
				}
			}
			if (m_Type == PauseMenu::GAME_OVER) {
				switch (getHorizontal() % 3) {
				case 0:
					if (m_Is_Camp_setted) {
						m_State = CAMP;
					}
					else return;
					break;
				case 1:
					m_State = RETRY;
					break;
				case 2:
					m_State = GAME_END;
					break;
				}
			}
			if (m_Type == PauseMenu::STAGE_CLEAR) {
				switch (getHorizontal() % 3) {
				case 0:
					m_State = NEXT_STAGE;
					break;
				case 1:
					m_State = RETRY;
					break;
				case 2:
					m_State = GAME_END;
					break;
				}
			}
			if (m_Type == PauseMenu::REPLAY) {
				switch (getHorizontal() % 3) {
				case 0:
					finalize();
					break;
				case 1:
					m_State = RETRY;
					break;
				case 2:
					m_State = SET_REPLAY_ROOM;
					break;
				}
			}
			if (m_Type == PauseMenu::REPLAY_END) {
				switch (getHorizontal() % 2) {
				case 0:
					m_State = RETRY;
					break;
				case 1:
					m_State = SET_REPLAY_ROOM;
					break;
				}
			}
			finalize();
		}
	}

	void Pause::cancel() {
		if (Key::Pad.checkInput(Key::KEY_TYPE::MENU) == 1) {
			Sound::sound.playSE(res::SELECT_CANCEL);
			finalize();
		}
	}
	void Pause::setScene(int type) {
		m_Type = type;
		m_Scene_flag = true;
	}
	void Pause::setCamp(int flag) {
		m_Is_Camp_setted = flag;
	}
	void Pause::checkPauseMode() {
		if (Replayer::GameRecorder.isReplayMode()) {
			if(Replayer::GameRecorder.isStop())setScene(PauseMenu::REPLAY_END);
			if (!m_Scene_flag && Key::Pad.checkInput(Key::KEY_TYPE::MENU) == 1)setScene(PauseMenu::REPLAY);
			if (obj::Player::PlayerObj.getItemStack().life < 0)setScene(PauseMenu::REPLAY_END);
		}
		else {
			if (!m_Scene_flag && Key::Pad.checkInput(Key::KEY_TYPE::MENU) == 1)setScene(PauseMenu::PUT_START);
			if (obj::Player::PlayerObj.getItemStack().life < 0)setScene(PauseMenu::NO_LIFE);
		}
	}
	void Pause::setFlag(bool flag) {
		m_Scene_flag = true;
	}
	int Pause::getState() {
		return m_State;
	}
	bool Pause::isFlag() {
		return m_Scene_flag;
	}
	bool Pause::isState(PauseState state) {
		if (m_State == state)return true;
		return false;
	}
	void Pause::initialize() {
		m_Menu_Num = 0;
		m_State = 0;
		m_Count = 0;
		m_State = NONE;
		m_Stage = 0;
		m_Menu_Num = 0;
		m_Scene_flag = false;
	}
	void Pause::finalize() {
		if (m_Type != PauseMenu::REPLAY)Sound::sound.unFreez();
		resetCoolDown();
		m_Scene_flag = false;
	}
}