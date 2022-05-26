#pragma once

namespace res {
	//�C���Q�[���g�̎��
	enum BOARD_TYPE {
		DFF,
		SINGLE,
		DOUBLES,
		SCORE_UI,
		BOARD_MAX
	};
	//�|�[�Y���̎��
	enum PAUSE_TYPE {
		NORMAL_PAUSE,
		EXTEND_PAUSE,
		GAMEOVER_PAUSE,
		PAUSE_MAX
	};
	//���ʂ�UI
	struct SpecialUI {
		int roulette;
		int crush_front;
		int crush_back;
		int apple;
		int camp[3];
	};
	//�����o��
	struct SerifBoxUI {
		int right;
		int left;
		int gray;
	};
	//�C���Q�[���ɂ�����UI
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