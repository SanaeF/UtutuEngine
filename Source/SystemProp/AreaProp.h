#pragma once
//ゲーム枠内のオブジェクトの制限と初期位置
enum AREA {
	FMAX_X = (624 * 2),//1529
	FMIN_X = 106,//391
	FMAX_Y = 1388,
	FMIN_Y = 52,


	//プレイヤの初期位置

	DEF_PLAYER_X = (FMAX_X - FMIN_X) / 2,
	DEF_PLAYER_Y = FMAX_Y * 3 / 4,

	DEF_BOSS_X = (FMAX_X - FMIN_X) / 2,
	DEF_BOSS_Y = 450,


	//ボスの初期位置

	P1_MIN_X = 30,
	P1_MAX_X = 946,
	P2_MIN_X = 974,
	P2_MAX_X = 1890,


	//マルチ対戦専用
	DEF_MULTI_X = (P1_MAX_X - P1_MIN_X) / 2,
};