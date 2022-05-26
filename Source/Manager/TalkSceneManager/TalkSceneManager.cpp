#include "TalkSceneManager.h"
#include <iostream>

#include "../../Source/Script/TalkScript/TalkScript.h"
#include "../../Source/Application/Key/Key.h"
#include "../../Source/Application/Replayer/Replayer.h"
#include "../../Source/Object/Player/Player.h"
#include "../../Source/EffectTools/ScreenFade/ScreenFade.h"
#pragma warning(disable : 4996)
namespace app {
	TalkSceneManager::TalkSceneManager():
		m_Is_serif_scene(false)
	{
		m_Script.reset(new script::TalkScript());
		m_saveFade[0].reset(new ScreenFade());
		m_saveFade[1].reset(new ScreenFade());
	}
	TalkSceneManager::~TalkSceneManager() {
	}
	void TalkSceneManager::initialize() {
		m_Script->clearValue();
		m_Count = 0;
		m_Wait_count = 0;
		m_Is_scene_end = false;
	}
	void TalkSceneManager::startEnding() {
		if (m_Is_serif_scene == true)return;
		*m_saveFade[0] = ScreenFade::BackDirect;
		*m_saveFade[1] = ScreenFade::Direct;
		ScreenFade::BackDirect.reset();
		ScreenFade::Direct.reset();
		char* fp = new char[40];
		sprintf(fp, "./dat/Script/Talk/ending.lua");
		m_Script->initialize(fp);
		delete[] fp;
		m_Is_serif_scene = true;
		obj::Player::PlayerObj.setNoShoot(true);
	}
	void TalkSceneManager::start(int id) {
		if (m_Is_serif_scene == true)return;
		*m_saveFade[0] = ScreenFade::BackDirect;
		*m_saveFade[1] = ScreenFade::Direct;
		ScreenFade::BackDirect.reset();
		ScreenFade::Direct.reset();
		char* fp = new char[40];
		sprintf(fp, "./dat/Script/Talk/%d.lua", id);
		m_Script->initialize(fp);
		delete[] fp;
		m_Is_serif_scene = true;
		obj::Player::PlayerObj.setNoShoot(true);
	}
	void TalkSceneManager::draw() {
		if (m_Is_serif_scene == false)return;
		m_Script->draw();
	}
	void TalkSceneManager::update() {
		if (m_Is_serif_scene == false)return;
		m_Script->update();
		m_Script->setScene(nextScene());
		if (m_Script->isEnd()) {
			obj::Player::PlayerObj.setNoShoot(false);
			ScreenFade::BackDirect = *m_saveFade[0];
			ScreenFade::Direct = *m_saveFade[1];
			m_Is_serif_scene = false;
			m_Is_scene_end = true;
			m_Count = 0;
		}
	}
	int TalkSceneManager::nextScene() {
		if (m_Script->getInfo().is_skip) {
			m_Wait_count++;
			if (m_Script->getInfo().is_skip && m_Script->getInfo().skip_wait_time <= m_Wait_count) {
				m_Script->getInfo().is_skip = false;
				m_Script->changeScene();
				m_Wait_count = 0;
				m_Count++;
			}
		}
		else {
			//m_Count++;//デバッグ用
			if (Replayer::GameRecorder.isReplayMode()) {
				if (Replayer::GameRecorder.getKeyData(Key::KEY_TYPE::SHOT) == 1 ||
					Replayer::GameRecorder.getKeyData(Key::KEY_TYPE::CHANGE) % 10 == 1) {
					m_Script->changeScene();
					m_Count++;
				}
			}
			else {
				Replayer::GameRecorder.pushBackKeyInputs(Key::KEY_TYPE::SHOT, Key::Pad.checkInput(Key::KEY_TYPE::SHOT));
				Replayer::GameRecorder.pushBackKeyInputs(Key::KEY_TYPE::CHANGE, Key::Pad.checkInput(Key::KEY_TYPE::CHANGE));
				if (Key::Pad.checkInput(Key::KEY_TYPE::SHOT) == 1 ||
					Key::Pad.checkInput(Key::KEY_TYPE::CHANGE) % 10 == 1) {
					m_Script->changeScene();
					m_Count++;
				}
			}
		}
		return m_Count;
	}
	int TalkSceneManager::calledBossType() {
		auto type = m_Script->getInfo().called_boss_type;
		return type;
	}
	int TalkSceneManager::bulletNum() {
		auto num = m_Script->getInfo().bullet_num;
		return num;
	}
	bool TalkSceneManager::isSummonBoss() {
		auto summon = m_Script->getInfo().isBoss_smmon;
		return summon;
	}
	bool TalkSceneManager::isSummonInterBoss() {
		auto summon = m_Script->getInfo().is_smmon_inter_boss;
		return summon;
	}
	bool TalkSceneManager::isTalkState() {
		return m_Is_serif_scene;
	}
	bool TalkSceneManager::isJoinBullet() {
		auto isJoinBullet = m_Script->getInfo().isJoin_Bullet;
		if(isJoinBullet)obj::Player::PlayerObj.setNoShoot(false);
		return isJoinBullet;
	}
	bool TalkSceneManager::isSceneEnd() {
		return m_Is_scene_end;
	}
	bool TalkSceneManager::isGoEnding() {
		auto isEnding = m_Script->getInfo().isGoEnding;
		return isEnding;
	}
}