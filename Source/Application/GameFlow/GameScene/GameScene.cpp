#include "GameScene.h"
#include <iostream>
#include "../../Source/library/Graphics/String/StringDX.h"
#include "../../Source/SystemProp/SceneProp.h"
#include "../../Source/SystemProp/GameSceneProp/GameSceneProp.h"
#include "../../Source/Application/Application/LoadScene/LoadScene.h"
#include "../../Source/Application/Replayer/Replayer.h"
#include "../../Source/Application/GameFlow/GameScene/Pause/Pause.h"
#include "../../Source/Application/GameFlow/GameScene/EndingTalk/EndingTalk.h"
#include "../../Source/Application/Sound/Sound.h"
#include "../../Source/Application/GameFlow/GameScene/GameMode/StoryMode/StoryMode.h"
#include "../../Source/Application/GameFlow/GameScene/GameMode/SingleMode/SingleMode.h"
#include "../../Source/Application/GameFlow/GameScene/GameMode/DuelMode/DuelMode.h"
#include "../../Source/Application/GameFlow/EndingScene/EndingScene.h"
#include "../../Source/Object/Player/Player.h"

namespace app {
	int GameScene::update() {
		setSceneState(SCENE_TYPE::GAME_MAIN);
		if (m_State == GAME_STATE::INITIALIZE) {
			if (LoadScene::isDraw()) {
				//シード値の決定(リプレイ用)
				Replayer::GameRecorder.callSeedProcess(100 * GAME_STATES::ALL_STAGE);
				Replayer::GameRecorder.initialize();
				if (m_Game_type == GAME_MODE::STORY)m_Story->initialize(m_Player_type);
			/*	if (m_Game_type == GAME_MODE::SINGLE)m_Single->initialize(m_Player_type, m_Stage_type, m_Bullet_type);
				if (m_Game_type == GAME_MODE::DOUBLES)m_Duel->initialize(m_Sound_type, m_Stage_type);*/
				m_State = GAME_STATE::LOOP;
				LoadScene::left();
			}
			else LoadScene::join();
		}
		if (m_State == GAME_STATE::LOOP) {
			if (m_Game_type == GAME_MODE::STORY)m_Story->update();
			/*if (m_Game_type == GAME_MODE::SINGLE)m_Single->update();
			if (m_Game_type == GAME_MODE::DOUBLES)m_Duel->update();*/
			stageEnd();
		}
		if (m_State == GAME_STATE::END_SCENE) {
			Replayer::GameRecorder.callStop();
			m_ED_talk->update();
			if (!m_ED_talk->isFlag()) {
				m_State = GAME_STATE::ENDING;
				m_Ending->setEnding();
			}
		}
		if (m_State == GAME_STATE::ENDING) {
			m_Ending->update();
			if (m_Ending->isEnded()) {
				m_State = GAME_STATE::CHECK_SAVE_REPLAY;
				resetCoolDown();
			}
		}
		if (m_State == GAME_STATE::CHECK_SAVE_REPLAY) {
			m_Select_YN.update();
			if (!m_Select_YN.isFlag()) {
				if (m_Select_YN.getState() == SELECT_LR::LEFT_STATE) {
					m_State = GAME_STATE::STAGE_END;
					setSceneState(SCENE_TYPE::REPLAY_WRITE_MODE);
				}
				if (m_Select_YN.getState() == SELECT_LR::RIGHT_STATE) {
					m_State = GAME_STATE::STAGE_END;
				}
				m_Select_YN.selectReset();
			}
		}
		else if (m_State == GAME_STATE::STAGE_END) {
			Replayer::GameRecorder.callStop();
			if (m_Game_type == GAME_MODE::STORY) {
				Sound::sound.playBGM(0);
				setSceneState(SCENE_TYPE::TITLE);
			}
			if (m_Game_type == GAME_MODE::SINGLE) {
				Sound::sound.playBGM(0);
				setSceneState(SCENE_TYPE::TITLE);
			}
			if (m_Game_type == GAME_MODE::DOUBLES)finalize();
		}
		pauseState();
		return getSceneState();
	}
	void GameScene::draw() {
		if (m_State == GAME_STATE::LOOP || m_State == GAME_STATE::STAGE_END) {
			if (m_Game_type == GAME_MODE::STORY)m_Story->draw();
			/*if (m_Game_type == GAME_MODE::SINGLE)m_Single->draw();
			if (m_Game_type == GAME_MODE::DOUBLES)m_Duel->draw();*/
		}
		if (m_State == GAME_STATE::END_SCENE) {
			m_ED_talk->draw();
		}
		if (m_State == GAME_STATE::ENDING) {
			m_Ending->draw();
		}
		if (m_State == GAME_STATE::CHECK_SAVE_REPLAY) {
			m_Select_YN.draw("リプレイを保存しますか?", lib::StringDX::color(255, 255, 255), "はい", "いいえ");
		}
	}
	void GameScene::pauseState() {
		if (Pause::Menu.isState(Pause::PauseState::GAME_END)) {//帰る
			Replayer::GameRecorder.callStop();
			Pause::Menu.initialize();
			finalize();
		}
		if (Pause::Menu.isState(Pause::PauseState::SET_SAVE_REPLAY_MODE)) {//リプレイの保存
			resetCoolDown();
			Replayer::GameRecorder.callStop();
			Pause::Menu.initialize();
			Pause::Menu.setFlag(true);
			setSceneState(SCENE_TYPE::REPLAY_WRITE_MODE);
		}
		if (Pause::Menu.isState(Pause::PauseState::SET_REPLAY_ROOM)) {//リプレイの保存
			resetCoolDown();
			Replayer::GameRecorder.callStop();
			Pause::Menu.initialize();
			setSceneState(SCENE_TYPE::REPLAY_READ_MODE);
		}
		if (Pause::Menu.isState(Pause::PauseState::CAMP)) {//死に戻り
			Replayer::GameRecorder.callStop();
			if (!GameSceneProp::is_practice) {
				GameSceneProp::is_use_camp = true;
				m_State = GAME_STATE::INITIALIZE;
			}
			else {
				GameSceneProp::is_use_camp = false;
				m_State = GAME_STATE::INITIALIZE;
			}
		}
		if (Pause::Menu.isState(Pause::PauseState::RETRY)) {//もう一度遊ぶ
			if(!Replayer::GameRecorder.isReplayMode())Replayer::GameRecorder.callStop();
			else {
				Replayer::GameRecorder.reload();
			}
			m_State = GAME_STATE::INITIALIZE;
			if (!GameSceneProp::is_practice)GameSceneProp::stage = 0;
			if (GameSceneProp::is_extra)GameSceneProp::stage = 7;
		}
		if (Pause::Menu.isState(Pause::PauseState::NEXT_STAGE)) {//次へ進む
			Replayer::GameRecorder.callStop();
			if (m_Bullet_type != -1 && m_Bullet_type != 4) {
				m_Bullet_type++;
				m_State = GAME_STATE::INITIALIZE;
			}
			else {
				finalize();
			}
		}
	}
	void GameScene::stageEnd() {
		if (m_Story->isEnd()) {
			m_Select_YN.initialize(SELECT_LR::LEFT_STATE);
			if (GameSceneProp::is_extra || GameSceneProp::is_alice) {
				m_State = GAME_STATE::CHECK_SAVE_REPLAY;
				return;
			}
			m_ED_talk->start();
			m_State = GAME_STATE::END_SCENE;
		}
		/*if (m_Single->isEnd()) {
			m_State = GAME_STATE::STAGE_END;
		}
		if (m_Duel->isEnd()) {
			m_State = GAME_STATE::STAGE_END;
		}*/
	}
	void GameScene::setGameType(GAME_MODE type) {
		m_Game_type = type;
	}
	void GameScene::setPlayerType(int type) {
		obj::Player::PlayerObj.setKeyPad(obj::Player::PAD_TYPE::DEF);
		m_Player_type = type;
	}
	void GameScene::setPlayerType(int type, int type2) {
	//	m_Duel->setupPlayer(m_Is_host, type, type2);
	}
	void GameScene::setSoundType(int type) {
		m_Sound_type = type;
	}
	void GameScene::setBulletType(int type) {
		m_Bullet_type = type;
	}
	void GameScene::setLockPose(bool flag, bool isHost) {
		m_Is_no_pause = flag;
		m_Is_host = isHost;
	}
	void GameScene::sharedReset() {
		if (m_Game_type == GAME_MODE::STORY)m_Story.reset(new StoryMode());
	//	if (m_Game_type == GAME_MODE::SINGLE)m_Single.reset(new SingleMode(m_Difficulty));
	//	if (m_Game_type == GAME_MODE::DOUBLES)m_Duel.reset(new DuelMode(m_Difficulty));
	}
	void GameScene::finalize() {
		m_State = GAME_STATE::INITIALIZE;
		resetCoolDown();
		Sound::sound.playBGM(0);
		if (m_Game_type == GAME_MODE::DOUBLES)setSceneState(SCENE_TYPE::SELECT_CHARA_DUEL);
		else if (m_Game_type == GAME_MODE::SINGLE)setSceneState(SCENE_TYPE::SELECT_STAGE);
		else if (m_Game_type == GAME_MODE::STORY) {
			if (!Replayer::GameRecorder.isReplayMode())setSceneState(SCENE_TYPE::SELECT_CHARA);
			else setSceneState(SCENE_TYPE::REPLAY_READ_MODE);
		}
		LoadScene::left();
	}
	GameScene::GameScene() :
		m_Game_type(GAME_MODE::NO_MODE),
		m_Player_type(0),
		m_Bullet_type(0),
		m_State(GAME_STATE::INITIALIZE),
		m_Count(0),
		m_Pause_state(0)
	{
		m_Story.reset(new StoryMode());
		//m_Single.reset(new SingleMode(m_Difficulty));
		//m_Duel.reset(new DuelMode(m_Difficulty));
		m_ED_talk.reset(new EndingTalk());
		m_Ending.reset(new EndingScene());
	}
	GameScene::~GameScene() {
	}
}