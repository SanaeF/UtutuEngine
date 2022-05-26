#pragma once
namespace res {
	enum ITEM_TYPE {
		POWER,
		POINT,
		LIFE_UP,
		LIFE_PEACE,
		BOM_PEACE,
		BOM_UP,
		APPLE,
		GOLDEN_APPLE,
		START_ROULETTE,
		SCORE_DUST,
		POWER_GHOST,
		POINT_GHOST,
		ITEM_TYPE_MAX
	};
	enum ITEM_GHOST_TYPE {
		RED_GHOST,
		BLUE_GHOST
	};
	class ItemImage {
	public:
		int bit[10];//小さいアイテムカード
		int ghost[2];
		static void load();
		static ItemImage item;
	};
}