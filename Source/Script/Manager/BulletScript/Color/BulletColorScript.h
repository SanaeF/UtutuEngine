#pragma once
#include "../../Lua/5.3/include/lua.hpp"
#include "../../Lua/5.3/include/lauxlib.h"
#include "../../Lua/5.3/include/lualib.h"

namespace script {
	class BulletColorScript {
	private:
	public:
		BulletColorScript();
		void setScript(lua_State* L);
	};
}