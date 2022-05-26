#include "BossBulletScript.h"
#include <iostream>
#include <windows.h>
#include "../../Source/library/FileManager/FileManager.h"
#include "../../Source/Script/ScriptLoader/ScriptLoader.h"
#include "../../Source/Script/Manager/BossScript/BossScript.h"
#include "../../Source/Script/Manager/PlayerScript/PlayerScript.h"
#include "../../Source/Script/Manager/MinionScript/MinionScript.h"
#include "../../Source/Script/Manager/ShakeScript/ShakeScript.h"
#include "../../Source/Script/Manager/SoundScript/SoundScript.h"
#include "../../Source/Script/Manager/BulletScript/Color/BulletColorScript.h"
#include "../../Source/Script/Manager/BulletScript/Type/BulletTypeScript.h"
#include "../../Source/Script/Manager/BulletScript/Shot/ShotScript.h"
#include "../../Source/Script/Manager/BulletScript/Lazer/LazerScript.h"
#include "../../Source/Script/Manager/BulletScript/TurnLazer/TurnLazerScript.h"
#include "../../Source/Script/Manager/HelperScript/HelperScript.h"
#include "../../Source/Script/Manager/EnemyImageScript/EnemyImageScript.h"
#include "../../Source/Object/Bullet/Shot/Shot_Info.h"
#include "../../Source/Object/Bullet/Lazer/Lazer_Info.h"
#include "../../Source/Object/Bullet/TurnLazer/TurnLazer_Info.h"
#include "../../Source/Object/Minion/Minion.h"
#include "../../Source/EffectTools/Shake/Shake.h"
#include "../../Source/Resource/BulletImage/BulletImage.h"
#include "../../Source/Application/Sound/Sound.h"
#include "../../Source/SystemProp/GameStatsProp.h"
#include "../../Source/SystemProp/GameSceneProp/GameSceneProp.h"


#include "../../Source/Manager/BossManager/BossManager.h"
#include "../../Source/Manager/BossManager/BossUI/BossUI.h"
#pragma warning(disable : 4996)

namespace script {
	int BulletScript::m_Bullet_state;
	void BulletScript::start() {
		if (m_L_state == nullptr)return;
		lua_getglobal(m_L_state, "Initialize");
		lua_pcall(m_L_state, 0, 0, 0);
		if (USE_DEBUGLOG)checkMassage(m_L_state);
	}
	void BulletScript::update() {
		if (m_L_state == nullptr)return;
		lua_getglobal(m_L_state, "BossShot");
		lua_pcall(m_L_state, 0, 0, 0);
		l_BossTime(m_L_state);
		if(USE_DEBUGLOG)checkMassage(m_L_state);
	}
	void BulletScript::create(lua_State* L) {
		lua_register(L, "BulletFunc", callFunction);
		l_BossTime(L);
		diffilutly(L);
	}
	int BulletScript::callFunction(lua_State* L) {
		const char* str = lua_tostring(L, -1);
		if (str == nullptr)return 1;
		if (!strcmp(str, "Func:Summon"))l_Summon(L);
		if (!strcmp(str, "Func:ResetPosition"))l_ResetPosition(L);
		if (!strcmp(str, "Func:Timer"))l_Timer(L);
		if (!strcmp(str, "Func:SetWaitTime"))l_WaitTimer(L);
		if (!strcmp(str, "Func:SetInvalidBom"))l_InvalidBom(L);
		if (!strcmp(str, "Func:SetInbicible"))l_Invincible(L);
		if (!strcmp(str, "Func:SetSpecialBullet"))l_SpecialBullet(L);
		if (!strcmp(str, "Func:SetReturnBack"))l_ReturnBack(L);
		if (!strcmp(str, "Func:SetSerifBox"))l_Serif(L);

		if (!strcmp(str, "Func:State"))l_BulletState(L);
		return 1;
	}
	int BulletScript::l_Summon(lua_State* L) {
		auto boss_manager = manager::BossManager::getInstance();
		int index = lua_tonumber(L, -2);
		int type = lua_tonumber(L, -3);
		float y = lua_tonumber(L, -4);
		float x = lua_tonumber(L, -5);
		boss_manager->summon(x, y, type, index);
		return 1;
	}
	int BulletScript::l_ResetPosition(lua_State* L) {
		auto boss_manager = manager::BossManager::getInstance();
		boss_manager->changePosition();
		return 1;
	}
	int BulletScript::l_Timer(lua_State* L) {
		auto boss_manager = manager::BossManager::getInstance();
		if (lua_toboolean(L, -2)) {
			int time = lua_tonumber(L, -3);
			boss_manager->setTimer(time*60);
		}
		else {
			lua_pushnumber(L, boss_manager->getTime());
		}
		return 1;
	}
	int BulletScript::l_WaitTimer(lua_State* L) {
		auto boss_manager = manager::BossManager::getInstance();
		int time = lua_tonumber(L, -2);
		boss_manager->setWaitTime(time * 60);
		return 1;
	}
	int BulletScript::l_InvalidBom(lua_State* L) {
		auto boss_manager = manager::BossManager::getInstance();
		bool flag = lua_toboolean(L, -2);
		boss_manager->setInvalidBom(flag);
		return 1;
	}
	int BulletScript::l_Invincible(lua_State* L) {
		auto boss_manager = manager::BossManager::getInstance();
		bool flag = lua_toboolean(L, -2);
		boss_manager->setInvincible(flag);
		return 1;
	}
	int BulletScript::l_SpecialBullet(lua_State* L) {
		auto boss_manager = manager::BossManager::getInstance();
		bool flag = lua_toboolean(L, -2);
		boss_manager->setSpecialBullet(flag);
		return 1;
	}
	int BulletScript::l_ReturnBack(lua_State* L) {
		auto boss_manager = manager::BossManager::getInstance();
		bool flag = lua_toboolean(L, -2);
		boss_manager->setReturnBack(flag);
		return 1;
	}
	int BulletScript::l_Serif(lua_State* L) {
		auto& ui = manager::BossManager::getInstance()->getUIInstance();
		float x = lua_tonumber(L, -5);
		float y = lua_tonumber(L, -4);
		int time = lua_tonumber(L, -3);
		std::string text = lua_tostring(L, -2);
		ui->setSerifBox(time, x, y, text);
		return 1;
	}
	void BulletScript::l_BossTime(lua_State* L) {
		auto boss_manager = manager::BossManager::getInstance();
		lua_pushnumber(L, boss_manager->getCount());
		lua_setglobal(L, "shot_time");
	}
	void BulletScript::diffilutly(lua_State* L) {
		lua_pushnumber(L, GameSceneProp::difficulty);
		lua_setglobal(L, "difficulty");
	}
	int BulletScript::l_PlaySE(lua_State* L) {
		int se_id = lua_tonumber(L, -1);
		app::Sound::sound.playSE(se_id);
		return 1;
	}

	int BulletScript::l_BulletState(lua_State* L) {
		if (lua_toboolean(L, -2)) {
			int num = lua_tonumber(L, -3);
			m_Bullet_state = num;
		}
		else {
			lua_pushnumber(L, m_Bullet_state);
		}
		return 1;
	}
	int BulletScript::l_Crush(lua_State* L) {
		return 1;
	}
	void BulletScript::setBulletPhase() {
		m_Shot->setUpdatePhase();
		m_Lazer->setUpdatePhase();
		m_TurnLazer->setUpdatePhase();
	}
	void BulletScript::setBossTime(int time) {
		m_Boss_time = time;
	}
	void BulletScript::set_state(int state) {
		this->m_State = state;
	}
	void BulletScript::setShake(std::shared_ptr<app::Shake>& shake) {
		m_Shake->setShake(shake);
	}

	bool BulletScript::getFlag() {
		return this->m_Flag;
	}
	int BulletScript::getShotSpawnedMax() {
		return m_Shot->getShotSpawnedMax();
	}
	std::shared_ptr<LazerScript>& BulletScript::getLazerScript() {
		return m_Lazer;
	}
	std::shared_ptr<TurnLazerScript>& BulletScript::getTLazer_Script() {
		return m_TurnLazer;
	}
	std::shared_ptr<BossScript>& BulletScript::getBossStats() {
		return m_Boss;
	}

	void BulletScript::loadFile(char* file) {
		m_Script_loader->openFile(file);
		data = m_Script_loader->getSource();
		m_Bullet_state = 0;
		m_L_state = luaL_newstate();
		luaL_openlibs(m_L_state);
		m_Boss.reset(new BossScript(m_L_state));
		m_Player.reset(new PlayerScript(m_L_state));
		m_Shake.reset(new ShakeScript(m_L_state));
		m_Sound->setScript(m_L_state);
		m_BulletImage->setScript(m_L_state);
		m_BulletColor->setScript(m_L_state);
		m_Shot->createScript(m_L_state, true);
		m_Lazer->createScript(m_L_state, true);
		m_TurnLazer->createScript(m_L_state, true);
		m_Minion->createScript(m_L_state);
		m_Helper->createScript(m_L_state);
		m_EnemyImage->setScript(m_L_state);
		m_Boss_time = -1;
		create(m_L_state);
		luaL_loadstring(m_L_state, data);//•¶Žš—ñ‚Åƒ[ƒh
		lua_pcall(m_L_state, 0, 0, 0);
		m_Flag = true;
	}
	void BulletScript::stop() {
		if (m_L_state == nullptr)return;
		lua_close(m_L_state);
		m_L_state = nullptr;
	}
	void BulletScript::checkMassage(lua_State* L) {
		if (lua_gettop(L) == LUA_TSTRING) {
			auto log = lua_tostring(L, -1);
			OutputDebugString("BulletScript->");
			OutputDebugString(log);
			OutputDebugString("\n");
		}
	}
	void BulletScript::finalize() {
		m_Flag = false;
		//m_Script_loader->bufferDelete();
	}
	BulletScript::BulletScript() :
		m_State(0),
		m_Boss_time(-1),
		m_Flag(false)
	{
		m_Script_loader.reset(new ScriptLoader());
		m_BulletImage.reset(new BulletTypeScript());
		m_BulletColor.reset(new BulletColorScript());
		m_Shot.reset(new ShotScript());
		m_Lazer.reset(new LazerScript());
		m_TurnLazer.reset(new TurnLazerScript());
		m_Minion.reset(new MinionScript());
		m_Helper.reset(new HelperScript());
		m_EnemyImage.reset(new EnemyImageScript());
		m_Sound.reset(new SoundScript());
	}
	BulletScript::~BulletScript() {
		finalize();
	}
}