#pragma once
namespace res {
	enum BACK_SCREEN {//2Dîwåi
		CHERRY_SKY,
		SNOW_SKY,
		LUNA_DAST,
		LUNA_VIO_DAST,
		BOSS_BACK00,
		BOSS_BACK01,
		BOSS_BACK02A,
		BOSS_BACK02B,
		BOSS_BACK03,
		BOSS_BACK04,
		BOSS_BACK05A,
		BOSS_BACK05B,
		BOSS_BACK07,
		BACK_SCREEN_MAX
	};
	enum BACK_MODEL {//3DÉÇÉfÉã
		CHERRY_ROOD,
		CLOCK_SKY,
		CLOCK_OBJ,
		CARPET_ROOD,
		CASTLE_ROOD,
		FOREST_ROOD,
		SKY_ROOD,
		BACK_MODEL_MAX
	};
	class MapImage {//îwåiëfçﬁ
	public:
		int model[BACK_MODEL_MAX];
		int back[BACK_SCREEN_MAX];
		static void load();
		static MapImage Map;
	};
}