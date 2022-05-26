#pragma once
#include <memory>
namespace obj {
	class FadeIn;
	class BossHP {
	private:
		bool m_Is_flag;
		std::shared_ptr<FadeIn> m_Fade_guage;
	public:
		BossHP();
		void start(int wait_time);
		void update();
		void draw(float boss_x, float boss_y, float cx, float cy, int hp_max, int hp);
		void stop();
	};
}