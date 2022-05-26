#include "BossScript.h"
#include <iostream>
#include "../../Source/Object/Boss/Boss.h"
#include "../../Source/Manager/BossManager/BossManager.h"

namespace script {
	BossScript::BossInfo
		BossScript::m_Boss;
	BossScript::BossInfo
		BossScript::m_Boss_stats;
	BossScript::GetFlag
		BossScript::m_Get_flag;
	BossScript::Move
		BossScript::m_Move;
	BossScript::SerifInfo 
		BossScript::m_Serif;

	BossScript::BossScript(lua_State* L)
	{
		m_Get_flag.clear();
		m_Serif.clear();
		/*m_Boss.is_inv_bom = false;
		m_Boss.is_NoDamage = false;*/
		lua_register(L, "BossFunc", callFunction);
	}

	int BossScript::callFunction(lua_State* L) {
		const char* str = lua_tostring(L, -1);
		if (!strcmp(str, "Func:X"))l_x(L);
		if (!strcmp(str, "Func:Y"))l_y(L);
		if (!strcmp(str, "Func:WaitTime"))l_waitTime(L);
		if (!strcmp(str, "Func:InitTime"))l_initTime(L);
		if (!strcmp(str, "Func:InitHP"))l_initHP(L);
		if (!strcmp(str, "Func:Time"))l_time(L);
		if (!strcmp(str, "Func:HP"))l_hp(L);
		if (!strcmp(str, "Func:IsLast"))l_isLast(L);
		if (!strcmp(str, "Func:IsMainBullet"))l_isMainBullet(L);
		if (!strcmp(str, "Func:NoDamage"))l_isNoDamage(L);
		if (!strcmp(str, "Func:moveFlag"))l_moveFlag(L);
		if (!strcmp(str, "Func:moveRandFlag"))l_moveRandFlag(L);
		if (!strcmp(str, "Func:setMove"))l_setMove(L);
		if (!strcmp(str, "Func:SetRandMove"))l_setRandomMove(L);
		if (!strcmp(str, "Func:Charge"))l_charge(L);
		if (!strcmp(str, "Func:SetDeathEffect"))l_DeathEffect(L);
		if (!strcmp(str, "Func:BulletState"))l_bulletState(L);
		if (!strcmp(str, "Func:MotionType"))l_MotionType(L);
		if (!strcmp(str, "Func:SerifBox"))l_SerifBox(L);
		if (!strcmp(str, "Func:NoDelMinion"))l_isNoDelMinon(L);
		if (!strcmp(str, "Func:InvalidBom"))l_isInvBom(L);
		return 1;
	}

	int BossScript::l_x(lua_State* L) {
		int index = lua_tonumber(L, -2);
		auto& boss = manager::BossManager::getInstance()->getBossList()[index].boss;
		if (lua_toboolean(L, -3)) {
			float x = lua_tonumber(L, -4);
			boss.setX(x);
			//m_Boss.x = x;
			//m_Get_flag.x = true;
		}
		else {

			lua_pushnumber(L, boss.getX());
		}
		return 1;
	}
	int BossScript::l_y(lua_State* L) {
		int index = lua_tonumber(L, -2);
		auto& boss = manager::BossManager::getInstance()->getBossList()[index].boss;
		if (lua_toboolean(L, -3)) {
			float y = lua_tonumber(L, -4);
			boss.setX(y);
			//m_Get_flag.y = true;
		}
		else {
			lua_pushnumber(L, boss.getY());
		}
		return 1;
	}
	int BossScript::l_initHP(lua_State* L) {
		int index = lua_tonumber(L, -2);
		auto& boss = manager::BossManager::getInstance()->getBossList()[index].boss;
		if (!lua_toboolean(L, -3))return 0;
		int hp = lua_tonumber(L, -4);
		boss.setHPMax(hp);
		boss.setHP(hp);
		//m_Boss.init_hp = hp;
		return 1;
	}
	int BossScript::l_hp(lua_State* L) {
		int index = lua_tonumber(L, -2);
		auto& boss = manager::BossManager::getInstance()->getBossList()[index].boss;
		if (lua_toboolean(L, -3)) {
			int hp = lua_tonumber(L, -4);
			boss.setHP(hp);
			//m_Get_flag.hp = true;
		}
		else {
			lua_pushnumber(L, boss.getHP());
		}
		return 1;
	}
	int BossScript::l_setMove(lua_State* L) {
		int index = lua_tonumber(L, -2);
		auto& boss = manager::BossManager::getInstance()->getBossList()[index].boss;
		float px = lua_tonumber(L, -5);
		float py = lua_tonumber(L, -4);
		float time = lua_tonumber(L, -3);
		boss.movePos(px, py, time);
		return 1;
	}
	int BossScript::l_setRandomMove(lua_State* L) {
		int index = lua_tonumber(L, -2);
		auto& boss = manager::BossManager::getInstance()->getBossList()[index].boss;
		float x0 = lua_tonumber(L, -8);
		float y0 = lua_tonumber(L, -7);
		float x1 = lua_tonumber(L, -6);
		float y1 = lua_tonumber(L, -5);
		float dist = lua_tonumber(L, -4);
		int time = lua_tonumber(L, -3);
		boss.moveRand(x0, y0, x1, y1, dist, time);
		return 1;
	}
	int BossScript::l_MotionType(lua_State* L) {
		int index = lua_tonumber(L, -2);
		auto& boss = manager::BossManager::getInstance()->getBossList()[index].boss;
		int type = lua_tonumber(L, -3);
		boss.setAnimationType(type);
		//m_Boss.motion_type = type;
		//m_Get_flag.motion_type = true;
		return 1;
	}
	int BossScript::l_charge(lua_State* L) {
		int index = lua_tonumber(L, -2);
		auto& boss = manager::BossManager::getInstance()->getBossList()[index].boss;
		boss.summonEffect(obj::Boss::EFFECT_TYPE::CHARGE);
		return 1;
	}
	int BossScript::l_DeathEffect(lua_State* L) {
		int index = lua_tonumber(L, -2);
		auto& boss = manager::BossManager::getInstance()->getBossList()[index].boss;
		bool flag = lua_toboolean(L, -3);
		boss.setDeathEffect(flag);
		return 1;
	}



	int BossScript::l_initTime(lua_State* L) {
		if (!lua_toboolean(L, -2))return 0;
		float time = lua_tonumber(L, -3);
		//m_Boss.init_time = time;
		return 1;
	}
	int BossScript::l_time(lua_State* L) {
		if (lua_toboolean(L, -2)) {
			float time = lua_tonumber(L, -3);
			m_Boss.time = time;
			m_Get_flag.time = true;
		}
		else {
			lua_pushnumber(L, m_Boss_stats.time);
		}
		return 1;
	}
	int BossScript::l_waitTime(lua_State* L) {
		if (lua_toboolean(L, -2)) {
			float wt = lua_tonumber(L, -3);
			m_Boss.wait_time = wt;
			m_Get_flag.wait_time = true;
		}
		else {
			lua_pushnumber(L, m_Boss_stats.wait_time);
		}
		return 1;
	}
	int BossScript::l_isLast(lua_State* L) {
		if (lua_toboolean(L, -2)) {
			bool flag = lua_toboolean(L, -3);
			m_Boss.is_last = flag;
			m_Get_flag.is_last = true;
		}
		else {
			lua_pushnumber(L, m_Boss_stats.wait_time);
		}
		return 1;
	}
	int BossScript::l_isNoDamage(lua_State* L) {
		bool flag = lua_toboolean(L, -3);
		m_Boss.is_NoDamage = flag;
		m_Get_flag.is_NoDamage = true;
		return 1;
	}
	int BossScript::l_moveFlag(lua_State* L) {

		m_Move.flag = true;
		return 1;
	}
	int BossScript::l_moveRandFlag(lua_State* L) {
		m_Move.flag_rand = true;
		return 1;
	}
	int BossScript::l_bulletState(lua_State* L) {
		if (lua_toboolean(L, -2)) {
			int state = lua_tonumber(L, -3);
			m_Boss.bullet_state = state;
			m_Get_flag.bullet_state = true;
		}
		else {
			lua_pushnumber(L, m_Boss_stats.bullet_state);
		}
		return 1;
	}
	int BossScript::l_SerifBox(lua_State* L) {
		m_Serif.x = lua_tonumber(L, -5);
		m_Serif.y = lua_tonumber(L, -4);
		m_Serif.time = lua_tonumber(L, -3);
		m_Serif.text = lua_tostring(L, -2);
		m_Serif.flag = true;
		return 1;
	}
	int BossScript::l_isNoDelMinon(lua_State* L) {
		m_Boss.is_no_del_minion = lua_toboolean(L, -2);
		return 1;
	}
	int BossScript::l_isMainBullet(lua_State* L) {
		m_Boss.is_main_bullet = true;
		m_Get_flag.is_main_bullet = true;
		return 1;
	}
	int BossScript::l_isInvBom(lua_State* L) {
		m_Boss.is_inv_bom = true;
		return 1;
	}
	void BossScript::setInfo(float x, float y, int wait_time, int time, int hp, int state) {
		m_Boss_stats.x = x;
		m_Boss_stats.y = y;
		m_Boss_stats.wait_time = wait_time;
		m_Boss_stats.time = time;
		m_Boss_stats.hp = hp;
		m_Boss_stats.bullet_state = state;
	}

	float BossScript::getPos_x() {
		m_Get_flag.x = false;
		return m_Boss.x;
	}
	float BossScript::getPos_y() {
		m_Get_flag.y = false;
		return m_Boss.y;
	}
	int BossScript::initTime() {
		return m_Boss.init_time * 60;
	}
	int BossScript::initHP() {
		return m_Boss.init_hp;
	}
	int BossScript::getTime() {
		m_Get_flag.time = false;
		return m_Boss.time * 60;
	}
	int BossScript::getHP() {
		m_Get_flag.hp = false;
		return m_Boss.hp;
	}
	int BossScript::getWaitTime() {
		m_Get_flag.wait_time = false;
		return m_Boss.wait_time * 60;
	}
	bool BossScript::isLast() {
		m_Get_flag.is_last = false;
		return m_Boss.is_last;
	}
	bool BossScript::isNoDamage() {
		m_Get_flag.is_NoDamage = false;
		return m_Boss.is_NoDamage;
	}
	bool BossScript::isMove() {
		return m_Move.flag;
	}
	bool BossScript::isMoveRand() {
		return m_Move.flag_rand;
	}
	bool BossScript::isCharge() {
		if (m_Boss.is_charge) {
			m_Boss.is_charge = false;
			return true;
		}
		return false;
	}
	BossScript::BossInfo& BossScript::getInputData() {
		return m_Boss;
	}
	BossScript::GetFlag& BossScript::isGetValue() {
		return m_Get_flag;
	}
	BossScript::Move& BossScript::getParam() {
		m_Move.flag = false;
		m_Move.flag_rand = false;
		return m_Move;
	}
	BossScript::SerifInfo& BossScript::getSerifUI() {
		return m_Serif;
	}
}