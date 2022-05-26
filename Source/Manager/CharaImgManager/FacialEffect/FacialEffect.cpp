#include "FacialEffect.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/Resource/FacialEffectImage/FacialEffectImage.h"
#include "../../Source/Helper/Helper.h"
using namespace res;

namespace app {
	void FacialEffect::spawn(int type, float x, float y) {
		if (m_Is_flag && m_Type == type)return;
		reset();
		m_Is_flag = true;
		m_Pos_x = x;
		m_Pos_y = -y;
		m_Type = type;
	}
	void FacialEffect::update() {
		if (!m_Is_flag)return;
		if (m_Type == FACIAL_EFFECT_TYPE::ACCENT)accent();
		if (m_Type == FACIAL_EFFECT_TYPE::HAPPY)happy();
		if (m_Type == FACIAL_EFFECT_TYPE::SWEAT)sweat();
		if (m_Type == FACIAL_EFFECT_TYPE::BLACK)black();
		if (m_Type == FACIAL_EFFECT_TYPE::ANGRY)angry();
		if (m_Type == FACIAL_EFFECT_TYPE::STOP)m_Is_flag = false;
		m_Count++;
	}
	void FacialEffect::draw(float x, float y) {
		if (!m_Is_flag)return;
		lib::Graphics2D::drawRota(
			x + m_Pos_x, y + m_Pos_y, m_Size, 0.f,
			m_Handle,
			true
		);
	}
	void FacialEffect::accent() {
		if (m_Count % 25 == 0) {
			m_Img_type = (m_Img_type + 1) % 2;
			m_Handle = FacialEffectImage::facial_eff.accent[m_Img_type];
		}
	}
	void FacialEffect::happy() {
		if (m_Count % 25 == 0) {
			m_Img_type = (m_Img_type + 1) % 2;
			m_Handle = FacialEffectImage::facial_eff.happy[m_Img_type];
		}
	}
	void FacialEffect::sweat() {
		if (m_Handle == -1) {
			m_Handle = FacialEffectImage::facial_eff.sweat;
			m_Pos_y -= 50;
		}
		int second = 25;
		if (m_Count < second)m_Pos_y += 50 / second;
	}
	void FacialEffect::black() {
		if (m_Handle == -1) {
			m_Handle = FacialEffectImage::facial_eff.black;
			m_Pos_y -= 50;
		}
		int second = 25;
		if (m_Count < second)m_Pos_y += 50 / second;
	}
	void FacialEffect::angry() {
		if (m_Handle == -1)m_Handle = FacialEffectImage::facial_eff.angry;
		if (BEDWEEN(m_Count, 0, 5))m_Size+=0.2;
		if (BEDWEEN(m_Count, 15, 20))m_Size-= 0.2;
	}
	void FacialEffect::reset() {
		m_Is_flag = false;
		m_Handle = -1;
		m_Count = 0;
		m_Type = 0;
		m_Img_type = 0;
		m_Size = 1.f;
	}
}