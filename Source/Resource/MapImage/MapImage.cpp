#include"MapImage.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/library/Graphics/Graphics3D/Graphics3D.h"
namespace res {
	MapImage MapImage::Map;
	void MapImage::load() {
		Map.model[BACK_MODEL::CHERRY_ROOD] = lib::Graphics3D::load("./dat/image/BackGround/Model/CherryRood/CherryRood.x");
		Map.model[BACK_MODEL::CLOCK_OBJ] = lib::Graphics3D::load("./dat/image/BackGround/Model/ClockRood/ClockObj.x");
		Map.model[BACK_MODEL::CLOCK_SKY] = lib::Graphics3D::load("./dat/image/BackGround/Model/ClockRood/ClockSky.x");
		Map.model[BACK_MODEL::CARPET_ROOD] = lib::Graphics3D::load("./dat/image/BackGround/Model/CarpetRood/Carpet.x");
		Map.model[BACK_MODEL::CASTLE_ROOD] = lib::Graphics3D::load("./dat/image/BackGround/Model/CastleRood/CastleRood.x");
		Map.model[BACK_MODEL::FOREST_ROOD] = lib::Graphics3D::load("./dat/image/BackGround/Model/ForestRood/ForestRood.x");
		Map.model[BACK_MODEL::SKY_ROOD] = lib::Graphics3D::load("./dat/image/BackGround/Model/skyrood/skyrood.x");

		Map.back[BACK_SCREEN::CHERRY_SKY] = lib::Graphics2D::load("./dat/image/BackGround/BackSky/CherryAir.png");
		Map.back[BACK_SCREEN::SNOW_SKY] = lib::Graphics2D::load("./dat/image/BackGround/BackSky/SnowAir.png");
		Map.back[BACK_SCREEN::LUNA_DAST] = lib::Graphics2D::load("./dat/image/BackGround/Effect/LunaDast.png");
		Map.back[BACK_SCREEN::LUNA_VIO_DAST] = lib::Graphics2D::load("./dat/image/BackGround/Effect/LunaVioDast.png");
		Map.back[BACK_SCREEN::BOSS_BACK00] = lib::Graphics2D::load("./dat/image/BackGround/BackSky/BossBack0.png");
		Map.back[BACK_SCREEN::BOSS_BACK01] = lib::Graphics2D::load("./dat/image/BackGround/BackSky/BossBack1.png");
		Map.back[BACK_SCREEN::BOSS_BACK02A] = lib::Graphics2D::load("./dat/image/BackGround/BackSky/BossBack2a.png");
		Map.back[BACK_SCREEN::BOSS_BACK02B] = lib::Graphics2D::load("./dat/image/BackGround/BackSky/BossBack2b.png");
		Map.back[BACK_SCREEN::BOSS_BACK03] = lib::Graphics2D::load("./dat/image/BackGround/BackSky/BossBack3.png");
		Map.back[BACK_SCREEN::BOSS_BACK04] = lib::Graphics2D::load("./dat/image/BackGround/BackSky/BossBack4.png");
		Map.back[BACK_SCREEN::BOSS_BACK05A] = lib::Graphics2D::load("./dat/image/BackGround/BackSky/BossBack5a.png");
		Map.back[BACK_SCREEN::BOSS_BACK05B] = lib::Graphics2D::load("./dat/image/BackGround/BackSky/BossBack5b.png");
		Map.back[BACK_SCREEN::BOSS_BACK07] = lib::Graphics2D::load("./dat/image/BackGround/BackSky/BossBack7.png");
	}
}