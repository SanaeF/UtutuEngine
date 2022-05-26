#pragma once

namespace obj {
	class MagicRingEffect {
	private :
		bool m_Is_flag;
		int m_Magicring_count;
	public:
		MagicRingEffect();
		void start();
		void draw(double x,double y, double crush_x = 0.f, double crush_y = 0.f);
		void update();
		void stop();
	};
}