#include"ItemImage.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
namespace res {
	ItemImage ItemImage::item;
	void ItemImage::load() {
		item.bit[ITEM_TYPE::POWER] = lib::Graphics2D::load("./dat/image/item/power.png");
		item.bit[ITEM_TYPE::POINT] = lib::Graphics2D::load("./dat/image/item/point.png");
		item.bit[ITEM_TYPE::LIFE_UP] = lib::Graphics2D::load("./dat/image/item/LifeUP.png");
		item.bit[ITEM_TYPE::LIFE_PEACE] = lib::Graphics2D::load("./dat/image/item/LifeFragument.png");
		item.bit[ITEM_TYPE::BOM_PEACE] = lib::Graphics2D::load("./dat/image/item/BomFragument.png");
		item.bit[ITEM_TYPE::APPLE] = lib::Graphics2D::load("./dat/image/item/Apple/Normal.png");
		item.bit[ITEM_TYPE::GOLDEN_APPLE] = lib::Graphics2D::load("./dat/image/item/Apple/Triple.png");
		item.bit[ITEM_TYPE::SCORE_DUST] = lib::Graphics2D::load("./dat/image/item/ScoreDust.png");
		item.ghost[ITEM_GHOST_TYPE::RED_GHOST] = lib::Graphics2D::load("./dat/image/item/PowerGhost.png");
		item.ghost[ITEM_GHOST_TYPE::BLUE_GHOST] = lib::Graphics2D::load("./dat/image/item/PointGhost.png");
	}
}