#include "SubTitle.h"
#include <string>
#include "../../Source/SystemProp/AreaProp.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/library/Graphics/String/StringDX.h"
#include "../../Source/Resource/GUI/GameUIImage/GameUIImage.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"
namespace app {
	void SubTitle::start(int stage) {
		m_Is_flag = true;
		m_Stage_num = stage;
		m_Count = 0;
		m_bright = 0;
	}
	void SubTitle::titleText() {
		if (m_Stage_num == 0) {
			drawText(
				0, "気喰るう救済は快楽と共に夢狂う",
				0, "虚界の千本桜街道353号"
			);
		}
		if (m_Stage_num == 1) {
			drawText(
				0, "トゥインクル・ゼロ",
				0, "時計塔前通り"
			);
		}
		if (m_Stage_num == 2) {
			drawText(
				0, "不思議な虚界",
				0, "シュピゲルビューネ"
			);
		}
		if (m_Stage_num == 3) {
			drawText(
				0, "愛しくも今は此処におらず",
				0, "廃城ラボラトリ"
			);
		}
		if (m_Stage_num == 4) {
			drawText(
				0, "ほら、世界はこんなに紅い",
				0, "廃城ラボラトリ最果て"
			);
		}
		if (m_Stage_num == 5) {
			drawText(
				0, "何度目の『はじめまして』",
				0, "見覚えのある森"
			);
		}
		if (m_Stage_num == 6) {
			drawText(
				0, "グリモア・オブ・エキシビジョン",
				0, "城内"
			);
		}
		if (m_Stage_num == 7) {
			drawText(
				0, "奈落を砕いて空に散る",
				0, "底無しの天空島"
			);
		}
	}
	void SubTitle::draw() {
		if (!m_Is_flag)return;
		lib::Graphics2D::setBlend(lib::BLEND_MODE::ALPHA, m_bright);
		lib::Graphics2D::draw(
			0, 0,
			res::GameUIImage::game_ui.sub_title,
			true
		);
		titleText();
		lib::Graphics2D::setBlend(lib::BLEND_MODE::NONE, 0);
	}
	void SubTitle::update() {
		if (!m_Is_flag)return;
		const int grow_time = 90;
		//最初の128の間段々明るく
		if (m_Count < grow_time)m_bright += 3;
		//段々暗く
		if (m_Count > grow_time * 2)m_bright -= 3;
		//値補正
		if (m_bright > 255)m_bright = 255;
		if (m_bright < 0)m_bright = 0;
		//終り
		if (m_Count > grow_time * 3) {
			m_Count = 0;
			m_bright = 0;
			m_Is_flag = false;
			return;
		}
		m_Count++;
	}
	void SubTitle::drawText(int x1, const char* title, int x2, const char* stage_name) {
		std::string title_text = title;
		std::string stage_text = stage_name;
		auto font1 = res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT];
		auto font2 = res::TextUIImage::text_ui.font[res::FONT::FONT_TITLE_NEWS];
		float title_x = AreaProp::min_x + (AreaProp::max_x - AreaProp::min_x) / 2 - lib::StringDX::getFontTextWidth(title_text.data(), title_text.length(), font1) / 2;
		float stage_x = AreaProp::max_x - 50 - lib::StringDX::getFontTextWidth(stage_text.data(), stage_text.length(), font2);
		lib::StringDX::draw(title_x + x1, 680, title, lib::StringDX::color(255, 200, 250), font1);
		lib::StringDX::draw(stage_x - x2, 780, stage_name, lib::StringDX::color(255, 255, 255), font2);
	}
	SubTitle::SubTitle() :
		m_Is_flag(false),
		m_Stage_num(0),
		m_bright(0),
		m_Count(0)
	{
	}
	SubTitle::~SubTitle() {

	}
}