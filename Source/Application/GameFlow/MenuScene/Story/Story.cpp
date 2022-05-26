#include "Story.h"
#include "../../Source/SystemProp/SceneProp.h"
#include "../../Source/SystemProp/GameSceneProp/GameSceneProp.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/Resource/GUI/SelectUIImage/SelectUIImage.h"
#include "../../Source/Resource/GUI/MenuUIImage/MenuUIImage.h"
#include "../../Source/Resource/SaveData/SaveData.h"
#include "../../Source/Resource/SoundData/SoundData.h"
#include "../../Source/Application/Key/Key.h"
#include "../../Source/Application/Sound/Sound.h"
namespace app {
	const int diffNum = 3;
	Story::Story():
		m_Change_type(CHANGE_TYPE::NONE),
		m_Leave_y(0.f)
	{
		setHorizontal(1);
	}
	void Story::draw() {
		MenuText diffGUI[diffNum] = {//280 420
			{ 1920 / 2, 300, "Eazy" },
			{ 1920 / 2, 700, "Normal" },
			{ 1920 / 2, 1100, "Hard" },
		};
		int middle_index = 1;
		lib::Graphics2D::setBright(255, 255, 255);
		lib::Graphics2D::drawRota(480 * 2, 360 * 2, 1.0, 0.0, res::MenuUIImage::menu_ui.title.back, true);
		lib::Graphics2D::drawMode(lib::DRAW_MODE::BILINEAR);
		for (int i = 0; i < diffNum; i++) {
			int index = ((diffNum - 1) * 2 - getHorizontal() + i) % diffNum;
			float new_y = diffGUI[index].y;
			if (i != getHorizontal()) {
				lib::Graphics2D::setBlend(lib::BLEND_MODE::ALPHA, 150);
				if (diffGUI[index].y < diffGUI[middle_index].y)new_y = diffGUI[middle_index].y - m_Leave_y;
				if (diffGUI[index].y > diffGUI[middle_index].y)new_y = diffGUI[middle_index].y + m_Leave_y;
			}
			lib::Graphics2D::drawRota(diffGUI[i].x - 40, new_y, 1.4, 0.0, res::SelectUIImage::select_ui.difficulty[i], true);
			if (res::SaveData::save_data.clear.difficulty[i]) {
				lib::Graphics2D::drawRota(diffGUI[i].x + 30, new_y - 5, 1.4, 0.0, res::MenuUIImage::menu_ui.icon.clearStamp, true);
			}
			lib::Graphics2D::setBlend(lib::BLEND_MODE::NONE, 0);
		}
		lib::Graphics2D::drawMode(lib::DRAW_MODE::NEAREST);
	}
	int Story::update() {
		if (sceneCoolDown(10)) {
			if (m_Change_type == CHANGE_TYPE::NONE) {
				//ëIëéàÇÃçXêV
				if (!m_Fade_leave.isFlag() && !m_Fade_approach.isFlag()) {
					up(diffNum);
					down(diffNum);
					select();
					cancel();
				}
			}
			else sceneChanger();
		}
		else {
			m_Leave_y = 0.f;
			m_Fade_leave.start(10, 400);
			setSceneState(SCENE_TYPE::DIFFICULTY_SELECT);
		}
		if (m_Fade_leave.isFlag())m_Leave_y = m_Fade_leave.getSize();
		if (m_Fade_approach.isFlag())m_Leave_y = 400 - m_Fade_approach.getSize();
		m_Fade_leave.update();
		m_Fade_approach.update();
		return getSceneState();
	}
	void Story::select() {
		if (Key::Pad.checkInput(Key::KEY_TYPE::SHOT) == 1) {
			Sound::sound.playSE(res::SE::SELECT_OK);
			GameSceneProp::difficulty = getHorizontal();
			m_Change_type = CHANGE_TYPE::SELECT;
			m_Fade_approach.start(10, 400);
		}
	}
	void Story::cancel() {
		if (Key::Pad.checkInput(Key::KEY_TYPE::BOM) == 1 || Key::Pad.checkInput(Key::KEY_TYPE::MENU) == 1) {
			Sound::sound.playSE(res::SE::SELECT_CANCEL);
			m_Change_type = CHANGE_TYPE::CHANCEL;
			m_Fade_approach.start(10, 400);
		}
	}
	void Story::sceneChanger() {
		if (m_Fade_leave.isFlag() || m_Fade_approach.isFlag())return;
		if (m_Change_type == CHANGE_TYPE::CHANCEL) {
			if (GameSceneProp::is_practice)setSceneState(SCENE_TYPE::STORY_SELECT);
			else setSceneState(SCENE_TYPE::TITLE);
		}
		if (m_Change_type == CHANGE_TYPE::SELECT) {
			setSceneState(SCENE_TYPE::SELECT_CHARA);
		}
		m_Change_type = CHANGE_TYPE::NONE;
		resetCoolDown();
	}
	Story::~Story() {
	}
}