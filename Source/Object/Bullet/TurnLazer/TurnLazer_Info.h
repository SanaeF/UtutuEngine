#pragma once
#include "../../Source/Object/Object/Object.h"
#include "../../Source/Object/Bullet/GrazeEffect/GrazeEffect.h"
#include <memory>
#include <vector>

namespace obj {
	enum {
		T_LAZ_NUM_MAX = 4000,
	};
	class Effect;
	class TurnLazer_Info :public Object {
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
		struct Last_Info {
			float x;
			float y;
			float collision_x;
			float collision_y;
			float m_Angle;
			float speed;
			float size;
			int color;
			int state[2];
			int number[2];
			bool bount_flag;
			bool bount_area;
		};
		GrazeEffect G_Effect;
		std::shared_ptr<Effect>m_Effect;
		std::vector<Last_Info> m_Last_info;
		Field m_Field;
		float disp_x[4];
		float disp_y[4];
		int number;
		int number_max;
		double angle;
		double speed;
		double size;
		int color;
		int graze;
		int bound_count;
		int length;
		int bount_area;
		bool bount_flag;
		bool pause_tail;
	public:
		TurnLazer_Info();
		~TurnLazer_Info();
		void ObjClear();
		void pause(bool flag);
		void update();
		void drawBack(double crush_x, double crush_y);
		void draw(double crush_x, double crush_y);
		void setDefault();
		void spawnTail(Last_Info& info, int num, int num_max);
		void setAngle(double angle);
		void setSpeed(double speed);
		void setSize(double size);
		void setColor(int color);
		void setGraze(int num);
		void setLength(int length);
		void setBound(bool flag);
		void setBoundArea(int area);
		void clear(bool flag);
		double getAngle();
		double getSpeed();
		double getSize();
		int getColor();
		int getGraze();
		int getNumber();
		int getNumberMax();
		bool isBound();
		int getBoundArea();
		int getBoundCount();
		Last_Info getLastInfo();
	private:
		void initTail();
		void setTail();
		void cleaLastInfo();
		void mover();
		void grazeUpdate();
		void outOfBoaderUpdate();
		void cutThick(Last_Info& data, float thick);
		void Collision();
		double cutPal(int num, int length);
		double cutPalShine(int num, int length);
	};
}
