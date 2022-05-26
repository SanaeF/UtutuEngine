#include "DuelMode.h"
#include "../../Source/SystemProp/AreaProp.h"
#include "../../Source/Helper/Helper.h"
#include "../../Source/Resource/SaveData/SaveData.h"
#include "../../Source/Resource/LoadManager.h"
#include "../../Source/Object/Player/Player.h"
#include "../../Source/Object/Boss/Boss.h"
#include "../../Source/Application/Application/LoadScene/LoadScene.h"
#include "../../Source/Application/GameFlow/GameScene/SingleGameStats/SingleGameStats.h"
#include "../../Source/Application/GameFlow/GameScene/Pause/Pause.h"
#include "../../Source/Application/GameFlow/GameScene/StageMap/StageMap.h"
#include "../../Source/Application/GameFlow/GameScene/TimeLine/TimeLine.h"
#include "../../Source/Application/GameFlow/EndingScene/EndingScene.h"
#include "../../Source/Application/ScoreBoard/StartingCall/StartingCall.h"
#include "../../Source/Application/ScoreBoard/ScoreBoard.h"
#include "../../Source/Application/Sound/Sound.h"
#include "../../Source/Manager/TalkSceneManager/TalkSceneManager.h"
#include "../../Source/Manager/SaveDataManager/SaveDataManager.h"
#include "../../Source/Manager/ItemManager/ItemManager.h"
#include "../../Source/EffectTools/Shake/Shake.h"
#include "../../Source/Script/Manager/BulletScript/Shot/ShotScript.h"
#include "../../Source/Script/Manager/BulletScript/Lazer/LazerScript.h"
#include "../../Source/Script/Manager/BulletScript/TurnLazer/TurnLazerScript.h"

namespace app {
	DuelMode::DuelMode(int difficulty) :
		m_Difficulty(difficulty)
	{
	}
	void DuelMode::initialize(int sound_type, int stage_type) {
	}
	void DuelMode::draw() {
	}
	void DuelMode::update() {
	}
	void DuelMode::updateGame() {
	}
	void DuelMode::sharedReset() {
	}
	void DuelMode::setupPlayer(bool is_host, int type1, int type2) {
	}
	bool DuelMode::isEnd() {
		return m_Is_end;
	}
}