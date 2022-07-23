#include "BossUI.h"
#include "../../Source/SystemProp/AreaProp.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/library/Graphics/String/StringDX.h"
#include "../../Source/Object/Object/Parameter/FadeIn/FadeIn.h"
#include "../../Source/Resource/GUI/BossUIImage/BossUIImage.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"
namespace obj {
	BossUI::BossUI() :
		m_Is_serif(false),
		m_Serif_time(0),
		m_Serif_count(0)
	{
	}
	void BossUI::update() {
		if (m_Is_serif) {
			if (m_Serif_time <= m_Serif_count) m_Is_serif = false;
			m_Serif_count++;
		}
	}
	void BossUI::drawCounter(int time, int bullet_num, int bullet_type) {
		int Timer = time / 60, time_Max = 99;
		if (Timer <= 9)lib::Graphics2D::setBright(255, 155, 155);
		else lib::Graphics2D::setBright(255, 255, 255);
		lib::Graphics2D::drawMode(lib::DRAW_MODE::BILINEAR);
		//制限時間の表示
		if (Timer < 0 || Timer > 99) {//カンストとした制限時間を99で固定
			for (int i = 0; i < 2; i++) {
				lib::Graphics2D::setBright(255, 255, 255);
				lib::Graphics2D::drawRota(
					(1200 - 36 * i) + 300,
					AreaProp::min_y + 50,
					1.0f,
					0.0f,
					res::TextUIImage::text_ui.number[0][time_Max % 10],
					true
				);
				time_Max /= 10;
			}
		}
		else {
			for (int i = 0; i < 2; i++) {
				lib::Graphics2D::drawRota(
					AreaProp::max_x - 50 - (36 * i),
					AreaProp::min_y + 50,
					1.0f,
					0.0f,
					res::TextUIImage::text_ui.number[0][Timer % 10],
					true
				);
				Timer /= 10;
			}
		}
		int last_bullet = bullet_num - bullet_type;
		for (int i = 0; i < last_bullet; i++) {
			lib::Graphics2D::drawRota(
				AreaProp::min_x + 30 + i * 50,
				AreaProp::min_y + 50,
				1.0f,
				0.0f,
				res::BossUIImage::boss_ui.bullet_num,
				true
			);
		}
		lib::Graphics2D::drawMode(lib::DRAW_MODE::NEAREST);
		lib::Graphics2D::setBright(255, 255, 255);
	}
	void BossUI::drawSerifBox() {
		if (!m_Is_serif)return;
		lib::Graphics2D::drawRota(
			m_Serif_x + AreaProp::min_x,
			m_Serif_y + AreaProp::min_y,
			1.f,
			0.f,
			res::BossUIImage::boss_ui.serif_box,
			true
		);
		auto font = res::TextUIImage::text_ui.font[res::FONT::FONT_SERIF_BULLET];
		lib::StringDX::draw(
			m_Serif_x + AreaProp::min_x - (lib::StringDX::getFontTextWidth(m_Serif_text.data(), m_Serif_text.length(), font) / 2),
			m_Serif_y + AreaProp::min_y - 5,
			m_Serif_text.data(),
			lib::StringDX::color(255, 255, 255),
			font
		);
	}
	void BossUI::setSerifBox(int time, float x, float y, std::string text) {
		m_Is_serif = true;
		m_Serif_time = time;
		m_Serif_count = 0;
		m_Serif_x = x;
		m_Serif_y = y;
		m_Serif_text = text;
	}
}