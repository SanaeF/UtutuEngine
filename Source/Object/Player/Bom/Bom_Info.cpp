#include "Bom_Info.h"
#include "../../Source/Application/Sound/Sound.h"
#include "../../Source/Object/Player/Shot/PlayerShot/PlayerShot.h"
#include "../../Source/Object/Boss/Boss.h"
#include "../../Source/Object/Player/Shot/OptionManager.h"
#include "../../Source/Object/Bullet/Shot/Shot_Info.h"
#include "../../Source/Object/Bullet/Lazer/Lazer_Info.h"
#include "../../Source/Object/Bullet/TurnLazer/TurnLazer_Info.h"
#include "../../Source/Script/BossBulletScript/BossBulletScript.h"
#include "../../Source/Script/Manager/BossScript/BossScript.h"
#include "../../Source/Script/Manager/BulletScript/Shot/ShotScript.h"
#include "../../Source/Script/Manager/BulletScript/Lazer/LazerScript.h"
#include "../../Source/Script/Manager/BulletScript/TurnLazer/TurnLazerScript.h"
#include "../../Source/Resource/BulletImage/BulletImage.h"
#include "../../Source/Resource/PlayerImage/PlayerImage.h"
#include "../../Source/Resource/SoundData/SoundData.h"
#include "../../Source/Helper/Helper.h"
#include "../../Source/SystemProp/AreaProp.h"
#include "../../Source/Collider/Collider.h"
#include "../../Source/EffectTools/ScreenFade/ScreenFade.h"
#include "../../Source/EffectTools/Shake/Shake.h"
using namespace res;
namespace obj {
	Bom_Info::Bom_Info() {
		m_Shake.reset(new app::Shake());
	}
	void Bom_Info::update(float x, float y, int type, bool is_damage) {
		m_Px = x;
		m_Py = y;
		if (type == -1)patternOrg();
		if (type == res::PLAYER_TYPE::EREMIRA)patternA();
		if (type == res::PLAYER_TYPE::MAI)patternB();
		if (type == res::PLAYER_TYPE::MEGU)patternC();
		if (type == res::PLAYER_TYPE::HIME)patternD();
		if (type == res::PLAYER_TYPE::IORIKO)patternE();
		m_Count++;
		if (is_damage) {
			clear();
		}
	}
	void Bom_Info::initialize() {
		m_Count = 0;
		m_Is_end = false;
		m_Is_no_damage = true;
		app::Sound::sound.playSE(res::SE::GYUUUUUUN);
		//Particle Effect;
		//int k;
		//SE_Output[14] = 1;//キュイーン音
		////キャラ
		//if ((k = Effect.search()) != -1) {
		//	effect[k].flag = 1;
		//	effect[k].cnt = 0;
		//	effect[k].knd = 2;//ボムのキャラ・線のエフェクト
		//	effect[k].brt = 0;
		//	effect[k].ang = 0;
		//	effect[k].mvang = -PI / 2;
		//	effect[k].spd = 0.7;
		//	effect[k].r = 2;
		//	effect[k].eff = 2;
		//	effect[k].img = img_eff_bom[2];
		//	effect[k].x = 260;
		//	effect[k].y = 300;
		//}
		//SE_Output[14] = 1;
		//bom.cnt = 0;
		//bom.knd = 0;
		//bom.flag = 1;
		//end_flag = false;
	}
	void Bom_Info::clear() {
		m_Count = 0;
		m_Is_end = true;
		m_Is_no_damage = false;
	}
	void Bom_Info::patternVS() {

	}
	void Bom_Info::patternOrg() {
		/*float BomRange = 300;
		auto boss_shot = m_Boss->getBulletScript()->getBulletScript()->getShotScript()->getShot();
		Collider collider(Collider::BULLET);
		for (int num = 0; num < BULLET_NUM_MAX; num++) {
			float posX[2] = { m_Px,boss_shot[num].getX() };
			float posY[2] = { m_Py,boss_shot[num].getY() };
			float Range[2] = { collider.getBulletRange(boss_shot[num].getColor()),BomRange };
			if (
				collider.hitCircle(
					posX,
					posY,
					boss_shot[num].getSpeed(),
					boss_shot[num].getAngle(),
					Range)
				) shotInit(num);
		}
		if (m_Count < 5)clear();*/
	}
	void Bom_Info::patternA() {//あやの
		/*fadeEffect();
		auto& option = OptionManager::Shot;
		auto& pl_shot = option.getShot();
		int k;
		if (BEDWEEN(m_Count, 41, 300) && m_Count % 6 == 1) {
			for (int ite = 0; ite < 6; ite++) {
				float angle, pos_x;
				if (ite == 0) angle = (-PI / 2 + PI / 3), pos_x = 80;
				if (ite == 1) angle = (-PI / 2 + PI / 6), pos_x = 80;
				if (ite == 2) angle = (-PI / 2 + PI / 18), pos_x = 80;
				if (ite == 3) angle = (-PI / 2 - PI / 3), pos_x = -80;
				if (ite == 4) angle = (-PI / 2 - PI / 6), pos_x = -80;
				if (ite == 5) angle = (-PI / 2 - PI / 18), pos_x = -80;
				if ((k = option.search()) != -1) {
					pl_shot[k].setSpawn(m_Px + pos_x, m_Py - 50, angle, 30, 3, PLAYER_SHOT_TYPE::SHOT_BIRD, PATTERN::CHANGE_HOMING, 20);
					pl_shot[k].setShine(true);
					pl_shot[k].setHitClear(true);
				}
				if ((k = option.search()) != -1) {
					pl_shot[k].setSpawn(m_Px + pos_x, m_Py - 50, angle, 30, 1.6, PLAYER_SHOT_TYPE::SHOT_BIRD, PATTERN::HOMING, 17);
					pl_shot[k].setShine(true);
					pl_shot[k].setHitClear(true);
				}
			}
		}
		if (m_Count == 312) {
			m_Boss->getBulletScript()->getBulletScript()->shotClear(true);
		}
		if (m_Count == 342)clear();*/
	}
	void Bom_Info::patternB() {//みさと
		/*fadeEffect();
		if (BEDWEEN(m_Count, 41, 310) && m_Count % 6 == 0) {
			auto& option = OptionManager::Shot;
			auto& pl_shot = option.getShot();
			int k;
			if ((k = option.search()) != -1) {
				pl_shot[k].setSpawn(m_Px, m_Py, -PI/2, 30, 2, PLAYER_SHOT_TYPE::BOM_LAZER, PATTERN::LAZER, 20);
				pl_shot[k].setAddPos(0, 0);
				pl_shot[k].setShine(true);
				pl_shot[k].setHitClear(false);
			}
			m_Boss->getBulletScript()->getBulletScript()->shotClear(true);
		}
		if (m_Count == 312) {
			m_Boss->getBulletScript()->getBulletScript()->shotClear(true);
		}
		if (m_Count == 342)clear();*/
	}
	void Bom_Info::patternC() {//あかぎ
		/*fadeEffect();
		auto& option = OptionManager::Shot;
		auto& pl_shot = option.getShot();
		if (m_Count == 1) {
			int k;
			if ((k = option.search()) != -1) {
				pl_shot[k].setSpawn(FMAX_X / 2, FMAX_Y / 2 - 100, 0, 3, 2, PLAYER_SHOT_TYPE::BOM_MOON, PATTERN::NONE, 0);
				pl_shot[k].setHitClear(false);
			}
		}
		if (m_Count < 250) {
			for (int ite = 0; ite < pl_shot.size(); ite++) {
				auto& shot = pl_shot[ite];
				if (shot.isFlag() && shot.getType() == PLAYER_SHOT_TYPE::BOM_MOON) {
					if (shot.getX() >= FMAX_X - FMIN_X - 1) {
						app::Sound::sound.playSE(res::SE::BULLET01);
						app::Sound::sound.playSE(res::SE::KIRAN);
						m_Shake->set(9, 10);
						shot.setAngle(PI);
						shot.setSpeed(3);
						m_Boss->setDamage(30);
						m_Boss->getBulletScript()->getBulletScript()->shotClear(true);
					}
					if (shot.getX() <= FMIN_X - 1) {
						app::Sound::sound.playSE(res::SE::BULLET01);
						app::Sound::sound.playSE(res::SE::KIRAN);
						m_Shake->set(9, 10);
						shot.setAngle(0);
						shot.setSpeed(3);
						m_Boss->setDamage(30);
						m_Boss->getBulletScript()->getBulletScript()->shotClear(true);
					}
					shot.setSpeed(shot.getSpeed() + 2.5);
					shot.setImgAng(shot.getImgAng() + 0.15);
				}
			}
		}
		if (m_Count == 312) {
			m_Boss->getBulletScript()->getBulletScript()->shotClear(true);
			clear();
			for (int ite = 0; ite < pl_shot.size(); ite++) {
				auto& shot = pl_shot[ite];
				if (shot.isFlag()&&shot.getType()==PLAYER_SHOT_TYPE::BOM_MOON) {
					shot.clear(true);
				}
			}
		}*/
	}
	void Bom_Info::patternD() {//ひめ
		/*fadeEffect();
		auto& option = OptionManager::Shot;
		auto& pl_shot = option.getShot();
		if (m_Count == 0) {
			for (int ite = 0; ite < pl_shot.size(); ite++) {
				pl_shot[ite].clear(true);
			}
		}
		if (BEDWEEN(m_Count, 41, 300) && m_Count % 5 == 0) {
			int k;
			for (int ite = 0; ite < 12; ite++) {
				if ((k = option.search()) != -1) {
					pl_shot[k].setSpawn(m_Px, m_Py, -PI / 2 + PI / 6 * ite + GET_SEED_RANDOM_F(PI / 6), 40, 3, PLAYER_SHOT_TYPE::SHOT_METEO, PATTERN::CIRCLE_SCRAMBLE, 20);
					pl_shot[k].setHitClear(true);
				}
			}
		}
		if (m_Count > 1) {
			for (int ite = 0; ite < pl_shot.size(); ite++) {
				auto& shot = pl_shot[ite];
				if (shot.isFlag()) {
					if (shot.getCount() > 13)shot.clear(true);
					else shot.setAngle(shot.getAngle() + PI / 8);
				}
			}
			const float range = 200;
			auto& bullet = m_Boss->getBulletScript()->getBulletScript()->getShotScript()->getShot();
			for (int ite = 0; ite < bullet.size(); ite++) {
				if (bullet[ite].isFlag()) {
					auto x = m_Px - bullet[ite].getX();
					auto y = m_Py - bullet[ite].getY();
					if (range > sqrt(x * x) && range > sqrt(y * y))bullet[ite].clear(true);
				}
			}
		}
		if (m_Count == 312) {
			m_Boss->getBulletScript()->getBulletScript()->shotClear(true);
		}
		if (m_Count == 342)clear();*/
	}
	void Bom_Info::patternE() {//いおりこ
		//m_Is_no_damage = false;
		//auto& option = OptionManager::Shot;
		//auto& pl_shot = option.getShot();
		//if (m_Count == 0) {
		//	for (int ite = 0; ite < pl_shot.size(); ite++) {
		//		pl_shot[ite].clear(true);
		//	}
		//}
		//if (m_Count == 1) {
		//	int k;
		//	for (int ite = 0; ite < 3; ite++) {
		//		if ((k = option.search()) != -1) {
		//			pl_shot[k].setSpawn(m_Px, m_Py, 0, 30, 1.5, PLAYER_SHOT_TYPE::ONMYOU, PATTERN::STOP, 47);
		//			pl_shot[k].setState(ite);
		//			pl_shot[k].setHitClear(false);
		//		}
		//	}
		//}
		//if (m_Count > 1) {
		//	const float range = 50;
		//	auto& bullet = m_Boss->getBulletScript()->getBulletScript()->getShotScript()->getShot();
		//	for (int ite1 = 0; ite1 < pl_shot.size(); ite1++) {
		//		auto& shot = pl_shot[ite1];
		//		if (shot.isFlag() && shot.getType() == PLAYER_SHOT_TYPE::ONMYOU) {
		//			shot.setImgAng(shot.getImgAng() + shot.getCount() * 0.017);
		//			shot.setX(m_Px + cos(PI2 / 3 * shot.getState() + PI / 60 * shot.getCount()) * 290);
		//			shot.setY(m_Py + sin(PI2 / 3 * shot.getState() + PI / 60 * shot.getCount()) * 290);
		//			for (int ite2 = 0; ite2 < bullet.size(); ite2++) {
		//				if (ite2 > m_Boss->getBulletScript()->getBulletScript()->getShotSpawnedMax())break;
		//				if (bullet[ite2].isFlag()) {
		//					auto x = shot.getX() - bullet[ite2].getX();
		//					auto y = shot.getY() - bullet[ite2].getY();
		//					float dist = sqrt((x * x) + (y * y));
		//					if (range > dist && !bullet[ite2].isNoDelete())bullet[ite2].clear(true);
		//				}
		//			}
		//		}
		//		/*if (shot.isFlag() && shot.getType() == PLAYER_SHOT_TYPE::ONMYOU) {
		//			shot.setImgAng(shot.getImgAng() + shot.getCount() * 0.017);
		//			shot.setX(m_Px + cos(PI2 / 3 * shot.getState() + PI / 60 * shot.getCount()) * 290);
		//			shot.setY(m_Py + sin(PI2 / 3 * shot.getState() + PI / 60 * shot.getCount()) * 290);
		//			auto& bullet = m_Boss->getBulletScript()->getBulletScript()->getShotScript()->getShot();
		//			for (int ite2 = 0; ite2 < bullet.size(); ite2++) {
		//				if (ite2 > m_Boss->getBulletScript()->getBulletScript()->getShotSpawnedMax())return;
		//				if (bullet[ite2].isFlag()) {
		//					auto x = shot.getX() - bullet[ite2].getX();
		//					auto y = shot.getY() - bullet[ite2].getY();
		//					float dist = sqrt((x * x) + (y * y));
		//					if (range > dist && !bullet[ite2].isNoDelete())bullet[ite2].clear(true);
		//				}
		//			}
		//		}*/
		//	}
		//}
	}
	void Bom_Info::fadeEffect() {

		if (BEDWEEN(m_Count, 40, 270))app::Sound::sound.playSE(res::SE::BOOOOM);

		if (m_Count == 0)app::ScreenFade::Direct.setFadeBright(app::ScreenFade::FADE_IN, 40, 150);//画面の明るさ設定(暗く)
		if (BEDWEEN(m_Count, 40, 310))app::ScreenFade::Direct.setBright(true, 150);
		if (m_Count == 310) {
			app::ScreenFade::Direct.setBright(false);
			app::ScreenFade::Direct.setFadeBright(app::ScreenFade::FADE_OUT, 90, 150);
		}
	}
	void Bom_Info::shotInit(int num) {
		/*m_Boss->getBulletScript()->getBulletScript()->getShotScript()->getShot()[num].clear(true);
		m_Boss->getBulletScript()->getBulletScript()->getShotScript()->getShot()[num].setDefault();*/
	}
	bool Bom_Info::isEndTime() {
		return m_Is_end;
	}
	bool Bom_Info::isNoDamage() {
		return m_Is_no_damage;
	}
	std::shared_ptr<app::Shake> Bom_Info::getShake() {
		return m_Shake;
	}
}