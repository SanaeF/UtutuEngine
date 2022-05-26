#pragma once
#include "../../Lua/5.3/include/lua.hpp"
#include "../../Lua/5.3/include/lauxlib.h"
#include "../../Lua/5.3/include/lualib.h"
#include <iostream>
#include <memory>

namespace manager {
	class BossManager;
}
namespace script {
	class BossScript {
	private:
		//ボスとスクリプトのやり取りは慎重に行うこと！
		struct Move {
			bool flag;
			bool flag_rand;
			float x;
			float y;
			float x0;
			float y0;
			float x1;
			float y1;
			float dist;
			int time;
		};
		struct SerifInfo {
			bool flag;
			float x;
			float y;
			int time;
			std::string text;
			void clear() {
				flag = false;
				x = 0.f;
				y = 0.f;
				time = 0;
				text.clear();
			}
		};
		struct BossInfo {
			float x;
			float y;
			int wait_time;
			int init_time;
			int init_hp;
			int time;
			int hp;
			int bullet_state;
			int motion_type;
			bool is_last;
			bool is_main_bullet;
			bool is_charge;
			bool is_NoDamage;
			bool is_no_del_minion;
			bool is_inv_bom;
		};
		struct GetFlag {
			bool x;
			bool y;
			bool wait_time;
			bool time;
			bool hp;
			bool is_last;
			bool is_main_bullet;
			bool bullet_state;
			bool motion_type;
			bool is_NoDamage;
			void clear() {
				x = false;
				y = false;
				wait_time = false;
				time = false;
				hp = false;
				is_last = false;
				bullet_state = false;
				is_main_bullet = false;
				is_NoDamage = false;
				motion_type = false;
			}
		};
		//std::shared_ptr<manager::BossManager>* m_Boss_manager;
		static Move m_Move;
		static SerifInfo m_Serif;
		static BossInfo m_Boss;
		static BossInfo m_Boss_stats;
		static GetFlag m_Get_flag;
	public:
		BossScript(lua_State* L);

		void setInfo(float x, float y, int wait_time, int time, int hp, int state);
		float getPos_x();
		float getPos_y();
		int initTime();
		int initHP();
		int getTime();
		int getHP();
		int getWaitTime();
		bool isLast();
		bool isNoDamage();
		bool isMove();
		bool isMoveRand();
		bool isCharge();
		GetFlag& isGetValue();
		BossInfo& getInputData();
		SerifInfo& getSerifUI();
		Move& getParam();
	private:
		//スクリプトに登録した関数に適した関数を呼び出す
		static int callFunction(lua_State* L);
		static int l_x(lua_State* L);
		static int l_y(lua_State* L);
		static int l_waitTime(lua_State* L);
		static int l_initTime(lua_State* L);
		static int l_initHP(lua_State* L);
		static int l_time(lua_State* L);
		static int l_hp(lua_State* L);
		static int l_isLast(lua_State* L);
		static int l_isNoDamage(lua_State* L);
		static int l_isMainBullet(lua_State* L);
		static int l_moveFlag(lua_State* L);
		static int l_moveRandFlag(lua_State* L);
		static int l_setMove(lua_State* L);
		static int l_setRandomMove(lua_State* L);
		static int l_charge(lua_State* L);
		static int l_bulletState(lua_State* L);
		static int l_MotionType(lua_State* L);
		static int l_SerifBox(lua_State* L);
		static int l_isNoDelMinon(lua_State* L);
		static int l_isInvBom(lua_State* L);
		static int l_DeathEffect(lua_State* L);
	};
}