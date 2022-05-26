#include "StoryMode.h"
#include <thread>
#include "../../Source/SystemProp/AreaProp.h"
#include "../../Source/SystemProp/GameStatsProp.h"
#include "../../Source/SystemProp/AliceProp/AliceProp.h"
#include "../../Source/SystemProp/GameSceneProp/GameSceneProp.h"
#include "../../Source/CustomWeapon/CustomWeapon.h"
#include "../../Source/Helper/Helper.h"
#include "../../Source/Resource/SaveData/SaveData.h"
#include "../../Source/Resource/LoadManager.h"
#include "../../Source/Object/Player/Player.h"
#include "../../Source/Application/GameFlow/GameScene/Pause/Pause.h"
#include "../../Source/Application/GameFlow/GameScene/StageMap/StageMap.h"
#include "../../Source/Application/GameFlow/GameScene/TimeLine/TimeLine.h"
#include "../../Source/Application/Application/LoadScene/LoadScene.h"
#include "../../Source/Application/GameFlow/EndingScene/EndingScene.h"
#include "../../Source/Application/ScoreBoard/ScoreBoard.h"
#include "../../Source/Application/ScoreBoard/ItemRoulette/ItemRoulette.h"
#include "../../Source/Application/ScoreBoard/SubTitle/SubTitle.h"
#include "../../Source/Application/GameMassage/GameMassage.h"
#include "../../Source/Application/Sound/Sound.h"
#include "../../Source/Application/DebugLog/DebugLog.h"
#include "../../Source/Application/Replayer/Replayer.h"
#include "../../Source/Manager/TalkSceneManager/TalkSceneManager.h"
#include "../../Source/Manager/SaveDataManager/SaveDataManager.h"
#include "../../Source/Manager/ItemManager/ItemManager.h"
#include "../../Source/EffectTools/Shake/Shake.h"
#include "../../Source/EffectTools/ScreenFade/ScreenFade.h"
#include "../../Source/Manager/BossManager/BossManager.h"
#include "../../Source/Manager/MinionManager/MinionManager.h"
#include "../../Source/Manager/BulletManager/BulletManager.h"

namespace app {
	StoryMode::StoryMode()
	{
		sharedReset();
	}
	void StoryMode::initialize(int player_type, bool is_first) {
		//サウンドの初期化(必ず最初)
		if (GameSceneProp::stage != 4)Sound::sound.handleReset();
		//変数初期化
		m_Player_type = player_type;
		m_Is_black_out = false;
		m_Is_no_pause = false;
		m_Is_Ending = false;
		m_Load_time = 0;
		m_Count = 0;
		m_End_time = -1;
		//ポーズの初期化
		Pause::Menu.initialize();
		//リソースのロード
		res::LoadManager& load = res::LoadManager::get_instance();
		if (!load.isGameLoaded()) {
			load.loadGameUI();
			load.loadShotImg();
			load.loadEffectImg();
			load.loadMapModel();
			load.setGameLoad();
		}
		else sharedReset();
		m_Load_time = 30;
		//プレイヤーの初期化
		if (is_first)obj::Player::PlayerObj.initialize(player_type, AREA::FMAX_X, AREA::FMIN_X);
		else obj::Player::PlayerObj.loadState(player_type);
		obj::Player::PlayerObj.initOption();
		//衣装の変数設定
		if (res::SaveData::save_data.chara_custom[player_type].outer_wear_type == 6)res::SaveData::save_data.chara_custom[player_type].outer_wear_type = 0;
		if (res::SaveData::save_data.chara_custom[player_type].under_wear_type == 6)res::SaveData::save_data.chara_custom[player_type].under_wear_type = 0;
		GameSceneProp::outer_wear = res::SaveData::save_data.chara_custom[player_type].outer_wear_type;
		GameSceneProp::under_wear = res::SaveData::save_data.chara_custom[player_type].under_wear_type;
		//キャンプデータの読み込み
		if (GameSceneProp::under_wear != 5 && GameSceneProp::is_use_camp) {
			inputCamp();
			Sound::sound.playStageBGM(GameSceneProp::stage);
			SaveDataManager save;
			save.out_game();
			GameSceneProp::is_use_camp = false;
		}
		//アリスモードの場合、ステージが変わるタイミングでパラメーター乱数の再計算
		if (!is_first && AliceProp::flag) {
			AliceProp::recreate();
			if (GameSceneProp::stage == 6)AliceProp::noParamater();
		}
		//クラス初期化
		m_TalkScene->initialize();
		manager::BossManager::getInstance()->initialize();
		obj::BulletManager::getInstance()->initialize();
		load.loadTalkBossImg(GameSceneProp::stage);
		m_MapObj->create(false, GameSceneProp::stage);
		m_TL->initialize();
		ScreenFade::Screen.reset();
	}
	void StoryMode::draw() {
		if (LoadScene::isDraw())return;
		float x = Shake::crush.get_x();
		float y = Shake::crush.get_y();
		m_MapObj->draw(x, y);
		ScreenFade::BackDirect.draw();
		m_ItemRoulette->draw();
		ScreenFade::Direct.draw();
		manager::BossManager::getInstance()->draw(x, y);
		manager::MinionManager::getInstance()->draw(x, y);
		obj::Player::PlayerObj.draw(x, y);
		m_ItemSpawner->draw(x, y);
		obj::BulletManager::getInstance()->draw(x, y);
		obj::Player::PlayerObj.drawHitbox();
		manager::BossManager::getInstance()->drawUI(x, y);
		m_SubTitle->draw();
		m_Board->draw(obj::Player::PlayerObj);
		m_TalkScene->draw();
		Pause::Menu.draw();
		//Sound::sound.drawDebugString();
		ScreenFade::Screen.draw();
		m_GameMassage->draw();
		if (USE_DEBUGLOG)DebugLog::draw(m_Count);
	}
	void StoryMode::update() {
		int id = GameSceneProp::difficulty;
		if (AliceProp::flag)id = 3;
		auto input = res::SaveData::save_data.clear.camp_data[id];
		if (!GameSceneProp::is_practice)Pause::Menu.setCamp(input.camped);
		if (obj::Player::PlayerObj.getItemStack().life < 0)Pause::Menu.setScene(Pause::NO_LIFE);
		//空のロード時間があれば、カウントダウン
		if (m_Load_time > 0) {
			LoadScene::join();
			m_Load_time--;
			return;
		}
		LoadScene::left();
		if (!m_TalkScene->isGoEnding() && !m_Is_no_pause)m_Pause_state = Pause::Menu.update();
		//ゲームメインの更新
		if (!Pause::Menu.isFlag())updateGame();
		else {
			Sound::sound.freez();
			//ポーズ中の処理
			obj::BulletManager::getInstance()->stop();
			//m_Boss->pauseScript();
		}
	}
	void StoryMode::updateGame() {
		std::thread back_th([&]() {
			ScreenFade::BackDirect.update();
			m_MapObj->update(m_Count);
			});
		std::thread player_th([&]() {
			Shake::crush.update();
			obj::Player::PlayerObj.update();
			});
			Replayer::GameRecorder.update();
		std::thread obj_th([&]() {
			gamePhase();
			manager::MinionManager::getInstance()->update();
			manager::BossManager::getInstance()->update();
			obj::BulletManager::getInstance()->update();
			});
		std::thread time_th([&]() {
			m_ItemSpawner->update();
			m_ItemRoulette->update(obj::Player::PlayerObj, m_ItemSpawner);
			});
		std::thread gui_th([&]() {
			m_SubTitle->update();
			m_TalkScene->update();
			ScreenFade::Direct.update();
			m_GameMassage->update();
			ScreenFade::Screen.update();
			});
		back_th.join();
		player_th.join();
		obj_th.join();
		time_th.join();
		gui_th.join();
	}
	void StoryMode::gamePhase() {
		//道中のBGM再生
		if (m_Count == 1)Sound::sound.playStageBGM(GameSceneProp::stage);
		//サブタイトルの表示
		if (m_TL->isSubTitle())m_SubTitle->start(GameSceneProp::stage);
		
		//会話シーンへの移行
		if (m_TL->isTalkScene()) {
			obj::BulletManager::getInstance()->clear(true);
			m_TalkScene->start(m_TL->getTalkID());
			//m_Count++;
		}
		//ボス召喚
		if (manager::BossManager::getInstance()->isFlag() || m_TalkScene->isTalkState()) {
			/*if (m_TalkScene->isSummonBoss())
				m_Boss->summon(
					m_TalkScene->calledBossType(),
					0,
					m_TalkScene->bulletNum()
				);
			if (m_TalkScene->isSummonInterBoss())
				m_Boss->interSummon(
					false,
					m_TalkScene->calledBossType(),
					m_TalkScene->bulletNum()
				);
			if (m_TalkScene->isJoinBullet())m_Boss->setBulletMode();*/
		}
		else {
			m_TL->setFlag(true);
			m_TL->setCampLock(GameSceneProp::is_practice);
			m_TL->update(m_Count, m_MapObj->getCount());
			if (m_TL->isEndingPhase() && !m_Is_black_out) {
				ScreenFade::Screen.setFade(ScreenFade::FADE_OUT, 240);
				m_Is_black_out = true;
			}
			m_Count++;
		}
		//ステージエンドの処理
		if (!m_TL->isRood() || (m_Is_black_out && !ScreenFade::Screen.isRun())) {
			if (GameSceneProp::stage != 3)Sound::sound.freez();
			if (GameSceneProp::is_practice) {
				Pause::Menu.setScene(Pause::PauseMenu::NO_LIFE);
			}
			else {
				if ((!GameSceneProp::is_practice && !GameSceneProp::is_alice) &&
					(GameSceneProp::difficulty == 0 && (GameSceneProp::stage == 4 && obj::Player::PlayerObj.getItemStack().life < 5))
					) {
					Pause::Menu.setScene(Pause::PauseMenu::GAME_OVER);
				}
				else {
					if (GameSceneProp::stage == 5 ||
						GameSceneProp::stage == 6 ||
						GameSceneProp::stage == 7)
						ScreenFade::Screen.setBright(true, 255);
					stageEnd();
				}
			}
		}
	}
	void StoryMode::acheve() {
		//スコアの入力
		if (res::SaveData::save_data.clear.highScore[GameSceneProp::difficulty] < obj::Player::PlayerObj.getItemStack().score) {
			res::SaveData::save_data.clear.highScore[GameSceneProp::difficulty] = obj::Player::PlayerObj.getItemStack().score;
		}
		res::SaveData::save_data.clear.all_score += obj::Player::PlayerObj.getItemStack().score;//総合スコアに加算
		//ステージクリアによるアリスモードのレベル開放
		if (res::SaveData::save_data.clear.clear_story_num <= GameSceneProp::stage) {
			if (!GameSceneProp::is_extra)res::SaveData::save_data.clear.clear_story_num = GameSceneProp::stage + 1;
			if (res::SaveData::save_data.clear.clear_story_num == 3) {
				res::SaveData::save_data.clear.level += 1;
				m_GameMassage->setText("アリスモードが遊べるようになりました", 180);
			}
		}
		else {
			if (res::SaveData::save_data.clear.level < 100) {
				//score9742667で10レベル
				if (res::SaveData::save_data.clear.all_score > (500000 * res::SaveData::save_data.clear.level)) {
					res::SaveData::save_data.clear.level++;
				}
			}
		}
		//ステージ6に移行する前の特殊メッセージ
		if ((!GameSceneProp::is_practice&& !GameSceneProp::is_alice) && GameSceneProp::stage == 4)m_GameMassage->setText("ここからは綾乃で行動します", 180);
		//アリスモードの未開放ステージ用メッセージ
		if (GameSceneProp::is_alice) {
			if (res::SaveData::save_data.clear.clear_story_num < 6 &&
				GameSceneProp::stage >= res::SaveData::save_data.clear.clear_story_num
				) {
				m_GameMassage->setText("この先はストーリーでクリアしていません。", 180);
			}
			if (GameSceneProp::stage == 5 && AliceProp::level_num < 10) {
				m_GameMassage->setText("この先にはLv.10以上からのみ進めます。", 180);
			}
		}
		//衣装と特殊装備を獲得した際に出るメッセージ
		//上着
		if (GameSceneProp::stage == 4) {//5面クリア
			if (m_Player_type == 1) {//みさとクリア
				if (!res::SaveData::save_data.chara_custom[0].unlocked_outer_wear[2]) {
					for (int ite = 0; ite < 5; ite++)res::SaveData::save_data.chara_custom[ite].unlocked_outer_wear[2] = true;
					m_GameMassage->setText("「ブレザー&セーター」を獲得しました。", 180);
				}
			}
			if (m_Player_type == 4) {//庵狐クリア
				if (!res::SaveData::save_data.chara_custom[0].unlocked_outer_wear[1]) {
					for (int ite = 0; ite < 5; ite++)res::SaveData::save_data.chara_custom[ite].unlocked_outer_wear[1] = true;
					m_GameMassage->setText("「セーラー服」を獲得しました。", 180);
				}
			}
		}
		if (GameSceneProp::stage == 5) {//ステージクリア
			res::SaveData::save_data.clear.camp_data[GameSceneProp::difficulty].initialize();
			res::SaveData::save_data.clear.difficulty[GameSceneProp::difficulty] = true;
			if (!res::SaveData::save_data.chara_custom[0].unlocked_outer_wear[4]) {
				for (int ite = 0; ite < 5; ite++)res::SaveData::save_data.chara_custom[ite].unlocked_outer_wear[4] = true;
				m_GameMassage->setText("「赤ずきんの衣装」を獲得しました。", 180);
			}
		}
		if (GameSceneProp::stage == 6) {//アリスモード7面クリア
			res::SaveData::save_data.clear.camp_data[3].initialize();
			if (!res::SaveData::save_data.chara_custom[0].unlocked_outer_wear[3]) {
				for (int ite = 0; ite < 5; ite++)res::SaveData::save_data.chara_custom[ite].unlocked_outer_wear[3] = true;
				m_GameMassage->setText("「私服」を獲得しました。", 180);
			}
			m_GameMassage->setText("「特殊装備」を獲得しました。", 180);
		}
		if (GameSceneProp::stage == 7) {//Exクリア
			res::SaveData::save_data.clear.camp_data[4].initialize();
			res::SaveData::save_data.clear.difficulty[4] = true;
			if (!res::SaveData::save_data.chara_custom[0].unlocked_outer_wear[5]) {
				for (int ite = 0; ite < 5; ite++)res::SaveData::save_data.chara_custom[ite].unlocked_outer_wear[5] = true;
				m_GameMassage->setText("「ロングコート」を獲得しました。", 180);
			}
		}
		//スカートなど
		if (!GameSceneProp::is_practice) {
			if (!res::SaveData::save_data.chara_custom[0].unlocked_under_wear[1]) {
				if (GameSceneProp::stage == 1 && obj::Player::PlayerObj.getItemStack().life >= 4) {
					for (int ite = 0; ite < 5; ite++)res::SaveData::save_data.chara_custom[ite].unlocked_under_wear[1] = true;
					m_GameMassage->setText("「プリーツスカート(ライン)」を獲得しました。", 180);
				}
			}
			if (!res::SaveData::save_data.chara_custom[0].unlocked_under_wear[2]) {
				if ((GameSceneProp::is_alice && AliceProp::level_num >= 10) && GameSceneProp::stage == 5) {
					for (int ite = 0; ite < 5; ite++)res::SaveData::save_data.chara_custom[ite].unlocked_under_wear[2] = true;
					m_GameMassage->setText("「プリーツスカート(長め)」を獲得しました。", 180);
				}
			}
			if (!res::SaveData::save_data.chara_custom[0].unlocked_under_wear[3]) {
				if (GameSceneProp::difficulty>=1 && GameSceneProp::stage == 5) {
					for (int ite = 0; ite < 5; ite++)res::SaveData::save_data.chara_custom[ite].unlocked_under_wear[3] = true;
					m_GameMassage->setText("「短パン」を獲得しました。", 180);
				}
			}
			if (!res::SaveData::save_data.chara_custom[0].unlocked_under_wear[4]) {
				if ((GameSceneProp::is_alice && AliceProp::level_num >= 50) && GameSceneProp::stage == 5) {
					for (int ite = 0; ite < 5; ite++)res::SaveData::save_data.chara_custom[ite].unlocked_under_wear[4] = true;
					m_GameMassage->setText("おめでとう!「赤いスカート」を獲得した。", 180);
				}
			}
			if (!res::SaveData::save_data.chara_custom[0].unlocked_under_wear[5]) {
				//残機ゼロで獲得
				if (obj::Player::PlayerObj.getItemStack().life == 0) {
					for (int ite = 0; ite < 5; ite++)res::SaveData::save_data.chara_custom[ite].unlocked_under_wear[5] = true;
					m_GameMassage->setText("「バグったスカート」を獲得してしまった。", 180);
				}
			}
		}
	}
	void StoryMode::stageEnd() {
		//データの入力やメッセージの表記を行います
		if (!m_GameMassage->isFlag()) {
			if (m_TL->isEndingPhase());
			acheve();
		}
		if (!m_GameMassage->isNotEndFlag()) {
			//アリスモードのクリア後ボーナスやステージ未開放による強制リタイア
			if (GameSceneProp::is_alice) {
				if (GameSceneProp::stage >= res::SaveData::save_data.clear.clear_story_num) {
					Pause::Menu.setScene(Pause::PauseMenu::NO_LIFE);
				}
				if (GameSceneProp::stage == 5 && AliceProp::level_num < 10) {
					Pause::Menu.setScene(Pause::PauseMenu::NO_LIFE);
				}
				if (GameSceneProp::stage == 6) {
					app::CustomWeapon::create(GameSceneProp::difficulty, GameSceneProp::difficulty, AliceProp::level_num/2);
				}
			}
			//データのセーブやステージ移行、エンディングを行います
			SaveDataManager save;
			save.out_game();
			if (m_TL->isEndingPhase()) {//エンディング画面へ
				m_Is_Ending = true;
			}
			else {
				if ((!AliceProp::flag && !GameSceneProp::is_practice) && GameSceneProp::stage == 4)m_Player_type = 0;
				GameSceneProp::stage = GameSceneProp::stage + 1;
				initialize(m_Player_type, false);
			}
		}
	}
	void StoryMode::inputCamp() {
		int id = GameSceneProp::difficulty;
		if (AliceProp::flag)id = 3;
		auto input = res::SaveData::save_data.clear.camp_data[id];
		auto& player = obj::Player::PlayerObj.getItemStack();
		//プレイヤーデータの復帰
		player.score = input.player.score;
		player.life = input.player.life;
		player.life_fragument = input.player.life_frag;
		player.bom = input.player.bom;
		player.bom_fragument = input.player.bom_frag;
		player.power = input.player.power;
		player.apple = 0;
		//ステージの復帰
		GameSceneProp::stage = input.stage_num;
		m_Count = input.stage_time;
		//保存時の状態からBGMを再生
		Sound::sound.setPosition(input.sound_count);
		m_MapObj->setCount(input.map_time);
	}
	void StoryMode::sharedReset() {
		m_SubTitle.reset(new SubTitle());
		m_Save.reset(new SaveDataManager());
		m_TL.reset(new TimeLine());
		//m_Boss.reset(new obj::Boss());
		m_Board.reset(new ScoreBoard());
		m_TalkScene.reset(new TalkSceneManager());
		m_MapObj.reset(new StageMap());
		m_ItemSpawner.reset(new obj::ItemManager());
		/*m_ShotScript.reset(new script::ShotScript());
		m_LazerScript.reset(new script::LazerScript());
		m_TurnLazerScript.reset(new script::TurnLazerScript());*/
		m_Ending.reset(new EndingScene());
		m_ItemRoulette.reset(new ItemRoulette());
		m_GameMassage.reset(new GameMassage());
		ScreenFade::Direct.reset();
		ScreenFade::BackDirect.reset();
	}
	bool StoryMode::isEnd() {
		return m_Is_Ending;
	}
}