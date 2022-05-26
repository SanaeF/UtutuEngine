#pragma once
#include "../../Source/Application/GameFlow/Scene/Scene.h"

namespace app {
	class HelpRoom :public Scene {
	private:

		int m_Help_state;
	public:
		int update()override;
		void draw()override;
		void select()override;
		void cancel()override;
		HelpRoom();
	};
}