#pragma once
#include "HelpRoom.h"
#include <iostream>
#include"../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include"../../Source/library/Graphics/String/StringDX.h"
#include "../../Source/Application/Sound/Sound.h"
#include "../../Source/Application/Key/Key.h"
#include "../../Source/Resource/LoadManager.h"
#include "../../Source/Resource/SoundData/SoundData.h"
#include "../../Source/Resource/PlayerImage/PlayerImage.h"
#include "../../Source/Resource/EnemyImage/EnemyImage.h"
#include "../../Source/Resource/GUI/BossUIImage/BossUIImage.h"
#include "../../Source/Resource/GUI/GameUIImage/GameUIImage.h"
#include "../../Source/Resource/GUI/MenuUIImage/MenuUIImage.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"
#include "../../Source/SystemProp/SceneProp.h"
namespace app {
	HelpRoom::HelpRoom() {
		m_Help_state = 0;
	}
	void HelpRoom::draw() {
		const int p_x = 700;
		const int p_y = 450;
		const int add_y = 100;
		MenuText m_Help_menu[4] = {
			{ p_x, p_y + add_y * 0, "1．操作について" },
			{ p_x, p_y + add_y * 1, "2．ゲームの使用" },
			{ p_x, p_y + add_y * 2, "3．アイテムについて" },
			{ p_x, p_y + add_y * 3, "4．画面とかの見方" },
		};
		lib::Graphics2D::drawRota(480 * 2, 360 * 2, 1.0, 0.0, res::MenuUIImage::menu_ui.title.back, true);
		switch (m_Help_state) {
		case 0:
			lib::Graphics2D::drawRota(480 * 2, 360 * 2, 1.0, 0.0, res::MenuUIImage::menu_ui.help[0], true);
			for (int i = 0; i < 4; i++) { // メニュー項目を描画
				if (i == getHorizontal()) {
					lib::StringDX::draw(
						m_Help_menu[i].x - 20,
						m_Help_menu[i].y,
						m_Help_menu[i].name,
						lib::StringDX::color(255, 255, 255),
						res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]
					);
				}
				else {
					lib::StringDX::draw(
						m_Help_menu[i].x,
						m_Help_menu[i].y,
						m_Help_menu[i].name,
						lib::StringDX::color(133, 133, 133),
						res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]
					);
				}
			}
			break;
		case 1:
			lib::Graphics2D::drawRota(480 * 2, 360 * 2, 1.0, 0.0, res::MenuUIImage::menu_ui.help[1], true);
			break;
		case 2:
			lib::Graphics2D::drawRota(480 * 2, 360 * 2, 1.0, 0.0, res::MenuUIImage::menu_ui.help[2], true);
			break;
		case 3:
			lib::Graphics2D::drawRota(480 * 2, 360 * 2, 1.0, 0.0, res::MenuUIImage::menu_ui.help[3], true);
			break;
		case 4:
			lib::Graphics2D::setBright(1, 1, 1);
			lib::Graphics2D::drawRota(785, 480, 0.9f, 0, res::EnemyImage::enemy.boss[0][0], true);
			lib::Graphics2D::setBright(255, 255, 255);
			lib::Graphics2D::drawRota(785, 480, 0.7f, 0.0f, res::BossUIImage::boss_ui.hp_back, true);
			lib::Graphics2D::drawRota(785, 1006, 0.65f, 0.0f, res::PlayerImage::Player.type[0][0], true);
			lib::Graphics2D::drawRota(785, 1006, 1.3f, 0, res::PlayerImage::Player.hitbox, true);
			lib::Graphics2D::drawRota(430, 260, 0.65f, 0.0f, res::BossUIImage::boss_ui.bullet_num, true);
			int time_Max = 60;
			for (int i = 0; i < 2; i++) {//ポイント表示
				lib::Graphics2D::setBright(255, 255, 255);
				lib::Graphics2D::drawRota((1120 - 22 * i), 260, 0.65f, 0.0f, res::TextUIImage::text_ui.number[0][time_Max % 10], true);
				time_Max /= 10;
			}
			lib::Graphics2D::drawRota(1920 / 2, 1440 / 2 - 50, 0.65f, 0.0f, res::GameUIImage::game_ui.score_board[res::BOARD_TYPE::DFF], true);
			lib::Graphics2D::drawRota(1920 / 2, 1440 / 2 - 50, 0.65f, 0.0f, res::GameUIImage::game_ui.score_board[res::BOARD_TYPE::SCORE_UI], true);
			lib::Graphics2D::drawRota(480 * 2, 360 * 2, 1.0, 0.0, res::MenuUIImage::menu_ui.help[4], true);
			break;
		}
	}
	int HelpRoom::update() {
		if (sceneCoolDown(10)) {
			up(4);
			down(4);
			select();
			cancel();
		}
		else {
			setSceneState(SCENE_TYPE::HELP);
			res::LoadManager& load = res::LoadManager::get_instance();
			load.loadGameUI();
			load.loadCharaObjImg();
		}
		return getSceneState();
	}
	void HelpRoom::select() {
		if (Key::Pad.checkInput(Key::KEY_TYPE::SHOT) == 1) {
			Sound::sound.playSE(res::SE::SELECT_OK);
			if (m_Help_state == 0) {
				m_Help_state = getHorizontal() + 1;
			}
			else {
				m_Help_state++;
				if (m_Help_state == 5)m_Help_state = 0;
			}
		}
	}
	void HelpRoom::cancel() {
		if (Key::Pad.checkInput(Key::KEY_TYPE::BOM) == 1 || Key::Pad.checkInput(Key::KEY_TYPE::BOM) == 1) {
			resetCoolDown();
			Sound::sound.playSE(res::SE::SELECT_CANCEL);
			if (m_Help_state == 0) {
				setSceneState(SCENE_TYPE::TITLE);
			}
			else {
				m_Help_state = 0;
			}
		}
	}
}