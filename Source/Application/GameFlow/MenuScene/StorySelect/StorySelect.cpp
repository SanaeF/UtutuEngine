#include "StorySelect.h"
#include "../../Source/SystemProp/SceneProp.h"
#include "../../Source/SystemProp/GameSceneProp/GameSceneProp.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/library/Graphics/String/StringDX.h"
#include "../../Source/Resource/GUI/SelectUIImage/SelectUIImage.h"
#include "../../Source/Resource/GUI/MenuUIImage/MenuUIImage.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"
#include "../../Source/Resource/SaveData/SaveData.h"
#include "../../Source/Resource/SoundData/SoundData.h"
#include "../../Source/Application/Key/Key.h"
#include "../../Source/Application/Sound/Sound.h"
namespace app {
	int StorySelect::update() {
		if (sceneCoolDown(10)) {
			up(7);
			down(7);
			select();
			cancel();
			GameSceneProp::stage = getHorizontal();
		}
		else {
			setSceneState(SCENE_TYPE::STORY_SELECT);
		}
		return getSceneState();
	}
	void StorySelect::draw() {
		const int text_x = 400;
		const int constant_y = 200;
		const int dist_y = 150;
		MenuText diffGUI[7] = {//280 420
			{ text_x, constant_y + dist_y * 0, "ストーリー1 (難易度:★★)" },
			{ text_x, constant_y + dist_y * 1, "ストーリー2 (難易度:★★★)" },
			{ text_x, constant_y + dist_y * 2, "ストーリー3 (難易度:★★★★)" },
			{ text_x, constant_y + dist_y * 3, "ストーリー4 (難易度:★★★★★★)" },
			{ text_x, constant_y + dist_y * 4, "ストーリー5 (難易度:★★★★★)" },
			{ text_x, constant_y + dist_y * 5, "ストーリー6 (難易度:★★★★★★★)" },
			{ text_x, constant_y + dist_y * 6, "ストーリー7 (難易度:不明)" }
		};
		lib::Graphics2D::setBright(255, 255, 255);
		lib::Graphics2D::drawRota(480 * 2, 360 * 2, 1.0, 0.0, res::MenuUIImage::menu_ui.title.back, true);
		lib::Graphics2D::drawRota(480 * 2, 360 * 2, 1.0, 0.0, res::MenuUIImage::menu_ui.gray_box[1], true);
		for (int i = 0; i < 7; i++) {
			int add_x = 0;
			int color = 0;
			if (i == getHorizontal()) {
				color = lib::StringDX::color(255, 255, 255);
				add_x = -40;
			}
			else {
				color = lib::StringDX::color(120, 120, 120);
			}
			lib::StringDX::draw(
				diffGUI[i].x + add_x,
				diffGUI[i].y,
				diffGUI[i].name,
				color,
				res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]
			);
		}
		if (res::SaveData::save_data.clear.clear_story_num <= getHorizontal()) {
			lib::StringDX::draw(
				410, 1250,
				"このストーリーはまだ未開放です。突破すると選べます。",
				lib::StringDX::color(255, 120, 120),
				res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]
			);
		}
		lib::Graphics2D::setBlend(lib::BLEND_MODE::NONE, 0);
	}
	void StorySelect::select() {
		if (res::SaveData::save_data.clear.clear_story_num <= GameSceneProp::stage)return;
		if (Key::Pad.checkInput(Key::KEY_TYPE::SHOT) == 1) {
			Sound::sound.playSE(res::SE::SELECT_OK);
			setSceneState(SCENE_TYPE::DIFFICULTY_SELECT);
			resetCoolDown();
		}
	}
	void StorySelect::cancel() {
		if (Key::Pad.checkInput(Key::KEY_TYPE::BOM) == 1 || Key::Pad.checkInput(Key::KEY_TYPE::MENU) == 1) {
			Sound::sound.playSE(res::SE::SELECT_CANCEL);
			setSceneState(SCENE_TYPE::TITLE);
			resetCoolDown();
		}
	}
}