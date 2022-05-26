#pragma once
#include <iostream>
namespace app {
	class WeaponLore {
	private:
		float m_Pos_x;
		float m_Pos_y;
	public:
		WeaponLore(float x, float y);
		void draw(int life, int bom, int pow,int special_type);
	private:
		void drawSPLore(int special_type);
	};
}