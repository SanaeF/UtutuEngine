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
		bool camped;//�L�����v�f�[�^�����邩�ǂ���
		int stage_num;//�Z�[�u���̃X�e�[�W��
		int stage_time;//�Z�[�u���̃X�e�[�W����
		int map_time;//�w�i�̌o�ߎ���
		int sound_count;//�Z�[�u���̃T�E���h�Đ�����
		PlayerData player; //���f�f�[�^(�v���C���[�X�e�[�^�X)
		//�L�����v�f�[�^�폜
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
		CharaCustom chara_custom[5];//�t�@�C�����M�p�ł��B(SaveManager�ȊO�ŃA�N�Z�X���Ȃ��ł�������)
		CampData camp_data[5];//�L�����v�f�[�^(0:easy 1:normal 2:hard 3:alice 4:extra)
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
		CharaCustom chara_custom[5];//�Z�[�u�f�[�^�ɓ����\��̈ߑ��f�[�^
		WeaponData weapon[100];//�J�X�^������
		static SaveData save_data;
	};
}