#pragma once
#include "../../Lua/5.3/include/lua.hpp"
#include "../../Lua/5.3/include/lauxlib.h"
#include "../../Lua/5.3/include/lualib.h"

namespace script {
	class SoundScript {
	private:
	public:
		SoundScript();
		//�X�N���v�g�ɓo�^�����֐��ɓK�����֐����Ăяo��
		void setScript(lua_State* L);
	private:
		void setID(lua_State* L);
		static int l_PlaySE(lua_State* L);
	};
}