#pragma once
#include "../../Lua/5.3/include/lua.hpp"
#include "../../Lua/5.3/include/lauxlib.h"
#include "../../Lua/5.3/include/lualib.h"
#pragma comment(lib, "../../Lua/5.3/lua53.lib")

#include <memory>
#include <vector>
namespace app {
	class Shake;
}
namespace script {
	class ScriptLoader;
	class BossScript;
	class ShotScript;
	class LazerScript;
	class TurnLazerScript;
	class BulletTypeScript;
	class BulletColorScript;
	class PlayerScript;
	class MinionScript;
	class ShakeScript;
	class SoundScript;
	class HelperScript;
	class EnemyImageScript;
}
namespace script {
	class BulletScript {
	private:
		static int m_Bullet_state;
		lua_State* m_L_state = nullptr;
		int m_State;
		int m_Boss_time;
		bool m_Flag;
		char* data;
		std::shared_ptr<ScriptLoader> m_Script_loader;//アーカイブのスクリプトをロードするクラス
		std::shared_ptr<ShotScript> m_Shot;
		std::shared_ptr<LazerScript> m_Lazer;
		std::shared_ptr<TurnLazerScript> m_TurnLazer;
		std::shared_ptr<BulletTypeScript> m_BulletImage;
		std::shared_ptr<BulletColorScript> m_BulletColor;
		std::shared_ptr<BossScript> m_Boss;
		std::shared_ptr<PlayerScript> m_Player;
		std::shared_ptr<MinionScript> m_Minion;
		std::shared_ptr<ShakeScript> m_Shake;
		std::shared_ptr<SoundScript> m_Sound;
		std::shared_ptr<HelperScript> m_Helper;
		std::shared_ptr<EnemyImageScript> m_EnemyImage;
	public:

		BulletScript();
		~BulletScript();
		//ポーズさせる(これが無いとバグる)
		void stop();
		void start();
		void update();
		void loadFile(char* file);

		void finalize();
		//弾幕が始まった事を弾にセットする
		void setBulletPhase();
		void setShake(std::shared_ptr<app::Shake>& shake);
		void setBossTime(int time);
		void set_state(int state);
		bool getFlag();
		int getShotSpawnedMax();
		std::shared_ptr<LazerScript>& getLazerScript();
		std::shared_ptr<TurnLazerScript>& getTLazer_Script();
		std::shared_ptr<BossScript>& getBossStats();
	private:
		void checkMassage(lua_State* L);
		void l_BossTime(lua_State* L);
		void diffilutly(lua_State* L);
		void create(lua_State* L);
		//スクリプトに登録した関数に適した関数を呼び出す
		static int callFunction(lua_State* L);
		static int l_PlaySE(lua_State* L);
		static int l_Crush(lua_State* L);
		static int l_BulletState(lua_State* L);

		static int l_Summon(lua_State* L);
		static int l_ResetPosition(lua_State* L);
		static int l_Timer(lua_State* L);
		static int l_WaitTimer(lua_State* L);
		static int l_InvalidBom(lua_State* L);
		static int l_Invincible(lua_State* L);
		static int l_SpecialBullet(lua_State* L);
		static int l_ReturnBack(lua_State* L);
		static int l_Serif(lua_State* L);
	};
}
