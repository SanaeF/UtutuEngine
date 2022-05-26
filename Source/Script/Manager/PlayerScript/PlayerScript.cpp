#pragma once
#include "PlayerScript.h"
#include <iostream>

#include "../../Source/Object/Player/Player.h"
#include "../../Source/Resource/SaveData/SaveData.h"

namespace script {
	PlayerScript::PlayerScript(lua_State* L) {
		lua_register(L, "PlayerFunc", callFunction);
	}
	int PlayerScript::callFunction(lua_State* L) {
		const char* str = lua_tostring(L, -3);
		if (!strcmp(str, "Func:X"))l_PosX(L);
		if (!strcmp(str, "Func:Y"))l_PosY(L);
		if (!strcmp(str, "Func:GetP1X"))l_GetX1(L);
		if (!strcmp(str, "Func:GetP1Y"))l_GetY1(L);
		if (!strcmp(str, "Func:GetP2X"))l_GetX2(L);
		if (!strcmp(str, "Func:GetP2Y"))l_GetY2(L);
		if (!strcmp(str, "Func:GetType"))l_GetType(L);
		if (!strcmp(str, "Func:GetIsHide"))l_GetIsHide(L);
		if (!strcmp(str, "Func:GetKeyInput"))l_GetKeyInput(L);
		if (!strcmp(str, "Func:ItemApple"))l_ItemApple(L);
		return 1;
	}
	int PlayerScript::l_PosX(lua_State* L) {
		if (lua_toboolean(L, -1)) {
			double x = lua_tonumber(L, -2);
			obj::Player::PlayerObj.setX(x);
		}
		else {
			lua_pushnumber(L, obj::Player::PlayerObj.getX());
		}
		return 1;
	}
	int PlayerScript::l_PosY(lua_State* L) {
		if (lua_toboolean(L, -1)) {
			double y = lua_tonumber(L, -2);
			obj::Player::PlayerObj.setY(y);
		}
		else {
			lua_pushnumber(L, obj::Player::PlayerObj.getY());
		}
		return 1;
	}
	int PlayerScript::l_GetX1(lua_State* L) {
		lua_pushnumber(L, obj::Player::PlayersObj[0].getX());
		return 1;
	}
	int PlayerScript::l_GetY1(lua_State* L) {
		lua_pushnumber(L, obj::Player::PlayersObj[0].getY());
		return 1;
	}
	int PlayerScript::l_GetX2(lua_State* L) {
		lua_pushnumber(L, obj::Player::PlayersObj[1].getX());
		return 1;
	}
	int PlayerScript::l_GetY2(lua_State* L) {
		lua_pushnumber(L, obj::Player::PlayersObj[1].getY());
		return 1;
	}
	int PlayerScript::l_GetType(lua_State* L) {
		lua_pushnumber(L, obj::Player::PlayerObj.getType());
		return 1;
	}
	int PlayerScript::l_GetIsHide(lua_State* L) {
		int who = lua_tonumber(L, -1);
		if (who >= 2)return 1;
		lua_pushboolean(L, obj::Player::PlayersObj[who].isHideMode());
		return 1;
	}
	int PlayerScript::l_GetKeyInput(lua_State* L) {
		int who = lua_tonumber(L, -1);
		int keyType = lua_tonumber(L, -2);
		if (who >= 2 || keyType > 3)return 1;
		lua_pushnumber(L, obj::Player::PlayersObj[who].getKeyInputData(keyType));
		return 1;
	}
	int PlayerScript::l_ItemApple(lua_State* L) {
		if (lua_toboolean(L, -1)) {
			int num = lua_tonumber(L, -2);
			obj::Player::PlayerObj.getItemStack().apple = num;
		}
		else {
			lua_pushnumber(L, obj::Player::PlayerObj.getItemStack().apple);
		}
		return 1;
	}
	PlayerScript::~PlayerScript() {
	}
}