#include "TimeLineScript.h"
#include <iostream>
#include <windows.h>
#include "../../Source/Script/ScriptLoader/ScriptLoader.h"
#include "../../Source/Script/Manager/SoundScript/SoundScript.h"
#include "../../Source/Script/Manager/PlayerScript/PlayerScript.h"
#include "../../Source/Script/Manager/MinionScript/MinionScript.h"
#include "../../Source/Script/Manager/BulletScript/Shot/ShotScript.h"
#include "../../Source/Script/Manager/BulletScript/Lazer/LazerScript.h"
#include "../../Source/Script/Manager/BulletScript/TurnLazer/TurnLazerScript.h"
#include "../../Source/Script/Manager/BulletScript/Color/BulletColorScript.h"
#include "../../Source/Script/Manager/BulletScript/Type/BulletTypeScript.h"
#include "../../Source/Script/Manager/EnemyImageScript/EnemyImageScript.h"
#include "../../Source/Script/Manager/HelperScript/HelperScript.h"
#include "../../Source/SystemProp/GameStatsProp.h"
#include "../../Source/SystemProp/GameSceneProp/GameSceneProp.h"
#include "../../Source/Manager/BossManager/BossManager.h"
namespace script {
	bool TimeLineScript::m_Is_road = true;
	bool TimeLineScript::m_Is_talk_scene = false;
	bool TimeLineScript::m_Is_sub_title = false;
	bool TimeLineScript::m_Is_ending_phase = false;
	int TimeLineScript::m_Is_talk_id = -1;

	TimeLineScript::InterBoss TimeLineScript::m_Inter_boss;

	void TimeLineScript::update(int time) {
		if (m_L_state == nullptr)return;
		//スクリプトの関数実行
		lua_getglobal(m_L_state, "TimeLine");
		lua_pcall(m_L_state, 0, 0, 0);
		//ステージの現在カウントを転送
		lua_pushnumber(m_L_state, time);
		lua_setglobal(m_L_state, "stage_time");
		//難易度を転送
		lua_pushnumber(m_L_state, GameSceneProp::difficulty);
		lua_setglobal(m_L_state, "difficulty");
		//アリスモードのフラグを転送
		lua_pushboolean(m_L_state, GameSceneProp::is_alice);
		lua_setglobal(m_L_state, "IS_ALICE_MODE");
		if(USE_DEBUGLOG)checkValue(m_L_state);
	}
	void TimeLineScript::scriptProp(lua_State* L) {
		lua_register(L, "TimeFunc", callFunction);
	}
	void TimeLineScript::setSubTitle(bool flag) {
		m_Is_sub_title = flag;
	}
	void TimeLineScript::setTalkScene(bool flag) {
		m_Is_talk_scene = flag;
	}
	int TimeLineScript::getTalkID() {
		return m_Is_talk_id;
	}
	bool TimeLineScript::isTalkScene() {
		return m_Is_talk_scene;
	}
	bool TimeLineScript::isRoad() {
		return this->m_Is_road;
	}
	bool TimeLineScript::isSubTitle() {
		return m_Is_sub_title;
	}
	TimeLineScript::InterBoss* 
		TimeLineScript::pInterBoss() {
		return &m_Inter_boss;
	}
	int TimeLineScript::callFunction(lua_State* L) {
		const char* str = lua_tostring(L, -1);
		if (!strcmp(str, "Func:RoadFlag"))l_RoadFlag(L);
		if (!strcmp(str, "Func:TalkSceneFlag"))l_TalkScene(L);
		if (!strcmp(str, "Func:SubTitleFlag"))l_SubTitle(L);
		if (!strcmp(str, "Func:InterBoss"))l_InterBoss(L);
		if (!strcmp(str, "Func:GoEnding"))l_GoEnding(L);
		return 1;
	}
	int TimeLineScript::l_RoadFlag(lua_State* L) {
		bool flag = lua_toboolean(L, -2);
		m_Is_road = flag;
		return 1;
	}
	int TimeLineScript::l_TalkScene(lua_State* L) {
		bool flag = lua_toboolean(L, -2);
		int num = lua_tonumber(L, -3);
		m_Is_talk_scene = flag;
		m_Is_talk_id = num;
		return 1;
	}
	int TimeLineScript::l_SubTitle(lua_State* L) {
		bool flag = lua_toboolean(L, -2);
		m_Is_sub_title = flag;
		return 1;
	}
	int TimeLineScript::l_InterBoss(lua_State* L) {
		int type = lua_tonumber(L, -4);
		int first = lua_tonumber(L, -3);
		int end = lua_tonumber(L, -2);
		manager::BossManager::getInstance()->summon(type);
		manager::BossManager::getInstance()->startBullet(first, end);
		return 1;
	}
	int TimeLineScript::l_GoEnding(lua_State* L) {
		bool flag = lua_toboolean(L, -2);
		m_Is_ending_phase = flag;
		return 1;
	}
	bool TimeLineScript::isEndingPhase() {
		return m_Is_ending_phase;
	}
	void TimeLineScript::initialize(char* file) {
		m_Script_loader->openFile(file);
		data = m_Script_loader->getSource();
		m_L_state = luaL_newstate();
		luaL_openlibs(m_L_state);
		m_Player.reset(new PlayerScript(m_L_state));
		m_Sound->setScript(m_L_state);
		m_Shot->createScript(m_L_state,false);
		m_Lazer->createScript(m_L_state, false);
		m_T_lazer->createScript(m_L_state, false);
		m_Bullet_type->setScript(m_L_state);
		m_BulletColor->setScript(m_L_state);
		m_Minion->createScript(m_L_state);
		m_Helper->createScript(m_L_state);
		m_EnemyImage->setScript(m_L_state);
		scriptProp(m_L_state);
		luaL_loadstring(m_L_state, data);//文字列でロード
		lua_pcall(m_L_state, 0, 0, 0);
		m_Shot->setUpdatePhase();
		m_Lazer->setUpdatePhase();
		m_T_lazer->setUpdatePhase();
		m_Flag = true;
		m_Is_road = true;
		m_Is_ending_phase = false;
		m_Is_talk_id = -1;
		m_Inter_boss.boss_type = 0;
		m_Inter_boss.bullet_num = 0;
		m_Inter_boss.is_summon = false;
	}
	void TimeLineScript::pause() {
		//m_Script_loader->reset();
	}
	void TimeLineScript::checkValue(lua_State* L) {
		if (lua_gettop(L) == LUA_TSTRING) {
			auto log = lua_tostring(L, -1);
			OutputDebugString("TimeLineScript->");
			OutputDebugString(log);
			OutputDebugString("\n");
		}
	}
	void TimeLineScript::finalize() {
		//m_Script_loader->bufferDelete();
	}
	TimeLineScript::TimeLineScript() :
		m_Flag(false)
	{
		m_Script_loader.reset(new ScriptLoader());
		m_Minion.reset(new MinionScript());
		m_Bullet_type.reset(new BulletTypeScript());
		m_BulletColor.reset(new BulletColorScript());
		m_Shot.reset(new ShotScript());
		m_Lazer.reset(new LazerScript());
		m_T_lazer.reset(new TurnLazerScript());
		m_Helper.reset(new HelperScript());
		m_EnemyImage.reset(new EnemyImageScript());
		m_Sound.reset(new SoundScript());
	}
	TimeLineScript::~TimeLineScript() {
		finalize();
	}
}