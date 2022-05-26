#pragma once

namespace res {
	//インゲーム枠の種類
	enum BOARD_TYPE {
		DFF,
		SINGLE,
		DOUBLES,
		SCORE_UI,
		BOARD_MAX
	};
	//ポーズ中の種類
	enum PAUSE_TYPE {
		NORMAL_PAUSE,
		EXTEND_PAUSE,
		GAMEOVER_PAUSE,
		PAUSE_MAX
	};
	//特別なUI
	struct SpecialUI {
		int roulette;
		int crush_front;
		int crush_back;
		int apple;
		int camp[3];
	};
	//吹き出し
	struct SerifBoxUI {
		int right;
		int left;
		int gray;
	};
	//インゲームにおけるUI
	class GameUIImage {
	public:
		SpecialUI special;
		int score_board[BOARD_MAX];
		int diff[3];
		int life[4];
		int bom[8];
		int bossLife;
		int boss_position;
		int pause[PAUSE_MAX];
		int sub_title;
		SerifBoxUI sBox;
		static void load();
		static GameUIImage game_ui;
	};
}