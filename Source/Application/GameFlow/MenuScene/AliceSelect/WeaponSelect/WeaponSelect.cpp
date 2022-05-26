#include "WeaponSelect.h"
#include "../WeaponLore/WeaponLore.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/library/Graphics/String/StringDX.h"
#include "../../Source/Application/Key/Key.h"
#include "../../Source/Application/Sound/Sound.h"
#include "../../Source/Resource/SoundData/SoundData.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"
#include "../../Source/Resource/GUI/MenuUIImage/MenuUIImage.h"
#include "../../Source/CustomWeapon/CustomWeapon.h"
#include "../../Source/Resource/SaveData/SaveData.h"
#pragma warning(disable : 4996)
namespace app {
	void WeaponSelect::initialize() {
		m_Is_select = false;
		for (int ite = 0; ite < 100; ite++)CustomWeapon::createName(ite);
	}
	void WeaponSelect::initialize(int id) {
		m_Last_id = id;
		m_Weapon_id = id;
		m_Is_select = false;
		m_Scene_type = WP_SELECT;
	}
	void WeaponSelect::draw() {
		lib::Graphics2D::setBlend(lib::BLEND_MODE::ALPHA, 50);
		int color = lib::StringDX::color(0, 0, 0);
		lib::Graphics2D::box(0, 0, 1920, 1440, color, true);
		lib::Graphics2D::setBlend(lib::BLEND_MODE::NONE, 0);
		lib::Graphics2D::drawRota(480 * 2, 360 * 2, 1.0, 0.0, res::MenuUIImage::menu_ui.alice_select[2], true);
		for (int ite = 0; ite < 100; ite++) {
			if (m_Weapon_id == ite)color = lib::StringDX::color(255, 200, 200);
			else color = lib::StringDX::color(155, 155, 155);
			lib::StringDX::draw(
				200,
				800 + ((ite - m_Weapon_id) * 80),
				CustomWeapon::getName(ite).data(),
				color,
				res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]
			);
		}
		lib::Graphics2D::drawRota(480 * 2, 360 * 2, 1.0, 0.0, res::MenuUIImage::menu_ui.alice_select[3], true);
		WeaponLore lore(450, 900);
		auto weapon = res::SaveData::save_data.weapon[m_Weapon_id];
		lore.draw(weapon.life, weapon.bom, weapon.strength, weapon.ex_type);
		if (m_Scene_type == DEL_SELECT) {
			m_Select_YN.draw("‘•”õ‚ðíœ‚·‚é‚Ì?", lib::StringDX::color(255, 5, 5), "‚¢‚¢‚¦", "‚Í‚¢");
		}
	}
	int WeaponSelect::update() {
		if (sceneCoolDown(10)) {
			if (m_Scene_type == WP_SELECT) {
				up(100);
				down(100);
				m_Weapon_id = getHorizontal();
				select();
				cancel();
			}
			if (m_Scene_type == DEL_SELECT) {
				if (m_Select_YN.isFlag())m_Select_YN.update();
				else {
					if (m_Select_YN.getState()== SELECT_LR::RIGHT_STATE) {
						CustomWeapon::dispose(m_Weapon_id);
						for (int ite = 0; ite < 100; ite++)CustomWeapon::createName(ite);
					}
					m_Scene_type = WP_SELECT;
				}
			}
		}
		return 0;
	}
	void WeaponSelect::select() {
		if (Key::Pad.checkInput(Key::KEY_TYPE::SHOT) == 1) {
			Sound::sound.playSE(res::SE::SELECT_OK);
			resetCoolDown();
			m_Is_select = true;
		}
	}
	void WeaponSelect::cancel() {
		if (Key::Pad.checkInput(Key::KEY_TYPE::BOM) == 1 || Key::Pad.checkInput(Key::KEY_TYPE::MENU) == 1) {
			Sound::sound.playSE(res::SE::SELECT_CANCEL);
			m_Scene_type = DEL_SELECT;
			m_Select_YN.initialize(SELECT_LR::LEFT_STATE);
		}
	}
	int WeaponSelect::getID() {
		return m_Weapon_id;
	}
	bool WeaponSelect::isSelect() {
		return m_Is_select;
	}
}