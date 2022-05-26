#include"GhostItem.h"

#include <iostream>
#include "../../Source/SystemProp/AreaProp.h"
#include "../../Source/SystemProp/AliceProp/AliceProp.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/Resource/ItemImage/ItemImage.h"

namespace obj {
	void GhostItem::draw(double crush_x, double crush_y) {
		if (isFlag()) {
			m_Angle = 0;
			int type = getType();
			int size = 1;
			if (AliceProp::flag)size = 1 + AliceProp::add_size;
			lib::Graphics2D::drawRota(
				getX() + m_Field.m_Min_x + crush_x,
				getY() + FMIN_Y + crush_y,
				size,
				m_Angle,
				res::ItemImage::item.ghost[type],
				true
			);
		}
	}
	void GhostItem::update(bool is_graze, double x, double y) {
		if (isFlag()) {
			if(is_graze)absorb(x, y);
			setFieldArea();
			countUpdate();
			if (getY() > AREA::FMAX_Y)valueReset();
		}
	}
	void GhostItem::absorb(double x, double y) {
		float speed = 5.0f;
		float m_Angle = atan2(y - getY(), x - getX());//Ž©‹@‚Ö‚ÌŠp“x‚ðŒvŽZ‚µ‚Ä
		setX(getX() + cos(m_Angle) * speed);
		setY(getY() + sin(m_Angle) * speed);
	}
	void GhostItem::setFieldArea() {
		if (getRayer() == 0) {
			m_Field.m_Min_x = AREA::FMIN_X;
			m_Field.m_Max_x = AREA::FMAX_X;
		}
		if (getRayer() == 1) {
			m_Field.m_Min_x = AREA::P1_MIN_X;
			m_Field.m_Max_x = AREA::P1_MAX_X;
		}
		if (getRayer() == 2) {
			m_Field.m_Min_x = AREA::P2_MIN_X;
			m_Field.m_Max_x = AREA::P2_MAX_X;
		}
	}
	void GhostItem::clear() {
		valueReset();
	}
}