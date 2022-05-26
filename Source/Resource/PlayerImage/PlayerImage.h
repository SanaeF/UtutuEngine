#pragma once
namespace res {
	enum PLAYER_TYPE {
		EREMIRA,
		MAI,
		MEGU,
		HIME,
		IORIKO,
		MANIWA,
		URANA,
		UZUKI,
		NUM_MAX
	};
	class PlayerImage {
	public:
		int type[PLAYER_TYPE::NUM_MAX][12];
		int hitbox;
		int shot;
		static void load();
		static PlayerImage Player;
	};
}