#pragma once
#include <memory>
#include "./Parameter/Position/Position.h"
#include "./Parameter/FadeIn/FadeIn.h"
#define PI 3.1415926535898
#define PI2 (PI*2)

namespace app {
	class Shake;
}
namespace obj {
	class Object {
	public:
		struct Field {
			int m_Max_x;
			int m_Min_x;
		};
	private:
		struct Shake_Info {
			bool flag;
			float size;
			int time;
		};
		bool obj_flag;
		double x;
		double y;
		double z;
		double size;
		int type;
		int count;
		int state[2];
		int rayer;
		Shake_Info mShake_info;
		std::shared_ptr<app::Shake>m_Shake;
	public:
		Object();
		void valueReset(bool DeathFlag = false);
		void countUpdate();
		void setFlag(bool flag);
		void setX(double x);
		void setY(double y);
		void setZ(double z);
		void setSize(double size);
		void setType(int type);
		void setState(int state1);
		void setStateSub(int state2);
		void setCount(int count);
		void setRayer(int num);
		bool isFlag();
		double getX();
		double getY();
		double getZ();
		double getSize();
		int getType();
		int getState();
		int getStateSub();
		int getCount();
		int getRayer();
		std::shared_ptr<app::Shake>& getShake();
	};
}