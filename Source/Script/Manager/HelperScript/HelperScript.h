#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "../../Lua/5.3/include/lua.hpp"
#include "../../Lua/5.3/include/lauxlib.h"
#include "../../Lua/5.3/include/lualib.h"
namespace script {
	class HelperScript {
	private:
		struct ScriptFile {
			std::string file_name;
			std::string script_text;
		};
		static std::vector<ScriptFile> m_Script_file;
	public:
		HelperScript();
		void createScript(lua_State* L);
		void reset();
	private:
		//スクリプトに登録した関数に適した関数を呼び出す
		static int callFunction(lua_State* L);
		static int l_Random(lua_State* L);
		static int l_Crush(lua_State* L);
		static int l_Include(lua_State* L);
	};
}