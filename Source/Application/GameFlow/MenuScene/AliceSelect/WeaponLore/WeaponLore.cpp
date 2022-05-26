#include "WeaponLore.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/library/Graphics/String/StringDX.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"
#include "../../Source/Resource/GUI/MenuUIImage/MenuUIImage.h"
#pragma warning(disable : 4996)
namespace app {
	WeaponLore::WeaponLore(float x, float y) {
		m_Pos_x = x;
		m_Pos_y = y;
	}
	void WeaponLore::draw(int life, int bom, int pow, int special_type) {
		char life_text[128];
		sprintf(life_text, "残機：%d", life);
		char bom_text[128];
		sprintf(bom_text, "ボム：%d", bom);
		char power_text[128];
		sprintf(power_text, "攻撃力：%d", pow);
		lib::StringDX::draw(
			m_Pos_x, m_Pos_y,
			life_text,
			lib::StringDX::color(255, 255, 255),
			res::TextUIImage::text_ui.font[res::FONT::FONT_MINI_LORE]
		);
		lib::StringDX::draw(
			m_Pos_x, m_Pos_y + 40,
			bom_text,
			lib::StringDX::color(255, 255, 255),
			res::TextUIImage::text_ui.font[res::FONT::FONT_MINI_LORE]
		);
		lib::StringDX::draw(
			m_Pos_x, m_Pos_y + 40 * 2,
			power_text,
			lib::StringDX::color(255, 255, 255),
			res::TextUIImage::text_ui.font[res::FONT::FONT_MINI_LORE]
		);
		drawSPLore(special_type);
	}
	void WeaponLore::drawSPLore(int special_type) {
		lib::StringDX::draw(
			m_Pos_x, m_Pos_y + 40 * 3,
			"【特殊効果】",
			lib::StringDX::color(255, 255, 255),
			res::TextUIImage::text_ui.font[res::FONT::FONT_MINI_LORE]
		);
		char text[128];
		if (special_type == 0)sprintf(text, "ステージの最初にPowerが最大値になる。");
		if (special_type == 1)sprintf(text, "ステージの最初にリンゴを2個もらえる。");
		if (special_type == 2)sprintf(text, "ボム使用時に25%%の確立で1個獲得できる。");
		if (special_type == 3)sprintf(text, "何があっても「Lost Bullet」しない。");
		if (special_type == 4)sprintf(text, "ルーレットで出るアイテムを+2する。");
		lib::StringDX::draw(
			m_Pos_x+30, m_Pos_y + 40 * 4,
			text,
			lib::StringDX::color(255, 255, 255),
			res::TextUIImage::text_ui.font[res::FONT::FONT_MINI_LORE]
		);
	}
}