#pragma once
#define FIRST_STAGE (0)//�ŏ��̃X�e�[�WID
#define EX_STAGE (7)//�ŏ��̃X�e�[�WID
#define USE_DEBUGLOG (true)

//�c�@�ƃ{�����̏����ݒ�
enum PLAYER_STATES{
	LIFE = 3,//2
	BOM = 2,
	POWER = 0,//stage1:174
};
//�{�X�̒e����ނ̐�(���ݖ��g�p)
enum BULLER_STATES {
	B_1_BULLET_MAX,
	B_2_BULLET_MAX,
	B_3_BULLET_MAX,
	B_4_BULLET_MAX,
	B_5_BULLET_MAX,
	B_6_BULLET_MAX,
	B_ex_BULLET_MAX,
};
//�Q�[���̃X�e�[�W���ƁA�e���X�e�[�W�̐���ݒ�
enum GAME_STATES {
	STAGE = 6,
	BULLET_NUM = 6,
	ALL_STAGE = 8
};
//��Փx�̎��
enum DIFFICULTY {
	EASY,
	NORMAL,
	HARD,
	VERYHARD,
	EXTRA,
	DIFF_MAX
};
