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
		//�^�C�g�����
		if (isState(SCENE_TYPE::TITLE)) m_Title->draw();

		//�S�V���[�Y���ʂ̃^�C�g�����j���[
		if (isState(SCENE_TYPE::REPLAY) ||//���v���C���j���[
			isState(SCENE_TYPE::REPLAY_READ_MODE) ||
			isState(SCENE_TYPE::REPLAY_WRITE_MODE)
			)m_ReplayRoom->draw();
		if (isState(SCENE_TYPE::MUSIC))m_MusicRoom->draw();//���y�����j���[
		if (isState(SCENE_TYPE::HELP))m_Help->draw();//�w���v���j���[
		if (isState(SCENE_TYPE::CONFIG))m_Config->draw();//�ݒ胁�j���[

		if (isState(SCENE_TYPE::DIFFICULTY_SELECT))m_Story->draw();//��Փx�I��
		if (isState(SCENE_TYPE::SELECT_CHARA))m_CharaSelect->draw();//�L�����I��
		if (isState(SCENE_TYPE::STORY_SELECT))m_StorySelect->draw();//�X�e�[�W�I��(Practice�p)

		//����d�l�ɂ��ǉ����j���[
		if (isState(SCENE_TYPE::SERVER_ROOM))m_Online->draw();//�T�[�o�[�̃��j���[
		if (isState(SCENE_TYPE::ALICE_MODE))m_Alice->draw();//�A���X���[�h�̃��j���[
		if (isState(SCENE_TYPE::DRESS_UP))m_DressRoom->draw();//�ߑ��ύX���j���[

		if (isState(SCENE_TYPE::SELECT_CHARA_DUEL))m_VS_Player->draw();//�ΐ�p�L�����I��
		if (isState(SCENE_TYPE::SELECT_STAGE))m_StageSelect->draw();//�X�e�[�W�I��(at�V���[�Y�p)

		//�Q�[�����̉��
		if (isState(SCENE_TYPE::GAME_MAIN))m_Game->draw();
	}
	void SceneManager::update() {
		//�^�C�g�����
		if (isState(SCENE_TYPE::TITLE)) {
			GameSceneProp::initialize();
			m_State = m_Title->update();
		}

		//�S�V���[�Y���ʂ̃^�C�g�����j���[
		if (isState(SCENE_TYPE::REPLAY) ||//���v���C���j���[
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
		if (isState(SCENE_TYPE::MUSIC))m_State = m_MusicRoom->update();//���y�����j���[
		if (isState(SCENE_TYPE::HELP))m_State = m_Help->update();//�w���v�̃��j���[
		if (isState(SCENE_TYPE::CONFIG))m_State = m_Config->update();//�ݒ胁�j���[

		if (isState(SCENE_TYPE::DIFFICULTY_SELECT))m_State = m_Story->update();//��Փx�Z���N�g
		if (isState(SCENE_TYPE::SELECT_CHARA)) {//�L�����Z���N�g���
			m_State = m_CharaSelect->update();
			if (isState(SCENE_TYPE::GAME_MAIN)) {
				m_Game.reset(new GameScene());
				m_Game->setPlayerType(m_CharaSelect->getCharaType());
				m_Game->setGameType(GAME_MODE::STORY);
			}
		}
		if (isState(SCENE_TYPE::STORY_SELECT))m_State = m_StorySelect->update();//�X�e�[�W�I��(Practice�p)

		//����d�l�ɂ��ǉ����j���[
		if (isState(SCENE_TYPE::ALICE_MODE))m_State = m_Alice->update();//�A���X���[�h�̃��j���[
		if (isState(SCENE_TYPE::DRESS_UP))m_State = m_DressRoom->update();//�ߑ����j���[
		if (isState(SCENE_TYPE::SERVER_ROOM)) {//�T�[�o�[�p�̃��j���[
			m_State = m_Online->update();
			m_Is_connecting = m_Online->getServer().getConnecting();
		}

		if (isState(SCENE_TYPE::SELECT_STAGE))m_State = m_StageSelect->update();//�X�e�[�W�I��(at�V���[�Y�p)
		
		//�Q�[�����̉��
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