#pragma once
#include "../../Lua/5.3/include/lua.hpp"
#include "../../Lua/5.3/include/lauxlib.h"
#include "../../Lua/5.3/include/lualib.h"
#include <vector>

namespace obj {
	class TurnLazer_Info;
}
namespace script {
	class TurnLazerScript {
	private:
		static bool m_Is_bullet_phase;
		static int m_Object_num;
		static int m_Shot_spawned_max;
	public:

		TurnLazerScript();
		void createScript(lua_State* L, bool rock_script);
		void update();
		void draw(double crush_x = 0.f, double crush_y = 0.f);
		void pause();
		void setUpdatePhase();
	private:
		//スクリプトに登録した関数に適した関数を呼び出す
		static int callFunction(lua_State* L);
		static int l_Default(lua_State* L);
		static int l_Flag(lua_State* L);
		static int l_Number(lua_State* L);
		static int l_Color(lua_State* L);
		static int l_Length(lua_State* L);
		static int l_Count(lua_State* L);
		static int l_State(lua_State* L);
		static int l_State2(lua_State* L);
		static int l_Bound(lua_State* L);
		static int l_Bound_Area(lua_State* L);
		static int l_PosX(lua_State* L);
		static int l_PosY(lua_State* L);
		static int l_Angle(lua_State* L);
		static int l_Speed(lua_State* L);
		static int l_Who(lua_State* L);
		static int l_Search(lua_State* L);
		static bool isCanInput();
	};
}