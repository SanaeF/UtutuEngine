#include "DressRoom.h"
#include "ClothText/ClothText.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/library/Graphics/String/StringDX.h"
#include "../../Source/Resource/GUI/MenuUIImage/MenuUIImage.h"
#include "../../Source/Resource/GUI/SelectUIImage/SelectUIImage.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"
#include "../../Source/Resource/SaveData/SaveData.h"
#include "../../Source/Resource/SoundData/SoundData.h"
#include "../../Source/Resource/PlayerImage/PlayerImage.h"

#include "../../Source/Application/Key/Key.h"
#include "../../Source/Application/Sound/Sound.h"
#include "../../Source/SystemProp/SceneProp.h"
#include "../../Source/Resource/LoadManager.h"
#include "../../Source/Manager/CharaImgManager/CharaImgManager.h"
#include "../../Source/Resource/FacialEffectImage/FacialEffectImage.h"
#include "../../Source/Manager/SaveDataManager/SaveDataManager.h"
namespace app {
	DressRoom::DressRoom() {
		m_Img.reset(new CharaImgManager());
	}
	DressRoom::~DressRoom() {

	}
	void DressRoom::draw() {
		lib::Graphics2D::drawRota(480 * 2, 360 * 2, 1.0, 0.0, res::MenuUIImage::menu_ui.title.back, true);
		if (m_Count < 250)lib::Graphics2D::setBlend(lib::BLEND_MODE::ALPHA, m_Count);
		lib::Graphics2D::drawRota(480 * 2, 360 * 2, 1.0, 0.0, res::MenuUIImage::menu_ui.dress_room, true);
		if (m_Count >= 250) {
			m_Img->draw();
		}
		text::ClothText::drawText(m_Chara_type, m_Select_num[m_Chara_type][0], m_Select_num[m_Chara_type][1]);
		outerText();
		underText();
		selectText();
		MenuText diffGUI[5] = {//280 420
			{ 0, 0, "綾乃" },
			{ 0, 0, "みさと" },
			{ 0, 0, "赤城" },
			{ 0, 0, "媛" },
			{ 0, 0, "庵子" }
		};
		int add_col = 0;
		if (getHorizontal() == 0)add_col = 100;
		lib::StringDX::draw(
			1300,
			70,
			diffGUI[m_Chara_type].name,
			lib::StringDX::color(155 + add_col, 155 + add_col, 155 + add_col),
			res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]
		);
		lib::Graphics2D::setBlend(lib::BLEND_MODE::NONE, 0);
	}
	int DressRoom::update() {
		if (sceneCoolDown(10)) {
			if (m_Count < 250) {
				m_Count += 10;
				return getSceneState();
			}
			else m_Count = 255;
			up(4);
			down(4);
			if (getHorizontal() == 0) {
				if (isRight())m_Chara_type = (m_Chara_type + 1) % 5;
				if (isLeft())m_Chara_type = (m_Chara_type + 4) % 5;
			}
			int num = getHorizontal() - 1;
			if ((getHorizontal() == 1 || getHorizontal() == 2)) {
				if (isRight())m_Select_num[m_Chara_type][num] = (m_Select_num[m_Chara_type][num] + 1) % 6;
				if (isLeft())m_Select_num[m_Chara_type][num] = (m_Select_num[m_Chara_type][num] + 5) % 6;
			}
			if (getHorizontal() == 3)select();
			cancel();
			m_Img->setEyeState(EYE_STATE::BLINK);
			m_Img->setMouthState(MOUTH_STATE::MOUTH_CLOSE);
			m_Img->summon(m_Chara_type, 500, 800, 1.f, 0.f);
			int outer_wear_type = m_Select_num[m_Chara_type][0];
			if (!res::SaveData::save_data.chara_custom[m_Chara_type].unlocked_outer_wear[outer_wear_type])outer_wear_type = 6;
			m_Img->setOuterType(outer_wear_type);
			int under_wear_type = m_Select_num[m_Chara_type][1];
			if (!res::SaveData::save_data.chara_custom[m_Chara_type].unlocked_under_wear[under_wear_type])under_wear_type = 6;
			m_Img->setUnderType(under_wear_type);
			m_Img->update();
			if (getHorizontal() == 3) {
				if (strcmp(m_Check_unlocked[0], m_Locked_name) == 0 || 
					strcmp(m_Check_unlocked[1], m_Locked_name) == 0
					)setHorizontal(0);
			}
		}
		else {
			initialize();
		}
		return getSceneState();
	}
	void DressRoom::outerText() {
		float add_col = 0.f;
		if (getHorizontal() == 1)add_col = 155.f;
		m_Check_unlocked[0] = m_Outer_wear_name[m_Select_num[m_Chara_type][0]][m_Chara_type].name;
		if (!res::SaveData::save_data.chara_custom[m_Chara_type].unlocked_outer_wear[m_Select_num[m_Chara_type][0]])
			m_Check_unlocked[0] = m_Locked_name;
		lib::StringDX::draw(
			1000,
			300,
			m_Check_unlocked[0],
			lib::StringDX::color(100 + add_col, 100 + add_col, 100 + add_col),
			res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]
		);
	}
	void DressRoom::underText() {
		float add_col = 0.f;
		if (getHorizontal() == 2)add_col = 155.f;
		m_Check_unlocked[1] = m_Under_wear_name[m_Select_num[m_Chara_type][1]].name;
		if (!res::SaveData::save_data.chara_custom[m_Chara_type].unlocked_under_wear[m_Select_num[m_Chara_type][1]])
			m_Check_unlocked[1] = m_Locked_name;
		lib::StringDX::draw(
			1000,
			800,
			m_Check_unlocked[1],
			lib::StringDX::color(100 + add_col, 100 + add_col, 100 + add_col),
			res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]
		);
	}
	void DressRoom::selectText() {
		float add_col = 0.f;
		if (getHorizontal() == 3)add_col = 155.f;
		lib::StringDX::draw(
			1120,
			1305,
			"これで行く(決定)",
			lib::StringDX::color(100 + add_col, 100 + add_col, 100 + add_col),
			res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]
		);
	}
	void DressRoom::select() {
		if (Key::Pad.checkInput(Key::KEY_TYPE::SHOT) == 1) {
			Sound::sound.playSE(res::SE::SELECT_OK);
			res::SaveData::save_data.chara_custom[m_Chara_type].outer_wear_type = m_Select_num[m_Chara_type][0];
			res::SaveData::save_data.chara_custom[m_Chara_type].under_wear_type = m_Select_num[m_Chara_type][1];
			checkAndReset();
			SaveDataManager save;
			save.out_game();
			resetCoolDown();
			setSceneState(SCENE_TYPE::TITLE);
		}
	}
	void DressRoom::cancel() {
		if (Key::Pad.checkInput(Key::KEY_TYPE::BOM) == 1 || Key::Pad.checkInput(Key::KEY_TYPE::MENU) == 1) {
			Sound::sound.playSE(res::SE::SELECT_CANCEL);
			checkAndReset();
			resetCoolDown();
			setSceneState(SCENE_TYPE::TITLE);
		}
	}
	void DressRoom::initialize() {
		for (int ite = 0; ite < 5; ite++) {
			if (res::SaveData::save_data.chara_custom[ite].outer_wear_type == 6)res::SaveData::save_data.chara_custom[ite].outer_wear_type = 0;
			if (res::SaveData::save_data.chara_custom[ite].under_wear_type == 6)res::SaveData::save_data.chara_custom[ite].under_wear_type = 0;
			m_Select_num[ite][0] = res::SaveData::save_data.chara_custom[ite].outer_wear_type;
			m_Select_num[ite][1] = res::SaveData::save_data.chara_custom[ite].under_wear_type;
		}
		res::LoadManager& load = res::LoadManager::get_instance();
		load.loadCharaObjImg();
		setSceneState(SCENE_TYPE::DRESS_UP);
		setHorizontal(0);
		m_Count = 0;
		for (int ite = 0; ite < 5; ite++) {
			res::SaveData::save_data.chara_custom[ite].unlocked_outer_wear[0] = true;
			res::SaveData::save_data.chara_custom[ite].unlocked_under_wear[0] = true;
		}
	}
	void DressRoom::unlock() {
		for (int ite = 0; ite < 5; ite++) {
			for (int ite2 = 0; ite2 < 6; ite2++) {
				res::SaveData::save_data.chara_custom[ite].unlocked_outer_wear[ite2] = true;
				res::SaveData::save_data.chara_custom[ite].unlocked_under_wear[ite2] = true;
			}
		}
	}
	void DressRoom::checkAndReset() {
		auto& outer = res::SaveData::save_data.chara_custom;
		for (int ite = 0; ite < 5; ite++) {
			//服(うえ)で、未所持の場合リセット
			if (res::SaveData::save_data.chara_custom[ite].outer_wear_type==6) {
				res::SaveData::save_data.chara_custom[ite].outer_wear_type = 0;
				m_Select_num[ite][0] = 0;
			}
			//服(下)で、未所持の場合リセット
			if (res::SaveData::save_data.chara_custom[ite].under_wear_type == 6) {
				res::SaveData::save_data.chara_custom[ite].under_wear_type = 0;
				m_Select_num[ite][1] = 0;
			}
			//実装されていない衣装の場合、リセットする
			if ((ite == 1 && (m_Select_num[ite][0] == 2 || m_Select_num[ite][0] == 4 || m_Select_num[ite][0] == 5)) ||
				(ite == 2 && (m_Select_num[ite][0] == 1 || m_Select_num[ite][0] == 2 || m_Select_num[ite][0] == 5)) ||
				(ite == 3 && (m_Select_num[ite][0] == 1 || m_Select_num[ite][0] == 4 || m_Select_num[ite][0] == 5)) ||
				(ite == 4 && (m_Select_num[ite][0] == 1 || m_Select_num[ite][0] == 2 || m_Select_num[ite][0] == 4))
				) {
				outer[ite].outer_wear_type = 0;
				m_Select_num[ite][0] = 0;
			}
		}
	}
	int DressRoom::getCharaType() {
		int result = 0;
		/*if (m_Select_num == 0)result = res::PLAYER_TYPE::AYANO;
		if (m_Select_num == 1)result = res::PLAYER_TYPE::AKAGI;
		if (m_Select_num == 2)result = res::PLAYER_TYPE::HIME;
		if (m_Select_num == 3)result = res::PLAYER_TYPE::MISATO;
		if (m_Select_num == 4)result = res::PLAYER_TYPE::IORIKO;*/
		return result;
	}
}