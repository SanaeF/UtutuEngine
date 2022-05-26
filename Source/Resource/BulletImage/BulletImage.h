#pragma once
namespace res {
	enum BULLET_COLOR {
		RED,
		GREEN,
		BLUE,
		YELLOW,
		PINK,
		SKY,
		ORANGE,
		PURPLE,
		CLEAR_BLUE,
		ORIGINAL,
		BLACKBACK,
		COLOR_MAX
	};
	enum BULLET_TYPE {
		NORMAL,//通常弾
		SCALY,//鱗弾
		OVERLAP,//二重弾
		RICE,//米弾
		POIFUL,//ポイフル弾
		BIG_STAR,//星弾(大)
		DUST,//小粒弾
		BIG,//大弾
		MEGA,//巨大弾
		AMMO,//座薬弾
		MINI_STAR,//星弾(小)
		BONE,//骨弾
		PETAL,//花びら
		TRAMP,//トランプ
		TURN_LAZ,//へにょりレーザー用
		B_FLY,//蝶弾
		LAZER,//まっすぐなレーザー
		CLOCK_LAZ,
		EX_HAND,
		EX_META,
		FAKE_APPLE,
		MOON,
		EXCALIBUR,
		LOCK,
		EFFECT,
		TYPE_MAX
	};
	enum PLAYER_SHOT_TYPE {
		SHOT_BLUE,
		SHOT_CYAN,
		SHOT_POTATO,
		SHOT_COMET,
		SHOT_METEO,
		SHOT_BIRD,
		SHOT_MOON,
		LAZ_RED,
		LAZ_BLUE,
		LAZ_THUNDER,
		BOM_LAZER,
		BOM_MOON,
		ONMYOU,
		PLAYER_SHOT_MAX
	};
	class BulletImage {
	public:
		int shot[TYPE_MAX][COLOR_MAX];
		int lazer[TYPE_MAX][COLOR_MAX];//弾幕
		int player_shot[PLAYER_SHOT_MAX];
		int charge_effect[2];
		static void load();
		static BulletImage Bullet;
	};
}