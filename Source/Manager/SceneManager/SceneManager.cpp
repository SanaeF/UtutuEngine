#include "SceneManager.h"
#include <iostream>

#include "../../Source/SystemProp/SceneProp.h"
#include "../../Source/SystemProp/GameStatsProp.h"
#include "../../Source/SystemProp/GameSceneProp/GameSceneProp.h"
#include "../../Source/Application/GameFlow/MenuScene/Title/Title.h"

#include "../../Source/Application/GameFlow/MenuScene/Story/Story.h"
#include "../../Source/Application/GameFlow/MenuScene/StorySelect/StorySelect.h"
#include "../../Source/Application/GameFlow/MenuScene/ReplayRoom/ReplayRoom.h"
#include "../../Source/Application/GameFlow/MenuScene/AliceSelect/AliceSelect.h"
#include "../../Source/Application/GameFlow/MenuScene/DressRoom/DressRoom.h"
#include "../../Source/Application/GameFlow/MenuScene/Online/OnlineRoom.h"
#include "../../Source/Application/GameFlow/MenuScene/Music/MusicRoom.h"
#include "../../Source/Application/GameFlow/MenuScene/Help/HelpRoom.h"
#include "../../Source/Application/GameFlow/MenuScene/Config/ConfigRoom.h"

#include "../../Source/Application/GameFlow/MenuScene/CharaSelect/CharaSelectDuel/CharaSelectDuel.h"
#include "../../Source/Application/GameFlow/MenuScene/CharaSelect/CharaSelect.h"
#include "../../Source/Application/GameFlow/MenuScene/StageSelect/StageSelect.h"
#include "../../Source/Application/GameFlow/GameScene/GameScene.h"
#include "../../Source/Resource/PlayerImage/PlayerImage.h"

namespace app {
	SceneManager::SceneManager():
	m_State(SCENE_TYPE::TITLE)
	{
		m_Title.reset(new Title());

		m_Story.reset(new Story());
		m_StorySelect.reset(new StorySelect());
		m_Alice.reset(new AliceSelect());
		m_ReplayRoom.reset(new ReplayRoom());
		m_DressRoom.reset(new DressRoom());
		m_Online.reset(new Online());
		m_MusicRoom.reset(new MusicRoom());
		m_Help.reset(new HelpRoom());
		m_Config.reset(new ConfigMenu());

		m_CharaSelect.reset(new CharaSelect());
		m_VS_Player.reset(new CharaSelectDuel());
		m_StageSelect.reset(new StageSelect());

		m_Game.reset(new GameScene());
	}
	void SceneManager::draw() {
		//タイトル画面
		if (isState(SCENE_TYPE::TITLE)) m_Title->draw();

		//全シリーズ共通のタイトルメニュー
		if (isState(SCENE_TYPE::REPLAY) ||//リプレイメニュー
			isState(SCENE_TYPE::REPLAY_READ_MODE) ||
			isState(SCENE_TYPE::REPLAY_WRITE_MODE)
			)m_ReplayRoom->draw();
		if (isState(SCENE_TYPE::MUSIC))m_MusicRoom->draw();//音楽室メニュー
		if (isState(SCENE_TYPE::HELP))m_Help->draw();//ヘルプメニュー
		if (isState(SCENE_TYPE::CONFIG))m_Config->draw();//設定メニュー

		if (isState(SCENE_TYPE::DIFFICULTY_SELECT))m_Story->draw();//難易度選択
		if (isState(SCENE_TYPE::SELECT_CHARA))m_CharaSelect->draw();//キャラ選択
		if (isState(SCENE_TYPE::STORY_SELECT))m_StorySelect->draw();//ステージ選択(Practice用)

		//特殊仕様による追加メニュー
		if (isState(SCENE_TYPE::SERVER_ROOM))m_Online->draw();//サーバーのメニュー
		if (isState(SCENE_TYPE::ALICE_MODE))m_Alice->draw();//アリスモードのメニュー
		if (isState(SCENE_TYPE::DRESS_UP))m_DressRoom->draw();//衣装変更メニュー

		if (isState(SCENE_TYPE::SELECT_CHARA_DUEL))m_VS_Player->draw();//対戦用キャラ選択
		if (isState(SCENE_TYPE::SELECT_STAGE))m_StageSelect->draw();//ステージ選択(atシリーズ用)

		//ゲーム中の画面
		if (isState(SCENE_TYPE::GAME_MAIN))m_Game->draw();
	}
	void SceneManager::update() {
		//タイトル画面
		if (isState(SCENE_TYPE::TITLE)) {
			GameSceneProp::initialize();
			m_State = m_Title->update();
		}

		//全シリーズ共通のタイトルメニュー
		if (isState(SCENE_TYPE::REPLAY) ||//リプレイメニュー
			isState(SCENE_TYPE::REPLAY_READ_MODE) ||
			isState(SCENE_TYPE::REPLAY_WRITE_MODE)
			) {
			if (isState(SCENE_TYPE::REPLAY_READ_MODE))m_ReplayRoom->setState(REPLAY_ROOM::READ_STATE);
			if (isState(SCENE_TYPE::REPLAY_WRITE_MODE))m_ReplayRoom->setState(REPLAY_ROOM::WRITE_STATE);
			m_State = m_ReplayRoom->update();
			if (m_ReplayRoom->getState() == REPLAY_ROOM::READ_STATE) {
				if (isState(SCENE_TYPE::GAME_MAIN)) {
					m_Game.reset(new GameScene());
					m_Game->setGameType(GAME_MODE::STORY);
				}
			}
		}
		if (isState(SCENE_TYPE::MUSIC))m_State = m_MusicRoom->update();//音楽室メニュー
		if (isState(SCENE_TYPE::HELP))m_State = m_Help->update();//ヘルプのメニュー
		if (isState(SCENE_TYPE::CONFIG))m_State = m_Config->update();//設定メニュー

		if (isState(SCENE_TYPE::DIFFICULTY_SELECT))m_State = m_Story->update();//難易度セレクト
		if (isState(SCENE_TYPE::SELECT_CHARA)) {//キャラセレクト画面
			m_State = m_CharaSelect->update();
			if (isState(SCENE_TYPE::GAME_MAIN)) {
				m_Game.reset(new GameScene());
				m_Game->setPlayerType(m_CharaSelect->getCharaType());
				m_Game->setGameType(GAME_MODE::STORY);
			}
		}
		if (isState(SCENE_TYPE::STORY_SELECT))m_State = m_StorySelect->update();//ステージ選択(Practice用)

		//特殊仕様による追加メニュー
		if (isState(SCENE_TYPE::ALICE_MODE))m_State = m_Alice->update();//アリスモードのメニュー
		if (isState(SCENE_TYPE::DRESS_UP))m_State = m_DressRoom->update();//衣装メニュー
		if (isState(SCENE_TYPE::SERVER_ROOM)) {//サーバー用のメニュー
			m_State = m_Online->update();
			m_Is_connecting = m_Online->getServer().getConnecting();
		}

		if (isState(SCENE_TYPE::SELECT_STAGE))m_State = m_StageSelect->update();//ステージ選択(atシリーズ用)
		
		//ゲーム中の画面
		if (isState(SCENE_TYPE::GAME_MAIN)) m_State = m_Game->update();
	}
	void SceneManager::NoThreadUptdate() {
		if (isState(SCENE_TYPE::SERVER_ROOM))m_Online->serverProp();
		serverUpdate();
	}
	void SceneManager::serverUpdate() {
		if (m_Is_connecting) {
			m_Game->setLockPose(true, m_Online->isHost());
			m_Online->getServer().update();
			if (isState(SCENE_TYPE::SERVER_ROOM))m_State = SCENE_TYPE::SELECT_CHARA;
			else {
				auto data = m_Online->getServer().getServerData();
				if (m_Online->isHost()) {
					m_Online->getServer().inputParam(
						m_VS_Player->getSelectInput(0),
						m_VS_Player->getCharaType1(),
						m_VS_Player->getSoundType(),
						m_VS_Player->getMapType(),
						m_VS_Player->isStart()
					);
					m_VS_Player->setServerDataHost(data.charaK, data.select_num);
				}
				else {
					m_VS_Player->setServerDataConnect(data.charaK, data.select_num, data.sound, data.stage, data.start);
					m_Online->getServer().inputParam(
						m_VS_Player->getSelectInput(1),
						m_VS_Player->getCharaType2(),
						m_VS_Player->getSoundType(),
						m_VS_Player->getMapType(),
						m_VS_Player->isStart()
					);
				}
			}
			if (isState(SCENE_TYPE::GAME_MAIN))m_VS_Player->setState(false);
		}
		else {
			if (isState(SCENE_TYPE::SERVER_ROOM)) {
				m_Online->getServer().update();
			}
		}
	}
	bool SceneManager::isState(int state) {
		if (m_State == state)return true;
		return false;
	}
	SceneManager::~SceneManager() {

	}
}