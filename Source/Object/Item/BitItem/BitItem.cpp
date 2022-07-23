#include "BitItem.h"
#include <iostream>
#include "../../Source/SystemProp/AreaProp.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/Resource/ItemImage/ItemImage.h"
namespace obj {
	void BitItem::draw(double crush_x, double crush_y) {
		if (isFlag()) {
			if (getCount() < 40)m_Angle = getCount();
			else m_Angle = 0;
			int type = getType();
			if (getType() == res::ITEM_TYPE::START_ROULETTE) {
				type = res::ITEM_TYPE::SCORE_DUST;
			}
			lib::Graphics2D::drawRota(
				getX() + m_Field.m_Min_x + crush_x,
				getY() + AreaProp::min_y + crush_y,
				1,
				m_Angle,
				res::ItemImage::item.bit[type],
				true
			);
		}
	}
	void BitItem::update(bool isAbsorb, double x, double y) {
		if (isFlag()) {
			if (isAbsorb) {
				setState(1);
				absorb(x, y);
			}
			else {
				setState(0);
				if (m_Speed < 3)m_Speed += 0.12;
				if (getType() == res::ITEM_TYPE::APPLE ||
					getType() == res::ITEM_TYPE::GOLDEN_APPLE)m_Speed = 0;
				setY(getY() + m_Speed * 2);
			}
			if (getType() == res::ITEM_TYPE::START_ROULETTE) {
				setState(1);
				absorb(x, y);
			}
			setFieldArea();
			countUpdate();
			if (getY() > AreaProp::max_y)valueReset();
		}
	}
	void BitItem::setFieldArea() {
		if (getRayer() == 0) {
			m_Field.m_Min_x = AreaProp::min_x;
			m_Field.m_Max_x = AreaProp::max_x;
		}
		if (getRayer() == 1) {
			m_Field.m_Min_x = AreaProp::p1_min_x;
			m_Field.m_Max_x = AreaProp::p1_max_x;
		}
		if (getRayer() == 2) {
			m_Field.m_Min_x = AreaProp::p2_min_x;
			m_Field.m_Max_x = AreaProp::p2_max_x;
		}
	}
	void BitItem::absorb(double x, double y) {
		float v = getState() ? 32 : 20;//state1ならスピード8、違うなら2
		float m_Angle = atan2(y - getY(), x - getX());//自機への角度を計算して
		setX(getX() + cos(m_Angle) * v);
		setY(getY() + sin(m_Angle) * v);
	}
	void BitItem::clear() {
		m_Speed = 0;
		valueReset();
	}
	void BitItem::setSpeed(float num) {
		m_Speed = num;
	}
}