#pragma once
#include "../../Source/Resource/BulletImage/BulletImage.h"
#include <memory>
namespace obj {
	class OptionManager;
	class Collider {
	private:
		struct BulletObjInfo {
			int size_x;
			int size_y;
			int col_num;
			int kaiten;
			float range;
		};
		struct Point {
			float x; 
			float y;
		};
		struct Vector2 {
			float x, y;
		};

		BulletObjInfo m_Bullet[res::TYPE_MAX];
		float m_Player_shot_range[res::PLAYER_SHOT_MAX];
		bool m_Is_inv_bom;
	public:
		enum TYPE {
			BULLET,
			PLAYER_SHOT
		};

		enum HIT_TYPE {
			NONE,
			GRAZE,
			DAMAGE,
		};
		void setInvPlayerBom(bool flag);
		int hitBullet(
			float get_x,
			float get_y,
			int get_type,
			float getSpeed,
			float getAngle,
			float size,
			int graze,
			int who = 0
		);
		int hitLazer(
			float get_x[4],
			float get_y[4],
			int get_type,
			float getSpeed,
			float getAngle,
			int graze,
			int who = 0
		);
		bool hitCircle(
			float get_x[2],
			float get_y[2],
			float getSpeed,
			float getAngle,
			float hit_range[2]
		);
		int hitPlayerShot(float x, float y, float obj_size, int who = 0);
		int getBulletRange(int num);
		Collider(int type);
	private:
		void inputBulletInfo(BulletObjInfo* binfo, int size1_x, int size1_y, int col1_num, double range1);
		void inputInfo();
		void inputPlayerShotInfo();
	};
}