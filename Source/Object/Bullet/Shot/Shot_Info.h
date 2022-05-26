#pragma once
#include "../../Source/Object/Object/Object.h"
#include "../../Source/Object/Bullet/GrazeEffect/GrazeEffect.h"
#include <memory>

namespace obj {
	enum {
		BULLET_NUM_MAX = 8000,
	};
	class Effect;
	class Shot_Info :public Object {
	private:
		enum Bound {
			AREA_LEFT = 1,
			AREA_RIGHT = 2,
			AREA_UP = 3,
			AREA_DOWN = 4
		};
		enum EFFECT {
			NONE,
			CREATE,
			GRAZE,
			CREATE_COUNT = 4,
		};
		GrazeEffect G_Effect;
		std::shared_ptr<Effect>m_Effect;
		Field m_Field;
		double angle;
		double speed;
		int color;
		int graze;
		int bound_count;
		int bount_area;
		bool is_hide;
		bool rota_flag;
		bool shine_flag;
		bool bount_flag;
		bool no_delete;
	public:
		Shot_Info();
		~Shot_Info();
		void setField(Field& field);
		void ObjClear();
		void update();
		void draw(double crush_x, double crush_y);
		void clear(bool flag);
		void setDefault();
		void setAngle(double angle);
		void setSpeed(double speed);
		void setColor(int color);
		void setGraze(int num);
		void set_rota(bool flag);
		void set_shine(bool flag);
		void setBound(bool flag);
		void setBoundArea(int area);
		void setBoundCount(int count);
		void setHide(bool flag);
		void setNoDelete(bool flag);
		double getAngle();
		double getSpeed();
		int getColor();
		int getGraze();
		bool isRota();
		bool isShine();
		bool isBound();
		bool isHide();
		bool isNoDelete();
		int getBoundArea();
		int getBoundCount();
	private:
		void mover();
		void grazeUpdate();
		void outOfBoaderUpdate();
		void Collision();
	};

}
