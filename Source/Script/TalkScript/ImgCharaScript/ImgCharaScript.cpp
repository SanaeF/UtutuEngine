#include "ImgCharaScript.h"
#include <iostream>

#include"../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include"../../Source/library/Graphics/String/StringDX.h"
#include "../../Source/Resource/GUI/GameUIImage/GameUIImage.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"
#include "../../Source/Manager/CharaImgManager/CharaImgManager.h"
#include "../../Source/Helper/Helper.h"
//#include "DxLib.h"
#pragma warning(disable : 4996)
namespace script {
	std::vector<app::CharaImgManager> ImgCharaScript::m_Animation;
	bool ImgCharaScript::m_Is_scene;

	ImgCharaScript::ImgCharaScript(lua_State* L) {
		m_Animation.clear();
		lua_register(L, "CharaFunc", callFunction);
	}
	ImgCharaScript::~ImgCharaScript() {
	}
	void ImgCharaScript::draw() {
		if (m_Animation.size() < 1)return;
		for (int num = 0; num < m_Animation.size(); num++) {
			if (m_Animation[num].isBack())m_Animation[num].draw();
		}
		for (int num = 0; num < m_Animation.size(); num++) {
			if (!m_Animation[num].isBack())m_Animation[num].draw();
		}
	}
	void ImgCharaScript::update() {
		if (m_Animation.size() < 1)return;
		for (int num = 0; num < m_Animation.size(); num++)m_Animation[num].update();
	}
	void ImgCharaScript::setIsScene(bool flag) {
		m_Is_scene = flag;
	}
	int ImgCharaScript::callFunction(lua_State* L) {
		if (m_Is_scene) {
			const char* str = lua_tostring(L, -1);
			if (!strcmp(str, "Func:AddChara"))l_AddChara(L);
			if (!strcmp(str, "Func:Flag"))l_Flag(L);
			if (!strcmp(str, "Func:FacialEffect"))l_Facial(L);
			if (!strcmp(str, "Func:Back"))l_Back(L);
			if (!strcmp(str, "Func:SetType"))l_Type(L);
			if (!strcmp(str, "Func:SetPos"))l_Pos(L);
			if (!strcmp(str, "Func:SetSize"))l_Size(L);
			if (!strcmp(str, "Func:EyeState"))l_EyeState(L);
			if (!strcmp(str, "Func:BodyState"))l_BodyState(L);
			if (!strcmp(str, "Func:BrowState"))l_BrowState(L);
			if (!strcmp(str, "Func:MouthState"))l_MouthState(L);
		}
		return 1;
	}
	int ImgCharaScript::l_AddChara(lua_State* L) {
		int size = lua_tonumber(L, -2);
		if (m_Animation.size() != size)m_Animation.resize(size);
		return 1;
	}
	int ImgCharaScript::l_Facial(lua_State* L) {
		int id = lua_tonumber(L, -5);
		int type = lua_tonumber(L, -4);
		float x = lua_tonumber(L, -3);
		float y = lua_tonumber(L, -2);
		if (isOK(id))m_Animation[id].summonFacial(type, x, y);
		return 1;
	}
	int ImgCharaScript::l_Flag(lua_State* L) {
		int id = lua_tonumber(L, -3);
		bool flag = lua_toboolean(L, -2);
		if (isOK(id))m_Animation[id].setFlag(flag);
		return 1;
	}
	int ImgCharaScript::l_Back(lua_State* L) {
		int id = lua_tonumber(L, -3);
		bool flag = lua_toboolean(L, -2);
		if (isOK(id))m_Animation[id].setBack(flag);
		return 1;
	}
	int ImgCharaScript::l_Type(lua_State* L) {
		int type = lua_tonumber(L, -2);
		int id = lua_tonumber(L, -3);
		if (isOK(id))m_Animation[id].setType(type);
		return 1;
	}
	int ImgCharaScript::l_Pos(lua_State* L) {
		int id = lua_tonumber(L, -4);
		float posX = lua_tonumber(L, -3);
		float posY = lua_tonumber(L, -2);
		//printfDx("%f", posY);
		//if (mAnimation.size() >= id)return 1;
		if (isOK(id))m_Animation[id].setPos(posX, posY);
		return 1;
	}
	int ImgCharaScript::l_Size(lua_State* L) {
		float size = lua_tonumber(L, -2);
		int id = lua_tonumber(L, -3);
		if (isOK(id))m_Animation[id].setSize(size);
		return 1;
	}
	int ImgCharaScript::l_BodyState(lua_State* L) {
		int state = lua_tonumber(L, -2);
		int id = lua_tonumber(L, -3);
		if (isOK(id))m_Animation[id].setBodyState(state);
		return 1;
	}
	int ImgCharaScript::l_EyeState(lua_State* L) {
		int state = lua_tonumber(L, -2);
		int id = lua_tonumber(L, -3);
		if (isOK(id))m_Animation[id].setEyeState(state);
		return 1;
	}
	int ImgCharaScript::l_BrowState(lua_State* L) {
		int state = lua_tonumber(L, -2);
		int id = lua_tonumber(L, -3);
		if (isOK(id))m_Animation[id].setBrowState(state);
		return 1;
	}
	int ImgCharaScript::l_MouthState(lua_State* L) {
		int state = lua_tonumber(L, -2);
		int id = lua_tonumber(L, -3);
		if (isOK(id))m_Animation[id].setMouthState(state);
		return 1;
	}
	bool ImgCharaScript::isOK(int id) {
		if (m_Animation.size() < 1)return false;
		if (BEDWEEN(id, 0, m_Animation.size()))return true;
		return false;
	}
}