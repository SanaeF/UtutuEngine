#pragma once
namespace res {
	enum BOSS_TYPE {
		N01_MATUMI,//マツミ
		N02_EREMIRA,//エレミラ
		N03_ALICE,//アリス
		N03_MATUMI,//マツミ(偽)
		N03_EREMIRA,//エレミラ(偽)
		N04_NARSIRU,//ナルシル
		N05_BLACK,//5ボスの影
		N05_FEATORIA,//フェアトリア
		N06_SHIENA,//シエナ
		N07_ALICE,//アリス(裏)
		N07_FEATORIA,//フェアトリア(偽)
		N08_KURO,//クロ
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

	class EnemyImage {//敵の画像
	public:
		int boss[B_MAX][16];//ボス
		int minion[ENE_MAX][6];//雑魚敵(ボス)
		static void load();
		static EnemyImage enemy;
	};
}