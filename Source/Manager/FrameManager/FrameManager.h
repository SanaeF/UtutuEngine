#pragma once

namespace app {
	class FrameManager {
	private:
		int mFrame;
		int* mFrameData;

		int fps_count;
		int count0t;
		float ave;
	public:

		FrameManager(int FPS);

		void update();

		void draw(int x, int y);
	};
}