#include "MinionBulletScript.h"
#include <iostream>
#include "../../Source/Script/Manager/SoundScript/SoundScript.h"
#include "../../Source/Script/Manager/PlayerScript/PlayerScript.h"
#include "../../Source/Script/Manager/BulletScript/Shot/ShotScript.h"
#include "../../Source/Script/Manager/BulletScript/Lazer/LazerScript.h"
#include "../../Source/Script/Manager/BulletScript/TurnLazer/TurnLazerScript.h"
#include "../../Source/Script/Manager/BulletScript/Color/BulletColorScript.h"
#include "../../Source/Script/Manager/BulletScript/Type/BulletTypeScript.h"
#include "../../Source/Script/Manager/HelperScript/HelperScript.h"
#include "DxLib.h"
namespace script {
	MinionBulletScript::Minion_Info MinionBulletScript::minion;
	MinionBulletScript::MinionBulletScript() :
		mFlag(false)
	{
		mBulletType_Script.reset(new BulletTypeScript());
		mBulletColor_Script.reset(new BulletColorScript());
		mShot_Script.reset(new ShotScript());
		mLazer_Script.reset(new LazerScript());
		mT_Lazer_Script.reset(new TurnLazerScript());
		mHelper_Script.reset(new HelperScript());
		mSound.reset(new SoundScript());
	}
	void MinionBulletScript::Initialize() {
		ml_State = luaL_newstate();
		luaL_openlibs(ml_State);
		mPlayer.reset(new PlayerScript(ml_State));
		mShot_Script->createScript(ml_State);
		mLazer_Script->createScript(ml_State);
		mT_Lazer_Script->createScript(ml_State);
		mBulletType_Script->setScript(ml_State);
		mBulletColor_Script->setScript(ml_State);
		mHelper_Script->createScript(ml_State);
		mSound->setScript(ml_State);
		mShot_Script->setUpdatePhase();
		mLazer_Script->setUpdatePhase();
		mT_Lazer_Script->setUpdatePhase();
		lua_register(ml_State, "MinionBulletFunc", MinionFunc);
		mFlag = true;
	}
	void MinionBulletScript::finalize() {
		mFlag = false;
	}
	void MinionBulletScript::pause() {

	}
	void MinionBulletScript::update(const char* file, float x, float y, int count, int bullet_type, int bullet_color,int who) {
		minion.x = x;
		minion.y = y;
		minion.count = count;
		minion.bulletType = bullet_type;
		minion.bulletColor = bullet_color;
		minion.who = who;
		luaL_loadfile(ml_State, file);
		lua_pcall(ml_State, 0, 0, 0);
		checkValue(ml_State);
	}
	void MinionBulletScript::checkValue(lua_State* L) {
		if (lua_gettop(L) == LUA_TSTRING) {
			auto log = lua_tostring(L, -1);
			printfDx("%s", log);
		}
	}
	int MinionBulletScript::MinionFunc(lua_State* L) {
		const char* str = lua_tostring(L, -1);
		if (!strcmp(str, "Func:getX"))l_getX(L);
		if (!strcmp(str, "Func:getY"))l_getY(L);
		if (!strcmp(str, "Func:getCount"))l_getCount(L);
		if (!strcmp(str, "Func:getBulletType"))l_getBulletType(L);
		if (!strcmp(str, "Func:getBulletColor"))l_getBulletColor(L);
		if (!strcmp(str, "Func:getWho"))l_getWho(L);
		return 1;
	}
	int MinionBulletScript::l_getX(lua_State* L) {
		lua_pushnumber(L, minion.x);
		return 1;
	}
	int MinionBulletScript::l_getY(lua_State* L) {
		lua_pushnumber(L, minion.y);
		return 1;
	}
	int MinionBulletScript::l_getCount(lua_State* L) {
		if(minion.count<0)lua_pushnumber(L, 0);
		lua_pushnumber(L, minion.count);
		return 1;
	}
	int MinionBulletScript::l_getBulletColor(lua_State* L) {
		lua_pushnumber(L, minion.bulletColor);
		return 1;
	}
	int MinionBulletScript::l_getBulletType(lua_State* L) {
		lua_pushnumber(L, minion.bulletType);
		return 1;
	}
	int MinionBulletScript::l_getWho(lua_State* L) {
		lua_pushnumber(L, minion.who);
		return 1;
	}
	bool MinionBulletScript::isFlag() {
		return mFlag;
	}
	MinionBulletScript::~MinionBulletScript() {
		finalize();
	}
}