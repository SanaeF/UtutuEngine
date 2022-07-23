#include "StageMap.h"
#include <iostream>
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/SystemProp/AreaProp.h"
#include "../../Source/Object/BackGround/BackGround.h"
#include "../../Source/Object/Player/Player.h"
#include "../../Source/Object/Boss/Boss.h"
#include "../../Source/Resource/MapImage/MapImage.h"
#include "../../Source/EffectTools/ScreenFade/ScreenFade.h"
#include "../../Source/Manager/BossManager/BossManager.h"
using namespace res;

namespace app {
	void StageMap::startForRood() {
		obj::BackGraph map;
		obj::Position cam_pos;
		obj::Position cam_rd;
		obj::Position obj_pos;
		if (isState(0)) {
			setMapObjNum(1);
			cam_pos.set(AreaProp::max_x / 2 - AreaProp::min_x - 100, 1400.0f, -80.0f);
			cam_rd.set(45.0f * PI / 180.0f, 0.f, 0.f);
			obj_pos.set((m_Count * (PI / 8) / 60) + 500, 0, 0);
			map.setCamera(cam_pos, cam_rd);
			map.create(obj_pos, 1, 0, 18, BACK_MODEL::CHERRY_ROOD, 7200, obj::BackGraph::ROOD_3D_SCROLL, m_Count);

			int type = BACK_SCREEN::SNOW_SKY;
			if (m_Count == 2940)ScreenFade::BackDirect.setFade(ScreenFade::FADE_OUT, 60, 255, 255, 255);
			if (m_Count > 3000)type = BACK_SCREEN::CHERRY_SKY;
			if (m_Count == 3000)ScreenFade::BackDirect.setFade(ScreenFade::FADE_IN, 120, 255, 255, 255);
			obj_pos.set((AreaProp::max_x - AreaProp::min_x) / 2, AreaProp::max_y / 2, 0);
			map.set_DistX(1.3, 6, 70);
			map.set_DistY(1.3, 6, 100);
			map.create(obj_pos, PI, 1, 0, type, 0, obj::BackGraph::BACK_DIST_2D, m_Count);
		}
		if (isState(1)) {
			setMapObjNum(1);
			cam_pos.set(AreaProp::max_x / 2 - AreaProp::min_x - 100, 1400.0f, -80.0f);
			cam_rd.set(45.0f * PI / 180.0f, 0.f, -PI / 6);
			obj_pos.set((m_Count * (PI / 8) / 60) + 500, -300, 0);
			map.setCamera(cam_pos, cam_rd);
			map.create(obj_pos, 1, 0, 9, BACK_MODEL::CLOCK_SKY, 7200, obj::BackGraph::ROOD_3D_SCROLL, m_Count);

			cam_pos.set(AreaProp::max_x / 2 - AreaProp::min_x - 100, 1400.0f, -80.0f);
			cam_rd.set(45.0f * PI / 180.0f, 0.f, cos(m_Count * (PI / 8) / 60) / 5);
			obj_pos.set((m_Count * (PI / 8) / 60) + 500, -300, 0);
			map.setCamera(cam_pos, cam_rd);
			map.create(obj_pos, 1, 0, 42, BACK_MODEL::CLOCK_OBJ, 7200, obj::BackGraph::ROOD_3D_SCROLL, m_Count);
		}
		if (isState(2)) {
			cam_pos.set(AreaProp::max_x / 2 - AreaProp::min_x - 100, 1400.0f, -80.0f);
			cam_rd.set(45.0f * PI / 180.0f, 0.f,0);
			obj_pos.set((m_Count * (PI / 8) / 60) + 500, 0, 0);
			map.setCamera(cam_pos, cam_rd);
			map.create(obj_pos, 1, 0, 28, BACK_MODEL::CARPET_ROOD, 7200, obj::BackGraph::ROOD_3D_SCROLL, m_Count);
		}
		if (isState(3)) {
			cam_pos.set(AreaProp::max_x / 2 - AreaProp::min_x - 100, 1800.0f, -80.0f);
			cam_rd.set(50.0f * PI / 180.0f, 0.f, 0);
			obj_pos.set((m_Count * (PI / 8) / 60) + 500, 0, 0);
			map.setCamera(cam_pos, cam_rd);
			map.create(obj_pos, 1, 0, 28, BACK_MODEL::CASTLE_ROOD, 7200, obj::BackGraph::ROOD_3D_SCROLL, m_Count);
			obj_pos.set(AreaProp::max_x / 2, AreaProp::max_y / 2, 0);
			map.create(obj_pos, PI, 1, -6, BACK_SCREEN::LUNA_DAST, -2880, obj::BackGraph::ROOD_2D_SCROLL, m_Count);
		}
		if (isState(4)) {
			if (m_Stage_count <= 2202) {
				cam_pos.set(AreaProp::max_x / 2 - AreaProp::min_x - 100, 1800.0f, -80.0f);
				cam_rd.set(50.0f * PI / 180.0f, 0.f, 0);
				obj_pos.set((m_Count * (PI / 8) / 60) + 500, 0, 0);
				map.setCamera(cam_pos, cam_rd);
				map.create(obj_pos, 1, 0, 28, BACK_MODEL::CASTLE_ROOD, 7200, obj::BackGraph::ROOD_3D_SCROLL, m_Count);
			}
			obj_pos.set(AreaProp::max_x / 2, AreaProp::max_y / 2, 0);
			map.create(obj_pos, PI, 1, -6, BACK_SCREEN::LUNA_DAST, -2880, obj::BackGraph::ROOD_2D_SCROLL, m_Count);
			map.create(obj_pos, PI, 1, 18, BACK_SCREEN::LUNA_VIO_DAST, 2880, obj::BackGraph::ROOD_2D_SCROLL, m_Count);
		}
		if (isState(5)) {
			if (m_Stage_count <= 3162) {
				cam_pos.set(AreaProp::max_x / 2 - AreaProp::min_x - 100, 3400.0f, -80.0f);
				cam_rd.set(55.0f * PI / 180.0f, 0.f, 0);
				obj_pos.set((m_Count * (PI / 8) / 60) + 500, 0, 0);
				map.setCamera(cam_pos, cam_rd);
				map.create(obj_pos, 1, 0, 28, BACK_MODEL::FOREST_ROOD, 7200, obj::BackGraph::ROOD_3D_SCROLL, m_Count);
				obj_pos.set(AreaProp::max_x / 2, AreaProp::max_y / 2, 0);
				map.create(obj_pos, PI, 1, -6, BACK_SCREEN::LUNA_VIO_DAST, -2880, obj::BackGraph::ROOD_2D_SCROLL, m_Count);
			}
			else {
				obj_pos.set((AreaProp::max_x - AreaProp::min_x) / 2 + AreaProp::min_x, (AreaProp::max_y - AreaProp::min_y) / 2, 0);
				map.create(obj_pos, 0, 1, 0, res::BACK_SCREEN::BOSS_BACK05A, 2880, obj::BackGraph::STAY_2D, m_Count);
				map.create(obj_pos, PI / 340 * m_Count, 1.4, 0, res::BACK_SCREEN::BOSS_BACK05B, 2880, obj::BackGraph::STAY_2D, m_Count);
			}
		}
		if (isState(6)) {
			cam_pos.set(AreaProp::max_x / 2 - AreaProp::min_x - 100, 1400.0f, -80.0f);
			cam_rd.set(45.0f * PI / 180.0f, 0.f, cos(m_Count * (PI / 8) / 60) / 5);
			obj_pos.set((m_Count * (PI / 8) / 60) + 500, 0, 0);
			map.setCamera(cam_pos, cam_rd);
			map.create(obj_pos, 1, 0, 28, BACK_MODEL::CARPET_ROOD, 7200, obj::BackGraph::ROOD_3D_SCROLL, m_Count);
			obj_pos.set(AreaProp::max_x / 2, AreaProp::max_y / 2, 0);
			map.create(obj_pos, PI, 1, -6, BACK_SCREEN::LUNA_DAST, -2880, obj::BackGraph::ROOD_2D_SCROLL, m_Count);
		}
		if (isState(7)) {
			if (m_Stage_count <= 6708) {
				cam_pos.set(AreaProp::max_x / 2 - AreaProp::min_x - 100, 3400.0f, -80.0f);
				cam_rd.set(55.0f * PI / 180.0f, 0.f, cos(m_Count * (PI / 8) / 60) / 5);
				obj_pos.set((m_Count * (PI / 8) / 60) + 500, 0, 0);
				map.setCamera(cam_pos, cam_rd);
				map.create(obj_pos, 1, 0, 22, BACK_MODEL::SKY_ROOD, 7200, obj::BackGraph::ROOD_3D_SCROLL, m_Count);
				obj_pos.set(AreaProp::max_x / 2, AreaProp::max_y / 2, 0);
				map.create(obj_pos, PI, 1, 6, BACK_SCREEN::LUNA_VIO_DAST, 2880, obj::BackGraph::ROOD_2D_SCROLL, m_Count);
			}
			else {
				obj_pos.set((AreaProp::max_x - AreaProp::min_x) / 2 + AreaProp::min_x, (AreaProp::max_y - AreaProp::min_y) / 2, 0);
				map.create(obj_pos, 0, 1, 0, res::BACK_SCREEN::BOSS_BACK07, 2880, obj::BackGraph::STAY_2D, m_Count);
			}
		}
	}
	void StageMap::startForBullet() {
		obj::Position obj_pos;
		obj::BackGraph map;
		if (isState(0)) {
			obj_pos.set((AreaProp::max_x - AreaProp::min_x) / 2, AreaProp::max_y / 2, 0);
			map.set_DistX(4.3, 4, 200);
			map.set_DistY(4.3, 4, 300);
			map.create(obj_pos, PI, 1, 0, res::BACK_SCREEN::BOSS_BACK00, 0, obj::BackGraph::BACK_DIST_2D, m_Count);
		}
		if (isState(1)) {
			obj_pos.set((AreaProp::max_x - AreaProp::min_x) / 2, AreaProp::max_y / 2, 0);
			map.create(obj_pos, PI / 340 * m_Count, 1, 0, res::BACK_SCREEN::BOSS_BACK01, 0, obj::BackGraph::STAY_2D, m_Count);
		}
		if (isState(2)) {
			obj_pos.set((AreaProp::max_x - AreaProp::min_x) / 2+ AreaProp::min_x, (AreaProp::max_y - AreaProp::min_y) / 2, 0);
			map.create(obj_pos, 0, 1, 5, res::BACK_SCREEN::BOSS_BACK02A, 2880, obj::BackGraph::ROOD_2D_SCROLL, m_Count);
			map.create(obj_pos, 0, 1, -5, res::BACK_SCREEN::BOSS_BACK02B, -2880, obj::BackGraph::ROOD_2D_SCROLL, m_Count);
		}
		if (isState(3)) {
			obj_pos.set((AreaProp::max_x - AreaProp::min_x) / 2 + AreaProp::min_x, (AreaProp::max_y - AreaProp::min_y) / 2, 0);
			map.create(obj_pos, 0, 1, 0, res::BACK_SCREEN::BOSS_BACK03, 2880, obj::BackGraph::STAY_2D, m_Count);
		}
		if (isState(4)) {
			obj_pos.set((AreaProp::max_x - AreaProp::min_x) / 2 + AreaProp::min_x, (AreaProp::max_y - AreaProp::min_y) / 2, 0);
			map.create(obj_pos, -PI / 340 * m_Count, 1, 0, res::BACK_SCREEN::BOSS_BACK04, 2880, obj::BackGraph::STAY_2D, m_Count);
		}
		if (isState(5)) {
			obj_pos.set((AreaProp::max_x - AreaProp::min_x) / 2 + AreaProp::min_x, (AreaProp::max_y - AreaProp::min_y) / 2, 0);
			map.create(obj_pos, 0, 1, 0, res::BACK_SCREEN::BOSS_BACK05A, 2880, obj::BackGraph::STAY_2D, m_Count);
			map.create(obj_pos, PI / 340 * m_Count, 1.4, 0, res::BACK_SCREEN::BOSS_BACK05B, 2880, obj::BackGraph::STAY_2D, m_Count);
		}
		if (isState(6)) {
			obj_pos.set((AreaProp::max_x - AreaProp::min_x) / 2 + AreaProp::min_x, (AreaProp::max_y - AreaProp::min_y) / 2, 0);
			map.create(obj_pos, 0, 1, 5, res::BACK_SCREEN::BOSS_BACK02A, 2880, obj::BackGraph::ROOD_2D_SCROLL, m_Count);
			map.create(obj_pos, 0, 1, -5, res::BACK_SCREEN::BOSS_BACK02B, -2880, obj::BackGraph::ROOD_2D_SCROLL, m_Count);
		}
		if (isState(7)) {
			obj_pos.set((AreaProp::max_x - AreaProp::min_x) / 2 + AreaProp::min_x, (AreaProp::max_y - AreaProp::min_y) / 2, 0);
			map.create(obj_pos, 0, 1, 0, res::BACK_SCREEN::BOSS_BACK07, 2880, obj::BackGraph::STAY_2D, m_Count);
		}
	}

	void StageMap::update(int stage_count) {
		m_Stage_count = stage_count;
		m_Count++;
	}
	void StageMap::draw(double cx, double cy) {
		if (manager::BossManager::getInstance()->isSpecialBullet()) {
			startForBullet();
		}
		else {
			startForRood();
		}
	}
	void StageMap::setCount(int count) {
		m_Count = count;
	}
	bool StageMap::isState(int stage) {
		if (stage == m_Stage)return true;
		return false;
	}
	int StageMap::getCount() {
		return m_Count;
	}
	void StageMap::create(bool isMainBullet, int stage) {
		m_Is_main_bullet = isMainBullet;
		m_Stage = stage;
	}
	bool StageMap::setMapObjNum(int num) {
		return true;
	}
	StageMap::StageMap() :
		m_Stage(0),
		m_Count(0),
		m_Is_main_bullet(false)
	{
	}
}