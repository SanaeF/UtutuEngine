#include "OptionManager.h"
#include <iostream>
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/Resource/PlayerImage/PlayerImage.h"
#include "../../Source/Resource/BulletImage/BulletImage.h"
#include "../../Source/Application/Sound/Sound.h"
#include "../../Source/Resource/SoundData/SoundData.h"
#include "../../Source/Resource/SaveData/SaveData.h"
#include "../../Source/Helper/Helper.h"
#include "../../Source/Object/Player/Shot/SideOption/SideOption.h"
#include "../../Source/Manager/BossManager/BossManager.h"
#include "../../Source/Manager/MinionManager/MinionManager.h"
#include "../../Source/Object/Boss/Boss.h"
#include "../../Source/Object/Minion/Minion.h"

using namespace res;
namespace obj {
	OptionManager OptionManager::Shot;
	OptionManager::OptionManager() :
		m_Px(0),
		m_Py(0),
		ch_type(0),
		m_Charge_count(0),
		m_Count(0)
	{
		m_Side_option.reset(new SideOption());
		m_Shot.resize(PLAYER_SHOT_MAX);
	}
	void OptionManager::initialize(int max_x, int min_x) {
		m_Shot_type = GET_RANDOM(3);
		ch_type = 0;
		m_Charge_count = 0;
		for (int num = 0; num < PLAYER_SHOT_MAX; num++)m_Shot[num].initialize(max_x, min_x);
		m_Side_option->initialize();
	}
	void OptionManager::update(float x, float y, bool is_shoot) {
		m_Px = x;
		m_Py = y;
		for (int num = 0; num < PLAYER_SHOT_MAX; num++) {
			m_Shot[num].update();
			homingEnemy(num);
			circleScramble(num);
			damageChanger(num);
			anguler(num);
			lazer(num);
		}
		if (is_shoot) {
			m_Side_option->update(x, y, m_Shot);
			m_Count++;
		}
		else m_Count = 0;
	}
	void OptionManager::draw(double crush_x, double crush_y) {
		if (m_Shot_type == 1 && m_Count != 0) {
			int img_state = (m_Count / 24) % 2;
			lib::Graphics2D::drawRota(
				m_Px + 100, m_Py + 10, 0.3f + 0.08 * m_Charge_count, 0.f,
				BulletImage::Bullet.charge_effect[img_state],
				true
			);
		}
		for (int num = 0; num < PLAYER_SHOT_MAX; num++)m_Shot[num].draw(crush_x, crush_y);
		if(m_Count != 0)m_Side_option->draw(crush_x, crush_y);
	}
	void OptionManager::pattern(int type, bool isSlow, bool is_bom) {
		ch_type = type;
		if (type == res::PLAYER_TYPE::EREMIRA && !is_bom)patternA(isSlow);
		else if (type == res::PLAYER_TYPE::MAI && !is_bom)patternB(isSlow);
		else if (type == res::PLAYER_TYPE::MEGU)patternC(isSlow);
		else if (type == res::PLAYER_TYPE::SARA && !is_bom)patternD(isSlow);
		else if (type == res::PLAYER_TYPE::KANA)patternE(isSlow);//else if (type == res::PLAYER_TYPE::UZUKI)patternOrg(isSlow);
		else patternDef(isSlow);
	}
	void OptionManager::patternA(bool isSlow) {//綾乃
		auto cloth_type = SaveData::save_data.chara_custom[res::EREMIRA].outer_wear_type;
		if (cloth_type == 0)m_Shot_type = 0;
		if (cloth_type == 1)m_Shot_type = 1;
		if (cloth_type == 2)m_Shot_type = 2;
		if (cloth_type == 4)m_Shot_type = 0;
		if (cloth_type == 5)m_Shot_type = 3;
		int k;
		if (m_Count % 6 == 1) {
			app::Sound::sound.playSE(res::SE::PLAYER_SHOT);
			if (!isSlow) {
				for (int ite = 0; ite < 2; ite++) {
					if ((k = search()) != -1) {
						m_Shot[k].setSpawn(m_Px + 80 * (-ite) + 40, m_Py, -PI / 2, 38, 1, PLAYER_SHOT_TYPE::SHOT_BLUE, PATTERN::NONE, 4);
						m_Shot[k].setHitClear(true);
					}
				}
			}
			else {
				for (int ite = 0; ite < 2; ite++) {
					if ((k = search()) != -1) {
						m_Shot[k].setSpawn(m_Px + 30 * (-ite) + 15, m_Py, -PI / 2, 38, 1, PLAYER_SHOT_TYPE::SHOT_BLUE, PATTERN::NONE, 6);
						m_Shot[k].setHitClear(true);
					}
				}
			}
		}
		if (m_Shot_type == 0) {//ホーミング鶴
			if (!isSlow) {
				if (m_Count % 13 == 1) {
					app::Sound::sound.playSE(res::SE::PLAYER_SHOT);
					for (int ite = 0; ite < 2; ite++) {
						float angle, pos_x;
						if (ite == 0) angle = (-PI / 2 + PI / 6), pos_x = (m_Px + 120);
						if (ite == 1) angle = (-PI / 2 - PI / 6), pos_x = (m_Px - 120);
						if ((k = search()) != -1) {
							m_Shot[k].setSpawn(pos_x, m_Py - 50, angle, 28, 1, PLAYER_SHOT_TYPE::SHOT_BIRD, PATTERN::HOMING, 12);
							m_Shot[k].setHitClear(true);
						}
					}
				}
			}
			else {
				if (m_Count % 9 == 1) {
					app::Sound::sound.playSE(res::SE::PLAYER_SHOT);
					for (int i = 0; i < 2; i++) {
						float angle, pos_x;
						if (i == 0) angle = (-PI / 2 + PI / 8), pos_x = (m_Px + 80);
						if (i == 1) angle = (-PI / 2 - PI / 8), pos_x = (m_Px - 80);
						if ((k = search()) != -1) {
							m_Shot[k].setSpawn(pos_x, m_Py - 50, angle, 28, 1, PLAYER_SHOT_TYPE::SHOT_BIRD, PATTERN::HOMING, 16);
							m_Shot[k].setHitClear(true);
						}
					}
				}
			}
		}
		if (m_Shot_type == 1) {//チャージオプション
			if (!isSlow) {
				if (m_Count % 13 == 1) {
					app::Sound::sound.playSE(res::SE::PLAYER_SHOT);
					int max = 10 + m_Charge_count / 10;
					for (int i = 0; i < max; i++) {
						if ((k = search()) != -1) {
							m_Shot[k].setSpawn(m_Px, m_Py, PI2 / max * i, 28, 1 + 0.07 * m_Charge_count, PLAYER_SHOT_TYPE::SHOT_MOON, PATTERN::NONE, 5 + m_Charge_count * 8);
							m_Shot[k].setHitClear(true);
						}
					}
					m_Charge_count = 0;
				}
			}
			else {
				if (m_Count % 9 == 1) {
					if (m_Charge_count < 30)m_Charge_count += 4;
				}
			}
		}
		if (m_Shot_type == 2) {//湾曲&レーザー
			if (!isSlow) {
				if (m_Count % 7 == 1) {//湾曲ショット
					app::Sound::sound.playSE(res::SE::PLAYER_SHOT);
					for (int ite = 0; ite < 2; ite++) {
						if ((k = search()) != -1) {
							m_Shot[k].setSpawn(m_Px + 90 * (-ite) + 40, m_Py + 40, -PI / 2, 18, 1, PLAYER_SHOT_TYPE::SHOT_CYAN, PATTERN::ANGULAR, 3);
							m_Shot[k].setState(ite);
							m_Shot[k].setHitClear(true);
						}
					}
				}
				if (m_Count % 2 == 1) {//レーザー
					if ((k = search()) != -1) {
						m_Shot[k].setSpawn(m_Px, m_Py - 150, -PI / 2, 30, 1, PLAYER_SHOT_TYPE::LAZ_BLUE, PATTERN::LAZER, 4);
						m_Shot[k].setAddPos(0, -150);
						m_Shot[k].setShine(true);
						m_Shot[k].setHitClear(false);
					}
				}
			}
			else {
				if (m_Count % 6 == 1) {//湾曲ショット
					app::Sound::sound.playSE(res::SE::PLAYER_SHOT);
					for (int ite = 0; ite < 2; ite++) {
						if ((k = search()) != -1) {
							m_Shot[k].setSpawn(m_Px + 20 * (-ite) + 10, m_Py + 40, -PI / 2, 16, 1, PLAYER_SHOT_TYPE::SHOT_CYAN, PATTERN::ANGULAR, 4);
							m_Shot[k].setState(ite);
							m_Shot[k].setHitClear(true);
						}
					}
				}
				if (m_Count % 2 == 1) {//レーザー
					if ((k = search()) != -1) {
						m_Shot[k].setSpawn(m_Px, m_Py - 150, -PI / 2, 30, 1, PLAYER_SHOT_TYPE::LAZ_BLUE, PATTERN::LAZER, 4);
						m_Shot[k].setAddPos(0, -150);
						m_Shot[k].setShine(true);
						m_Shot[k].setHitClear(false);
					}
				}
			}
		}
		if (m_Shot_type == 3) {//広範囲コメット
			if (!isSlow) {
				if (m_Count % 12 == 1) {//湾曲ショット
					app::Sound::sound.playSE(res::SE::PLAYER_SHOT);
					for (int ite = 0; ite < 5; ite++) {
						if ((k = search()) != -1) {
							m_Shot[k].setSpawn(m_Px - 120 + (ite * 60), m_Py - 40, -PI / 2, 20, 1, PLAYER_SHOT_TYPE::SHOT_COMET, PATTERN::NONE, 4);
							m_Shot[k].setHitClear(true);
						}
					}
				}
			}
			else {
				if (m_Count % 10 == 1) {//湾曲ショット
					app::Sound::sound.playSE(res::SE::PLAYER_SHOT);
					for (int ite = 0; ite < 5; ite++) {
						if ((k = search()) != -1) {
							m_Shot[k].setSpawn(m_Px - 80 + (ite * 40), m_Py - 40, -PI / 2, 25, 1, PLAYER_SHOT_TYPE::SHOT_COMET, PATTERN::NONE, 6);
							m_Shot[k].setHitClear(true);
						}
					}
				}
			}
		}
	}
	void OptionManager::patternB(bool isSlow) {//みさと
		auto cloth_type = SaveData::save_data.chara_custom[res::MAI].outer_wear_type;
		m_Shot_type = 0;
		int k;
		if (m_Shot_type == 0) {
			if (!isSlow) {
				if (m_Count % 2 == 1) {
					for (int ite = 0; ite < 2; ite++) {
						if ((k = search()) != -1) {
							m_Shot[k].setSpawn(m_Px + 100 * (-ite) + 50, m_Py - 60, -PI / 2, 30, 1, PLAYER_SHOT_TYPE::LAZ_BLUE, PATTERN::LAZER, 5);
							m_Shot[k].setAddPos(100 * (-ite) + 50, -60);
							m_Shot[k].setShine(true);
							m_Shot[k].setHitClear(false);
						}
					}
				}
			}
			else {
				if (m_Count % 4 == 1) {
					app::Sound::sound.playSE(res::SE::PLAYER_SHOT);
					for (int ite = 0; ite < 2; ite++) {
						if ((k = search()) != -1) {
							m_Shot[k].setSpawn(m_Px + 30 * (-ite) + 15, m_Py, -PI / 2, 38, 1, PLAYER_SHOT_TYPE::SHOT_POTATO, PATTERN::NONE, 11);
							m_Shot[k].setHitClear(true);
						}
					}
				}
				if (m_Count % 24 == 1) {
					float  x, y;
					for (int ite = 0; ite < 2; ite++) {
						if (ite == 0)x = m_Px + 100;
						if (ite == 1)x = m_Px - 100;
						for (int ite2 = 0; ite2 < 12; ite2++) {
							if ((k = search()) != -1) {
								m_Shot[k].setSpawn(x, m_Py, PI / 6 * ite2, 10, 1, PLAYER_SHOT_TYPE::SHOT_POTATO, PATTERN::CIRCLE_SCRAMBLE, 18);
								m_Shot[k].setState(ite);
								m_Shot[k].setHitClear(true);
							}
						}
					}
				}
			}
		}
	}
	void OptionManager::patternC(bool isSlow) {//赤城
		auto cloth_type = SaveData::save_data.chara_custom[res::MEGU].outer_wear_type;
		m_Shot_type = 0;
		int k;
		if (m_Shot_type == 0) {
			if (!isSlow) {
				if (m_Count % 2 == 1) {//レーザー
					for (int ite = 0; ite < 2; ite++) {
						if ((k = search()) != -1) {
							m_Shot[k].setSpawn(m_Px + 30, m_Py - 40, -PI / 2 - PI / 30 + (PI2 / 30 * ite), 30, 1, PLAYER_SHOT_TYPE::LAZ_RED, PATTERN::LAZER, 3);
							m_Shot[k].setAddPos(30, -40);
							m_Shot[k].setShine(true);
							m_Shot[k].setHitClear(false);
						}
					}
				}
				if (m_Count % 6 == 1) {//普通のショット
					app::Sound::sound.playSE(res::SE::PLAYER_SHOT);
					for (int ite = 0; ite < 2; ite++) {
						if ((k = search()) != -1) {
							m_Shot[k].setSpawn(m_Px + 30, m_Py - 60, -PI / 2 - PI / 60 + (PI2 / 60 * ite), 38, 1, PLAYER_SHOT_TYPE::SHOT_POTATO, PATTERN::NONE, 5);
							m_Shot[k].setHitClear(true);
						}
					}
				}
			}
			else {
				if (m_Count % 2 == 1) {//レーザー
					if ((k = search()) != -1) {
						m_Shot[k].setSpawn(m_Px + 30, m_Py - 40, -PI / 2, 30, 1, PLAYER_SHOT_TYPE::LAZ_RED, PATTERN::LAZER, 4);
						m_Shot[k].setAddPos(30, -40);
						m_Shot[k].setShine(true);
						m_Shot[k].setHitClear(false);
					}
				}
				if (m_Count % 5 == 1) {//6連集中ショット
					app::Sound::sound.playSE(res::SE::PLAYER_SHOT);
					float angle[6] = { PI / 12,PI / 14,PI / 16,-PI / 16,-PI / 14,-PI / 12 };
					int x[6] = { -190,-100,-40,40,100,190 };
					for (int ite = 0; ite < 6; ite++) {
						if ((k = search()) != -1) {
							m_Shot[k].setSpawn(m_Px + 15 * 2 + x[ite], m_Py - 30, -PI / 2 + angle[ite], 47, 1, PLAYER_SHOT_TYPE::SHOT_CYAN, PATTERN::DAMAGE_CHANGER, 4);
							m_Shot[k].setChangeType(PLAYER_SHOT_TYPE::SHOT_BLUE);
							m_Shot[k].setHitClear(true);
						}
					}
				}
			}
		}
	}
	void OptionManager::patternD(bool isSlow) {
		auto cloth_type = SaveData::save_data.chara_custom[res::SARA].outer_wear_type;
		m_Shot_type = 0;
		int k;
		if (m_Shot_type == 0) {
			if (!isSlow) {
				if (m_Count % 8 == 1) {//ファイヤー
					app::Sound::sound.playSE(res::SE::PLAYER_SHOT);
					float angle, x;
					for (int ite = 0; ite < 2; ite++) {
						if (ite == 0)x = 70, angle = PI / 5;
						if (ite == 1)x = -70, angle = -PI / 5;
						if ((k = search()) != -1) {
							m_Shot[k].setSpawn(m_Px + x, m_Py, -PI / 2 + angle + GET_SEED_RANDOM_F(PI / 7), 38, 1, PLAYER_SHOT_TYPE::SHOT_METEO, PATTERN::NONE, 150);
							m_Shot[k].setHitClear(true);
						}
					}
				}
				if (m_Count % 2 == 1) {//雷レーザー
					for (int ite = 0; ite < 3; ite++) {
						float x = 0, y = 0, angle = 0;
						if (ite == 0)x = 70, angle = -PI / 2 + PI / 20;
						if (ite == 1)x = 0, angle = -PI / 2;
						if (ite == 2)x = -70, angle = -PI / 2 - PI / 20;
						if (ite == 0 || ite == 2)y = 50;
						if ((k = search()) != -1) {
							m_Shot[k].setSpawn(m_Px + x, m_Py + y, angle, 30, 1, PLAYER_SHOT_TYPE::LAZ_THUNDER, PATTERN::LAZER, 3);
							m_Shot[k].setAddPos(x, y);
							m_Shot[k].setShine(true);
							m_Shot[k].setHitClear(false);
						}
					}
				}
			}
			else {
				if (m_Count % 6 == 1) {//氷
					app::Sound::sound.playSE(res::SE::PLAYER_SHOT);
					float angle, x;
					for (int ite = 0; ite < 2; ite++) {
						if ((k = search()) != -1) {
							m_Shot[k].setSpawn(m_Px + 80*(-ite)+40, m_Py, -PI / 2, 38, 1, PLAYER_SHOT_TYPE::SHOT_COMET, PATTERN::NONE, 6);
							m_Shot[k].setHitClear(true);
						}
					}
				}
				if (m_Count % 2 == 1) {//雷レーザー
					for (int ite = 0; ite < 3; ite++) {
						float x = 0, y = 0, angle = 0;
						if (ite == 0)x = 60, angle = -PI / 2 + PI / 30;
						if (ite == 1)x = 0, angle = -PI / 2;
						if (ite == 2)x = -60, angle = -PI / 2 - PI / 30;
						if (ite == 0 || ite == 2)y = 50;
						if ((k = search()) != -1) {
							m_Shot[k].setSpawn(m_Px + x, m_Py + y, angle, 30, 1, PLAYER_SHOT_TYPE::LAZ_THUNDER, PATTERN::LAZER, 3);
							m_Shot[k].setAddPos(x, y);
							m_Shot[k].setShine(true);
							m_Shot[k].setHitClear(false);
						}
					}
				}
			}
		}
	}
	void OptionManager::patternE(bool isSlow) {
		auto cloth_type = SaveData::save_data.chara_custom[res::KANA].outer_wear_type;
		m_Shot_type = 0;
		int k;
		if (m_Shot_type == 0) {
			if (!isSlow) {
				if (m_Count % 6 == 1) {//メテオ
					app::Sound::sound.playSE(res::SE::PLAYER_SHOT);
					for (int ite = 0; ite < 2; ite++) {
						if ((k = search()) != -1) {
							m_Shot[k].setSpawn(m_Px + 30 * (-ite) + 15, m_Py, -PI / 2, 38, 1, PLAYER_SHOT_TYPE::SHOT_METEO, PATTERN::NONE, 6);
							m_Shot[k].setHitClear(true);
						}
					}
				}
				if (m_Count % 16 == 8) {//コメット
					for (int ite = 0; ite < 3; ite++) {
						if ((k = search()) != -1) {
							m_Shot[k].setSpawn(m_Px - 40, m_Py, PI, 17 - ite * 2, 1, PLAYER_SHOT_TYPE::SHOT_COMET, PATTERN::CHANGE_HOMING, 4);
							m_Shot[k].setHitClear(true);
						}
						if ((k = search()) != -1) {
							m_Shot[k].setSpawn(m_Px + 40, m_Py, 0, 17 - ite * 2, 1, PLAYER_SHOT_TYPE::SHOT_COMET, PATTERN::CHANGE_HOMING, 4);
							m_Shot[k].setHitClear(true);
						}
					}
				}
			}
			else {
				if (m_Count % 6 == 1) {//メテオ
					app::Sound::sound.playSE(res::SE::PLAYER_SHOT);
					for (int ite = 0; ite < 2; ite++) {
						if ((k = search()) != -1) {
							m_Shot[k].setSpawn(m_Px + 20 * (-ite) + 10, m_Py, -PI / 2, 38, 1, PLAYER_SHOT_TYPE::SHOT_METEO, PATTERN::NONE, 7);
							m_Shot[k].setHitClear(true);
						}
					}
				}
				if (m_Count % 14 == 5) {//コメット
					for (int ite = 0; ite < 3; ite++) {
						if ((k = search()) != -1) {
							m_Shot[k].setSpawn(m_Px - 40, m_Py, PI, 17 - ite * 2, 1, PLAYER_SHOT_TYPE::SHOT_COMET, PATTERN::CHANGE_HOMING, 5);
							m_Shot[k].setHitClear(true);
						}
						if ((k = search()) != -1) {
							m_Shot[k].setSpawn(m_Px + 40, m_Py, 0, 17 - ite * 2, 1, PLAYER_SHOT_TYPE::SHOT_COMET, PATTERN::CHANGE_HOMING, 5);
							m_Shot[k].setHitClear(true);
						}
					}
				}
			}
		}
	}
	void OptionManager::patternDef(bool isSlow) {
		if (m_Count % 6 == 1) {
			app::Sound::sound.playSE(res::SE::PLAYER_SHOT);
			if (!isSlow) {
				for (int i = 0; i < 2; i++) {
					int k;
					if ((k = search()) != -1) {
						m_Shot[k].setSpawn(m_Px + 80 * (-i) + 40, m_Py, -PI / 2, 38, 1, 0, 0, 4);
						m_Shot[k].setHitClear(true);
					}
				}
			}
			else {
				for (int i = 0; i < 2; i++) {
					int k;
					if ((k = search()) != -1) {
						m_Shot[k].setSpawn(m_Px + 30 * (-i) + 15, m_Py, -PI / 2, 38, 1, 0, 0, 6);
						m_Shot[k].setHitClear(true);
					}
				}
			}
		}
	}
	void OptionManager::patternOrg(bool isSlow) {
		if (m_Count % 6 == 1) {
			app::Sound::sound.playSE(res::SE::PLAYER_SHOT);
			if (!isSlow) {
				for (int i = 0; i < 2; i++) {
					int k;
					if ((k = search()) != -1) {
						m_Shot[k].setSpawn(m_Px + 80 * (-i) + 40, m_Py, -PI / 2, 38, 1, 0, 0, 4);
					}
				}
			}
			else {
				for (int i = 0; i < 2; i++) {
					int k;
					if ((k = search()) != -1) {
						m_Shot[k].setSpawn(m_Px + 30 * (-i) + 15, m_Py, -PI / 2, 38, 1, 0, 0, 6);
					}
				}
			}
		}
	}
	void OptionManager::homingEnemy(int id) {
		if (m_Shot[id].isFlag() && m_Shot[id].getPattern() == PATTERN::CHANGE_HOMING) {
			if (m_Shot[id].getCount() > 10) {
				m_Shot[id].setPattern(PATTERN::HOMING);
				m_Shot[id].setCount(0);
			}
		}
		if (m_Shot[id].isFlag() && m_Shot[id].getPattern() == PATTERN::HOMING) {
			if (m_Shot[id].getCount() > 10)return;
			int index = -1;
			float distance=-1;
			float dist_min = -1;
			float near_x, near_y;
			bool is_for_boss=false;
			auto& minion = manager::MinionManager::getInstance()->getMinion();
			for (int ite = 0; ite < minion.size(); ite++) {
				if (minion[ite].isFlag()) {
					float x = (minion[ite].getX() - m_Shot[id].getX());
					float y = (minion[ite].getY() - m_Shot[id].getY());
					distance = x * x + y * y;//ショットと敵の距離
					if (distance < dist_min || dist_min == -1) {//計算結果が最小値かまだ格納していないなら
						index = ite;
						dist_min = distance;//距離記録
					}
				}
			}
			//ショットから一番近いボスを算出(フラグが立っている)
			auto& obj = manager::BossManager::getInstance()->getBossList();
			for (int ite = 0; ite < obj.size(); ite++) {
				if (obj[ite].boss.isFlag()) {
					float x = (obj[ite].boss.getX() - m_Shot[id].getX());
					float y = (obj[ite].boss.getY() - m_Shot[id].getY());
					distance = x * x + y * y;//ショットと敵の距離
					if (distance < dist_min || dist_min == -1) {//計算結果が最小値かまだ格納していないなら
						is_for_boss = true;//ボスのほうが近いフラグを立てる
						index = ite;
						dist_min = distance;//距離記録
					}
				}
			}
			if (distance != -1) {
				if (is_for_boss) {
					near_x = (obj[index].boss.getX() - m_Shot[id].getX());
					near_y = (obj[index].boss.getY() - m_Shot[id].getY());
				}
				else {
					near_x = (minion[index].getX() - m_Shot[id].getX());
					near_y = (minion[index].getY() - m_Shot[id].getY());
				}
				m_Shot[id].setAngle(atan2(near_y, near_x));
			}
		}
	}
	void OptionManager::circleScramble(int id) {
		if (m_Shot[id].isFlag() && m_Shot[id].getPattern() == PATTERN::CIRCLE_SCRAMBLE) {
			if (m_Shot[id].getCount() % 13 == 0) {
				if (m_Shot[id].getState() == 0)m_Shot[id].setAngle(m_Shot[id].getAngle() - PI / 12);//左
				if (m_Shot[id].getState() == 1)m_Shot[id].setAngle(m_Shot[id].getAngle() + PI / 12);//右
				m_Shot[id].setSpeed(m_Shot[id].getSpeed() + 5);
				if (BEDWEEN(m_Shot[id].getCount(), 10, 40))
					m_Shot[id].setPower(m_Shot[id].getPower() + m_Shot[id].getCount() / 5);
			}
		}
	}
	void OptionManager::damageChanger(int id) {
		if (m_Shot[id].isFlag() && m_Shot[id].getPattern() == PATTERN::DAMAGE_CHANGER) {
			if (m_Shot[id].getCount() == 17) {
				m_Shot[id].setPower(m_Shot[id].getPower() / 2);
				m_Shot[id].setType(m_Shot[id].getChangeType());
			}
		}
	}
	void OptionManager::anguler(int id) {
		if (m_Shot[id].isFlag() && m_Shot[id].getPattern() == PATTERN::ANGULAR) {
			if (m_Shot[id].getState() == 0) {
				if (m_Shot[id].getCount() < 5)m_Shot[id].setAngle(-PI / 2 + PI / 3.5);
				if (m_Shot[id].getCount() > 5 && m_Shot[id].getCount() % 20 < 5)m_Shot[id].setAngle(m_Shot[id].getAngle() + PI / 2 / 10);
				if (m_Shot[id].getCount() % 20 >= 5 && m_Shot[id].getCount() % 20 < 10)m_Shot[id].setAngle(m_Shot[id].getAngle() - PI2 / 2 / 10);
				if (m_Shot[id].getCount() % 20 >= 15 && m_Shot[id].getCount() % 20 < 30)m_Shot[id].setAngle(m_Shot[id].getAngle() + PI / 2 / 10);
			}
			if (m_Shot[id].getState() == 1) {
				if (m_Shot[id].getCount() < 5)m_Shot[id].setAngle(-PI / 2 - PI / 3.5);
				if (m_Shot[id].getCount() > 5 && m_Shot[id].getCount() % 20 < 5)m_Shot[id].setAngle(m_Shot[id].getAngle() - PI / 2 / 10);
				if (m_Shot[id].getCount() % 20 >= 5 && m_Shot[id].getCount() % 20 < 10)m_Shot[id].setAngle(m_Shot[id].getAngle() + PI2 / 2 / 10);
				if (m_Shot[id].getCount() % 20 >= 15 && m_Shot[id].getCount() % 20 < 30)m_Shot[id].setAngle(m_Shot[id].getAngle() - PI / 2 / 10);
			}
		}
	}
	void OptionManager::lazer(int id) {
		if (m_Shot[id].isFlag() && m_Shot[id].getPattern() == PATTERN::LAZER) {
			float move_param_x = cos(m_Shot[id].getAngle()) * m_Shot[id].getCount() * m_Shot[id].getSpeed();
			float move_param_y = sin(m_Shot[id].getAngle()) * m_Shot[id].getCount() * m_Shot[id].getSpeed();
			m_Shot[id].setX(m_Px + m_Shot[id].getAddX() + move_param_x);
			m_Shot[id].setY(m_Py + m_Shot[id].getAddY() + move_param_y);
		}
	}
	void OptionManager::clear(bool is_all) {
		for (int i = 0; i < PLAYER_SHOT_MAX; i++) {
			if (is_all)m_Shot[i].clear(false);
			else if (m_Shot[i].getType() != ONMYOU)m_Shot[i].clear(false);
		}
	}
	int OptionManager::search() {
		for (int i = 0; i < PLAYER_SHOT_MAX; i++) {
			if (!m_Shot[i].isFlag()) {
				return i;
			}
		}
		return -1;
	}
	std::vector<PlayerShot>& OptionManager::getShot() {
		return m_Shot;
	}
	OptionManager::~OptionManager() {

	}
}