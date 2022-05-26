#include "CharaSelect.h"
#include "CharaProfile/CharaProfile.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/library/Graphics/String/StringDX.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"
#include "../../Source/Resource/GUI/MenuUIImage/MenuUIImage.h"
#include "../../Source/Resource/GUI/SelectUIImage/SelectUIImage.h"
#include "../../Source/Resource/SoundData/SoundData.h"
#include "../../Source/Resource/PlayerImage/PlayerImage.h"
#include "../../Source/Resource/SaveData/SaveData.h"
#include "../../Source/Application/Key/Key.h"
#include "../../Source/Application/Sound/Sound.h"
#include "../../Source/SystemProp/SceneProp.h"
#include "../../Source/SystemProp/GameSceneProp/GameSceneProp.h"
#include "../../Source/CustomWeapon/CustomWeapon.h"
namespace app {
	CharaSelect::CharaSelect() :
		m_State(STATE::DEF),
		m_Select_num(0),
		m_Camp_select(0),
		m_Change_type(CHANGE_TYPE::NONE),
		m_Add_x(0) 
	{
		m_Profile.reset(new CharaProfile());
	}
	void CharaSelect::draw() {
		lib::Graphics2D::drawRota(480 * 2, 360 * 2, 1.0, 0.0, res::MenuUIImage::menu_ui.title.back, true);
		m_Profile->draw();
		//lib::Graphics2D::drawRota(standard_x + m_Add_x, 360 * 2, 1.0, 0.0, res::SelectUIImage::select_ui.chara[1], true);
		//lib::Graphics2D::drawRota(standard_x + m_Add_x, 360 * 2, 1.0, 0.0, res::SelectUIImage::select_ui.frame[m_Select_num], true);
		if (m_State == STATE::CAMP) {
			m_Select_YN.draw("途中データから始めますか?", lib::StringDX::color(255, 255, 255), "いいえ", "はい");
		}
	}
	int CharaSelect::update() {
		if (sceneCoolDown(10)) {
			if (m_Change_type == CHANGE_TYPE::NONE) {
				//選択肢の更新
				if (!m_Fade_in.isFlag() && !m_Fade_back.isFlag() && !m_Fade_out.isFlag()) {
					if (m_State == STATE::DEF) {
						right(5);
						left(5);
						//up(2);
						//down(2);
						m_Select_num = getVertical();
						//if (getHorizontal() == 1)m_Select_num += 3;
						//m_Select_num = m_Select_num % 6;
						select();
						cancel();
					}
					if (m_State == STATE::CAMP) {
						if (m_Select_YN.isFlag())m_Select_YN.update();
						else {
							if (m_Select_YN.getState() == SELECT_LR::NONE_STATE) {
								m_State = STATE::DEF;
								GameSceneProp::is_use_camp = false;
							}
							else {
								if (m_Select_YN.getState() == SELECT_LR::RIGHT_STATE) {
									GameSceneProp::is_use_camp = true;
								}
								if (m_Select_YN.getState() == SELECT_LR::LEFT_STATE) {
									GameSceneProp::is_use_camp = false;
								}
								m_State = STATE::GAME;
							}
						}
					}
					if (m_State == STATE::GAME) {
						int id = GameSceneProp::difficulty;
						if (GameSceneProp::is_alice)id = 3;
						if (!GameSceneProp::is_use_camp)res::SaveData::save_data.clear.camp_data[id].initialize();
						m_Change_type = CHANGE_TYPE::SELECT;
						m_Fade_out.start(10, 1920);
					}
				}
			}
			else sceneChanger();
		}
		else {
			m_State = STATE::DEF;
			GameSceneProp::is_use_camp = false;
			if (!GameSceneProp::is_extra && !GameSceneProp::is_practice)GameSceneProp::stage = FIRST_STAGE;
			if (GameSceneProp::is_extra)GameSceneProp::stage = EX_STAGE;
			setSceneState(SCENE_TYPE::SELECT_CHARA);
			m_Select_YN.initialize(SELECT_LR::RIGHT_STATE);
			if (!m_Fade_in.isFlag())m_Add_x = 0;//UIを画面外へ移動
			m_Fade_in.start(10, 1920);//UIのフェードインを開始
		}
		//フェーダークラスによる値の代入
		if (m_Fade_in.isFlag())m_Add_x = m_Fade_in.getSize();
		if (m_Fade_back.isFlag())m_Add_x = 1920 - m_Fade_back.getSize();
		if (m_Fade_out.isFlag())m_Add_x = 1920 + m_Fade_out.getSize();
		m_Fade_in.update();
		m_Fade_back.update();
		m_Fade_out.update();
		//キャラプロフィールのクラス設定
		m_Profile->update();
		m_Profile->setType(m_Select_num);
		const int standard_x = -1920 / 2;
		m_Profile->setFadeX(standard_x + m_Add_x);
		return getSceneState();
	}
	void CharaSelect::select() {
		if (Key::Pad.checkInput(Key::KEY_TYPE::SHOT) == 1) {
			if (m_Select_num != 5) {
				Sound::sound.playSE(res::SE::SELECT_OK);
				int id = GameSceneProp::difficulty;
				if (GameSceneProp::is_alice)id = 3;
				if (m_State == STATE::DEF && res::SaveData::save_data.clear.camp_data[id].camped && !GameSceneProp::is_practice) {
					m_State = STATE::CAMP;
					m_Select_YN.initialize(SELECT_LR::RIGHT_STATE);
					return;
				}
				else {
					m_State = STATE::GAME;
				}
			}
			else {
				if (!GameSceneProp::is_alice && !GameSceneProp::is_extra) {
					Sound::sound.playSE(res::SE::SELECT_CANCEL);
					m_Change_type = CHANGE_TYPE::BACK;
					m_Fade_back.start(10, 1920);
				}
			}
			resetCoolDown();
		}
	}
	void CharaSelect::cancel() {
		if (Key::Pad.checkInput(Key::KEY_TYPE::BOM) == 1 || Key::Pad.checkInput(Key::KEY_TYPE::MENU) == 1) {
			Sound::sound.playSE(res::SE::SELECT_CANCEL);
			if (m_State == STATE::CAMP) {
				m_State = STATE::DEF;
				return;
			}
			m_Change_type = CHANGE_TYPE::BACK;
			m_Fade_back.start(10, 1920);
		}
	}
	void CharaSelect::sceneChanger() {
		if (m_Fade_back.isFlag() || m_Fade_out.isFlag())return;
		if (m_Change_type == CHANGE_TYPE::BACK) {
			if (!GameSceneProp::is_alice)setSceneState(SCENE_TYPE::DIFFICULTY_SELECT);
			if (GameSceneProp::is_alice)setSceneState(SCENE_TYPE::ALICE_MODE);
			if (GameSceneProp::is_extra)setSceneState(SCENE_TYPE::TITLE);
		}
		if (m_Change_type == CHANGE_TYPE::SELECT) {
			setSceneState(SCENE_TYPE::GAME_MAIN);
		}
		m_Change_type = CHANGE_TYPE::NONE;
		m_Add_x = 0;
		resetCoolDown();
	}
	int CharaSelect::getCharaType() {
		int result = 0;
		if (m_Select_num == 0)result = res::PLAYER_TYPE::EREMIRA;
		if (m_Select_num == 1)result = res::PLAYER_TYPE::MEGU;
		if (m_Select_num == 2)result = res::PLAYER_TYPE::HIME;
		if (m_Select_num == 3)result = res::PLAYER_TYPE::MAI;
		if (m_Select_num == 4)result = res::PLAYER_TYPE::IORIKO;
		return result;
	}
}