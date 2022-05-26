#include "MinionScript.h"
#include <iostream>

#include "../../Source/Helper/Helper.h"
#include "../../Source/Object/Minion/Minion.h"
#include "../../Source/Manager/MinionManager/MinionManager.h"

namespace script {
	int MinionScript::m_Object_num = 0;
	int MinionScript::m_Minion_spawned_max = 0;
	MinionScript::MinionScript()
	{
		m_Minion_spawned_max = 0;
	}
	void MinionScript::createScript(lua_State* L) {
		m_Minion_spawned_max = 0;
		lua_register(L, "MinionFunc", callFunction);
		lua_pushnumber(L, obj::MINION_NUM_MAX);
		lua_setglobal(L, "getMinion_max");
	}
	int MinionScript::callFunction(lua_State* L) {
		const char* str = lua_tostring(L, -1);
		if (!strcmp(str, "Func:Number"))l_Number(L);
		if (!strcmp(str, "Func:Search"))l_Search(L);
		if (!strcmp(str, "Func:Flag"))l_Flag(L);
		if (!strcmp(str, "Func:X"))l_PosX(L);
		if (!strcmp(str, "Func:Y"))l_PosY(L);
		if (!strcmp(str, "Func:Size"))l_Size(L);
		if (!strcmp(str, "Func:Type"))l_Type(L);
		if (!strcmp(str, "Func:Speed"))l_Speed(L);
		if (!strcmp(str, "Func:Angle"))l_Angle(L);
		if (!strcmp(str, "Func:HP"))l_HP(L);
		if (!strcmp(str, "Func:LastHP"))l_LastHP(L);
		if (!strcmp(str, "Func:MoveID"))l_MoveType(L);
		if (!strcmp(str, "Func:BulletID"))l_BulletType(L);
		if (!strcmp(str, "Func:ItemID"))l_ItemType(L);
		if (!strcmp(str, "Func:ItemNum"))l_ItemNum(L);
		if (!strcmp(str, "Func:Count"))l_Count(L);
		if (!strcmp(str, "Func:State1"))l_State(L);
		if (!strcmp(str, "Func:State2"))l_State2(L);
		if (!strcmp(str, "Func:Who"))l_Who(L);
		if (!strcmp(str, "Func:BulletObjColor"))l_BulletObjColor(L);
		if (!strcmp(str, "Func:BulletObjType"))l_BulletObjType(L);
		if (!strcmp(str, "Func:MotionType"))l_MotionType(L);
		if (!strcmp(str, "Func:Move"))l_Move(L);
		if (!strcmp(str, "Func:RandMove"))l_RandomMove(L);
		if (!strcmp(str, "Func:SendID"))l_SendID(L);
		return 1;
	}
	int MinionScript::l_Number(lua_State* L) {
		bool isSetter = lua_toboolean(L, -3);
		if (isSetter) {
			m_Object_num = lua_tonumber(L, -2);
		}
		else {
			lua_pushnumber(L, m_Object_num);
		}
		return 1;
	}
	//‘æ4ˆø”(true = Setter ,false = Getter)
	int MinionScript::l_Flag(lua_State* L) {
		auto& minion = manager::MinionManager::getInstance()->getMinion();
		int num = lua_tonumber(L, -4);
		bool isSetter = lua_toboolean(L, -3);
		if (!BEDWEEN(num, 0, minion.size()))return 1;
		if (isSetter) {
			bool flag = lua_toboolean(L, -2);
			minion[num].setFlag(flag);
		}
		else {
			lua_pushboolean(L, minion[num].isFlag());
		}
		return 1;
	}
	int MinionScript::l_PosX(lua_State* L) {
		auto& minion = manager::MinionManager::getInstance()->getMinion();
		int num = lua_tonumber(L, -4);
		bool isSetter = lua_toboolean(L, -3);
		if (!BEDWEEN(num, 0, minion.size()))return 1;
		if (isSetter) {
			double x = lua_tonumber(L, -2);
			minion[num].setX(x);
		}
		else {
			lua_pushnumber(L, minion[num].getX());
		}
		return 1;
	}
	int MinionScript::l_PosY(lua_State* L) {
		auto& minion = manager::MinionManager::getInstance()->getMinion();
		int num = lua_tonumber(L, -4);
		bool isSetter = lua_toboolean(L, -3);
		if (!BEDWEEN(num, 0, minion.size()))return 1;
		if (isSetter) {
			double y = lua_tonumber(L, -2);
			minion[num].setY(y);
		}
		else {
			lua_pushnumber(L, minion[num].getY());
		}
		return 1;
	}
	int MinionScript::l_Size(lua_State* L) {
		auto& minion = manager::MinionManager::getInstance()->getMinion();
		int num = lua_tonumber(L, -4);
		bool isSetter = lua_toboolean(L, -3);
		if (!BEDWEEN(num, 0, minion.size()))return 1;
		if (isSetter) {
			double size = lua_tonumber(L, -2);
			minion[num].setSize(size);
		}
		else {
			lua_pushnumber(L, minion[num].getSize());
		}
		return 1;
	}
	int MinionScript::l_Angle(lua_State* L) {
		auto& minion = manager::MinionManager::getInstance()->getMinion();
		int num = lua_tonumber(L, -4);
		bool isSetter = lua_toboolean(L, -3);
		if (!BEDWEEN(num, 0, minion.size()))return 1;
		if (isSetter) {
			double m_Angle = lua_tonumber(L, -2);
			minion[num].setAngle(m_Angle);
		}
		else {
			lua_pushnumber(L, minion[num].getAngle());
		}
		return 1;
	}
	int MinionScript::l_Speed(lua_State* L) {
		auto& minion = manager::MinionManager::getInstance()->getMinion();
		int num = lua_tonumber(L, -4);
		bool isSetter = lua_toboolean(L, -3);
		if (!BEDWEEN(num, 0, minion.size()))return 1;
		if (isSetter) {
			double speed = lua_tonumber(L, -2);
			minion[num].setSpeed(speed);
		}
		else {
			lua_pushnumber(L, minion[num].getSpeed());
		}
		return 1;
	}
	int MinionScript::l_Type(lua_State* L) {
		auto& minion = manager::MinionManager::getInstance()->getMinion();
		int num = lua_tonumber(L, -4);
		bool isSetter = lua_toboolean(L, -3);
		if (!BEDWEEN(num, 0, minion.size()))return 1;
		if (isSetter) {
			int type = lua_tonumber(L, -2);
			minion[num].setType(type);
		}
		else {
			lua_pushnumber(L, minion[num].getType());
		}
		return 1;
	}
	int MinionScript::l_HP(lua_State* L) {
		auto& minion = manager::MinionManager::getInstance()->getMinion();
		int num = lua_tonumber(L, -4);
		bool isSetter = lua_toboolean(L, -3);
		if (!BEDWEEN(num, 0, minion.size()))return 1;
		if (isSetter) {
			int hp = lua_tonumber(L, -2);
			minion[num].setHP(hp);
		}
		else {
			lua_pushnumber(L, minion[num].getHP());
		}
		return 1;
	}
	int MinionScript::l_LastHP(lua_State* L) {
		auto& minion = manager::MinionManager::getInstance()->getMinion();
		int num = lua_tonumber(L, -3);
		int hp = lua_tonumber(L, -2);
		minion[num].setLastHP(hp);
		return 1;
	}
	int MinionScript::l_MoveType(lua_State* L) {
		auto& minion = manager::MinionManager::getInstance()->getMinion();
		int num = lua_tonumber(L, -4);
		bool isSetter = lua_toboolean(L, -3);
		if (!BEDWEEN(num, 0, minion.size()))return 1;
		if (isSetter) {
			int move_type = lua_tonumber(L, -2);
			minion[num].setMoveType(move_type);
		}
		else {
			lua_pushnumber(L, minion[num].getMoverID());
		}
		return 1;
	}
	int MinionScript::l_BulletType(lua_State* L) {
		auto& minion = manager::MinionManager::getInstance()->getMinion();
		int num = lua_tonumber(L, -4);
		bool isSetter = lua_toboolean(L, -3);
		if (!BEDWEEN(num, 0, minion.size()))return 1;
		if (isSetter) {
			int bullet_type = lua_tonumber(L, -2);
			minion[num].setBulletType(bullet_type);
		}
		else {
			lua_pushnumber(L, minion[num].getBulletID());
		}
		return 1;
	}
	int MinionScript::l_ItemType(lua_State* L) {
		auto& minion = manager::MinionManager::getInstance()->getMinion();
		int num = lua_tonumber(L, -4);
		bool isSetter = lua_toboolean(L, -3);
		if (!BEDWEEN(num, 0, minion.size()))return 1;
		if (isSetter) {
			int item_type = lua_tonumber(L, -2);
			minion[num].setItemType(item_type);
		}
		else {
			lua_pushnumber(L, minion[num].getItem());
		}
		return 1;
	}
	int MinionScript::l_ItemNum(lua_State* L) {
		auto& minion = manager::MinionManager::getInstance()->getMinion();
		int num = lua_tonumber(L, -3);
		int item_num = lua_tonumber(L, -2);
		minion[num].setItemNum(item_num);
		return 1;
	}
	int MinionScript::l_Count(lua_State* L) {
		auto& minion = manager::MinionManager::getInstance()->getMinion();
		int num = lua_tonumber(L, -4);
		bool isSetter = lua_toboolean(L, -3);
		if (!BEDWEEN(num, 0, minion.size()))return 1;
		if (isSetter) {
			int count = static_cast<int>(lua_tonumber(L, -2));
			minion[num].setCount(count);
		}
		else {
			lua_pushnumber(L, minion[num].getCount());
		}
		return 1;
	}
	int MinionScript::l_State(lua_State* L) {
		auto& minion = manager::MinionManager::getInstance()->getMinion();
		int num = lua_tonumber(L, -4);
		bool isSetter = lua_toboolean(L, -3);
		if (!BEDWEEN(num, 0, minion.size()))return 1;
		if (isSetter) {
			int state = lua_tonumber(L, -2);
			minion[num].setState(state);
		}
		else {
			lua_pushnumber(L, minion[num].getState());
		}
		return 1;
	}
	int MinionScript::l_State2(lua_State* L) {
		auto& minion = manager::MinionManager::getInstance()->getMinion();
		int num = lua_tonumber(L, -4);
		bool isSetter = lua_toboolean(L, -3);
		if (!BEDWEEN(num, 0, minion.size()))return 1;
		if (isSetter) {
			int state = static_cast<int>(lua_tonumber(L, -2));
			minion[num].setStateSub(state);
		}
		else {
			lua_pushnumber(L, minion[num].getStateSub());
		}
		return 1;
	}
	int MinionScript::l_Who(lua_State* L) {
		auto& minion = manager::MinionManager::getInstance()->getMinion();
		int num = lua_tonumber(L, -4);
		bool isSetter = lua_toboolean(L, -3);
		if (!BEDWEEN(num, 0, minion.size()))return 1;
		if (isSetter) {
			int who = lua_tonumber(L, -2);
			minion[num].setRayer(who);
		}
		else {
			lua_pushnumber(L, minion[num].getRayer());
		}
		return 1;
	}
	int MinionScript::l_BulletObjColor(lua_State* L) {
		auto& minion = manager::MinionManager::getInstance()->getMinion();
		int num = lua_tonumber(L, -4);
		bool isSetter = lua_toboolean(L, -3);
		int param = lua_tonumber(L, -2);
		if (isSetter) {
			minion[num].setBulletObjColor(param);
		}
		else {
			lua_pushnumber(L, minion[num].getBulletObjColor());
		}
		return 1;
	}
	int MinionScript::l_BulletObjType(lua_State* L) {
		auto& minion = manager::MinionManager::getInstance()->getMinion();
		int num = lua_tonumber(L, -4);
		bool isSetter = lua_toboolean(L, -3);
		int param = lua_tonumber(L, -2);
		if (isSetter) {
			minion[num].setBulletObjType(param);
		}
		else {
			lua_pushnumber(L, minion[num].getBulletObjType());
		}
		return 1;
	}
	int MinionScript::l_MotionType(lua_State* L) {
		auto& minion = manager::MinionManager::getInstance()->getMinion();
		int num = lua_tonumber(L, -4);
		int param = lua_tonumber(L, -2);
		minion[num].setMotion(param);
		return 1;
	}
	int MinionScript::l_Move(lua_State* L) {
		auto& minion = manager::MinionManager::getInstance()->getMinion();
		int num = lua_tonumber(L, -5);
		float x = lua_tonumber(L, -4);
		float y = lua_tonumber(L, -3);
		int time = lua_tonumber(L, -2);
		minion[num].setMove(x, y, time);
		return 1;
	}
	int MinionScript::l_RandomMove(lua_State* L) {
		auto& minion = manager::MinionManager::getInstance()->getMinion();
		int num = lua_tonumber(L, -8);
		float x0 = lua_tonumber(L, -7);
		float y0 = lua_tonumber(L, -6);
		float x1 = lua_tonumber(L, -5);
		float y1 = lua_tonumber(L, -4);
		float dist = lua_tonumber(L, -3);
		int time = lua_tonumber(L, -2);
		minion[num].setRandMove(x0, y0, x1, y1, dist, time);
		return 1;
	}
	int MinionScript::l_SendID(lua_State* L) {
		int id = lua_tonumber(L, -2);
		if (m_Minion_spawned_max < id)m_Minion_spawned_max = id;
		return 1;
	}
	int MinionScript::l_Search(lua_State* L) {
		auto& minion = manager::MinionManager::getInstance()->getMinion();
		for (int i = 0; i < obj::MINION_NUM_MAX; i++) {
			if (!minion[i].isFlag()) {
				if (m_Minion_spawned_max < i)m_Minion_spawned_max = i;
				lua_pushnumber(L, i);
				return 1;
			}
		}
		return 0;
	}
}