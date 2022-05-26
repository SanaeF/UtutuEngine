#pragma once
#include "../../Source/Object/Object/Object.h"

namespace obj {
	class Effect : public  Object {
	private:
		int m_Bright;
		int m_Shot_color;
		float m_Angle;
	public:
		void draw(Field field);
		void update();
		void setColor(int color);
		void setAngle(float num);
	private:
		void none();
		void drawPlayerDeath(Field field);
		void drawBossCrush(Field field);
		void drawBossCharge(Field field);
		void drawShotKill(Field field);
		bool isType(int num);
	public:
		enum {
			NONE,
			SHOT_CLEAR,
			BOSS_CRUSH,
			BOSS_CHARGE,
			PLAYER_DEATH
		};
	};
}