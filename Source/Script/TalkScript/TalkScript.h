#pragma once
#include "../../Lua/5.3/include/lua.hpp"
#include "../../Lua/5.3/include/lauxlib.h"
#include "../../Lua/5.3/include/lualib.h"
#include <memory>

namespace script {
	class ScriptLoader;
	class BoxScript;
	class ImgCharaScript;
	class PlayerScript;
	class EnemyImageScript;
	class HelperScript;
	class TalkScript {
	private:
		char* data;
		struct ScriptInfo {
			int m_Scene;
			int end_scene;
			int playBGM;
			int called_boss_type;
			int bullet_num;
			int skip_wait_time;
			bool isBoss_smmon;
			bool is_smmon_inter_boss;
			bool isJoin_Bullet;
			bool isDoEndTalk;
			bool isGoEnding;
			bool is_skip;
			void init() {
				m_Scene = 0;
				end_scene = 0;
				playBGM = 0;
				called_boss_type = 0;
				bullet_num = 0;
				skip_wait_time = 0;
				isBoss_smmon = false;
				isJoin_Bullet = false;
				isDoEndTalk = false;
				isGoEnding = false;
				is_skip = false;
			}
		};
		lua_State* m_L_state = nullptr;
		std::shared_ptr<ScriptLoader> m_Script_loader;
		std::shared_ptr<PlayerScript> m_Player;
		std::shared_ptr<EnemyImageScript> m_EnemyImage;
		std::shared_ptr<HelperScript> m_Helper;
		static ScriptInfo m_Input_info;
		static int m_Scene;
		static std::shared_ptr<BoxScript> m_BoxText;
		static std::shared_ptr<ImgCharaScript> m_CharaAnim;
	public:
		TalkScript();
		~TalkScript();
		void initialize(char* file);
		void finalize();
		void clearValue();
		void update();
		void draw();
		void setScene(int num);
		void setEndTalk(bool flag);
		void changeScene();
		bool isSummonBoss();
		bool isJoinBullet();
		bool isEnd();
		ScriptInfo& getInfo();
	private:
		void checkValue(lua_State* L);
		static void setDrawUpdate(bool flag);
		static bool isSceneTrue();
		//スクリプトに登録した関数に適した関数を呼び出す
		static int callFunction(lua_State* L);
		static int l_Scene(lua_State* L);
		static int l_WaitAndSkip(lua_State* L);
		static int l_PlayBGM(lua_State* L);
		static int l_SummonBoss(lua_State* L);
		static int l_JoinBullet(lua_State* L);
		static int l_EndScene(lua_State* L);
		static int l_GoEnding(lua_State* L);
	};
}