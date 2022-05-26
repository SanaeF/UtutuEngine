#pragma once

namespace app {
	class LoadScene {
	private:
		static bool m_Is_load;
		static int m_Load_count;
	public:
		static void join();
		static void left();
		static bool isDraw();
		static void draw();
		static void draw(int count);
	};
}