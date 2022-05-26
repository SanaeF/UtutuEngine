#pragma once

namespace res {
	enum SE{
		BULLET01,
		BULLET02,
		LAZER01,
		LAZER02,
		KIRAN,
		EXPLODE,

		CHARGE,
		BOOOOM,
		BREAK,
		BOSSBREAK,
		GET_BONUS,
		GYUUUUUUN,

		PLAYER_SHOT,
		GRAZE,
		GOT_ITEM,
		BOMGET,
		LIFEGET,
		PLAYER_OUT,

		SELECT,
		SELECT_CANCEL,
		SELECT_OK,

		SE_MAX
	};

	class SoundData {
	public:
		int bgm[17];
		int se[SE_MAX];
		static void load();
		static SoundData sound;
	};
}