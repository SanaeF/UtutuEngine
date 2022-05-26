#pragma once
#define FIRST_STAGE (0)//最初のステージID
#define EX_STAGE (7)//最初のステージID
#define USE_DEBUGLOG (true)

//残機とボム数の初期設定
enum PLAYER_STATES{
	LIFE = 3,//2
	BOM = 2,
	POWER = 0,//stage1:174
};
//ボスの弾幕種類の数(現在未使用)
enum BULLER_STATES {
	B_1_BULLET_MAX,
	B_2_BULLET_MAX,
	B_3_BULLET_MAX,
	B_4_BULLET_MAX,
	B_5_BULLET_MAX,
	B_6_BULLET_MAX,
	B_ex_BULLET_MAX,
};
//ゲームのステージ数と、弾幕ステージの数を設定
enum GAME_STATES {
	STAGE = 6,
	BULLET_NUM = 6,
	ALL_STAGE = 8
};
//難易度の種類
enum DIFFICULTY {
	EASY,
	NORMAL,
	HARD,
	VERYHARD,
	EXTRA,
	DIFF_MAX
};
