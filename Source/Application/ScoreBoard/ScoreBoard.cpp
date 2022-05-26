#include "ScoreBoard.h"
#include <iostream>
#include "PlayerScore/PlayerScore.h"
#include "StartingCall/StartingCall.h"
#include "DuelScore/DuelScore.h"

#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/library/Graphics/String/StringDX.h"
#include "../../Source/Object/Player/Player.h"
#include "../../Source/Object/Boss/Boss.h"
#include "../../Source/Resource/GUI/GameUIImage/GameUIImage.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"
#include "../../Source/Resource/EnemyImage/EnemyImage.h"
#include "../../Source/SystemProp/AliceProp/AliceProp.h"
#include "../../Source/SystemProp/AreaProp.h"
#include "../../Source/SystemProp/GameSceneProp/GameSceneProp.h"
#include "../../Source/Application/Sound/Sound.h"
#include "../../Source/Helper/Helper.h"
#include "../../Source/Manager/BossManager/BossManager.h"
#pragma warning(disable : 4996)

namespace app {
	ScoreBoard::ScoreBoard() {
		m_StCall.reset(new StartingCall());
	}
	void ScoreBoard::draw(obj::Player& player) {
		lib::Graphics2D::drawRota(1920 / 2, 1440 / 2, 1.0f, 0.0f, res::GameUIImage::game_ui.score_board[res::BOARD_TYPE::DFF], true);
		lib::Graphics2D::drawRota(1920 / 2, 1440 / 2, 1.0f, 0.0f, res::GameUIImage::game_ui.score_board[res::BOARD_TYPE::SCORE_UI], true);
		if (GameSceneProp::difficulty != -1 && GameSceneProp::difficulty != 4)PlayerScore::drawLevel(GameSceneProp::difficulty);
		PlayerScore::drawScore(player, 0, 1);
		PlayerScore::drawLife(player,2);
		PlayerScore::drawBom(player,3);
		PlayerScore::drawPower(player,4);
		//PlayerScore::drawPoint(player,5);
		PlayerScore::drawGraze(player,5);
		PlayerScore::drawApple(player);
		PlayerScore::drawCamp(player);
		entity_pos();
		drawAliceLevel();
		drawSoundTitle();
	}
	void ScoreBoard::draw_single(obj::Player& player, obj::Boss& m_Boss) {
		lib::Graphics2D::drawRota(1920 / 2, 1440 / 2, 1.0f, 0.0f, res::GameUIImage::game_ui.score_board[res::BOARD_TYPE::SINGLE], true);
		PlayerScore::drawCrush(player);
		entity_pos();
		drawSoundTitle();
	}
	void ScoreBoard::draw_vs(obj::Player& player1, obj::Player& player2, obj::Boss& boss) {
		/*if (!m_Is_bom_scene) {
			if (player1.isBom() || player2.isBom())m_Is_change = true;
			if (!player1.isBom() && !player2.isBom())m_Is_change_back = true;
		}
		if (m_State == BOARD::DUEL) {
			if (!m_Is_change)lib::Graphics2D::drawRota(1920 / 2, 1440 / 2, 1.0f, 0.0f, res::GameUIImage::game_ui.score_board[res::BOARD_TYPE::DOUBLES], true);
			else changeBoard(res::BOARD_TYPE::SINGLE);
			if (50 <= m_Count && m_Count < 75) {
				DuelScore::changeBossMode(player1, player2, m_Bom_type, m_Bom_who);
			}
			DuelScore::drawRoodModeUI(player1, player2);
		}
		if (m_State == BOARD::SINGLE) {
			if (!m_Is_change_back)lib::Graphics2D::drawRota(1920 / 2, 1440 / 2, 1.0f, 0.0f, res::GameUIImage::game_ui.score_board[res::BOARD_TYPE::SINGLE], true);
			else changeBoard(res::BOARD_TYPE::DOUBLES);
			if (50 <= m_Count && m_Count < 75) {
				DuelScore::changeNormalMode(player1, player2, boss);
			}
			DuelScore::drawBomModeUI(player1, player2);
			if (player1.isDamageNow() || player2.isDamageNow()) {
				boss.kill3();
				changeBoard(res::BOARD_TYPE::DOUBLES);
			}
		}
		m_StCall->draw(player1, player2);
		drawSoundTitle();*/
	}

	void ScoreBoard::changeBoard(int type) {
		const float HalfScreen_SizeY = 1440.0f / 2.0f;
		int board[2] = { 0,0 };
		int boardState = 0;
		if (type == res::BOARD_TYPE::SINGLE) {
			board[0] = res::BOARD_TYPE::DOUBLES;
			board[1] = res::BOARD_TYPE::SINGLE;
			boardState = BOARD::SINGLE;
			m_Is_bom_scene = true;
		}
		else if (type == res::BOARD_TYPE::DOUBLES) {
			board[0] = res::BOARD_TYPE::SINGLE;
			board[1] = res::BOARD_TYPE::DOUBLES;
			boardState = BOARD::DUEL;
			m_Is_bom_scene = false;
		}
		else return;
		if (m_Count < 50) {
			lib::Graphics2D::box(0, 0, 1920, 0 + m_Count * ((int)HalfScreen_SizeY / 50), 0, true);
			lib::Graphics2D::box(0, 1440 - m_Count * ((int)HalfScreen_SizeY / 50), 1920, 1440, 0, true);
			lib::Graphics2D::drawModi(//レーザーを描画
				0, 0 + (float)m_Count * (HalfScreen_SizeY / 50.0f),
				1920, 0 + (float)m_Count * (HalfScreen_SizeY / 50.0f),
				1920, 1440 - (float)m_Count * (HalfScreen_SizeY / 50.0f),
				0, 1440 - (float)m_Count * (HalfScreen_SizeY / 50.0f),
				res::GameUIImage::game_ui.score_board[board[0]], true
			);
		}
		if (50 <= m_Count && m_Count < 75)lib::Graphics2D::box(0, 0, 1920, 1440, 0, true);
		if (m_Count == 74)m_Is_scene_out = true;
		if (75 <= m_Count && m_Count < 125) {
			lib::Graphics2D::box(0, 0, 1920, 720 - (m_Count - 75.0f) * ((int)HalfScreen_SizeY / 50), 0, true);
			lib::Graphics2D::box(0, 720 + (m_Count - 75.0f) * ((int)HalfScreen_SizeY / 50), 1920, 1440, 0, true);
			lib::Graphics2D::drawModi(//レーザーを描画
				0, HalfScreen_SizeY - ((float)m_Count - 75.0f) * (HalfScreen_SizeY / 50.0f),
				1920, HalfScreen_SizeY - ((float)m_Count - 75.0f) * (HalfScreen_SizeY / 50.0f),
				1920, HalfScreen_SizeY + ((float)m_Count - 75.0f) * (HalfScreen_SizeY / 50.0f),
				0, HalfScreen_SizeY + ((float)m_Count - 75.0f) * (HalfScreen_SizeY / 50.0f),
				res::GameUIImage::game_ui.score_board[board[1]],
				true
			);
		}
		m_Count++;
		if (125 <= m_Count) {
			m_State = boardState;
			m_Count = 0;
			m_Is_change = false;
			m_Is_change_back = false;
		}
	}
	void ScoreBoard::entity_pos() {
		if(!manager::BossManager::getInstance()->isFlag())return;
		for(auto obj: manager::BossManager::getInstance()->getBossList())
			lib::Graphics2D::draw(obj.boss.getX() - 43 * 2 + FMIN_X, 694 * 2, res::GameUIImage::game_ui.boss_position, true);
	}
	void ScoreBoard::drawSoundTitle() {
		int bgmNum = Sound::sound.getNowPlayBGM();
		lib::StringDX::draw(10, 10, Sound::sound.m_Title[bgmNum].name, lib::StringDX::color(182, 184, 233), res::TextUIImage::text_ui.font[res::FONT::FONT_SB_SOUND]);
	}
	void ScoreBoard::drawAliceLevel() {
		if (!AliceProp::flag)return;
		char* text = new char[38];
		sprintf(text, "アリスレベル: %d", AliceProp::level_num);
		lib::StringDX::draw(
			1435,
			7,
			text,
			lib::StringDX::color(155 + AliceProp::level_num, 255 - (AliceProp::level_num / 2), 120),
			res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]
		);
	}
	void ScoreBoard::endBom() {
		m_Is_change_back = true;
		m_Is_bom_scene = false;
	}
	void ScoreBoard::sceneIsNotOut() {
		m_Is_scene_out = false;
	}
	bool ScoreBoard::isBom() {
		return this->m_Is_bom_scene;
	}
	bool ScoreBoard::isSceneOut() {
		return m_Is_scene_out;
	}
	int ScoreBoard::getPlayerType() {
		return m_Bom_type;
	}
	int ScoreBoard::getBomWho() {
		return m_Bom_who;
	}
	std::shared_ptr<StartingCall> ScoreBoard::getStartCall() {
		return m_StCall;
	}
}