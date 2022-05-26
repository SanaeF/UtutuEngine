#pragma once
#include "../../Lua/5.3/include/lua.hpp"
#include "../../Lua/5.3/include/lauxlib.h"
#include "../../Lua/5.3/include/lualib.h"
#include <memory>
namespace script {
	class ShotScript;
	class LazerScript;
	class TurnLazerScript;
	class BulletTypeScript;
	class BulletColorScript;
	class HelperScript;
	class PlayerScript;
	class SoundScript;
	class MinionBulletScript {
	private:
		struct Minion_Info {
			float x;
			float y;
			int count;
			int bulletColor;
			int bulletType;
			int who;
		};
		static Minion_Info minion;
		lua_State* ml_State = nullptr;

		std::shared_ptr<PlayerScript> mPlayer;
		std::shared_ptr<ShotScript> mShot_Script;
		std::shared_ptr<LazerScript> mLazer_Script;
		std::shared_ptr<TurnLazerScript> mT_Lazer_Script;
		std::shared_ptr<BulletTypeScript> mBulletType_Script;
		std::shared_ptr<BulletColorScript> mBulletColor_Script;
		std::shared_ptr<HelperScript> mHelper_Script;
		std::shared_ptr<SoundScript> mSound;
		bool mFlag;
	public:
		MinionBulletScript();
		~MinionBulletScript();
		void Initialize();
		void finalize();
		void pause();
		void update(const char* file, float x, float y, int count, int bullet_type, int bullet_color, int who);
		bool isFlag();
	private:
		static int MinionFunc(lua_State* L);
		static int l_getX(lua_State* L);
		static int l_getY(lua_State* L);
		static int l_getCount(lua_State* L);
		static int l_getBulletColor(lua_State* L);
		static int l_getBulletType(lua_State* L);
		static int l_getWho(lua_State* L);
		void checkValue(lua_State* L);
	};
}