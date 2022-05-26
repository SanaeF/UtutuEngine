#include "CustomWeapon.h"
#include "../../Source/Helper/Helper.h"
#include "../../Source/Resource/SaveData/SaveData.h"
#include "../../Source/Manager/SaveDataManager/SaveDataManager.h"
namespace app {
	std::string CustomWeapon::name[100];
	void CustomWeapon::creaateRookie(){
		auto& data = res::SaveData::save_data.weapon[0];
		data.is_created = true;
		data.life = 3;
		data.bom = 2;
		data.strength = 10;
		data.ex_type = 0;
		SaveDataManager::out_weapon();
	}
	void CustomWeapon::dispose(int id) {
		if (id == 0)return;
		int id_max = 0;
		//�f�[�^�̌��𒲂ׂ�
		for (int ite = id; ite < 100; ite++) {
			if (!res::SaveData::save_data.weapon[ite].is_created)break;
			id_max = ite;
		}
		for (int ite = id; ite < 99; ite++) {
			res::SaveData::save_data.weapon[ite] = res::SaveData::save_data.weapon[ite + 1];
		}
		//�Ō�̃f�[�^���폜
		res::SaveData::save_data.weapon[id_max].initialize();
	}
	void CustomWeapon::create(int add_life, int add_bom, int add_strength) {
		int id = 0;
		for (id = 0; id <= 100; id++) {
			if (id == 100)return;
			if (!res::SaveData::save_data.weapon[id].is_created)break;
		}
		int life = getParam(add_life, 7);
		int bom = getParam(add_bom, 7);
		int strength = getParam(add_strength, 100 - (life + bom));
		int ex_type= GET_RANDOM(4);

		auto& data = res::SaveData::save_data.weapon[id];
		data.is_created = true;
		data.life = life;
		data.bom = bom;
		data.strength = strength;
		data.ex_type = ex_type;
		SaveDataManager::out_weapon();

		for (int ite = 0; ite < 100; ite++) {
			if (!res::SaveData::save_data.weapon[id].is_created)break;
			createName(ite);
		}
	}
	int CustomWeapon::getParam(int add, int max) {
		int param = (add + GET_RANDOM(max));
		if (param > max)param = max;
		return param;
	}
	void CustomWeapon::createName(int id) {
		if (!res::SaveData::save_data.weapon[id].is_created) {
			name[id] = "??????????";
			return;
		}
		std::string top[8] = {
			"�y��x1�z",
			"�y��x1�z",
			"�y��x2�z",
			"�y��x2�z",
			"�y��x3�z",
			"�y��x3�z",
			"�y��x4�z",
			"�y��x5�z"
		};
		std::string middle[8] = {
			"���̓^�C�v��",
			"�n���f�t����",
			"���ʂ�",
			"���������`���[�W���ꂽ",
			"����Ȃ�Ƀ`���[�W���ꂽ",
			"���ƃ`���[�W���ꂽ",
			"���Ȃ�`���[�W���ꂽ",
			"�t���`���[�W���ꂽ"
		};
		std::string bottom[5] = {
			"�����w��",
			"�֒f�ʎ�",
			"�����",
			"���~�w��",
			"����",
		};
		auto& data = res::SaveData::save_data.weapon[id];
		name[id] = top[data.life];
		name[id] += middle[data.bom];
		name[id] += bottom[data.ex_type];
	}
	std::string CustomWeapon::getName(int id) {
		return name[id];
	}
}