#include "LoadManager.h"
#include <iostream>
#include <thread>

#include "./GUI/BossUIImage/BossUIImage.h"
#include "./GUI/GameUIImage/GameUIImage.h"
#include "./GUI/LoadUIImage/LoadUIImage.h"
#include "./GUI/MenuUIImage/MenuUIImage.h"
#include "./GUI/TextUIImage/TextUIImage.h"
#include "./GUI/SelectUIImage/SelectUIImage.h"
#include "./BulletImage/BulletImage.h"
#include "./CharacterImage/CharacterImage.h"
#include "./FacialEffectImage/FacialEffectImage.h"
#include "./EnemyImage/EnemyImage.h"
#include "./MapImage/MapImage.h"
#include "./ParticleImage/ParicleImage.h"
#include "./PlayerImage/PlayerImage.h"
#include "./SoundData/SoundData.h"
#include "./ItemImage/ItemImage.h"
#include "./OnePictureImage/OnePictureImage.h"
#pragma warning(disable : 4996)

namespace res {
	LoadManager::LoadManager() :
		m_Sound(false),
		m_App_ui(false),
		m_Text_ui(false),
		m_Menu_ui(false),
		m_Game_ui(false),
		m_Chara_img(false),
		m_Shot_img(false),
		m_Effect_img(false),
		m_Talk_chara_img(false),
		m_Is_load_map(false),
		m_Is_game_load(false)
	{
	}
	void LoadManager::loadMusic() {
		if (!m_Sound) {
			SoundData::load();
			m_Sound = true;
		}
	}
	void LoadManager::loadAppUI() {
		if (!m_App_ui) {
			LoadUIImage::load();
			m_App_ui = true;
		}
	}
	void LoadManager::loadTextUI() {
		if (!m_Text_ui) {
			TextUIImage::load();
			m_Text_ui = true;
		}
	}
	void LoadManager::loadMenuUI() {
		if (!m_Menu_ui) {
			MenuUIImage::load();
			SelectUIImage::load();
			m_Menu_ui = true;
		}
	}
	void LoadManager::loadGameUI() {
		if (!m_Game_ui) {
			BossUIImage::load();
			GameUIImage::load();
			ItemImage::load();
			m_Game_ui = true;
		}
	}
	void LoadManager::loadCharaObjImg() {
		if (!m_Chara_img) {
			PlayerImage::load();
			EnemyImage::load();
			m_Chara_img = true;
		}
	}
	void LoadManager::loadShotImg() {
		if (!m_Shot_img) {
			BulletImage::load();
			m_Shot_img = true;
		}
	}
	void LoadManager::loadEffectImg() {
		if (!m_Effect_img) {
			ParticleImage::load();
			m_Effect_img = true;
		}
	}
	void LoadManager::loadTalkCharaImg() {
		if (!m_Talk_chara_img) {
			CharacterImage::load();
			FacialEffectImage::load();
			OnePictureImage::load();
			m_Talk_chara_img = true;
		}
	}
	void LoadManager::loadTalkBossImg(int stage) {
		CharacterImage::loadBoss(stage);
	}
	void LoadManager::loadMapModel() {
		if (!m_Is_load_map) {
			MapImage::load();
			m_Is_load_map = true;
		}
	}
	void LoadManager::setGameLoad() {
		m_Is_game_load = true;
	}
	bool LoadManager::isGameLoaded() {
		return m_Is_game_load;
	}
}