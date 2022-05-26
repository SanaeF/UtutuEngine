#pragma once
#include "../../Lua/5.3/include/lua.hpp"
#include "../../Lua/5.3/include/lauxlib.h"
#include "../../Lua/5.3/include/lualib.h"

namespace script {
	class PlayerScript {
	public:
		PlayerScript(lua_State* L);
		~PlayerScript();
	private:
		//スクリプトに登録した関数に適した関数を呼び出す
		static int callFunction(lua_State* L);
		static int l_PosX(lua_State* L);
		static int l_PosY(lua_State* L);
		static int l_GetX1(lua_State* L);
		static int l_GetY1(lua_State* L);
		static int l_GetX2(lua_State* L);
		static int l_GetY2(lua_State* L);
		static int l_GetType(lua_State* L);
		static int l_GetIsHide(lua_State* L);
		static int l_GetKeyInput(lua_State* L);
		static int l_ItemApple(lua_State* L);
	};
}