#include "EnemyImageScript.h"
#include <iostream>

#include "../../Source/Resource/EnemyImage/EnemyImage.h"

namespace script {
	EnemyImageScript::EnemyImageScript() {
	}
	void EnemyImageScript::setScript(lua_State* L) {
		lua_pushnumber(L, res::BOSS_TYPE::N01_MATUMI);
		lua_setglobal(L, "N01_MATUMI");
		lua_pushnumber(L, res::BOSS_TYPE::N02_EREMIRA);
		lua_setglobal(L, "N02_EREMIRA");
		lua_pushnumber(L, res::BOSS_TYPE::N03_ALICE);
		lua_setglobal(L, "N03_ALICE");
		lua_pushnumber(L, res::BOSS_TYPE::N03_MATUMI);
		lua_setglobal(L, "N03_MATUMI");
		lua_pushnumber(L, res::BOSS_TYPE::N03_EREMIRA);
		lua_setglobal(L, "N03_EREMIRA");
		lua_pushnumber(L, res::BOSS_TYPE::N04_NARSIRU);
		lua_setglobal(L, "N04_NARSIRU");
		lua_pushnumber(L, res::BOSS_TYPE::N05_BLACK);
		lua_setglobal(L, "N05_BLACK");
		lua_pushnumber(L, res::BOSS_TYPE::N05_FEATORIA);
		lua_setglobal(L, "N05_FEATORIA");
		lua_pushnumber(L, res::BOSS_TYPE::N06_SHIENA);
		lua_setglobal(L, "N06_SHIENA");
		lua_pushnumber(L, res::BOSS_TYPE::N07_ALICE);
		lua_setglobal(L, "N07_ALICE");
		lua_pushnumber(L, res::BOSS_TYPE::N07_FEATORIA);
		lua_setglobal(L, "N07_FEATORIA");
		lua_pushnumber(L, res::BOSS_TYPE::N08_KURO);
		lua_setglobal(L, "N08_KURO");

		lua_pushnumber(L, res::ENEMY_TYPE::DEV_NORMAL);
		lua_setglobal(L, "DEV_NORMAL");
		lua_pushnumber(L, res::ENEMY_TYPE::DEV_ORANGE);
		lua_setglobal(L, "DEV_ORANGE");
		lua_pushnumber(L, res::ENEMY_TYPE::DEV_GREEN);
		lua_setglobal(L, "DEV_GREEN");
		lua_pushnumber(L, res::ENEMY_TYPE::DEV_HACK);
		lua_setglobal(L, "DEV_HACK");
		lua_pushnumber(L, res::ENEMY_TYPE::DEV_BONE);
		lua_setglobal(L, "DEV_BONE");
		lua_pushnumber(L, res::ENEMY_TYPE::DEV_ITEM_BALLOON);
		lua_setglobal(L, "DEV_ITEMBALLOON");
		lua_pushnumber(L, res::ENEMY_TYPE::DEV_Lninyo);
		lua_setglobal(L, "DEV_Lninyo");
		lua_pushnumber(L, res::ENEMY_TYPE::OBJ_ONMYOU);
		lua_setglobal(L, "OBJ_ONMYOU");
		lua_pushnumber(L, res::ENEMY_TYPE::OBJ_SHADOWWING);
		lua_setglobal(L, "OBJ_SHADOWWING");
		lua_pushnumber(L, res::ENEMY_TYPE::FIRE_FEARY);
		lua_setglobal(L, "FIRE_FEARY");
		lua_pushnumber(L, res::ENEMY_TYPE::TRAMP_MATSU);
		lua_setglobal(L, "TRAMP_MATSU");
		lua_pushnumber(L, res::ENEMY_TYPE::TRAMP_ELEMIRA);
		lua_setglobal(L, "TRAMP_ELEMIRA");
		lua_pushnumber(L, res::ENEMY_TYPE::TRAMP_FEATORIA);
		lua_setglobal(L, "TRAMP_FEATORIA");
	}
}