#pragma once
#include "../../Lua/5.3/include/lua.hpp"
#include "../../Lua/5.3/include/lauxlib.h"
#include "../../Lua/5.3/include/lualib.h"
#include <vector>

namespace obj {
	class Minion;
}
namespace script {
	class MinionScript {
	private:
		static int m_Object_num;
		static int m_Minion_spawned_max;
	public:
		MinionScript();
		void createScript(lua_State* L);
	private:
		//スクリプトに登録した関数に適した関数を呼び出す
		static int callFunction(lua_State* L);
		static int l_Flag(lua_State* L);
		static int l_Number(lua_State* L);
		static int l_HP(lua_State* L);
		static int l_LastHP(lua_State* L);
		static int l_MoveType(lua_State* L);
		static int l_BulletType(lua_State* L);
		static int l_ItemType(lua_State* L);
		static int l_ItemNum(lua_State* L);
		static int l_Search(lua_State* L);
		static int l_Type(lua_State* L);
		static int l_Count(lua_State* L);
		static int l_State(lua_State* L);
		static int l_State2(lua_State* L);
		static int l_Size(lua_State* L);
		static int l_PosX(lua_State* L);
		static int l_PosY(lua_State* L);
		static int l_Angle(lua_State* L);
		static int l_Speed(lua_State* L);
		static int l_Who(lua_State* L);
		static int l_BulletObjColor(lua_State* L);
		static int l_BulletObjType(lua_State* L);
		static int l_MotionType(lua_State* L);
		static int l_Move(lua_State* L);
		static int l_RandomMove(lua_State* L);
		static int l_SendID(lua_State* L);
	};
}