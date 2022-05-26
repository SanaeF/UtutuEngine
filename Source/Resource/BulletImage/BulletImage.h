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
		NORMAL,//�ʏ�e
		SCALY,//�ؒe
		OVERLAP,//��d�e
		RICE,//�Ēe
		POIFUL,//�|�C�t���e
		BIG_STAR,//���e(��)
		DUST,//�����e
		BIG,//��e
		MEGA,//����e
		AMMO,//����e
		MINI_STAR,//���e(��)
		BONE,//���e
		PETAL,//�Ԃт�
		TRAMP,//�g�����v
		TURN_LAZ,//�ւɂ�背�[�U�[�p
		B_FLY,//���e
		LAZER,//�܂������ȃ��[�U�[
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
		int lazer[TYPE_MAX][COLOR_MAX];//�e��
		int player_shot[PLAYER_SHOT_MAX];
		int charge_effect[2];
		static void load();
		static BulletImage Bullet;
	};
}