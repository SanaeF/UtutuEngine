#pragma once
#include "../../Lua/5.3/include/lua.hpp"
#include "../../Lua/5.3/include/lauxlib.h"
#include "../../Lua/5.3/include/lualib.h"
#include <memory>

namespace script {
	class ScriptLoader;
	class ShotScript;
	class LazerScript;
	class TurnLazerScript;
	class BulletTypeScript;
	class BulletColorScript;
	class MinionScript;
	class HelperScript;
	class EnemyImageScript;
	class PlayerScript;
	class SoundScript;
}
namespace script {
	class TimeLineScript {
	private:
		lua_State* m_L_state = nullptr;
		std::shared_ptr<ScriptLoader> m_Script_loader;
		std::shared_ptr<PlayerScript> m_Player;
		std::shared_ptr<ShotScript> m_Shot;
		std::shared_ptr<LazerScript> m_Lazer;
		std::shared_ptr<TurnLazerScript> m_T_lazer;
		std::shared_ptr<BulletTypeScript> m_Bullet_type;
		std::shared_ptr<BulletColorScript> m_BulletColor;
		std::shared_ptr<MinionScript> m_Minion;
		std::shared_ptr<HelperScript> m_Helper;
		std::shared_ptr<EnemyImageScript> m_EnemyImage;
		std::shared_ptr<SoundScript> m_Sound;
		struct InterBoss {
			bool is_summon;
			int boss_type;
			int bullet_num;
		};
		bool m_Flag;
		char* data;
		static InterBoss m_Inter_boss;
		static bool m_Is_road;
		static bool m_Is_talk_scene;
		static bool m_Is_sub_title;
		static bool m_Is_ending_phase;
		static int m_Is_talk_id;
	public:
		TimeLineScript();
		~TimeLineScript();
		void initialize(char* file);
		void pause();
		void update(int time);
		void finalize();
		void setSubTitle(bool flag);
		void setTalkScene(bool flag);
		int getTalkID();
		bool isTalkScene();
		bool isRoad();
		bool isSubTitle();
		bool isEndingPhase();
		InterBoss* pInterBoss();
	private:
		void scriptProp(lua_State* L);
		//スクリプトに登録した関数に適した関数を呼び出す
		static int callFunction(lua_State* L);
		static int l_RoadFlag(lua_State* L);
		static int l_TalkScene(lua_State* L);
		static int l_SubTitle(lua_State* L);
		static int l_InterBoss(lua_State* L);
		static int l_GoEnding(lua_State* L);
		void checkValue(lua_State* L);
	};
}