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
		sprintf(life_text, "�c�@�F%d", life);
		char bom_text[128];
		sprintf(bom_text, "�{���F%d", bom);
		char power_text[128];
		sprintf(power_text, "�U���́F%d", pow);
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
			"�y������ʁz",
			lib::StringDX::color(255, 255, 255),
			res::TextUIImage::text_ui.font[res::FONT::FONT_MINI_LORE]
		);
		char text[128];
		if (special_type == 0)sprintf(text, "�X�e�[�W�̍ŏ���Power���ő�l�ɂȂ�B");
		if (special_type == 1)sprintf(text, "�X�e�[�W�̍ŏ��Ƀ����S��2���炦��B");
		if (special_type == 2)sprintf(text, "�{���g�p����25%%�̊m����1�l���ł���B");
		if (special_type == 3)sprintf(text, "���������Ă��uLost Bullet�v���Ȃ��B");
		if (special_type == 4)sprintf(text, "���[���b�g�ŏo��A�C�e����+2����B");
		lib::StringDX::draw(
			m_Pos_x+30, m_Pos_y + 40 * 4,
			text,
			lib::StringDX::color(255, 255, 255),
			res::TextUIImage::text_ui.font[res::FONT::FONT_MINI_LORE]
		);
	}
}