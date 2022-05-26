#include "TalkScript.h"
#include <windows.h>
#include "../../Source/Script/ScriptLoader/ScriptLoader.h"
#include "../../Source/Script/TalkScript/BoxScript/BoxScript.h"
#include "../../Source/Script/TalkScript/ImgCharaScript/ImgCharaScript.h"
#include "../../Source/Script/Manager/PlayerScript/PlayerScript.h"
#include "../../Source/Script/Manager/EnemyImageScript/EnemyImageScript.h"
#include "../../Source/Script/Manager/HelperScript/HelperScript.h"
#include "../../Source/Application/Sound/Sound.h"
#include "../../Source/Manager/BossManager/BossManager.h"
namespace script {
	int TalkScript::m_Scene = 0;
	TalkScript::ScriptInfo TalkScript::m_Input_info;
	std::shared_ptr<BoxScript> TalkScript::m_BoxText;
	std::shared_ptr<ImgCharaScript> TalkScript::m_CharaAnim;
	void TalkScript::update() {
		lua_getglobal(m_L_state, "TalkScene");
		lua_pcall(m_L_state, 0, 0, 0);
		m_CharaAnim->update();
	}
	void TalkScript::draw() {
		m_CharaAnim->draw();
		m_BoxText->draw();
	}
	void TalkScript::setDrawUpdate(bool flag) {
		m_BoxText->setIsScene(flag);
		m_CharaAnim->setIsScene(flag);
	}
	void TalkScript::setScene(int num) {
		m_Scene = num;
	}
	void TalkScript::changeScene() {
		m_BoxText->changeScene();
	}
	bool TalkScript::isEnd() {
		if (m_Scene == m_Input_info.end_scene) {
			lua_close(m_L_state);
			if (m_Input_info.isBoss_smmon || m_Input_info.is_smmon_inter_boss)m_Input_info.isJoin_Bullet = true;
			return true;
		}
		return false;
	}
	bool TalkScript::isSceneTrue() {
		if (m_Scene == m_Input_info.m_Scene)return true;
		return false;
	}
	int TalkScript::callFunction(lua_State* L) {
		const char* str = lua_tostring(L, -1);
		if (!strcmp(str, "Func:Scene"))l_Scene(L);
		if (!strcmp(str, "Func:WaitAndSkip"))l_WaitAndSkip(L);
		if (!strcmp(str, "Func:PlayBGM"))l_PlayBGM(L);
		if (!strcmp(str, "Func:SummonBoss"))l_SummonBoss(L);
		if (!strcmp(str, "Func:JoinBullet"))l_JoinBullet(L);
		if (!strcmp(str, "Func:End"))l_EndScene(L);
		if (!strcmp(str, "Func:GoEnding"))l_GoEnding(L);
		return 1;
	}
	int TalkScript::l_Scene(lua_State* L) {
		m_Input_info.m_Scene = lua_tonumber(L, -2);
		if (m_Scene == m_Input_info.m_Scene)setDrawUpdate(true);
		else setDrawUpdate(false);
		return 1;
	}
	int TalkScript::l_WaitAndSkip(lua_State* L) {
		if (isSceneTrue()) {
			m_Input_info.skip_wait_time = lua_tonumber(L, -2);
			m_Input_info.is_skip = true;
		}
		return 1;
	}
	int TalkScript::l_PlayBGM(lua_State* L) {
		if (isSceneTrue()) {
			int bgm = lua_tonumber(L, -2);
			app::Sound::sound.playBGM(bgm);
		}
		return 1;
	}
	int TalkScript::l_SummonBoss(lua_State* L) {
		if (isSceneTrue()) {
			int index = lua_tonumber(L, -2);
			int type = lua_tonumber(L, -3);
			manager::BossManager::getInstance()->summon(type, index);
		}
		return 1;
	}
	int TalkScript::l_JoinBullet(lua_State* L) {
		if (isSceneTrue()) {
			int end = lua_tonumber(L, -2);
			int first = lua_tonumber(L, -3);
			manager::BossManager::getInstance()->startBullet(first, end);
		}
		return 1;
	}
	int TalkScript::l_EndScene(lua_State* L) {
		m_Input_info.end_scene = lua_tonumber(L, -2);
		return 1;
	}
	int TalkScript::l_GoEnding(lua_State* L) {
		if (isSceneTrue())m_Input_info.isGoEnding = lua_toboolean(L, -2);
		return 1;
	}
	TalkScript::ScriptInfo&
		TalkScript::getInfo() {
		return m_Input_info;
	}
	void TalkScript::initialize(char* file) {
		m_Script_loader->openFile(file);
		data = m_Script_loader->getSource();
		m_Input_info.init();
		clearValue();
		m_L_state = luaL_newstate();
		luaL_openlibs(m_L_state);
		m_BoxText.reset(new BoxScript(m_L_state));
		m_CharaAnim.reset(new ImgCharaScript(m_L_state));
		m_Player.reset(new PlayerScript(m_L_state));
		m_EnemyImage->setScript(m_L_state);
		m_Helper->createScript(m_L_state);
		lua_register(m_L_state, "TalkFunc", callFunction);
		luaL_loadstring(m_L_state, data);//•¶Žš—ñ‚Åƒ[ƒh
		lua_pcall(m_L_state, 0, 0, 0);
		checkValue(m_L_state);
	}
	void TalkScript::clearValue() {
		m_Input_info.end_scene = 0;
		m_Input_info.isGoEnding = false;
		m_Input_info.isBoss_smmon = false;
		m_Input_info.is_smmon_inter_boss = false;
		m_Input_info.isJoin_Bullet = false;
		m_Scene = 0;
		m_Input_info.m_Scene = 0;
	}
	void TalkScript::checkValue(lua_State* L) {
		if (lua_gettop(L) == LUA_TSTRING) {
			auto log = lua_tostring(L, -1);
			OutputDebugString("TalkScript->");
			OutputDebugString(log);
			OutputDebugString("\n");
		}
	}
	void TalkScript::finalize() {
		//m_Script_loader->bufferDelete();
	}
	TalkScript::TalkScript() {
		m_Script_loader.reset(new ScriptLoader());
		m_EnemyImage.reset(new EnemyImageScript());
		m_Helper.reset(new HelperScript());
	}
	TalkScript::~TalkScript() {
		finalize();
	}
}