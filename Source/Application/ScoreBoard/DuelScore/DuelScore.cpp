#include "DuelScore.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/Object/Player/Player.h"
#include "../../Source/Object/Boss/Boss.h"
#include "../../Source/SystemProp/AreaProp.h"
#include "../../Source/Resource/GUI/GameUIImage/GameUIImage.h"

namespace app {
	void DuelScore::drawRoodModeUI(obj::Player player1, obj::Player player2) {
		/*for (int i = 1; i <= player1.getItemStack().life; i++)lib::Graphics2D::draw(P1_MIN_X, 1440 - 52 - 52 * i, res::GameUIImage::game_ui.life[3], true);
		for (int i = 1; i <= player2.getItemStack().life; i++)lib::Graphics2D::draw(P2_MAX_X - P1_MIN_X * 2, 1440 - 52 - 52 * i, res::GameUIImage::game_ui.life[3], true);
		for (int i = 0; i < player1.getItemStack().bom; i++)lib::Graphics2D::drawRota(((P1_MIN_X + 50) + 60 * i), FMIN_Y + 30, 1.0f, 0.0f, res::GameUIImage::game_ui.bossLife, true);
		for (int i = 0; i < player2.getItemStack().bom; i++)lib::Graphics2D::drawRota(((P2_MAX_X - 50) - 60 * i), FMIN_Y + 30, 1.0f, 0.0f, res::GameUIImage::game_ui.bossLife, true);
		lib::Graphics2D::draw(P1_MIN_X, FMIN_Y + 100, res::GameUIImage::game_ui.bom[player1.getItemStack().bom_fragument], true);
		lib::Graphics2D::draw(P2_MAX_X - P1_MIN_X * 2, FMIN_Y + 100, res::GameUIImage::game_ui.bom[player2.getItemStack().bom_fragument], true);*/
	}
	void DuelScore::drawBomModeUI(obj::Player player1, obj::Player player2) {
		/*for (int i = 1; i <= player1.getItemStack().life; i++)lib::Graphics2D::draw(FMIN_X + 50, 1440 - 52 - 52 * i, res::GameUIImage::game_ui.life[3], true);
		for (int i = 1; i <= player2.getItemStack().life; i++)lib::Graphics2D::draw(FMAX_X - 50, 1440 - 52 - 52 * i, res::GameUIImage::game_ui.life[3], true);*/
	}
	void DuelScore::changeBossMode(obj::Player& player1, obj::Player& player2,int& bom_type,int& rayer) {
		/*if (player1.isBom()) {
			player1.initialize(player1.getType(), AREA::FMAX_X, AREA::FMIN_X, true);
			player1.setX(AREA::DEF_BOSS_X);
			player1.setY(AREA::DEF_BOSS_Y);
			player1.setHide();
			player2.initialize(player2.getType(), AREA::FMAX_X, AREA::FMIN_X, true);
			player2.setX(AREA::DEF_PLAYER_X);
			player2.setY(AREA::DEF_PLAYER_Y);
			bom_type = player1.getType();
			rayer = player1.getRayer();
		}
		if (player2.isBom()) {
			player2.initialize(player2.getType(), AREA::FMAX_X, AREA::FMIN_X, true);
			player2.setX(AREA::DEF_BOSS_X);
			player2.setY(AREA::DEF_BOSS_Y);
			player2.setHide();
			player1.initialize(player1.getType(), AREA::FMAX_X, AREA::FMIN_X, true);
			player1.setX(AREA::DEF_PLAYER_X);
			player1.setY(AREA::DEF_PLAYER_Y);
			bom_type = player2.getType();
			rayer = player2.getRayer();
		}*/
	}
	void DuelScore::changeNormalMode(obj::Player& player1, obj::Player& player2, obj::Boss& boss) {
		//if (player1.isBom()) {
		//	player1.initialize(player1.getType(), AREA::P1_MAX_X, AREA::P1_MIN_X, true);
		//	player1.setX(AREA::DEF_MULTI_X);
		//	player1.setY(AREA::DEF_PLAYER_Y);
		//	player2.initialize(player2.getType(), AREA::P2_MAX_X, AREA::P2_MIN_X, true);
		//	player2.setX(AREA::DEF_MULTI_X);
		//	player2.setY(AREA::DEF_PLAYER_Y);
		//	//boss.summon(player1.getType());
		//}
		//if (player2.isBom()) {
		//	player2.initialize(player2.getType(), AREA::P1_MAX_X, AREA::P1_MIN_X, true);
		//	player2.setX(AREA::DEF_MULTI_X);
		//	player2.setY(AREA::DEF_PLAYER_Y);
		//	player1.initialize(player1.getType(), AREA::P2_MAX_X, AREA::P2_MIN_X, true);
		//	player1.setX(AREA::DEF_MULTI_X);
		//	player1.setY(AREA::DEF_PLAYER_Y);
		//	//boss.summon(player2.getType());
		//}
	}
}