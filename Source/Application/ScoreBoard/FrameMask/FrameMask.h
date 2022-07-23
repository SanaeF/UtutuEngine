#pragma once
#include "../../Source/Tools/TimeFader/TimeFader.h"
namespace app {
	class FrameMask {
	private:
		TimeFader m_Fade_in;
	public:
		void start(int count);
		void draw();
		void clear();
	};
}