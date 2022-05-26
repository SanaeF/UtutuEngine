#pragma once
#include "../../Lua/5.3/include/lua.hpp"
#include "../../Lua/5.3/include/lauxlib.h"
#include "../../Lua/5.3/include/lualib.h"
#include <memory>
namespace app {
	class Shake;
}
namespace script {
	class ShakeScript {
	private:
		static bool m_Flag;
		static int m_Time;
		static float m_Size;
	public:
		ShakeScript(lua_State* L);
		~ShakeScript();
		void setShake(std::shared_ptr<app::Shake>& m_Shake);
	private:
		static int l_Shake(lua_State* L);
	};
}