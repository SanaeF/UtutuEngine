#include "ScoreBoard.h"
#include <iostream>
#include "PlayerScore/PlayerScore.h"
#include "StartingCall/StartingCall.h"
#include "DuelScore/DuelScore.h"
#include "FrameMask/FrameMask.h"

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
		m_Mask.reset(new FrameMask());
	}
	void ScoreBoard::initialize() {
		m_Mask->start(20);
	}
	void ScoreBoard::draw(obj::Player& player) {
		m_Mask->draw();
		lib::Graphics2D::drawRota(lib::ScreenSize::width / 2, lib::ScreenSize::height / 2, 1.0f, 0.0f, res::GameUIImage::game_ui.score_board[res::BOARD_TYPE::FRAME], true);
		m_Mask->clear();
		lib::Graphics2D::drawRota(lib::ScreenSize::width / 2, lib::ScreenSize::height / 2, 1.0f, 0.0f, res::GameUIImage::game_ui.score_board[res::BOARD_TYPE::SCORE_UI], true);
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
	}
	void ScoreBoard::draw_vs(obj::Player& player1, obj::Player& player2, obj::Boss& boss) {
	}

	void ScoreBoard::changeBoard(int type) {
	}
	void ScoreBoard::entity_pos() {
		if(!manager::BossManager::getInstance()->isFlag())return;
		for(auto obj: manager::BossManager::getInstance()->getBossList())
			lib::Graphics2D::draw(obj.boss.getX() - 43 * 2 + AreaProp::min_x, 694 * 2, res::GameUIImage::game_ui.boss_position, true);
	}
	void ScoreBoard::drawSoundTitle() {
		int bgmNum = Sound::sound.getNowPlayBGM();
		lib::StringDX::draw(10, 10, Sound::sound.m_Title[bgmNum].name, lib::StringDX::color(182, 184, 233), res::TextUIImage::text_ui.font[res::FONT::FONT_SB_SOUND]);
	}
	void ScoreBoard::drawAliceLevel() {
		if (!AliceProp::flag)return;
		char* text = new char[38];
		sprintf(text, "ƒAƒŠƒXƒŒƒxƒ‹: %d", AliceProp::level_num);
		lib::StringDX::draw(
			1435,
			7,
			text,
			lib::StringDX::color(155 + AliceProp::level_num, 255 - (AliceProp::level_num / 2), 120),
			res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]
		);
	}
	void ScoreBoard::update() {

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