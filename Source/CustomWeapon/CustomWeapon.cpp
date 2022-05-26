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
		//ƒf[ƒ^‚ÌŒÂ”‚ğ’²‚×‚é
		for (int ite = id; ite < 100; ite++) {
			if (!res::SaveData::save_data.weapon[ite].is_created)break;
			id_max = ite;
		}
		for (int ite = id; ite < 99; ite++) {
			res::SaveData::save_data.weapon[ite] = res::SaveData::save_data.weapon[ite + 1];
		}
		//ÅŒã‚Ìƒf[ƒ^‚ğíœ
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
			"yšx1z",
			"yšx1z",
			"yšx2z",
			"yšx2z",
			"yšx3z",
			"yšx3z",
			"yšx4z",
			"yšx5z"
		};
		std::string middle[8] = {
			"À—Íƒ^ƒCƒv‚È",
			"ƒnƒ“ƒf•t‚«‚È",
			"•’Ê‚È",
			"‚»‚±‚»‚±ƒ`ƒƒ[ƒW‚³‚ê‚½",
			"‚»‚ê‚È‚è‚Éƒ`ƒƒ[ƒW‚³‚ê‚½",
			"‚í‚è‚Æƒ`ƒƒ[ƒW‚³‚ê‚½",
			"‚©‚È‚èƒ`ƒƒ[ƒW‚³‚ê‚½",
			"ƒtƒ‹ƒ`ƒƒ[ƒW‚³‚ê‚½"
		};
		std::string bottom[5] = {
			"‹¶ŒÀw—Ö",
			"‹Ö’f‰ÊÀ",
			"‚¨ç‚è",
			"‹­—~w—Ö",
			"…»",
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