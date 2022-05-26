#pragma once
#include "../../Source/Application/GameFlow/Scene/Scene.h"
namespace app {
	class ConfigMenu :public Scene {
	private:
		const int m_Cool_down = 6;
		int m_Config_state;
		int m_Key_sub[10];
		int m_Key_sub2P[10];
		int m_Vol;
		int m_Vol_max;
		int m_Count;
	public:
		int update()override;
		void draw()override;
		ConfigMenu() {
			m_Config_state = 0;
			m_Count = 0;
		}
	private:
		void select()override;
		void cancel()override;
		void right();
		void left();
		void keyConfig();
	};
}