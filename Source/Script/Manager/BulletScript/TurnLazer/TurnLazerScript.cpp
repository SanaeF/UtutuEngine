#include "TurnLazerScript.h"
#include <iostream>

#include "../../Source/Object/Bullet/TurnLazer/TurnLazer_Info.h"
#include "../../Source/Manager/BulletManager/BulletManager.h"

namespace script {
	bool TurnLazerScript::m_Is_bullet_phase = false;
	int TurnLazerScript::m_Object_num = 0;
	int TurnLazerScript::m_Shot_spawned_max = 0;
	TurnLazerScript::TurnLazerScript()
	{
		m_Shot_spawned_max = 0;
	}
	void TurnLazerScript::createScript(lua_State* L, bool rock_script) {
		m_Shot_spawned_max = 0;
		lua_register(L, "T_LazFunc", callFunction);
		lua_pushnumber(L, obj::T_LAZ_NUM_MAX);
		lua_setglobal(L, "getT_Laz_max");
		if (rock_script)m_Is_bullet_phase = false;
	}
	void TurnLazerScript::setUpdatePhase() {
		m_Is_bullet_phase = true;
	}
	int TurnLazerScript::callFunction(lua_State* L) {
		const char* str = lua_tostring(L, -4);
		if (!strcmp(str, "Func:Number"))l_Number(L);
		if (!strcmp(str, "Func:Search"))l_Search(L);
		if (!strcmp(str, "Func:Default"))l_Default(L);
		if (!strcmp(str, "Func:Flag"))l_Flag(L);
		if (!strcmp(str, "Func:X"))l_PosX(L);
		if (!strcmp(str, "Func:Y"))l_PosY(L);
		if (!strcmp(str, "Func:Color"))l_Color(L);
		if (!strcmp(str, "Func:Length"))l_Length(L);
		if (!strcmp(str, "Func:Speed"))l_Speed(L);
		if (!strcmp(str, "Func:Angle"))l_Angle(L);
		if (!strcmp(str, "Func:Count"))l_Count(L);
		if (!strcmp(str, "Func:State1"))l_State(L);
		if (!strcmp(str, "Func:State2"))l_State2(L);
		if (!strcmp(str, "Func:Bound"))l_Bound(L);
		if (!strcmp(str, "Func:BoundArea"))l_Bound_Area(L);
		if (!strcmp(str, "Func:Who"))l_Who(L);
		return 1;
	}
	int TurnLazerScript::l_Default(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& t_las = obj::BulletManager::getInstance()->getTurnLaser();
		if (num >= t_las.size())return 1;
		if (isCanInput())t_las[num].setDefault();
		return 1;
	}
	int TurnLazerScript::l_Number(lua_State* L) {
		if (lua_toboolean(L, -1)) {
			m_Object_num = lua_tonumber(L, -2);
		}
		else {
			lua_pushnumber(L, m_Object_num);
		}
		return 1;
	}
	//‘æ4ˆø”(true = Setter ,false = Getter)
	int TurnLazerScript::l_Flag(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& t_las = obj::BulletManager::getInstance()->getTurnLaser();
		if (num >= t_las.size())return 1;
		if (lua_toboolean(L, -1)) {
			bool flag = lua_toboolean(L, -2);
			if (isCanInput())t_las[num].setFlag(flag);
		}
		else {
			lua_pushboolean(L, t_las[num].isFlag());
		}
		return 1;
	}
	int TurnLazerScript::l_PosX(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& t_las = obj::BulletManager::getInstance()->getTurnLaser();
		if (num >= t_las.size())return 1;
		if (lua_toboolean(L, -1)) {
			double x = lua_tonumber(L, -2);
			if (isCanInput())t_las[num].setX(x);
		}
		else {
			lua_pushnumber(L, t_las[num].getX());
		}
		return 1;
	}
	int TurnLazerScript::l_PosY(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& t_las = obj::BulletManager::getInstance()->getTurnLaser();
		if (num >= t_las.size())return 1;
		if (lua_toboolean(L, -1)) {
			double y = lua_tonumber(L, -2);
			if (isCanInput())t_las[num].setY(y);
		}
		else {
			lua_pushnumber(L, t_las[num].getY());
		}
		return 1;
	}
	int TurnLazerScript::l_Angle(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& t_las = obj::BulletManager::getInstance()->getTurnLaser();
		if (num >= t_las.size())return 1;
		if (lua_toboolean(L, -1)) {
			double m_Angle = lua_tonumber(L, -2);
			if (isCanInput())t_las[num].setAngle(m_Angle);
		}
		else {
			lua_pushnumber(L, t_las[num].getAngle());
		}
		return 1;
	}
	int TurnLazerScript::l_Speed(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& t_las = obj::BulletManager::getInstance()->getTurnLaser();
		if (num >= t_las.size())return 1;
		if (lua_toboolean(L, -1)) {
			double speed = lua_tonumber(L, -2);
			if (isCanInput())t_las[num].setSpeed(speed);
		}
		else {
			lua_pushnumber(L, t_las[num].getSpeed());
		}
		return 1;
	}
	int TurnLazerScript::l_Length(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& t_las = obj::BulletManager::getInstance()->getTurnLaser();
		if (num >= t_las.size())return 1;
		if (lua_toboolean(L, -1)) {
			int type = static_cast<int>(lua_tonumber(L, -2));
			if (isCanInput())t_las[num].setLength(type);
		}
		else {
			//lua_pushnumber(L, mT_Laz[num].get_Length());
		}
		return 1;
	}
	int TurnLazerScript::l_Color(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& t_las = obj::BulletManager::getInstance()->getTurnLaser();
		if (num >= t_las.size())return 1;
		if (lua_toboolean(L, -1)) {
			int color = static_cast<int>(lua_tonumber(L, -2));
			if (isCanInput())t_las[num].setColor(color);
		}
		else {
			lua_pushnumber(L, t_las[num].getColor());
		}
		return 1;
	}
	int TurnLazerScript::l_Count(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& t_las = obj::BulletManager::getInstance()->getTurnLaser();
		if (num >= t_las.size())return 1;
		if (lua_toboolean(L, -1)) {
			int count = static_cast<int>(lua_tonumber(L, -2));
			if (isCanInput())t_las[num].setCount(count);
		}
		else {
			lua_pushnumber(L, t_las[num].getCount());
		}
		return 1;
	}
	int TurnLazerScript::l_State(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& t_las = obj::BulletManager::getInstance()->getTurnLaser();
		if (num >= t_las.size())return 1;
		if (lua_toboolean(L, -1)) {
			int state = static_cast<int>(lua_tonumber(L, -2));
			if (isCanInput())t_las[num].setState(state);
		}
		else {
			lua_pushnumber(L, t_las[num].getState());
		}
		return 1;
	}
	int TurnLazerScript::l_State2(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& t_las = obj::BulletManager::getInstance()->getTurnLaser();
		if (num >= t_las.size())return 1;
		if (lua_toboolean(L, -1)) {
			int state = static_cast<int>(lua_tonumber(L, -2));
			if (isCanInput())t_las[num].setStateSub(state);
		}
		else {
			lua_pushnumber(L, t_las[num].getStateSub());
		}
		return 1;
	}
	int TurnLazerScript::l_Bound(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& t_las = obj::BulletManager::getInstance()->getTurnLaser();
		if (num >= t_las.size())return 1;
		if (lua_toboolean(L, -1)) {
			bool bound = lua_toboolean(L, -2);
			if (isCanInput())t_las[num].setBound(bound);
		}
		else {
			lua_pushboolean(L, t_las[num].isBound());
		}
		return 1;
	}
	int TurnLazerScript::l_Who(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& t_las = obj::BulletManager::getInstance()->getTurnLaser();
		if (num >= t_las.size())return 1;
		if (lua_toboolean(L, -1)) {
			int who = lua_tonumber(L, -2);
			if (isCanInput())t_las[num].setRayer(who);
		}
		else {
			lua_pushnumber(L, t_las[num].getRayer());
		}
		return 1;
	}
	//ˆø”(true = Get Area ,false = Get Count)
	int TurnLazerScript::l_Bound_Area(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& t_las = obj::BulletManager::getInstance()->getTurnLaser();
		if (num >= t_las.size())return 1;
		if (lua_toboolean(L, -1)) {
			lua_pushnumber(L, t_las[num].getBoundArea());
		}
		else {
			lua_pushnumber(L, t_las[num].getBoundCount());
		}
		return 1;
	}
	int TurnLazerScript::l_Search(lua_State* L) {
		auto& t_las = obj::BulletManager::getInstance()->getTurnLaser();
		for (int i = 0; i < t_las.size(); i++) {
			if (!t_las[i].isFlag()) {
				if (m_Shot_spawned_max < i)m_Shot_spawned_max = i;
				lua_pushnumber(L, i);
				return 1;
			}
		}
		return 0;
	}
	bool TurnLazerScript::isCanInput() {
		if (!m_Is_bullet_phase)return false;
		return true;
	}

}