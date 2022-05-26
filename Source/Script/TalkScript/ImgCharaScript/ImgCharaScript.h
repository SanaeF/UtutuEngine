#pragma once
#include "../../Lua/5.3/include/lua.hpp"
#include "../../Lua/5.3/include/lauxlib.h"
#include "../../Lua/5.3/include/lualib.h"
#include <vector>
namespace app {
	class CharaImgManager;
}
namespace script {
	class ImgCharaScript {
	private:
		static std::vector<app::CharaImgManager> m_Animation;
		static bool m_Is_scene;
	public:
		ImgCharaScript(lua_State* L);
		~ImgCharaScript();
		void draw();
		void update();
		void setIsScene(bool flag);
	private:
		//スクリプトに登録した関数に適した関数を呼び出す
		static int callFunction(lua_State* L);
		static int l_AddChara(lua_State* L);
		static int l_Facial(lua_State* L);
		static int l_Flag(lua_State* L);
		static int l_Back(lua_State* L);
		static int l_Type(lua_State* L);
		static int l_Pos(lua_State* L);
		static int l_Size(lua_State* L);
		static int l_BodyState(lua_State* L);
		static int l_EyeState(lua_State* L);
		static int l_BrowState(lua_State* L);
		static int l_MouthState(lua_State* L);
		static bool isOK(int id);
	};
}