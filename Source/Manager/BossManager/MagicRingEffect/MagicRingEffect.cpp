#include "MagicRingEffect.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/SystemProp/AreaProp.h"
#include "../../Source/Resource/GUI/BossUIImage/BossUIImage.h"

namespace obj {
	MagicRingEffect::MagicRingEffect():
		m_Magicring_count(0),
		m_Is_flag(false)
	{

	}
	void MagicRingEffect::start() {
		m_Is_flag = true;
		m_Magicring_count = 0;
	}
	void MagicRingEffect::draw(double x, double y, double crush_x, double crush_y) {
		if (!m_Is_flag)return;
		lib::Graphics2D::drawRota(
			x + AREA::FMIN_X + crush_x,
			y + AREA::FMIN_Y + crush_x,
			1,
			m_Magicring_count * 0.024,
			res::BossUIImage::boss_ui.magic_ring,
			true
		);
	}
	void MagicRingEffect::update() {
		if (!m_Is_flag)return;
		m_Magicring_count++;
	}
	void MagicRingEffect::stop() {
		m_Is_flag = false;
	}
}