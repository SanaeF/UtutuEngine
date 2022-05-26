#include "SoundScript.h"
#include <iostream>

#include "../../Source/Application/Sound/Sound.h"
#include "../../Source/Resource/SoundData/SoundData.h"
namespace script {
	SoundScript::SoundScript() {
	}
	void SoundScript::setScript(lua_State* L) {
		setID(L);
		lua_register(L, "playSE", l_PlaySE);
	}
	void SoundScript::setID(lua_State* L) {
		lua_pushnumber(L, res::SE::BULLET01);
		lua_setglobal(L, "BULLET01");
		lua_pushnumber(L, res::SE::BULLET02);
		lua_setglobal(L, "BULLET02");
		lua_pushnumber(L, res::SE::LAZER01);
		lua_setglobal(L, "LAZER01");
		lua_pushnumber(L, res::SE::LAZER02);
		lua_setglobal(L, "LAZER02");
		lua_pushnumber(L, res::SE::KIRAN);
		lua_setglobal(L, "KIRAN");
		lua_pushnumber(L, res::SE::EXPLODE);
		lua_setglobal(L, "EXPLODE");
		lua_pushnumber(L, res::SE::CHARGE);
		lua_setglobal(L, "CHARGE");
		lua_pushnumber(L, res::SE::BOOOOM);
		lua_setglobal(L, "BOOOOM");
		lua_pushnumber(L, res::SE::BREAK);
		lua_setglobal(L, "BREAK");
		lua_pushnumber(L, res::SE::BOSSBREAK);
		lua_setglobal(L, "BOSSBREAK");
		lua_pushnumber(L, res::SE::GYUUUUUUN);
		lua_setglobal(L, "GYUUUUUUN");
		lua_pushnumber(L, res::SE::PLAYER_SHOT);
		lua_setglobal(L, "PLAYER_SHOT");
		lua_pushnumber(L, res::SE::GRAZE);
		lua_setglobal(L, "GRAZE");
		lua_pushnumber(L, res::SE::GOT_ITEM);
		lua_setglobal(L, "GOT_ITEM");
		lua_pushnumber(L, res::SE::BOMGET);
		lua_setglobal(L, "BOMGET");
		lua_pushnumber(L, res::SE::LIFEGET);
		lua_setglobal(L, "LIFEGET");
		lua_pushnumber(L, res::SE::PLAYER_OUT);
		lua_setglobal(L, "PLAYER_OUT");
		lua_pushnumber(L, res::SE::SELECT);
		lua_setglobal(L, "SELECT");
		lua_pushnumber(L, res::SE::SELECT_CANCEL);
		lua_setglobal(L, "SELECT_CANCEL");
		lua_pushnumber(L, res::SE::SELECT_OK);
		lua_setglobal(L, "SELECT_OK");
	}
	int SoundScript::l_PlaySE(lua_State* L) {
		int se_id = lua_tonumber(L, -1);
		app::Sound::sound.playSE(se_id);
		return 1;
	}
}