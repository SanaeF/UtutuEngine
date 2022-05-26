#include "BossManager.h"
#include <iostream>
#include "BossUI/BossUI.h"
#include "BossBonus/BossBonus.h"
#include "../../Source/SystemProp/AreaProp.h"
#include "../../Source/SystemProp/GameSceneProp/GameSceneProp.h"
#include "../../Source/Application/Replayer/Replayer.h"
#include "../../Source/Manager/BulletManager/BulletManager.h"
#include "../../Source/Script/BossBulletScript/BossBulletScript.h"

#pragma warning(disable : 4996)
namespace manager {
	BossManager BossManager::m_Instance;
	BossManager::BossManager():
		m_Is_bullet(false),
		m_Is_invalid_bom(false),
		m_Is_invincible(false),
		m_Is_special_bullet(false),
		m_Is_need_all_kill(false),
		m_Is_return_back(false),
		m_First_bullet(0),
		m_End_bullet(0),
		m_Bullet_type(0),
		m_Time(0),
		m_Time_max(0),
		m_Wait_time(0),
		m_Count(0),
		m_State(PHASE::NONE)
	{
		m_UI.reset(new obj::BossUI());
		m_Bonus.reset(new obj::BossBonus());
		m_Script.reset(new script::BulletScript());
	}
	BossManager* BossManager::getInstance() {
		return &m_Instance;
	}
	void BossManager::initialize() {
		m_State = PHASE::NONE;
		m_Is_bullet = false;
		m_Count = 0;
		m_Boss_obj.resize(1);
	}
	//ボスの召喚
	void BossManager::summon(int type, int index) {
		summon(AREA::DEF_BOSS_X, AREA::DEF_BOSS_Y, type, index);
	}
	void BossManager::summon(double x, double y, int type, int index) {
		int resize = index + 1;
		if (m_Boss_obj.size() < resize)m_Boss_obj.resize(resize);
		if (m_Boss_obj[index].boss.isFlag())return;
		m_Boss_obj[index].magic_ring.start();
		m_Boss_obj[index].boss.setX(x);
		m_Boss_obj[index].boss.setY(y);
		m_Boss_obj[index].boss.setFlag(true);
		m_Boss_obj[index].boss.setType(type);
		m_Boss_obj[index].boss.setSize(1.6f);
		m_Boss_obj[index].boss.setFadeIN();
		m_Boss_obj[index].boss.setAnimationType(0);
	}
	void BossManager::removeNoLife() {
		for (int i = 1; i < m_Boss_obj.size();i++) {
			if (m_Boss_obj[i].boss.getHP())m_Boss_obj.erase(std::cbegin(m_Boss_obj) + i);
		}
	}
	//ボス弾幕の開始
	void BossManager::startBullet(int start_num, int end_num) {
		m_Is_bullet = true;
		resetBossBulletFlag();
		m_Bullet_type = start_num;
		m_End_bullet = end_num;
		obj::BulletManager::getInstance()->clear(true);
	}
	void BossManager::changePosition() {
		auto size = m_Boss_obj.size();
		if (size == 1) {
			m_Boss_obj[0].boss.movePos(AREA::DEF_BOSS_X, AREA::DEF_BOSS_Y, 50);
		}
		if (size == 2) {
			m_Boss_obj[0].boss.movePos(AREA::DEF_BOSS_X - 200, AREA::DEF_BOSS_Y, 50);
			m_Boss_obj[1].boss.movePos(AREA::DEF_BOSS_X + 200, AREA::DEF_BOSS_Y, 50);
		}
		if (size == 3) {
			m_Boss_obj[0].boss.movePos(AREA::DEF_BOSS_X, AREA::DEF_BOSS_Y, 50);
			m_Boss_obj[2].boss.movePos(AREA::DEF_BOSS_X - 200, AREA::DEF_BOSS_Y + 200, 50);
			m_Boss_obj[3].boss.movePos(AREA::DEF_BOSS_X + 200, AREA::DEF_BOSS_Y + 200, 50);
		}
		if (size > 3) {
			size = size - 1;
			m_Boss_obj[0].boss.movePos(AREA::DEF_BOSS_X, AREA::DEF_BOSS_Y, 50);
			int dist = 80;
			float add_x = dist * size;
			for (int i = 1; i < size; i++) {
				m_Boss_obj[i].boss.movePos(
					AREA::DEF_BOSS_X - add_x + i + dist,
					AREA::DEF_BOSS_Y + 200,
					40
				);
			}
		}
	}
	void BossManager::returnBackPosition() {
		auto size = m_Boss_obj.size();
		if (size == 1) {
			m_Boss_obj[0].boss.movePos(-350, -120, 120);
		}
		if (size == 2) {
			m_Boss_obj[0].boss.movePos(-350, -120, 120);
			m_Boss_obj[1].boss.movePos(AREA::FMAX_X+250, -120, 120);
		}
		if (size == 3) {
			m_Boss_obj[0].boss.movePos((AREA::FMAX_X - AREA::FMIN_X) / 2, -120, 120);
			m_Boss_obj[1].boss.movePos(-350, -120, 120);
			m_Boss_obj[2].boss.movePos(AREA::FMAX_X + 350, -120, 120);
		}
		if (size > 3) {
			for (auto& obj : m_Boss_obj)obj.boss.movePos(-350, -120, 120);
		}
	}
	void BossManager::update() {
		if (m_Boss_obj.size() == 0)return;
		for (auto& obj : m_Boss_obj) {
			obj.boss.update();
			obj.magic_ring.update();
			obj.hp.update();
		}
		m_UI->update();
		if (m_Is_bullet) {
			//何でもない状態
			if (isState(PHASE::NONE)) {
				resetBossBulletFlag();
				for (auto& obj : m_Boss_obj)obj.boss.setAnimationType(0);
				loadScript();
				m_Script->start();
				if (m_Wait_time > 0) {
					m_State = PHASE::WAIT;
					for (auto& obj : m_Boss_obj)obj.hp.start(m_Wait_time);
					m_Time_max = m_Time;
				}
			}
			//弾幕待機中
			if (isState(PHASE::WAIT)) {
				m_Wait_time--;
				if (m_Wait_time < 0) {
					app::Replayer::GameRecorder.callSeedProcess(100);
					m_Bonus->initialize(m_Is_invincible, m_Boss_obj[0].boss.getType(), m_Bullet_type);
					m_Count = -1;
					m_State = PHASE::BULLET;
					m_Script->setBulletPhase();
				}
			}
			//弾幕モード
			if (isState(PHASE::BULLET)) {
				m_Bonus->setBulletLastTime(m_Time_max - m_Time);
				m_Script->update();
				for (auto& obj : m_Boss_obj) {
					obj.boss.collision(m_Is_invalid_bom);
					if (obj.boss .isDeathEffect() && obj.boss.getHP() < 0) {
						obj.boss.summonEffect(obj::Boss::EFFECT_TYPE::DEAD);
					}
				}
				countTimer();
				if (isOverParam()) {
					m_State = PHASE::END;
					m_Boss_obj[0].boss.movePos(AREA::DEF_BOSS_X, AREA::DEF_BOSS_Y, 40);
					for (auto& obj : m_Boss_obj) {
						obj.boss.statsReset();
						obj.hp.stop();
					}
				}
				m_Count++;
			}
			//弾幕を全部終わらせた状態
			if (isState(PHASE::END)) {
				m_Script->stop();
				m_Bonus->setBonusCall(m_Time);
				m_Bonus->dropItem();
				if (m_Bullet_type == m_End_bullet) {
					resetBossBulletFlag();
					for (auto& obj : m_Boss_obj)obj.magic_ring.stop();
					m_Is_bullet = false;
					m_Count = 0;
				}
				else {
					if (m_Is_need_all_kill)removeNoLife();
					changePosition();
					m_State = PHASE::NONE;
					m_Bullet_type++;
				}
				obj::BulletManager::getInstance()->clear(true);
			}
		}
		else if (m_Is_return_back) {
			if (m_Count == 60)returnBackPosition();
			m_Count++;
			if (m_Count == 120) {
				m_Count = 0;
				for (auto& obj : m_Boss_obj)obj.boss.setFlag(false);
				m_Is_return_back = false;
			}
		}
	}
	void BossManager::draw(double crush_x, double crush_y) {
		if (m_Boss_obj.size() == 0)return;
		for (auto& obj : m_Boss_obj) {
			obj.magic_ring.draw(obj.boss.getX(), obj.boss.getY(), crush_x, crush_y);
			obj.boss.draw(crush_x, crush_y);
		}
	}
	void BossManager::drawUI(double crush_x, double crush_y) {
		if (m_Boss_obj.size() == 0)return;
		for (auto& obj : m_Boss_obj) {
			if (obj.boss.isFlag()&& obj.boss.getHP()>0) {
				if (m_Is_bullet && !m_Is_invincible) {
					obj.hp.draw(obj.boss.getX(), obj.boss.getY(), crush_x, crush_y, obj.boss.getHPMax(), obj.boss.getHP());
				}
			}
		}
		if (m_Is_bullet) {
			m_UI->drawCounter(m_Time, (m_End_bullet - m_First_bullet), m_Bullet_type);
			m_UI->drawSerifBox();
		}
		m_Bonus->draw();
	}
	void BossManager::loadScript() {
		char* fp = new char[38];
		sprintf(fp, "./dat/Script/Bullet/Boss%d/at%d.lua", GameSceneProp::stage, m_Bullet_type);
		m_Script->loadFile(fp);
		delete[] fp;
	}
	void BossManager::countTimer() {
		if (m_Time < 999 * 60)m_Time--;
	}
	void BossManager::resetBossBulletFlag() {
		m_Is_invalid_bom = false;
		m_Is_invincible = false;
		m_Is_special_bullet = false;
		m_Is_need_all_kill = false;
	}
	void BossManager::setTimer(int time) {
		m_Time_max = time;
		m_Time = time;
	}
	void BossManager::setWaitTime(int time) {
		m_Wait_time = time;
	}
	void BossManager::setInvalidBom(bool flag) {
		m_Is_invalid_bom = flag;
	}
	void BossManager::setInvincible(bool flag) {
		m_Is_invincible = flag;
	}
	void BossManager::setSpecialBullet(bool flag) {
		m_Is_special_bullet = flag;
	}
	void BossManager::setReturnBack(bool flag) {
		m_Is_return_back = flag;
	}
	bool BossManager::isFlag() {
		return m_Is_bullet;
	}
	bool BossManager::isSpecialBullet() {
		return m_Is_special_bullet;
	}
	int BossManager::getTime() {
		return m_Time;
	}
	int BossManager::getCount() {
		return m_Count;
	}
	std::vector<BossManager::BossObj>& BossManager::getBossList() {
		return m_Boss_obj;
	}
	std::shared_ptr<obj::BossUI>& BossManager::getUIInstance() {
		return m_UI;
	}
	bool BossManager::isOverParam() {
		//<条件1>制限時間を過ぎていたら
		if(m_Time < 0)return true;
		if (m_Is_need_all_kill) {
			//<条件2>ボスが全部死んでいたら
			bool result = true;
			for (auto& obj : m_Boss_obj) {
				if (obj.boss.getHP() > 0)result = false;
			}
			if (result)return true;
		}
		else {
			//<条件3>ボスがどれか死んでいたら
			for (auto& obj : m_Boss_obj) {
				if (obj.boss.getHP() < 0)return true;
			}
		}
		return false;
	}
	bool BossManager::isState(int state) {
		if (m_State == state)return true;
		return false;
	}
}