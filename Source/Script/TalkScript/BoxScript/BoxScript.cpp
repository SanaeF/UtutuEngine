#include "BoxScript.h"
#include <iostream>

#include"../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include"../../Source/library/Graphics/String/StringDX.h"
#include "../../Source/Resource/GUI/GameUIImage/GameUIImage.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"

#pragma warning(disable : 4996)
namespace script {
	const int trans_box_pos = 0;
	const int trans_text_pos = trans_box_pos - 280;
	BoxScript::Text_Info BoxScript::mText[5];
	int BoxScript::direction;
	bool BoxScript::m_Is_scene;
	bool BoxScript::m_Is_set_box;
	BoxScript::BoxScript(lua_State* L) {
		lua_register(L, "SetBoxFunc", l_SetBox);
		lua_register(L, "BoxFunc", l_Box);
		lua_register(L, "DirFunc", l_Func);
		lua_register(L, "TextColorFunc", l_TextColor);
	}
	BoxScript::~BoxScript() {
	}
	void BoxScript::draw() {
		if (!m_Is_set_box)return;
		if (direction == 0)
			lib::Graphics2D::drawRota(
				1920 / 2 + trans_box_pos,
				1440 / 2,
				1.0f,
				0.0f,
				res::GameUIImage::game_ui.sBox.left,
				true
			);
		if (direction == 1)
			lib::Graphics2D::drawRota(
				1920 / 2 + trans_box_pos,
				1440 / 2,
				1.0f,
				0.0f,
				res::GameUIImage::game_ui.sBox.right,
				true
			);
		if (direction == 2)
			lib::Graphics2D::drawRota(
				1920 / 2 + trans_box_pos,
				1440 / 2,
				1.0f,
				0.0f,
				res::GameUIImage::game_ui.sBox.gray,
				true
			);
		for (int i = 0; i < Text_TYPE::TEXT_MAX; i++) {
			draw(i);
		}
		lib::Graphics2D::setBright(255, 255, 255);
	}
	void BoxScript::draw(int id) {
		int font;
		if (id == NAME)font = res::TextUIImage::text_ui.font[res::FONT::FONT_SERIF];
		else font = res::TextUIImage::text_ui.font[res::FONT::FONT_SERIF];
		lib::StringDX::draw(
			mText[id].x + trans_text_pos,
			mText[id].y,
			mText[id].text,
			mText[id].color,
			font
		);
	}
	void BoxScript::setIsScene(bool flag) {
		m_Is_scene = flag;
	}
	void BoxScript::changeScene() {
		m_Is_set_box = false;
	}
	int BoxScript::l_SetBox(lua_State* L) {
		if (m_Is_scene)m_Is_set_box = true;
		return 1;
	}
	int BoxScript::l_Box(lua_State* L) {
		if (m_Is_scene) {
			int id = lua_tonumber(L, -5);//“o˜^”Ô†
			if (id == TEXT_MAX)return 1;
			mText[id].x = lua_tonumber(L, -4);
			mText[id].y = lua_tonumber(L, -3);
			mText[id].size = lua_tonumber(L, -2);
			sprintf(mText[id].text, "%s", lua_tostring(L, -1));
		}
		return 1;
	}
	int BoxScript::l_Func(lua_State* L) {
		if (m_Is_scene)direction = lua_tonumber(L, 1);
		return 1;
	}
	int BoxScript::l_TextColor(lua_State* L) {
		if (m_Is_scene) {
			int id = lua_tonumber(L, -4);
			int r = lua_tonumber(L, -3);
			int g = lua_tonumber(L, -2);
			int b = lua_tonumber(L, -1);
			mText[id].color = lib::StringDX::color(r, g, b);
		}
		return 1;
	}
}