#pragma once
//�Q�[���g���̃I�u�W�F�N�g�̐����Ə����ʒu
enum AREA {
	FMAX_X = (624 * 2),//1529
	FMIN_X = 106,//391
	FMAX_Y = 1388,
	FMIN_Y = 52,


	//�v���C���̏����ʒu

	DEF_PLAYER_X = (FMAX_X - FMIN_X) / 2,
	DEF_PLAYER_Y = FMAX_Y * 3 / 4,

	DEF_BOSS_X = (FMAX_X - FMIN_X) / 2,
	DEF_BOSS_Y = 450,


	//�{�X�̏����ʒu

	P1_MIN_X = 30,
	P1_MAX_X = 946,
	P2_MIN_X = 974,
	P2_MAX_X = 1890,


	//�}���`�ΐ��p
	DEF_MULTI_X = (P1_MAX_X - P1_MIN_X) / 2,
};