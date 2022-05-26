#include "BossBonus.h"
#include "BossScore/BossScore.h"
#include "BossItem/BossItem.h"
#include "../../Source/SystemProp/AreaProp.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/library/Graphics/String/StringDX.h"
#include "../../Source/Resource/GUI/GameUIImage/GameUIImage.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"
#include "../../Source/Resource/SoundData/SoundData.h"
#include "../../Source/Manager/ItemManager/ItemManager.h"
#include "../../Source/MassageHandle/MassageHandle.h"
#include "../../Source/Object/Player/Player.h"
#include "../../Source/Application/Sound/Sound.h"
#include "../../Source/SystemProp/AliceProp/AliceProp.h"
#include "../../Source/Resource/SaveData/SaveData.h"
namespace obj {
	void BossBonus::initialize(bool is_no_damage, int boss_type, int bullet_num) {
		m_Boss_type = boss_type;
		m_Bullet_num = bullet_num;
		m_Is_no_damage = is_no_damage;
		m_Is_call = false;
		m_Is_start_counter = false;
		m_Is_failed = false;
		m_Bounus_score = BossScore::result(boss_type, bullet_num);
	}
	void BossBonus::initialize(bool is_inter, bool is_main_bullet, bool is_no_damage, int boss_type, int bullet_num) {
		m_Is_inter = is_inter;
		m_is_main_bullet = is_main_bullet;
		m_Boss_type = boss_type;
		m_Bullet_num = bullet_num;
		m_Is_no_damage = is_no_damage;
		m_Is_call = false;
		m_Is_start_counter = false;
		m_Is_failed = false;
		m_Bounus_score = BossScore::result(is_inter, is_main_bullet, boss_type, bullet_num);
	}
	void BossBonus::update() {
		if (!m_Is_no_damage) {
			if (m_Is_start_counter && m_Bounus_score > 0)m_Bounus_score = m_Bounus_score - m_Bullet_last_time / 50;
		}
		if (m_Is_flag) {
			auto player = Player::PlayerObj;
			if (player.getCount() > 20 && player.isDamageNow())m_Is_failed = true;
			if (AliceProp::flag) {
				if (res::SaveData::save_data.weapon[AliceProp::weapon_type].ex_type == 3) {
					m_Is_failed = false;
					if (m_Bounus_score <= 0)m_Bounus_score = 3304;
				}
			}
		}
		if (m_Is_call) {
			m_Count++;
			if(m_Count>100)m_Is_call = false;
		}
	}
	void BossBonus::draw() {
		if (m_Is_flag) {
			int score = m_Bounus_score;
			if (score > 9999999)score = 9999999;
			if (m_Is_failed ||score < 0)score = 0;
			for (int i = 0; i < 7; i++) {
				//ハイスコア表示
				lib::Graphics2D::drawRota(
					AREA::FMIN_X + 240 - i * 20, AREA::FMIN_Y + 85,
					0.6f,
					0.0f,
					res::TextUIImage::text_ui.number[0][score % 10],
					true
				);
				score /= 10;
			}
			lib::StringDX::draw(
				AREA::FMIN_X + 10, AREA::FMIN_Y + 74,
				"BONUS:",
				lib::StringDX::color(255, 255, 255),
				res::TextUIImage::text_ui.font[res::FONT::FONT_SB_BOUNS_SCORE]
			);
		}
		if (m_Is_call) {
			if (!m_Is_failed) {
				const float mid_x = ((AREA::FMAX_X - AREA::FMIN_X) / 2);
				int score = m_Bounus_score;
				for (int i = 0; i < 7; i++) {
					//ハイスコア表示
					lib::Graphics2D::drawRota(
						mid_x + 290 - i * 70, AREA::FMIN_Y + 90,
						2.5f,
						0.0f,
						res::TextUIImage::text_ui.number[0][score % 10],
						true
					);
					score /= 10;
				}
			}
			else {
				lib::StringDX::draw(
					AREA::FMIN_X + 250, AREA::FMIN_Y + 30,
					"Lost Bullet...",
					lib::StringDX::color(255, 155, 155),
					res::TextUIImage::text_ui.font[res::FONT::FONT_SB_BOUNS_CALL]
				);
			}
		}
	}
	void BossBonus::dropItem() {
		m_Item->drop(m_Is_failed, m_Is_inter, m_is_main_bullet, m_Boss_type, m_Bullet_num);
	}
	void BossBonus::setBulletLastTime(int time) {
		m_Is_flag = true;
		m_Is_start_counter = true;
		m_Bullet_last_time = time;
	}
	void BossBonus::setBonusCall(int boss_time) {
		if (m_Is_call)return;
		if (!m_Is_no_damage && boss_time <= 0)m_Is_failed = true;
		if (!m_Is_failed) {
			app::Sound::sound.playSE(res::SE::GET_BONUS);
			MassageHandleItem(PLAYER::GetScore, m_Bounus_score, 0);
		}
		else app::Sound::sound.playSE(res::SE::BULLET01);
		m_Is_start_counter = false;
		m_Is_call = true;
		m_Is_flag = false;
		m_Count = 0;
	}
	BossBonus::BossBonus() {
		m_Item.reset(new BossItem());
		//m_ItemSpawner.reset(new ItemManager());
	}
}