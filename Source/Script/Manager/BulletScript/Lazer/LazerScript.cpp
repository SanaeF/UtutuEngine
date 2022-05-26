#include "LazerScript.h"
#include <iostream>

#include "../../Source/Object/Bullet/Lazer/Lazer_Info.h"
#include "../../Source/Manager/BulletManager/BulletManager.h"

namespace script {
	bool LazerScript::m_Is_bullet_phase = false;
	int LazerScript::m_Object_num = 0;
	int LazerScript::m_Shot_spawned_max = 0;
	LazerScript::LazerScript()
	{
		m_Shot_spawned_max = 0;
	}
	void LazerScript::createScript(lua_State* L, bool rock_script) {
		m_Shot_spawned_max = 0;
		lua_register(L, "LazerFunc", callFunction);
		lua_pushnumber(L, obj::LAZER_NUM_MAX);
		lua_setglobal(L, "getLazer_max");
		if(rock_script)m_Is_bullet_phase = false;
	}
	void LazerScript::setUpdatePhase() {
		m_Is_bullet_phase = true;
	}
	int LazerScript::callFunction(lua_State* L) {
		const char* str = lua_tostring(L, -4);
		if (!strcmp(str, "Func:Number"))l_Number(L);
		if (!strcmp(str, "Func:Search"))l_Search(L);
		if (!strcmp(str, "Func:Default"))l_Default(L);
		if (!strcmp(str, "Func:Flag"))l_Flag(L);
		if (!strcmp(str, "Func:X"))l_PosX(L);
		if (!strcmp(str, "Func:Y"))l_PosY(L);
		if (!strcmp(str, "Func:Color"))l_Color(L);
		if (!strcmp(str, "Func:Type"))l_Type(L);
		if (!strcmp(str, "Func:MainColor"))l_MainColor(L);
		if (!strcmp(str, "Func:MainType"))l_MainType(L);
		if (!strcmp(str, "Func:Speed"))l_Speed(L);
		if (!strcmp(str, "Func:Angle"))l_Angle(L);
		if (!strcmp(str, "Func:LengthAngle"))l_LengthAngle(L);
		if (!strcmp(str, "Func:Count"))l_Count(L);
		if (!strcmp(str, "Func:State1"))l_State(L);
		if (!strcmp(str, "Func:State2"))l_State2(L);
		if (!strcmp(str, "Func:Thick"))l_Thick(L);
		if (!strcmp(str, "Func:Length"))l_Length(L);
		if (!strcmp(str, "Func:Collision"))l_Collision(L);
		if (!strcmp(str, "Func:Bound"))l_Bound(L);
		if (!strcmp(str, "Func:BoundArea"))l_Bound_Area(L);
		if (!strcmp(str, "Func:BoundNoAngle"))l_BoundNoAngle(L);
		if (!strcmp(str, "Func:NoDelete"))l_NoDelete(L);
		if (!strcmp(str, "Func:Who"))l_Who(L);
		return 1;
	}
	int LazerScript::l_Default(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& lazer = obj::BulletManager::getInstance()->getLaser();
		if (num >= lazer.size())return 1;
		if (isCanInput())lazer[num].setDefault();
		return 1;
	}
	int LazerScript::l_Number(lua_State* L) {
		m_Object_num = lua_tonumber(L, -2);
		return 1;
	}
	//‘æ“ñˆø”(true = Setter ,false = Getter)
	int LazerScript::l_Flag(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& lazer = obj::BulletManager::getInstance()->getLaser();
		if (num >= lazer.size())return 1;
		if (lua_toboolean(L, -1)) {
			bool flag = lua_toboolean(L, -2);
			if (isCanInput())lazer[num].setFlag(flag);
		}
		else {
			lua_pushboolean(L, lazer[num].isFlag());
		}
		return 1;
	}
	int LazerScript::l_PosX(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& lazer = obj::BulletManager::getInstance()->getLaser();
		if (num >= lazer.size())return 1;
		if (lua_toboolean(L, -1)) {
			double x = lua_tonumber(L, -2);
			if (isCanInput())lazer[num].setX(x);
		}
		else {
			lua_pushnumber(L, lazer[num].getX());
		}
		return 1;
	}
	int LazerScript::l_PosY(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& lazer = obj::BulletManager::getInstance()->getLaser();
		if (num >= lazer.size())return 1;
		if (lua_toboolean(L, -1)) {
			double y = lua_tonumber(L, -2);
			if (isCanInput())lazer[num].setY(y);
		}
		else {
			lua_pushnumber(L, lazer[num].getY());
		}
		return 1;
	}
	int LazerScript::l_Size(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& lazer = obj::BulletManager::getInstance()->getLaser();
		if (num >= lazer.size())return 1;
		if (lua_toboolean(L, -1)) {
			double size = lua_tonumber(L, -2);
			if (isCanInput())lazer[num].setSize(size);
		}
		else {
			lua_pushnumber(L, lazer[num].getSize());
		}
		return 1;
	}
	int LazerScript::l_Angle(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& lazer = obj::BulletManager::getInstance()->getLaser();
		if (num >= lazer.size())return 1;
		if (lua_toboolean(L, -1)) {
			double m_Angle = lua_tonumber(L, -2);
			if (isCanInput())lazer[num].setAngle(m_Angle);
		}
		else {
			lua_pushnumber(L, lazer[num].getAngle());
		}
		return 1;
	}
	int LazerScript::l_LengthAngle(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& lazer = obj::BulletManager::getInstance()->getLaser();
		if (num >= lazer.size())return 1;
		if (lua_toboolean(L, -1)) {
			double m_Angle = lua_tonumber(L, -2);
			if (isCanInput())lazer[num].setLengthAngle(m_Angle);
		}
		else {
			lua_pushnumber(L, lazer[num].getLengthAngle());
		}
		return 1;
	}
	int LazerScript::l_Speed(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& lazer = obj::BulletManager::getInstance()->getLaser();
		if (num >= lazer.size())return 1;
		if (lua_toboolean(L, -1)) {
			double speed = lua_tonumber(L, -2);
			if (isCanInput())lazer[num].setSpeed(speed);
		}
		else {
			lua_pushnumber(L, lazer[num].getSpeed());
		}
		return 1;
	}
	int LazerScript::l_Type(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& lazer = obj::BulletManager::getInstance()->getLaser();
		if (num >= lazer.size())return 1;
		if (lua_toboolean(L, -1)) {
			int type = lua_tonumber(L, -2);
			if (isCanInput())lazer[num].setType(type);
		}
		else {
			lua_pushnumber(L, lazer[num].getType());
		}
		return 1;
	}
	int LazerScript::l_Color(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& lazer = obj::BulletManager::getInstance()->getLaser();
		if (num >= lazer.size())return 1;
		if (lua_toboolean(L, -1)) {
			int color = lua_tonumber(L, -2);
			if (isCanInput())lazer[num].setColor(color);
		}
		else {
		lua_pushnumber(L, lazer[num].getColor());
		}
		return 1;
	}
	int LazerScript::l_MainColor(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& lazer = obj::BulletManager::getInstance()->getLaser();
		if (num >= lazer.size())return 1;
		if (lua_toboolean(L, -1)) {
			int color = lua_tonumber(L, -2);
			if (isCanInput())lazer[num].setMainColor(color);
		}
		else {
			lua_pushnumber(L, lazer[num].getMainColor());
		}
		return 1;
	}
	int LazerScript::l_MainType(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& lazer = obj::BulletManager::getInstance()->getLaser();
		if (num >= lazer.size())return 1;
		if (lua_toboolean(L, -1)) {
			int type = lua_tonumber(L, -2);
			if (isCanInput())lazer[num].setMainType(type);
		}
		else {
			lua_pushnumber(L, lazer[num].getMainType());
		}
		return 1;
	}
	int LazerScript::l_Count(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& lazer = obj::BulletManager::getInstance()->getLaser();
		if (num >= lazer.size())return 1;
		if (lua_toboolean(L, -1)) {
			int count = lua_tonumber(L, -2);
			if (isCanInput())lazer[num].setCount(count);
		}
		else {
			lua_pushnumber(L, lazer[num].getCount());
		}
		return 1;
	}
	int LazerScript::l_State(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& lazer = obj::BulletManager::getInstance()->getLaser();
		if (num >= lazer.size())return 1;
		if (lua_toboolean(L, -1)) {
			int state = lua_tonumber(L, -2);
			if (isCanInput())lazer[num].setState(state);
		}
		else {
			lua_pushnumber(L, lazer[num].getState());
		}
		return 1;
	}
	int LazerScript::l_State2(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& lazer = obj::BulletManager::getInstance()->getLaser();
		if (num >= lazer.size())return 1;
		if (lua_toboolean(L, -1)) {
			int state = lua_tonumber(L, -2);
			if (isCanInput())lazer[num].setStateSub(state);
		}
		else {
			lua_pushnumber(L, lazer[num].getStateSub());
		}
		return 1;
	}
	int LazerScript::l_Collision(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& lazer = obj::BulletManager::getInstance()->getLaser();
		if (num >= lazer.size())return 1;
		if (lua_toboolean(L, -1)) {
			bool rota = lua_toboolean(L, -2);
			if (isCanInput())lazer[num].set_collision(rota);
		}
		else {
			lua_pushboolean(L, lazer[num].isCollision());
		}
		return 1;
	}
	int LazerScript::l_Shine(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& lazer = obj::BulletManager::getInstance()->getLaser();
		if (num >= lazer.size())return 1;
		if (lua_toboolean(L, -1)) {
			bool shine = lua_toboolean(L, -2);
			if (isCanInput())lazer[num].setShine(shine);
		}
		else {
			lua_pushboolean(L, lazer[num].isShine());
		}
		return 1;
	}
	int LazerScript::l_Bound(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& lazer = obj::BulletManager::getInstance()->getLaser();
		if (num >= lazer.size())return 1;
		if (lua_toboolean(L, -1)) {
			bool bound = lua_toboolean(L, -2);
			if (isCanInput())lazer[num].setBound(bound);
		}
		else {
			lua_pushboolean(L, lazer[num].isBound());
		}
		return 1;
	}
	int LazerScript::l_Who(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& lazer = obj::BulletManager::getInstance()->getLaser();
		if (num >= lazer.size())return 1;
		if (lua_toboolean(L, -1)) {
			int who = lua_tonumber(L, -2);
			if (isCanInput())lazer[num].setRayer(who);
		}
		else {
			lua_pushnumber(L, lazer[num].getRayer());
		}
		return 1;
	}
	//ˆø”(true = Get Area ,false = Get Count)
	int LazerScript::l_Bound_Area(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& lazer = obj::BulletManager::getInstance()->getLaser();
		if (num >= lazer.size())return 1;
		if (lua_toboolean(L, -1)) {
			lua_pushnumber(L, lazer[num].getBoundArea());
		}
		else {
			lua_pushnumber(L, lazer[num].getBoundCount());
		}
		return 1;
	}
	int LazerScript::l_BoundNoAngle(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& lazer = obj::BulletManager::getInstance()->getLaser();
		if (num >= lazer.size())return 1;
		if (lua_toboolean(L, -1)) {
			bool no_bound_angle = lua_toboolean(L, -2);
			if (isCanInput())lazer[num].setBoundNoAngle(no_bound_angle);
		}
		else {
		}
		return 1;
	}
	int LazerScript::l_Thick(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& lazer = obj::BulletManager::getInstance()->getLaser();
		if (num >= lazer.size())return 1;
		if (lua_toboolean(L, -1)) {
			float thick = lua_tonumber(L, -2);
			if (isCanInput())lazer[num].setThick(thick);
		}
		else {
			lua_pushnumber(L, lazer[num].getThick());
		}
		return 1;
	}
	int LazerScript::l_Length(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& lazer = obj::BulletManager::getInstance()->getLaser();
		if (num >= lazer.size())return 1;
		if (lua_toboolean(L, -1)) {
			float length = lua_tonumber(L, -2);
			if (isCanInput())lazer[num].setLength(length);
		}
		else {
			lua_pushnumber(L, lazer[num].getLength());
		}
		return 1;
	}
	int LazerScript::l_NoDelete(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& lazer = obj::BulletManager::getInstance()->getLaser();
		if (num >= lazer.size())return 1;
		if (lua_toboolean(L, -1)) {
			bool is_no_delete = lua_toboolean(L, -2);
			if (isCanInput())lazer[num].setNoDelete(is_no_delete);
		}
		else {
			lua_pushnumber(L, lazer[num].isNoDelete());
		}
		return 1;
	}
	int LazerScript::l_Search(lua_State* L) {
		auto& lazer = obj::BulletManager::getInstance()->getLaser();
		for (int i = 0; i < lazer.size(); i++) {
			if (!lazer[i].isFlag()) {
				if (m_Shot_spawned_max < i)m_Shot_spawned_max = i;
				lua_pushnumber(L, i);
				return 1;
			}
		}
		return 1;
	}
	bool LazerScript::isCanInput() {
		if (!m_Is_bullet_phase)return false;
		return true;
	}
}