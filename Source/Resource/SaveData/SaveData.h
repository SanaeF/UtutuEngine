#pragma once
#include "../../Source/SystemProp/GameStatsProp.h"
#include "../../Source/Object/Player/Data/PlayerData.h"
#include "../../Source/Object/Player/Data/CharaCustom.h"
namespace res {
	enum WEAPON_EX {
		POW400,
		APPLE2,
		BOM_CANCEL,
		NO_LOST_BULLET,
		ITEM_SLOT_1,
		WEAPON_EX_MAX
	};
	struct WeaponData {
		bool is_created;
		int life;
		int bom;
		int strength;
		int ex_type;
		void initialize() {
			is_created = false;
			life = 0;
			bom = 0;
			strength = 0;
			ex_type = 0;
		}
	};
	struct CampData {
		bool camped;//キャンプデータがあるかどうか
		int stage_num;//セーブ時のステージ数
		int stage_time;//セーブ時のステージ時間
		int map_time;//背景の経過時間
		int sound_count;//セーブ時のサウンド再生時間
		PlayerData player; //中断データ(プレイヤーステータス)
		//キャンプデータ削除
		void initialize() {
			camped = false;
			stage_num = 0;
			stage_time = 0;
			sound_count = 0;
			player.initialize();
		}
	};
	struct ClearData {
		bool difficulty[5];
		int highScore[5];
		int clear_story_num;
		int all_score;
		int level;
		int bullet[GAME_STATES::STAGE][GAME_STATES::BULLET_NUM];
		int stage[GAME_STATES::STAGE];
		CharaCustom chara_custom[5];//ファイル送信用です。(SaveManager以外でアクセスしないでください)
		CampData camp_data[5];//キャンプデータ(0:easy 1:normal 2:hard 3:alice 4:extra)
		void initialize(){
			clear_story_num = 0;
			for (int ite = 0; ite < 5; ite++)chara_custom[ite].initialize();
			for (int num = 0; num < GAME_STATES::STAGE; num++) {
				for (int num2 = 0; num2 < GAME_STATES::BULLET_NUM; num2++)bullet[num][num2] = 0;
				stage[num] = 0;
			}
			for (int ite = 0; ite < 5; ite++)camp_data[ite].initialize();
			for (int ite = 0; ite < 5; ite++)difficulty[ite] = false;
			for (int ite = 0; ite < 5; ite++)highScore[ite] = 0;
			all_score = 0;
			level = 0;
		}
	};
	struct ConfigData{
		int vol_se;
		int vol_bgm;
		int winType;
	};
	class SaveData {
	public:
		bool isSaved;
		ClearData clear;
		ConfigData config;
		PlayerData player[DIFF_MAX];
		CharaCustom chara_custom[5];//セーブデータに入れる予定の衣装データ
		WeaponData weapon[100];//カスタム武器
		static SaveData save_data;
	};
}