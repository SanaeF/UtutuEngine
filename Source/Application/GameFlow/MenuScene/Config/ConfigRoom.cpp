#pragma once
#include "ConfigRoom.h"
#include <iostream>
#include"../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include"../../Source/library/Graphics/String/StringDX.h"
#include "../../Source/Resource/GUI/MenuUIImage/MenuUIImage.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"
#include "../../Source/Resource/SoundData/SoundData.h"
#include "../../Source/Resource/SaveData/SaveData.h"
#include "../../Source/Application/Key/Key.h"
#include "../../Source/Application/Sound/Sound.h"
#include "../../Source/SystemProp/SceneProp.h"
#include "../../Source/Manager/SaveDataManager/SaveDataManager.h"
#pragma warning(disable : 4996)
namespace app {
	void ConfigMenu::draw() {
		lib::Graphics2D::drawRota(480 * 2, 360 * 2, 1.0, 0.0, res::MenuUIImage::menu_ui.title.back, true);
		if (m_Config_state == 0) {
			lib::Graphics2D::drawRota(480 * 2, 360 * 2, 1.0, 0.0, res::MenuUIImage::menu_ui.config[0], true);
			int m_Base_x = 500;
			int m_Base_y = 600;
			int m_Add_y = 80;
			char bgm_param[128];
			sprintf(bgm_param, "BGM Volume:  %d/255", 255 - res::SaveData::save_data.config.vol_bgm);
			char se_param[128];
			sprintf(se_param, "SE Volume:  %d/255", 255 - res::SaveData::save_data.config.vol_se);
			MenuText m_System[5] = {
				{ m_Base_x, m_Base_y + m_Add_y * 0, ""},
				{ m_Base_x, m_Base_y + m_Add_y * 1, ""},
				{ m_Base_x, m_Base_y + m_Add_y * 2, "Key Config" },
				{ m_Base_x, m_Base_y + m_Add_y * 3, "画面サイズ:" },
				{ m_Base_x, m_Base_y + m_Add_y * 4, "Default(初期設定)" },
			};
			for (int i = 0; i < 5; i++) { // コンフィグメニュー
				std::string text = m_System[i].name;
				if (i == 0)text = bgm_param;
				if (i == 1)text = se_param;
				if (i == getHorizontal()) {
					lib::StringDX::draw(
						m_System[i].x,
						m_System[i].y,
						text.data(),
						lib::StringDX::color(255, 255, 255),
						res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]
					);
				}
				else {
					lib::StringDX::draw(
						m_System[i].x,
						m_System[i].y,
						text.data(),
						lib::StringDX::color(133, 133, 133),
						res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]
					);
				}
			}
			MenuText m_ScreenTxt[5] = {
				{ 0, 0, "640 x 480" },
				{ 0, 0, "960 x 720" },
				{ 0, 0, "1280 x 960" },
				{ 0, 0, "1920 x 1440" },
				{ 0, 0, "フルスクリーン" }
			};
			int color = lib::StringDX::color(133, 133, 133);
			if (getHorizontal() == 3)color = lib::StringDX::color(255, 255, 255);
			lib::StringDX::draw(
				m_System[3].x + 380,
				m_System[3].y + 2,
				m_ScreenTxt[res::SaveData::save_data.config.winType].name,
				color,
				res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]
			);
		}
		else {
			lib::Graphics2D::drawRota(480 * 2, 360 * 2, 1.0, 0.0, res::MenuUIImage::menu_ui.config[1], true);
			char shot_param[128];
			sprintf(shot_param, "ショット(Z):  %d", m_Key_sub[1]);
			char bom_param[128];
			sprintf(bom_param, "ボム(X):  %d", m_Key_sub[0]);
			char slow_param[128];
			sprintf(slow_param, "低速(LShift):  %d", m_Key_sub[2]);
			char change_param[128];
			sprintf(change_param, "キャンプ設置(C):  %d", m_Key_sub[3]);
			char menu_param[128];
			sprintf(menu_param, "メニュー(Esc):  %d", m_Key_sub[4]);

			std::string text[6] = { bom_param, shot_param, slow_param ,change_param ,menu_param ,"Save" };
			for (int i = 0; i < 6; i++) { // メニュー項目を描画
				int color = lib::StringDX::color(133, 133, 133);
				int add_x = 0;
				if (i == getHorizontal()) {
					add_x = -40;
					color = lib::StringDX::color(255, 255, 255);
				}
				lib::StringDX::draw(
					600 + add_x,
					600 + (100 * i),
					text[i].data(),
					color,
					res::TextUIImage::text_ui.font[1]
				);
			}
			//for (int i = 0; i < 5; i++) {
			//	if (i == getHorizontal(1)) {
			//		int Num = m_Key_sub2P[i];
			//		for (int b = 0; b < 2; b++) {
			//			lib::Graphics2D::drawRota((m_Key2P[i].x - 60 * b) + 535, m_Key2P[i].y + 10 * b + 20, 2.4f, 0.0f, res::TextUIImage::text_ui.number[0][Num % 10], true);
			//			Num /= 10;
			//		}
			//	}
			//	else {
			//		int Num = m_Key_sub2P[i];
			//		for (int b = 0; b < 2; b++) {
			//			lib::Graphics2D::drawRota((m_Key2P[i].x - 60 * b) + 500, m_Key2P[i].y + 10 * b + 20, 2.4f, 0.0f, res::TextUIImage::text_ui.number[0][Num % 10], true);
			//			Num /= 10;
			//		}
			//	}
			//}
			//for (int i = 0; i < 5; i++) { // メニュー項目を描画
			//	if (i == getHorizontal(1)) {
			//		lib::StringDX::draw(
			//			m_Key2P[i].x,
			//			m_Key2P[i].y,
			//			m_Key2P[i].name,
			//			lib::StringDX::color(255, 255, 255),
			//			res::TextUIImage::text_ui.font[3]
			//		);
			//	}
			//	else {
			//		lib::StringDX::draw(
			//			m_Key2P[i].x,
			//			m_Key2P[i].y,
			//			m_Key2P[i].name,
			//			lib::StringDX::color(133, 133, 133),
			//			res::TextUIImage::text_ui.font[3]
			//		);
			//	}
			//}
		}
	}

	int ConfigMenu::update() {
		if (sceneCoolDown(10)) {
			if (m_Config_state == 0) {
				right();
				left();
				up(5);
				down(5);
			}
			else {
				keyConfig();
			}
			select();
			cancel();
		}
		else {
			setSceneState(SCENE_TYPE::CONFIG);
		}
		return getSceneState();
	}
	void ConfigMenu::select() {
		if (Key::Pad.checkInput(app::Key::KEY_TYPE::SHOT) == 1) {
			Sound::sound.playSE(res::SE::SELECT_OK);
			if (m_Config_state == 0) {
				switch (getHorizontal()) {
				case 2 % 5:
					m_Key_sub[0] = Key::Pad.getKey(app::Key::KEY_TYPE::BOM);
					m_Key_sub[1] = Key::Pad.getKey(app::Key::KEY_TYPE::SHOT);
					m_Key_sub[2] = Key::Pad.getKey(app::Key::KEY_TYPE::SHIFT);
					m_Key_sub[3] = Key::Pad.getKey(app::Key::KEY_TYPE::CHANGE);
					m_Key_sub[4] = Key::Pad.getKey(app::Key::KEY_TYPE::MENU);
					m_Config_state = 1;
					break;
				case 4 % 5:
					res::SaveData::save_data.config.vol_bgm = 0;
					res::SaveData::save_data.config.vol_se = 0;
					res::SaveData::save_data.config.winType = 0;
					Key::Pad.setKeyConfig(
						app::Key::PAD_TYPE::PLAYER_01,
						0,
						1,
						2,
						3,
						7,
						6,
						11,
						10,
						13
						);
					Key::MultPad[0] = Key::Pad;
					Key::MultPad[1].setKeyConfig(
						app::Key::PAD_TYPE::PLAYER_02,
						0,
						1,
						2,
						3,
						7,
						6,
						11,
						10,
						13
					);
					break;
				}
			}
			else {
				if (getHorizontal() == 5) {
					Key::Pad.setKeyConfig(
						app::Key::PAD_TYPE::PLAYER_01,
						0,
						1,
						2,
						3,
						m_Key_sub[1],
						m_Key_sub[0],
						m_Key_sub[3],
						m_Key_sub[2],
						m_Key_sub[4]
					);
					Key::MultPad[0] = Key::Pad;
					Key::MultPad[1].setKeyConfig(
						app::Key::PAD_TYPE::PLAYER_02,
						0,
						1,
						2,
						3,
						m_Key_sub2P[1],
						m_Key_sub2P[0],
						m_Key_sub2P[3],
						m_Key_sub2P[2],
						m_Key_sub2P[4]
					);
					SaveDataManager save;
					save.out_config();
					m_Config_state = 0;
					setHorizontal(0);
				}
			}
		}
	}
	void ConfigMenu::cancel() {
		if (Key::Pad.checkInput(app::Key::KEY_TYPE::BOM) == 1 ||
			Key::Pad.checkInput(app::Key::KEY_TYPE::MENU) == 1
			) {
			Sound::sound.playSE(res::SE::SELECT_CANCEL);
			if (m_Config_state == 0) {
				SaveDataManager save;
				save.out_config();
				setSceneState(SCENE_TYPE::TITLE);
				resetCoolDown();
			}
		}
	}
	void ConfigMenu::right() {
		if ((Key::Pad.checkInput(app::Key::KEY_TYPE::RIGHT) == 1) ||
			(Key::Pad.checkInput(app::Key::KEY_TYPE::RIGHT) > 12 &&
				Key::Pad.checkInput(app::Key::KEY_TYPE::RIGHT) % m_Cool_down == 1)
			) {
			Sound::sound.playSE(res::SE::SELECT);
			if (m_Config_state == 0) {
				switch (getHorizontal()) {
				case 0 % 5:
					res::SaveData::save_data.config.vol_bgm = (res::SaveData::save_data.config.vol_bgm - 5);
					if (res::SaveData::save_data.config.vol_bgm < 0)res::SaveData::save_data.config.vol_bgm = 0;
					break;
				case 1 % 5:
					res::SaveData::save_data.config.vol_se = (res::SaveData::save_data.config.vol_se - 5);
					if (res::SaveData::save_data.config.vol_se < 0)res::SaveData::save_data.config.vol_se = 0;
					break;
				case 3 % 5:
					res::SaveData::save_data.config.winType = (res::SaveData::save_data.config.winType + 1) % 5;
					break;
				}
				Sound::sound.setVolume(res::SaveData::save_data.config.vol_bgm, res::SaveData::save_data.config.vol_se);
			}
			else {
			}
		}
	}
	void ConfigMenu::left() {
		if ((Key::Pad.checkInput(Key::KEY_TYPE::LEFT) == 1) ||
			(
				Key::Pad.checkInput(Key::KEY_TYPE::LEFT) > 12 &&
				Key::Pad.checkInput(Key::KEY_TYPE::LEFT) % m_Cool_down == 1
				)
			) {
			Sound::sound.playSE(res::SE::SELECT);
			if (m_Config_state == 0) {

				switch (getHorizontal()) {
				case 0 % 5://WHAT_VOL
					res::SaveData::save_data.config.vol_bgm = (res::SaveData::save_data.config.vol_bgm + 5);
					if (res::SaveData::save_data.config.vol_bgm > 255)res::SaveData::save_data.config.vol_bgm = 255;
					break;
				case 1 % 5:
					res::SaveData::save_data.config.vol_se = (res::SaveData::save_data.config.vol_se + 5);
					if (res::SaveData::save_data.config.vol_se > 255)res::SaveData::save_data.config.vol_se = 255;
					break;
				case 3 % 5:
					res::SaveData::save_data.config.winType = (res::SaveData::save_data.config.winType + 4) % 5;
					break;
				}
				Sound::sound.setVolume(res::SaveData::save_data.config.vol_bgm, res::SaveData::save_data.config.vol_se);
			}
			else {
			}
		}
	}
	void ConfigMenu::keyConfig() {
		up(6);
		down(6);
		int now_val = Key::Pad.checkInputedKey();
		if (now_val >= 4) {
			int lastVal = m_Key_sub[getHorizontal()];
			m_Key_sub[getHorizontal()] = now_val;
			for(int num = 0; num<16; num++){
				if (getHorizontal()<5&&
					(getHorizontal() != num && m_Key_sub[num] == now_val)
					)m_Key_sub[num] = lastVal;
			}
		}
		/*up(1, 5);
		down(1, 5);
		int now_val2 = Key::MultPad[1].checkInputedKey();
		if (now_val2 >= 4) {
			int lastVal2 = m_Key_sub2P[getHorizontal(1)];
			m_Key_sub2P[getHorizontal(1)] = now_val2;
			for (int num = 0; num < 16; num++) {
				if (getHorizontal(1) != num && m_Key_sub2P[num] == now_val2)
					m_Key_sub2P[num] = lastVal2;
			}
		}*/
	}
}

