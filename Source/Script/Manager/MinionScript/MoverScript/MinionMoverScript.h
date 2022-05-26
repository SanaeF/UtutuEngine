#pragma once
#include <memory>
#include "../../Lua/5.3/include/lua.hpp"
#include "../../Lua/5.3/include/lauxlib.h"
#include "../../Lua/5.3/include/lualib.h"

namespace script {
	class PlayerScript;
	class HelperScript;
	class MinionMoverScript {
	public:
		struct Minion_Info {
			float x;
			float y;
			float size;
			float angle;
			float speed;
			int state[2];
			int count;
			int who;
		};
	private:
		struct GetInfo_Flag {
			bool x;
			bool y;
			bool size;
			bool angle;
			bool speed;
			bool state[2];
			bool count;
			void init() {
				x = false;
				y = false;
				size = false;
				angle = false;
				speed = false;
				state[0] = false;
				state[1] = false;
				count = false;
			}
		};
		static Minion_Info mimion;
		bool mFlag;
		lua_State* ml_State = nullptr;
		std::shared_ptr<PlayerScript> mPlayer_Script;
		std::shared_ptr<HelperScript> mHelper_Script;
	public:
		MinionMoverScript();
		~MinionMoverScript();
		void Initialize();
		void finalize();
		void pause();
		void update(const char* file);
		Minion_Info output();
		void input(Minion_Info minion);
		bool isFlag();
	private:
		void checkMassage(lua_State* L);
		static int PlayerFunc(lua_State* L);
		static int l_Size(lua_State* L);
		static int l_PosX(lua_State* L);
		static int l_PosY(lua_State* L);
		static int l_Angle(lua_State* L);
		static int l_Speed(lua_State* L);
		static int l_Count(lua_State* L);
		static int l_State(lua_State* L);
		static int l_State2(lua_State* L);
		static int l_Who(lua_State* L);
	public:
		static Minion_Info minion_stats;
		static GetInfo_Flag isGetInfo;
	};
}