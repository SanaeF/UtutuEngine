#include "HelperScript.h"
#include <windows.h>
#include "../../Source/Helper/Helper.h"
#include "../../Source/Script/ScriptLoader/ScriptLoader.h"
#include "../../Source/EffectTools/Shake/Shake.h"
#include "../../Source/SystemProp/GameStatsProp.h"

namespace script {
	std::vector<HelperScript::ScriptFile> HelperScript::m_Script_file;
	HelperScript::HelperScript() {
	}
	void HelperScript::createScript(lua_State* L) {
		lua_register(L, "HelperFunc", callFunction);
		if(!USE_DEBUGLOG)lua_register(L, "dofile", l_Include);
	}
	void HelperScript::reset() {
		m_Script_file.clear();
	}
	int HelperScript::callFunction(lua_State* L) {
		const char* str = lua_tostring(L, -1);
		if (str == nullptr)return 1;
		if (!strcmp(str, "Func:Random"))l_Random(L);
		if (!strcmp(str, "Func:Crush"))l_Crush(L);
		return 1;
	}
	int HelperScript::l_Random(lua_State* L) {
		float num = lua_tonumber(L, -2);
		lua_pushnumber(L, (float)GET_SEED_RANDOM_F(num));
		return 1;
	}
	int HelperScript::l_Crush(lua_State* L) {
		int size = lua_tonumber(L, -3);
		int time = lua_tonumber(L, -2);
		app::Shake::crush.set(size,time);
		return 1;
	}
	int HelperScript::l_Include(lua_State* L) {
		const char* file_name = lua_tostring(L, -1);
		int id = 0;
		std::string text;
		bool loaded = false;
		if (m_Script_file.size() > 0) {
			for (int ite = 0; ite < m_Script_file.size(); ite++) {
				if (strcmp(m_Script_file[ite].file_name.data(), file_name) == 0) {//”äŠr
					id = ite;
					text = m_Script_file[ite].script_text.c_str();
					loaded = true;
				}
			}
		}
		if (!loaded) {
			ScriptLoader loader;
			loader.readFile(file_name);
			text = loader.getSource();
		}
		if (!text.data()) {
			OutputDebugString("aflDoFile: could not load file \n");
			OutputDebugString(file_name);
			OutputDebugString("\n");
			return 0;
		}
		bool ok = true;
		if (luaL_loadbuffer(L, text.data(), text.length(), file_name)) {
			std::cout << text.data() << std::endl;
			OutputDebugString("luaL_loadbuffer failed! \n");
			OutputDebugString(file_name);
			OutputDebugString("\n");
			OutputDebugString("\n");
			//lua_pop(L, 1);
			ok = false;
		}
		//loader.bufferDelete();
		if (ok && lua_pcall(L, 0, LUA_MULTRET, 0)) {
			OutputDebugString("lua_pcall failed! \n");
			OutputDebugString(lua_tostring(L, -1));
			OutputDebugString("\n");
			//lua_pop(L, 1);
			ok = false;
		}
		if (!loaded && ok) {
			ScriptFile result = { file_name, text.data() };
			m_Script_file.push_back(result);
		}
		return 1;
	}
}