#pragma once
#include <iostream>

namespace obj {
	class BossUI {
	private:
		bool m_Is_serif;
		int m_Serif_time;
		int m_Serif_count;
		float m_Serif_x;
		float m_Serif_y;
		std::string m_Serif_text;
	public:
		BossUI();
		void update();
		void drawCounter(int time, int bullet_num, int bullet_type);
		void drawSerifBox();
		void setSerifBox(int time, float x, float y, std::string text);
	private:
	};
}