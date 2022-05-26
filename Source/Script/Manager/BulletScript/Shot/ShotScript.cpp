#include "ShotScript.h"
#include <iostream>
#include <thread>
#include "../../Source/Object/Bullet/Shot/Shot_Info.h"
#include "../../Source/SystemProp/AliceProp/AliceProp.h"
#include "../../Source/Manager/BulletManager/BulletManager.h"

namespace script {
	bool ShotScript::m_Is_bullet_phase = false;
	int ShotScript::m_Object_num = 0;
	int ShotScript::m_Shot_spawned_max = 0;

	ShotScript::ShotScript() {
		m_Shot_spawned_max = 0;
	}
	void ShotScript::createScript(lua_State* L, bool rock_script)
	{
		m_Shot_spawned_max = 0;
		lua_register(L, "ShotFunc", callFunction);
		lua_pushnumber(L, obj::BULLET_NUM_MAX);
		lua_setglobal(L, "getShot_max");
		if (rock_script)m_Is_bullet_phase = false;
	}
	void ShotScript::setUpdatePhase() {
		m_Is_bullet_phase = true;
	}
	int ShotScript::getShotSpawnedMax() {
		return m_Shot_spawned_max;
	}
	int ShotScript::callFunction(lua_State* L) {
		const char* str = lua_tostring(L, -4);
		if (str == nullptr)return 1;
		if (!strcmp(str, "Func:Number"))l_Number(L);
		if (!strcmp(str, "Func:Search"))l_Search(L);
		if (!strcmp(str, "Func:Default"))l_Default(L);
		if (!strcmp(str, "Func:Flag"))l_Flag(L);
		if (!strcmp(str, "Func:X"))l_PosX(L);
		if (!strcmp(str, "Func:Y"))l_PosY(L);
		if (!strcmp(str, "Func:Size"))l_Size(L);
		if (!strcmp(str, "Func:Color"))l_Color(L);
		if (!strcmp(str, "Func:Type"))l_Type(L);
		if (!strcmp(str, "Func:Speed"))l_Speed(L);
		if (!strcmp(str, "Func:Angle"))l_Angle(L);
		if (!strcmp(str, "Func:Count"))l_Count(L);
		if (!strcmp(str, "Func:State1"))l_State(L);
		if (!strcmp(str, "Func:State2"))l_State2(L);
		if (!strcmp(str, "Func:Rota"))l_Rota(L);
		if (!strcmp(str, "Func:Shine"))l_Shine(L);
		if (!strcmp(str, "Func:Bound"))l_Bound(L);
		if (!strcmp(str, "Func:BoundArea"))l_Bound_Area(L);
		if (!strcmp(str, "Func:BoundCount"))l_Bound_Count(L);
		if (!strcmp(str, "Func:Hide"))l_Hide(L);
		if (!strcmp(str, "Func:NoDelete"))l_NoDelete(L);
		if (!strcmp(str, "Func:Who"))l_Who(L);
		return 1;
	}
	int ShotScript::l_Default(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& shot = obj::BulletManager::getInstance()->getShot();
		if (num >= shot.size())return 1;
		if (isCanInput())shot[num].setDefault();
		return 1;
	}
	int ShotScript::l_Number(lua_State* L) {
		if (lua_toboolean(L, -1)) {
			m_Object_num = lua_tonumber(L, -2);
		}
		else {
			lua_pushnumber(L, m_Object_num);
		}
		return 1;
	}
	//‘æ4ˆø”(true = Setter ,false = Getter)
	int ShotScript::l_Flag(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& shot = obj::BulletManager::getInstance()->getShot();
		if (num >= shot.size())return 1;
		if (lua_toboolean(L, -1)) {
			bool flag = lua_toboolean(L, -2);
			if (isCanInput())shot[num].setFlag(flag);
		}
		else {
			lua_pushboolean(L, shot[num].isFlag());
		}
		return 1;
	}
	int ShotScript::l_PosX(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& shot = obj::BulletManager::getInstance()->getShot();
		if (num >= shot.size())return 1;
		if (lua_toboolean(L, -1)) {
			double x = lua_tonumber(L, -2);
			if (isCanInput())shot[num].setX(x);
		}
		else {
			lua_pushnumber(L, shot[num].getX());
		}
		return 1;
	}
	int ShotScript::l_PosY(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& shot = obj::BulletManager::getInstance()->getShot();
		if (num >= shot.size())return 1;
		if (lua_toboolean(L, -1)) {
			double y = lua_tonumber(L, -2);
			if (isCanInput())shot[num].setY(y);
		}
		else {
			lua_pushnumber(L, shot[num].getY());
		}
		return 1;
	}
	int ShotScript::l_Size(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& shot = obj::BulletManager::getInstance()->getShot();
		if (num >= shot.size())return 1;
		if (lua_toboolean(L, -1)) {
			double size = lua_tonumber(L, -2);
			if (isCanInput())shot[num].setSize(size);
		}
		else {
			lua_pushnumber(L, shot[num].getSize());
		}
		return 1;
	}
	int ShotScript::l_Angle(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& shot = obj::BulletManager::getInstance()->getShot();
		if (num >= shot.size())return 1;
		if (lua_toboolean(L, -1)) {
			double m_Angle = lua_tonumber(L, -2);
			if (isCanInput())shot[num].setAngle(m_Angle);
		}
		else {
			lua_pushnumber(L, shot[num].getAngle());
		}
		return 1;
	}
	int ShotScript::l_Speed(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& shot = obj::BulletManager::getInstance()->getShot();
		if (num >= shot.size())return 1;
		if (lua_toboolean(L, -1)) {
			double speed = lua_tonumber(L, -2);
			if (AliceProp::flag && shot[num].getCount() == 0)speed = speed * AliceProp::add_speed;
			if (isCanInput())shot[num].setSpeed(speed);
		}
		else {
			lua_pushnumber(L, shot[num].getSpeed());
		}
		return 1;
	}
	int ShotScript::l_Type(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& shot = obj::BulletManager::getInstance()->getShot();
		if (num >= shot.size())return 1;
		if (lua_toboolean(L, -1)) {
			int type = static_cast<int>(lua_tonumber(L, -2));
			if (isCanInput())shot[num].setType(type);
		}
		else {
			lua_pushnumber(L, shot[num].getType());
		}
		return 1;
	}
	int ShotScript::l_Color(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& shot = obj::BulletManager::getInstance()->getShot();
		if (num >= shot.size())return 1;
		if (lua_toboolean(L, -1)) {
			int color = static_cast<int>(lua_tonumber(L, -2));
			if (isCanInput())shot[num].setColor(color);
		}
		else {
			lua_pushnumber(L, shot[num].getColor());
		}
		return 1;
	}
	int ShotScript::l_Count(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& shot = obj::BulletManager::getInstance()->getShot();
		if (num >= shot.size())return 1;
		if (lua_toboolean(L, -1)) {
			int count = static_cast<int>(lua_tonumber(L, -2));
			if (isCanInput())shot[num].setCount(count);
		}
		else {
			lua_pushnumber(L, shot[num].getCount());
		}
		return 1;
	}
	int ShotScript::l_State(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& shot = obj::BulletManager::getInstance()->getShot();
		if (num >= shot.size())return 1;
		if (lua_toboolean(L, -1)) {
			int state = static_cast<int>(lua_tonumber(L, -2));
			if (isCanInput())shot[num].setState(state);
		}
		else {
			lua_pushnumber(L, shot[num].getState());
		}
		return 1;
	}
	int ShotScript::l_State2(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& shot = obj::BulletManager::getInstance()->getShot();
		if (num >= shot.size())return 1;
		if (lua_toboolean(L, -1)) {
			int state = static_cast<int>(lua_tonumber(L, -2));
			if (isCanInput())shot[num].setStateSub(state);
		}
		else {
			lua_pushnumber(L, shot[num].getStateSub());
		}
		return 1;
	}
	int ShotScript::l_Rota(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& shot = obj::BulletManager::getInstance()->getShot();
		if (num >= shot.size())return 1;
		if (lua_toboolean(L, -1)) {
			bool rota = lua_toboolean(L, -2);
			if (isCanInput())shot[num].set_rota(rota);
		}
		else {
			lua_pushboolean(L, shot[num].isRota());
		}
		return 1;
	}
	int ShotScript::l_Shine(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& shot = obj::BulletManager::getInstance()->getShot();
		if (num >= shot.size())return 1;
		if (lua_toboolean(L, -1)) {
			bool shine = lua_toboolean(L, -2);
			if (isCanInput())shot[num].set_shine(shine);
		}
		else {
			lua_pushboolean(L, shot[num].isShine());
		}
		return 1;
	}
	int ShotScript::l_Bound(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& shot = obj::BulletManager::getInstance()->getShot();
		if (num >= shot.size())return 1;
		if (lua_toboolean(L, -1)) {
			bool bound = lua_toboolean(L, -2);
			if (isCanInput())shot[num].setBound(bound);
		}
		else {
			lua_pushboolean(L, shot[num].isBound());
		}
		return 1;
	}
	int ShotScript::l_Who(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& shot = obj::BulletManager::getInstance()->getShot();
		if (num >= shot.size())return 1;
		if (lua_toboolean(L, -1)) {
			int who = lua_tonumber(L, -2);
			if (isCanInput())shot[num].setRayer(who);
		}
		else {
			lua_pushnumber(L, shot[num].getRayer());
		}
		return 1;
	}
	//ˆø”(true = Get Area ,false = Get Count)
	int ShotScript::l_Bound_Area(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& shot = obj::BulletManager::getInstance()->getShot();
		if (num >= shot.size())return 1;
		if (lua_toboolean(L, -1)) {
			int area = lua_tonumber(L, -2);
			if (isCanInput())shot[num].setBoundArea(area);
		}
		else {
			lua_pushnumber(L, shot[num].getBoundArea());
		}
		return 1;
	}
	int ShotScript::l_Bound_Count(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& shot = obj::BulletManager::getInstance()->getShot();
		if (num >= shot.size())return 1;
		if (lua_toboolean(L, -1)) {
			int count = lua_tonumber(L, -2);
			if(isCanInput())shot[num].setBoundCount(count);
		}
		else {
			lua_pushnumber(L, shot[num].getBoundCount());
		}
		return 1;
	}
	int ShotScript::l_Hide(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& shot = obj::BulletManager::getInstance()->getShot();
		if (num >= shot.size())return 1;
		if (lua_toboolean(L, -1)) {
			bool hide = lua_toboolean(L, -2);
			if (isCanInput())shot[num].setHide(hide);
		}
		else {
			lua_pushboolean(L, shot[num].isHide());
		}
		return 1;
	}
	int ShotScript::l_NoDelete(lua_State* L) {
		int num = lua_tonumber(L, -3);
		auto& shot = obj::BulletManager::getInstance()->getShot();
		if (num >= shot.size())return 1;
		if (lua_toboolean(L, -1)) {
			bool no_delete = lua_toboolean(L, -2);
			if (isCanInput())shot[num].setNoDelete(no_delete);
		}
		else {
			lua_pushboolean(L, shot[num].isNoDelete());
		}
		return 1;
	}
	int ShotScript::l_Search(lua_State* L) {
		auto& shot = obj::BulletManager::getInstance()->getShot();
		for (int i = 0; i < shot.size(); i++) {
			if (!shot[i].isFlag()) {
				if (m_Shot_spawned_max < i)m_Shot_spawned_max = i;
				lua_pushnumber(L, i);
				return 1;
			}
		}
		return 0;
	}
	bool ShotScript::isCanInput() {
		if (!m_Is_bullet_phase)return false;
		return true;
	}

}