#include "MinionMoverScript.h"
#include <iostream>
#include "../../Source/Script/Manager/PlayerScript/PlayerScript.h"
#include "../../Source/Script/Manager/HelperScript/HelperScript.h"
#include "DxLib.h"
namespace script {
	MinionMoverScript::Minion_Info MinionMoverScript::mimion;
	MinionMoverScript::Minion_Info MinionMoverScript::minion_stats;
	MinionMoverScript::GetInfo_Flag MinionMoverScript::isGetInfo;

	MinionMoverScript::MinionMoverScript() :
		mFlag(false)
	{
		mHelper_Script.reset(new HelperScript());
	}
	MinionMoverScript::~MinionMoverScript()
	{
		if (ml_State == nullptr)return;
		lua_close(ml_State);
	}
	void MinionMoverScript::Initialize() {
		ml_State = luaL_newstate();
		luaL_openlibs(ml_State);
		mPlayer_Script.reset(new PlayerScript(ml_State));
		mHelper_Script->createScript(ml_State);
		lua_register(ml_State, "minionMover", PlayerFunc);
		mFlag = true;
	}
	void MinionMoverScript::pause() {
		if (ml_State == nullptr)return;
		lua_close(ml_State);
		ml_State = nullptr;
	}
	void MinionMoverScript::update(const char* file) {
		if (!mFlag)return;
		luaL_loadfile(ml_State, file);
		lua_pcall(ml_State, 0, 0, 0);
		checkMassage(ml_State);
	}
	void MinionMoverScript::finalize() {
		mFlag = false;
	}
	void MinionMoverScript::checkMassage(lua_State* L) {
		if (lua_gettop(L) == LUA_TSTRING) {
			auto log = lua_tostring(L, -1);
			printfDx("%s", log);
		}
	}

	int MinionMoverScript::PlayerFunc(lua_State* L) {
		const char* str = lua_tostring(L, -1);
		if (!strcmp(str, "Func:X"))l_PosX(L);
		if (!strcmp(str, "Func:Y"))l_PosY(L);
		if (!strcmp(str, "Func:Size"))l_Size(L);
		if (!strcmp(str, "Func:Speed"))l_Speed(L);
		if (!strcmp(str, "Func:Angle"))l_Angle(L);
		if (!strcmp(str, "Func:Count"))l_Count(L);
		if (!strcmp(str, "Func:State1"))l_State(L);
		if (!strcmp(str, "Func:State2"))l_State2(L);
		if (!strcmp(str, "Func:Who"))l_Who(L);
		return 1;
	}

	int MinionMoverScript::l_PosX(lua_State* L) {
		bool isSetter = lua_toboolean(L, -3);
		if (isSetter) {
			double x = lua_tonumber(L, -2);
			isGetInfo.x = true;
			mimion.x = x;
		}
		else {
			lua_pushnumber(L, minion_stats.x);
		}
		return 1;
	}
	int MinionMoverScript::l_PosY(lua_State* L) {
		bool isSetter = lua_toboolean(L, -3);
		if (isSetter) {
			double y = lua_tonumber(L, -2);
			isGetInfo.y = true;
			mimion.y = y;
		}
		else {
			lua_pushnumber(L, minion_stats.y);
		}
		return 1;
	}
	int MinionMoverScript::l_Size(lua_State* L) {
		bool isSetter = lua_toboolean(L, -3);
		if (isSetter) {
			double size = lua_tonumber(L, -2);
			isGetInfo.size = true;
			mimion.size = size;
		}
		else {
			lua_pushnumber(L, minion_stats.size);
		}
		return 1;
	}
	int MinionMoverScript::l_Angle(lua_State* L) {
		bool isSetter = lua_toboolean(L, -3);
		if (isSetter) {
			double angle = lua_tonumber(L, -2);
			isGetInfo.angle = true;
			mimion.angle = angle;
		}
		else {
			lua_pushnumber(L, minion_stats.angle);
		}
		return 1;
	}
	int MinionMoverScript::l_Speed(lua_State* L) {
		bool isSetter = lua_toboolean(L, -3);
		if (isSetter) {
			double speed = lua_tonumber(L, -2);
			isGetInfo.speed = true;
			mimion.speed = speed;
		}
		else {
			lua_pushnumber(L, minion_stats.speed);
		}
		return 1;
	}
	int MinionMoverScript::l_Count(lua_State* L) {
		bool isSetter = lua_toboolean(L, -3);
		if (isSetter) {
			int count = static_cast<int>(lua_tonumber(L, -2));
			isGetInfo.count = true;
			mimion.count = count;
		}
		else {
			lua_pushnumber(L, minion_stats.count);
		}
		return 1;
	}
	int MinionMoverScript::l_State(lua_State* L) {
		bool isSetter = lua_toboolean(L, -3);
		if (isSetter) {
			int state = static_cast<int>(lua_tonumber(L, -2));
			isGetInfo.state[0] = true;
			mimion.state[0] = state;
		}
		else {
			lua_pushnumber(L, minion_stats.state[0]);
		}
		return 1;
	}
	int MinionMoverScript::l_State2(lua_State* L) {
		bool isSetter = lua_toboolean(L, -3);
		if (isSetter) {
			int state = static_cast<int>(lua_tonumber(L, -2));
			isGetInfo.state[1] = true;
			mimion.state[1] = state;
		}
		else {
			lua_pushnumber(L, minion_stats.state[1]);
		}
		return 1;
	}
	int MinionMoverScript::l_Who(lua_State* L) {
		lua_pushnumber(L, minion_stats.who);
		return 1;
	}
	void MinionMoverScript::input(Minion_Info minion) {
		minion_stats = minion;
		mimion = minion;
	}
	bool MinionMoverScript::isFlag() {
		return mFlag;
	}
	MinionMoverScript::Minion_Info
		MinionMoverScript::output() {
		return mimion;
	}
}