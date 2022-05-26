#pragma once
#include "../../Scene/Scene.h"

namespace app {
	class StorySelect : public Scene {
	public:
		int update()override;
		void draw()override;
		void select()override;
		void cancel()override;
	};
}