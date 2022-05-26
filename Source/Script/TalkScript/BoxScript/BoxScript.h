#pragma once
#include "../../Lua/5.3/include/lua.hpp"
#include "../../Lua/5.3/include/lauxlib.h"
#include "../../Lua/5.3/include/lualib.h"

namespace script {
	class BoxScript {
	private:
		enum Text_TYPE {
			NAME,
			TEXT1,
			TEXT2,
			TEXT3,
			TEXT4,
			TEXT_MAX
		};
		enum {
			MSG_BOX_POS_1 = 282,
			MSG_BOX_POS_2 = -282
		};
		struct Text_Info {
			float x;
			float y;
			float size;
			int color;
			char text[128];
		};
		lua_State* m_L_state = nullptr;
		static Text_Info mText[TEXT_MAX];
		static int direction;
		static bool m_Is_scene;
		static bool m_Is_set_box;
	public:
		//スクリプトに登録した関数に適した関数を呼び出す
		BoxScript(lua_State* L);
		~BoxScript();
		void draw();
		void setIsScene(bool flag);
		void changeScene();
	private:
		static int l_SetBox(lua_State* L);
		static int l_Box(lua_State* L);
		static int l_Func(lua_State* L);
		static int l_TextColor(lua_State* L);
		void draw(int id);
	};
}