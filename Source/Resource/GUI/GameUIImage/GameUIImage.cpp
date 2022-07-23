#include "GameUIImage.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/library/Graphics/Mask/Mask.h"
namespace res {
	GameUIImage GameUIImage::game_ui;
	void GameUIImage::load() {
		game_ui.score_board[BOARD_TYPE::FRAME] = lib::Graphics2D::load("./dat/image/GUI/Board/frame_main.png");
		game_ui.score_board[BOARD_TYPE::FRAME_MASK] = lib::Mask::load("./dat/image/GUI/Board/frame_mask.png");
		game_ui.score_board[BOARD_TYPE::SINGLE] = lib::Graphics2D::load("./dat/image/GUI/Board/board_single.png");
		game_ui.score_board[BOARD_TYPE::DOUBLES] = lib::Graphics2D::load("./dat/image/GUI/Board/board_double.png");
		game_ui.score_board[BOARD_TYPE::SCORE_UI] = lib::Graphics2D::load("./dat/image/GUI/Board/score.png");
		game_ui.pause[PAUSE_TYPE::NORMAL_PAUSE] = lib::Graphics2D::load("./dat/image/GUI/PauseScene/Normal.png");
		game_ui.pause[PAUSE_TYPE::EXTEND_PAUSE] = lib::Graphics2D::load("./dat/image/GUI/PauseScene/Extend.png");
		game_ui.pause[PAUSE_TYPE::GAMEOVER_PAUSE] = lib::Graphics2D::load("./dat/image/GUI/PauseScene/Gameover.png");
		game_ui.special.apple = lib::Graphics2D::load("./dat/image/GUI/Board/special_UI/apple_point.png");
		game_ui.special.crush_back = lib::Graphics2D::load("./dat/image/GUI/Board/special_UI/crush_back.png");
		game_ui.special.crush_front = lib::Graphics2D::load("./dat/image/GUI/Board/special_UI/crush_front.png");
		game_ui.special.roulette = lib::Graphics2D::load("./dat/image/GUI/Board/special_UI/roulette.png");
		game_ui.special.camp[0] = lib::Graphics2D::load("./dat/image/GUI/Board/special_UI/camp_back.png");
		game_ui.special.camp[1] = lib::Graphics2D::load("./dat/image/GUI/Board/special_UI/camp_front.png");
		game_ui.special.camp[2] = lib::Graphics2D::load("./dat/image/GUI/Board/special_UI/camp.png");
		game_ui.boss_position = lib::Graphics2D::load("./dat/image/GUI/Board/boss_pos.png");
		game_ui.sBox.right = lib::Graphics2D::load("./dat/image/GUI/SerifBox/right.png");
		game_ui.sBox.left = lib::Graphics2D::load("./dat/image/GUI/SerifBox/left.png");
		game_ui.sBox.gray = lib::Graphics2D::load("./dat/image/GUI/SerifBox/gray.png");

		game_ui.bossLife = lib::Graphics2D::load("./dat/image/GUI/Board/bossLife.png");
		game_ui.life[0] = lib::Graphics2D::load("./dat/image/GUI/Board/life/0.png");
		game_ui.life[1] = lib::Graphics2D::load("./dat/image/GUI/Board/life/1.png");
		game_ui.life[2] = lib::Graphics2D::load("./dat/image/GUI/Board/life/2.png");
		game_ui.life[3] = lib::Graphics2D::load("./dat/image/GUI/Board/life/3.png");
		game_ui.bom[0] = lib::Graphics2D::load("./dat/image/GUI/Board/bom/0.png");
		game_ui.bom[1] = lib::Graphics2D::load("./dat/image/GUI/Board/bom/1.png");
		game_ui.bom[2] = lib::Graphics2D::load("./dat/image/GUI/Board/bom/2.png");
		game_ui.bom[3] = lib::Graphics2D::load("./dat/image/GUI/Board/bom/3.png");
		game_ui.bom[4] = lib::Graphics2D::load("./dat/image/GUI/Board/bom/4.png");
		game_ui.bom[5] = lib::Graphics2D::load("./dat/image/GUI/Board/bom/5.png");
		game_ui.bom[6] = lib::Graphics2D::load("./dat/image/GUI/Board/bom/6.png");
		game_ui.bom[7] = lib::Graphics2D::load("./dat/image/GUI/Board/bom/7.png");
		game_ui.diff[0] = lib::Graphics2D::load("./dat/image/GUI/Board/Level/Easy.png");
		game_ui.diff[1] = lib::Graphics2D::load("./dat/image/GUI/Board/Level/Normal.png");
		game_ui.diff[2] = lib::Graphics2D::load("./dat/image/GUI/Board/Level/Hard.png");
		game_ui.sub_title = lib::Graphics2D::load("./dat/image/GUI/SubTitle/box.png");
	}
}