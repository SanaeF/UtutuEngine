#include "BulletColorScript.h"
#include <iostream>

#include "../../Source/Resource/BulletImage/BulletImage.h"

namespace script {
	BulletColorScript::BulletColorScript() {
	}
	void BulletColorScript::setScript(lua_State* L) {
		lua_pushnumber(L, res::BULLET_COLOR::RED);
		lua_setglobal(L, "CL_RED");
		lua_pushnumber(L, res::BULLET_COLOR::GREEN);
		lua_setglobal(L, "CL_GREEN");
		lua_pushnumber(L, res::BULLET_COLOR::BLUE);
		lua_setglobal(L, "CL_BLUE");
		lua_pushnumber(L, res::BULLET_COLOR::YELLOW);
		lua_setglobal(L, "CL_YELLOW");
		lua_pushnumber(L, res::BULLET_COLOR::PINK);
		lua_setglobal(L, "CL_PINK");
		lua_pushnumber(L, res::BULLET_COLOR::SKY);
		lua_setglobal(L, "CL_SKY");
		lua_pushnumber(L, res::BULLET_COLOR::ORANGE);
		lua_setglobal(L, "CL_ORANGE");
		lua_pushnumber(L, res::BULLET_COLOR::PURPLE);
		lua_setglobal(L, "CL_PURPLE");
		lua_pushnumber(L, res::BULLET_COLOR::CLEAR_BLUE);
		lua_setglobal(L, "CL_CYAN");
		lua_pushnumber(L, res::BULLET_COLOR::ORIGINAL);
		lua_setglobal(L, "CL_ORIGINAL");
	}
}