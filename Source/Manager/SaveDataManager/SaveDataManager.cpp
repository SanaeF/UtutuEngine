#include "SaveDataManager.h"
#include <iostream>

#include "../../Source/Application/Key/Key.h"
#include "../../Source/Resource/SaveData/SaveData.h"

#pragma warning(disable : 4996)
namespace app {
	void SaveDataManager::in_weapon() {//データを読み込む
		res::WeaponData weapon[100];
		for (int ite = 0; ite < 100; ite++)weapon[ite].initialize();
		FILE* fp = fopen("./data/weapon.dat", "r");
		fread(&weapon, sizeof(res::WeaponData), 100, fp);
		for (int ite = 0; ite < 100; ite++)res::SaveData::save_data.weapon[ite] = weapon[ite];
		fclose(fp);
	}
	void SaveDataManager::out_weapon() {//データを書き出す
		res::WeaponData weapon[100];
		for (int ite = 0; ite < 100; ite++)weapon[ite].initialize();
		FILE* fp = fopen("./data/weapon.dat", "w");
		for (int ite = 0; ite < 100; ite++)weapon[ite] = res::SaveData::save_data.weapon[ite];
		fwrite(&weapon, sizeof(res::WeaponData), 100, fp);
		fclose(fp);
	}
	void SaveDataManager::in_game() {//データを読み込む
		res::ClearData game_data;
		game_data.initialize();
		FILE* fp = fopen("./data/save.dat", "r");
		fread(&game_data, sizeof(res::ClearData), 1, fp);
		res::SaveData::save_data.clear = game_data;
		for (int ite = 0; ite < 5;ite++)res::SaveData::save_data.chara_custom[ite] = game_data.chara_custom[ite];
		fclose(fp);
	}
	void SaveDataManager::out_game() {//データを書き出す
		res::ClearData game_data;
		game_data.initialize();
		FILE* fp = fopen("./data/save.dat", "w");
		for (int ite = 0; ite < 5; ite++)res::SaveData::save_data.clear.chara_custom[ite] = res::SaveData::save_data.chara_custom[ite];
		game_data = res::SaveData::save_data.clear;
		fwrite(&game_data, sizeof(res::ClearData), 1, fp);
		fclose(fp);
	}
	void SaveDataManager::in_config() {//データを読み込む
		ConfigData config_data[2] = { false,false };
		config_data[0].initialize();
		config_data[1].initialize();
		FILE* fp = fopen("./data/prop.dat", "r");
		fread(&config_data, sizeof(ConfigData), 2, fp);
		res::SaveData::save_data.config.vol_bgm = config_data[0].vol_bgm;
		res::SaveData::save_data.config.vol_se = config_data[0].vol_se;
		res::SaveData::save_data.config.winType = config_data[0].win_size_type;
		res::SaveData::save_data.isSaved = config_data[0].flag;
		for (int key_num = 0; key_num < 16; key_num++)Key::Pad.setKey(key_num, config_data[0].key[key_num]);
		for (int key_num = 0; key_num < 16; key_num++)Key::MultPad[1].setKey(key_num, config_data[1].key[key_num]);
		Key::MultPad[0] = Key::Pad;
		fclose(fp);
		if (!res::SaveData::save_data.isSaved) {
			res::SaveData::save_data.config.vol_bgm = 155;
			res::SaveData::save_data.config.vol_se = 155;
			res::SaveData::save_data.config.winType = 2;
			Key::Pad.setKeyConfig(
				app::Key::PAD_TYPE::PLAYER_01,
				0,
				1,
				2,
				3,
				7,
				6,
				11,
				10,
				13
			);
			Key::MultPad[0] = Key::Pad;
			Key::MultPad[1].setKeyConfig(
				app::Key::PAD_TYPE::PLAYER_02,
				0,
				1,
				2,
				3,
				7,
				6,
				11,
				10,
				13
			);
			res::SaveData::save_data.isSaved = true;
			out_config();
		}
	}
	void SaveDataManager::out_config() {//データを書き出す
		ConfigData config_data[2];
		config_data[0].initialize();
		config_data[1].initialize();
		FILE* fp = fopen("./data/prop.dat", "w");
		config_data[0].vol_bgm = res::SaveData::save_data.config.vol_bgm;
		config_data[0].vol_se = res::SaveData::save_data.config.vol_se;
		config_data[0].win_size_type = res::SaveData::save_data.config.winType;
		for (int key_num = 0; key_num < 16; key_num++)config_data[0].key[key_num] = Key::Pad.getKey(key_num);
		for (int key_num = 0; key_num < 16; key_num++)config_data[1].key[key_num] = Key::MultPad[1].getKey(key_num);
		config_data[0].flag = res::SaveData::save_data.isSaved;
		fwrite(&config_data, sizeof(ConfigData), 2, fp);
		fclose(fp);
	}
}