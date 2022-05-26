#pragma once
#include <vector>
#include "../../../Object/Object.h"
#include "../../../Object/Parameter/Position/Position.h"
#include "../../Source/Object/Player/Shot/PlayerShot/PlayerShot.h"
namespace obj {
	class SideOption : public Object {
	private:
		float m_Player_x;
		float m_Player_y;
		float m_Pos_x[4];
		float m_Pos_y[4];
		float m_Angle;
		float m_Length;
		float m_Thick;
	public:
		SideOption();
		~SideOption();

		void initialize();

		void update(float x, float y, std::vector<PlayerShot>& player_shot);
		void draw(double crush_x, double crush_y);

		void setAngle(float angle);
		void setLength(float length);
		void setThick(float thick);
		float getAngle();
		float getLength();
		float getThick();
	private:
		int search(std::vector<PlayerShot>& player_shot);
		void setVertex();
		void collision(std::vector<PlayerShot>& player_shot);
	};
}