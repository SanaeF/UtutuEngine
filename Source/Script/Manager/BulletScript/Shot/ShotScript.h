#pragma once
#include "../../Lua/5.3/include/lua.hpp"
#include "../../Lua/5.3/include/lauxlib.h"
#include "../../Lua/5.3/include/lualib.h"

namespace script {

	class ShotScript {
	private:
		static bool m_Is_bullet_phase;
		static int m_Object_num;
		static int m_Shot_spawned_max;
		float m_Min_x;
		float m_Max_x;
	public:
		ShotScript();
		void createScript(lua_State* L, bool rock_script);
		void setUpdatePhase();
		int getShotSpawnedMax();
	private:
		//スクリプトに登録した関数に適した関数を呼び出す
		static int callFunction(lua_State* L);
		static int l_Default(lua_State* L);
		static int l_Flag(lua_State* L);
		static int l_Number(lua_State* L);
		static int l_Color(lua_State* L);
		static int l_Type(lua_State* L);
		static int l_Rota(lua_State* L);
		static int l_Shine(lua_State* L);
		static int l_Count(lua_State* L);
		static int l_State(lua_State* L);
		static int l_State2(lua_State* L);
		static int l_Bound(lua_State* L);
		static int l_Bound_Area(lua_State* L);
		static int l_Bound_Count(lua_State* L);
		static int l_Hide(lua_State* L);
		static int l_NoDelete(lua_State* L);
		static int l_Size(lua_State* L);
		static int l_PosX(lua_State* L);
		static int l_PosY(lua_State* L);
		static int l_Angle(lua_State* L);
		static int l_Speed(lua_State* L);
		static int l_Who(lua_State* L);
		static int l_Search(lua_State* L);
		static bool isCanInput();
	};
}