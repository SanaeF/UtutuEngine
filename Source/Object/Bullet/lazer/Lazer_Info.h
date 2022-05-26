#pragma once
#include "../../Source/Object/Object/Object.h"
#include "../../Source/Object/Bullet/GrazeEffect/GrazeEffect.h"
#include <memory>

namespace obj {

	enum {
		LAZER_NUM_MAX = 4000,
	};
	class Effect;
	class Lazer_Info :public Object {
	private:
		enum Bound {
			AREA_LEFT = 1,
			AREA_RIGHT = 2,
			AREA_UP = 3,
			AREA_DOWN = 4
		};
		GrazeEffect G_Effect;
		std::shared_ptr<Effect>m_Effect;
		Field m_Field;
		float disp_x[4];
		float disp_y[4];
		double debug_x[4];
		double debug_y[4];
		double angle;
		double length_rota;
		double speed;
		double dist;
		double length;
		int color;
		int graze;
		int bound_count;
		int laz_type;
		int laz_color;
		int bount_area;
		bool rota_flag;
		bool shine_flag;
		bool bount_flag;
		bool hit_flag;
		bool is_bount_no_angle;
		bool no_delete;

	public:
		Lazer_Info();
		~Lazer_Info();
		void setField(Field& field);
		void ObjClear();
		void update();
		void draw(double crush_x, double crush_y);
		void setDefault();
		void setLengthAngle(double angle);
		void setAngle(double angle);
		void setSpeed(double speed);
		void setThick(double dist);
		void setLength(double length);
		void setColor(int color);
		void setGraze(int num);
		void setMainColor(int color);
		void setMainType(int type);
		void setRota(bool flag);
		void setShine(bool flag);
		void setBound(bool flag);
		void set_collision(bool flag);
		void setBoundArea(int area);
		void setBoundNoAngle(bool flag);
		void setNoDelete(bool flag);
		void clear(bool flag);
		double getAngle();
		double getLengthAngle();
		double getSpeed();
		double getThick();
		double getLength();
		int getColor();
		int getGraze();
		int getMainColor();
		int getMainType();
		bool isRota();
		bool isShine();
		bool isBound();
		bool isCollision();
		bool isNoDelete();
		int getBoundArea();
		int getBoundCount();
	private:
		void rotation();
		void mover();
		void lengthUpdate();
		void outOfBoaderUpdate();
		void Collision();
	};
}
