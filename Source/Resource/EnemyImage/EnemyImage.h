#pragma once
namespace res {
	enum BOSS_TYPE {
		N01_MATUMI,//�}�c�~
		N02_EREMIRA,//�G���~��
		N03_ALICE,//�A���X
		N03_MATUMI,//�}�c�~(�U)
		N03_EREMIRA,//�G���~��(�U)
		N04_NARSIRU,//�i���V��
		N05_BLACK,//5�{�X�̉e
		N05_FEATORIA,//�t�F�A�g���A
		N06_SHIENA,//�V�G�i
		N07_ALICE,//�A���X(��)
		N07_FEATORIA,//�t�F�A�g���A(�U)
		N08_KURO,//�N��
		B_MAX,
	};
	enum ENEMY_TYPE{
		DEV_NORMAL,
		DEV_ORANGE,
		DEV_GREEN,
		DEV_HACK,
		DEV_BONE,
		DEV_Lninyo,
		DEV_ITEM_BALLOON,
		FIRE_FEARY,
		TRAMP_MATSU,
		TRAMP_ELEMIRA,
		TRAMP_FEATORIA,
		OBJ_ONMYOU,
		OBJ_SHADOWWING,
		ENE_MAX
	};

	class EnemyImage {//�G�̉摜
	public:
		int boss[B_MAX][16];//�{�X
		int minion[ENE_MAX][6];//�G���G(�{�X)
		static void load();
		static EnemyImage enemy;
	};
}