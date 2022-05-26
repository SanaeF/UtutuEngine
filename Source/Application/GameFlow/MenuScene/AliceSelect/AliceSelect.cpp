#include "AliceSelect.h"
#include "WeaponLore/WeaponLore.h"
#include "../../Source/CustomWeapon/CustomWeapon.h"
#include "../../Source/SystemProp/SceneProp.h"
#include "../../Source/SystemProp/AliceProp/AliceProp.h"
#include "../../Source/SystemProp/GameSceneProp/GameSceneProp.h"
#include "../../Source/Helper/Helper.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/library/Graphics/String/StringDX.h"
#include "../../Source/Application/Key/Key.h"
#include "../../Source/Application/Sound/Sound.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"
#include "../../Source/Resource/GUI/MenuUIImage/MenuUIImage.h"
#include "../../Source/Resource/SoundData/SoundData.h"
#include "../../Source/Resource/SaveData/SaveData.h"

#pragma warning(disable : 4996)
namespace app {
	AliceSelect::AliceSelect() :
		m_Is_locked(false),
		m_Level(0),
		m_Lv_select(1),
		m_Weapon_type(0),
		m_Menu_type(0),
		m_State(0)
	{

	}
	int AliceSelect::update() {
		if (sceneCoolDown(10)) {
			if (m_State == SELECT_STATE::NONE)menuSelect();
			if (m_State == SELECT_STATE::LEVEL)levelSelect();
			if (m_State != SELECT_STATE::WEAPON) {
				select();
				cancel();
			}
			if (m_State == SELECT_STATE::WEAPON) {
				m_WeaponSelect.update();
				if (m_WeaponSelect.isSelect()) {
					m_State = SELECT_STATE::NONE;
					m_Weapon_type = m_WeaponSelect.getID();
				}
			}
		}
		else {
			m_Menu_type = 0;
			m_Weapon_type = 0;
			CustomWeapon::creaateRookie();
			m_Level = res::SaveData::save_data.clear.level;
			m_WeaponSelect.initialize();
			if (res::SaveData::save_data.clear.clear_story_num >= 3)m_Is_locked = true;
			m_State = SELECT_STATE::NONE;
			setHorizontal(0);
			setSceneState(SCENE_TYPE::ALICE_MODE);
		}
		return getSceneState();
	}
	void AliceSelect::draw() {
		lib::Graphics2D::drawRota(480 * 2, 360 * 2, 1.0, 0.0, res::MenuUIImage::menu_ui.title.back, true);
		if (!m_Is_locked) {
			lib::StringDX::draw(
				300,
				700,
				"3ñ ÇÉNÉäÉAÇ∑ÇÈÇ±Ç∆Ç≈óVÇ◊ÇÈÇÊÇ§Ç…Ç»ÇËÇ‹Ç∑ÅB",
				lib::StringDX::color(255, 255, 255),
				res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]
			);
		}
		else{
			if (m_State == SELECT_STATE::WEAPON)m_WeaponSelect.draw();
			else {
				int type = 0;
				if (m_State == SELECT_STATE::LEVEL)type = 1;
				lib::Graphics2D::drawRota(480 * 2, 360 * 2, 1.0, 0.0, res::MenuUIImage::menu_ui.alice_select[type], true);
				char level_text[128];
				sprintf(level_text, "Åyåªç›ìÀåÇâ¬î\Ç»ÉåÉxÉãÇÕ<%d.Lv>Ç≈Ç∑Åz", m_Level);
				lib::StringDX::draw(
					300,
					500,
					level_text,
					lib::StringDX::color(255, 255, 255),
					res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]
				);
				char score_text[128];
				sprintf(score_text, "ÅyëççáÉXÉRÉA:%dÅz", res::SaveData::save_data.clear.all_score);
				lib::StringDX::draw(
					300,
					350,
					score_text,
					lib::StringDX::color(255, 255, 255),
					res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]
				);
				int color;
				if (m_Menu_type == 0)color = lib::StringDX::color(255, 255, 255);
				else color = lib::StringDX::color(155, 155, 155);
				char select_param[128];
				if (m_State == SELECT_STATE::NONE) {
					sprintf(select_param, "èoåÇÇ∑ÇÈ");
				}
				if (m_State == SELECT_STATE::LEVEL) {
					sprintf(select_param, "Ç«ÇÃÉåÉxÉãÇ…èoåÇÇµÇ‹Ç∑Ç©ÅH   Åy%d.LvÅz", m_Lv_select);
				}
				lib::StringDX::draw(
					300,
					700,
					select_param,
					color,
					res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]
				);
				if (m_Menu_type == 1)color = lib::StringDX::color(255, 255, 255);
				else color = lib::StringDX::color(155, 155, 155);
				lib::StringDX::draw(
					300,
					800,
					"ëïîı:",
					color,
					res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]
				);
				lib::StringDX::draw(
					450,
					800,
					CustomWeapon::getName(m_Weapon_type).data(),
					color,
					res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]
				);
				WeaponLore lore(470, 900);
				auto weapon = res::SaveData::save_data.weapon[m_Weapon_type];
				lore.draw(weapon.life, weapon.bom, weapon.strength, weapon.ex_type);
			}
		}
	}
	void AliceSelect::menuSelect() {
		up(2);
		down(2);
		m_Menu_type = getHorizontal();
	}
	void AliceSelect::levelSelect() {
		if (m_Level > 0 && m_Is_locked) {
			up(m_Level);
			down(m_Level);
			m_Lv_select = m_Level - getHorizontal();
			if (BEDWEEN(m_Level, 1, 30))GameSceneProp::difficulty = 0;
			if (BEDWEEN(m_Level, 31, 70))GameSceneProp::difficulty = 1;
			if (m_Level > 70)GameSceneProp::difficulty = 2;
		}
	}
	void AliceSelect::select() {
		if (!m_Is_locked) {
			if(Key::Pad.checkInput(Key::KEY_TYPE::SHOT) == 1) {
				Sound::sound.playSE(res::SE::SELECT_OK);
				resetCoolDown();
				setSceneState(SCENE_TYPE::TITLE);
			}
		}
		else {
			if (Key::Pad.checkInput(Key::KEY_TYPE::SHOT) == 1) {
				Sound::sound.playSE(res::SE::SELECT_OK);
				AliceProp::weapon_type = m_Weapon_type;
				if (m_State == SELECT_STATE::NONE) {
					if (m_Menu_type == 0) {
						m_State = SELECT_STATE::LEVEL;
						setHorizontal(m_Level-m_Lv_select);
						return;
					}
					if (m_Menu_type == 1) {
						m_State = SELECT_STATE::WEAPON;
						m_WeaponSelect.initialize(m_Weapon_type);
						return;
					}
				}
				if (m_State == SELECT_STATE::LEVEL) {
					resetCoolDown();
					AliceProp::setup(m_Lv_select);
					setSceneState(SCENE_TYPE::SELECT_CHARA);
				}
			}
		}
	}
	void AliceSelect::cancel() {
		if (Key::Pad.checkInput(Key::KEY_TYPE::BOM) == 1 || Key::Pad.checkInput(Key::KEY_TYPE::MENU) == 1) {
			Sound::sound.playSE(res::SE::SELECT_CANCEL);
			if (m_State == SELECT_STATE::LEVEL) {
				m_State = SELECT_STATE::NONE;
				setHorizontal(m_Menu_type);
				return;
			}
			if (m_State == SELECT_STATE::NONE) {
				resetCoolDown();
				setSceneState(SCENE_TYPE::TITLE);
			}
		}
	}
}