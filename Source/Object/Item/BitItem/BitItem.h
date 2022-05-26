#pragma once
#include "../../Source/Object/Object/Object.h"

namespace obj {
	enum {
		ITEM_MAX = 10,
		ITEM_HIT_BOX = 100,
		ITEM_INDRAW_RANGE = 200,
		ITEM_GET_BORDER_LINE = 400
	};
	class BitItem : public  Object {
	private:
		enum {
			NONE,ABSORB
		};
		Field m_Field;
		float m_Speed;
		float m_Angle;
	public:
		void update(bool isAbsorb, double x, double y);
		void draw(double crush_x = 0.f, double crush_y = 0.f);
		void clear();
		void setSpeed(float num);
	private:
		void setFieldArea();
		void absorb(double x, double y);
	};
}