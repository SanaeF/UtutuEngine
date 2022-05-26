#include "Camp.h"

#include "../../Source/SystemProp/AreaProp.h"
#include "../../Source/SystemProp/AliceProp/AliceProp.h"
#include "../../Source/SystemProp/GameSceneProp/GameSceneProp.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/library/Sound/SoundDX.h"
#include "../../Source/library/Graphics/String/StringDX.h"
#include "../../Source/Object/Player/Player.h"
#include "../../Source/Application/Sound/Sound.h"
#include "../../Source/Application/Key/Key.h"
#include "../../Source/Resource/GUI/GameUIImage/GameUIImage.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"
#include "../../Source/Resource/SoundData/SoundData.h"
#include "../../Source/Resource/SaveData/SaveData.h"
namespace app {
	void Camp::update(int time, int map_time) {
		campGetterKey();
		if (m_Is_saving) {
			m_Count++;
			if (m_Count > 40) {
				output(time, map_time);
				m_Count = 0;
				m_Is_saving = false;
			}
		}
	}
	void Camp::draw() {
		if (m_Is_saving) {
			lib::Graphics2D::setBlend(lib::BLEND_MODE::ALPHA, 255 - ((255.f / 40.f) * m_Count));
			lib::Graphics2D::drawRota(
				(AREA::FMAX_X - AREA::FMIN_X) / 2 + AREA::FMIN_X,
				(AREA::FMAX_Y - AREA::FMIN_Y) / 2,
				3.f / 40.f + m_Count,
				0.0f,
				res::GameUIImage::game_ui.special.camp[2],
				true
			);
			lib::Graphics2D::setBlend(lib::BLEND_MODE::NONE, 255);
			lib::StringDX::draw(
				obj::Player::PlayerObj.getX()+80,
				obj::Player::PlayerObj.getY()-80,
				"Pin!",
				lib::StringDX::color(255, 255, 255),
				res::TextUIImage::text_ui.font[res::FONT::FONT_SERIF]
			);
		}
	}
	void Camp::output(int time, int map_time) {
		if (m_Is_lock)return;
		int id = GameSceneProp::difficulty;
		if (AliceProp::flag)id = 3;
		auto& save = res::SaveData::save_data.clear.camp_data[id];
		auto player = obj::Player::PlayerObj.getItemStack();
		save.camped = true;
		//プレイヤーデータの復帰
		save.player.score = player.score;
		save.player.life = player.life;
		save.player.life_frag = player.life_fragument;
		save.player.bom = player.bom;
		save.player.bom_frag = player.bom_fragument;
		save.player.power = player.power;
		//ステージの復帰
		save.stage_num = GameSceneProp::stage;
		save.stage_time = time;
		save.map_time = map_time;
		//保存時の状態からBGMを再生
		save.sound_count = lib::SoundDX::getSoundPosition(res::SoundData::sound.bgm[Sound::sound.getNowPlayBGM()]);
	}
	void Camp::campGetterKey() {
		if (GameSceneProp::under_wear == 5)return;
		int id = GameSceneProp::difficulty;
		if (AliceProp::flag)id = 3;
		if (res::SaveData::save_data.clear.camp_data[id].stage_num == GameSceneProp::stage && res::SaveData::save_data.clear.camp_data[id].camped)return;
		if (Key::Pad.checkInput(Key::KEY_TYPE::CHANGE) == 1) {
			if (obj::Player::PlayerObj.getItemStack().camp_fragument > obj::Player::PlayerObj.getItemStack().camp_max) {
				obj::Player::PlayerObj.getItemStack().camp_fragument = 0;
				obj::Player::PlayerObj.getItemStack().is_setted_camp = true;
				m_Is_saving = true;
				m_Count = 0;
			}
		}
	}
	void Camp::setIsLock(bool flag) {
		m_Is_lock = flag;
	}
}