#include "BulletTypeScript.h"
#include <iostream>

#include "../../Source/Resource/BulletImage/BulletImage.h"

namespace script {
	BulletTypeScript::BulletTypeScript() {
	}
	void BulletTypeScript::setScript(lua_State* L) {
		lua_pushnumber(L, res::BULLET_TYPE::NORMAL);
		lua_setglobal(L, "IMG_NORMAL");
		lua_pushnumber(L, res::BULLET_TYPE::SCALY);
		lua_setglobal(L, "IMG_SCALY");
		lua_pushnumber(L, res::BULLET_TYPE::OVERLAP);
		lua_setglobal(L, "IMG_OVERLAP");
		lua_pushnumber(L, res::BULLET_TYPE::RICE);
		lua_setglobal(L, "IMG_RICE");
		lua_pushnumber(L, res::BULLET_TYPE::POIFUL);
		lua_setglobal(L, "IMG_POIFUL");
		lua_pushnumber(L, res::BULLET_TYPE::BIG_STAR);
		lua_setglobal(L, "IMG_BIG_STAR");
		lua_pushnumber(L, res::BULLET_TYPE::DUST);
		lua_setglobal(L, "IMG_DUST");
		lua_pushnumber(L, res::BULLET_TYPE::BIG);
		lua_setglobal(L, "IMG_BIG");
		lua_pushnumber(L, res::BULLET_TYPE::MEGA);
		lua_setglobal(L, "IMG_MEGA");
		lua_pushnumber(L, res::BULLET_TYPE::AMMO);
		lua_setglobal(L, "IMG_AMMO");
		lua_pushnumber(L, res::BULLET_TYPE::MINI_STAR);
		lua_setglobal(L, "IMG_MINI_STAR");
		lua_pushnumber(L, res::BULLET_TYPE::BONE);
		lua_setglobal(L, "IMG_BONE");
		lua_pushnumber(L, res::BULLET_TYPE::PETAL);
		lua_setglobal(L, "IMG_PETAL");
		lua_pushnumber(L, res::BULLET_TYPE::TRAMP);
		lua_setglobal(L, "IMG_TRAMP");
		lua_pushnumber(L, res::BULLET_TYPE::TURN_LAZ);
		lua_setglobal(L, "IMG_TURN_LAZ");
		lua_pushnumber(L, res::BULLET_TYPE::B_FLY);
		lua_setglobal(L, "IMG_B_FLY");
		lua_pushnumber(L, res::BULLET_TYPE::LAZER);
		lua_setglobal(L, "IMG_LAZER");
		lua_pushnumber(L, res::BULLET_TYPE::CLOCK_LAZ);
		lua_setglobal(L, "IMG_CLOCK_LAZ");
		lua_pushnumber(L, res::BULLET_TYPE::EX_HAND);
		lua_setglobal(L, "IMG_ExHAND");
		lua_pushnumber(L, res::BULLET_TYPE::EX_META);
		lua_setglobal(L, "IMG_ExMETA");
		lua_pushnumber(L, res::BULLET_TYPE::FAKE_APPLE);
		lua_setglobal(L, "IMG_APPLE");
		lua_pushnumber(L, res::BULLET_TYPE::MOON);
		lua_setglobal(L, "IMG_MOON");
		lua_pushnumber(L, res::BULLET_TYPE::EXCALIBUR);
		lua_setglobal(L, "IMG_Excalibur");
		lua_pushnumber(L, res::BULLET_TYPE::LOCK);
		lua_setglobal(L, "IMG_LOCK");
	}
}