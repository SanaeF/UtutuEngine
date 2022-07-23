#include "BossHP.h"
#include "../../Source/SystemProp/AreaProp.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/Object/Object/Parameter/FadeIn/FadeIn.h"
#include "../../Source/Resource/GUI/BossUIImage/BossUIImage.h"

namespace obj {
	BossHP::BossHP():
		m_Is_flag(false)
	{
		m_Fade_guage.reset(new FadeIn());
	}
	void BossHP::start(int wait_time) {
		m_Is_flag = true;
		m_Fade_guage->initialize();
		m_Fade_guage->setParam(wait_time/3);
	}
	void BossHP::update() {
		if (!m_Is_flag)return;
		m_Fade_guage->update();
	}
	void BossHP::draw(float boss_x, float boss_y, float cx, float cy, int hp_max, int hp) {
		if (!m_Is_flag)return;
		lib::Graphics2D::drawRota(
			boss_x + AreaProp::min_x + cx,
			boss_y + AreaProp::min_y + cy,
			1.3f,
			0.0f,
			res::BossUIImage::boss_ui.hp_back,
			true
		);
		float percent = (100 * hp) / hp_max;
		if(m_Fade_guage->isFlag())percent = (100 * m_Fade_guage->getSize(hp_max)) / hp_max;
		if (hp > 0) {
			lib::Graphics2D::circleGauge(
				boss_x + AreaProp::min_x + cx,
				boss_y + AreaProp::min_y + cy,
				percent,
				res::BossUIImage::boss_ui.hp,
				0
			);
		}
		lib::Graphics2D::setBright(255, 255, 255);
	}
	void BossHP::stop() {
		m_Is_flag = false;
	}
}