#include "ItemStack.h"
#include "../../Source/SystemProp/GameStatsProp.h"
#include "../../Source/SystemProp/GameSceneProp/GameSceneProp.h"
#include "../../Source/SystemProp/AliceProp/AliceProp.h"
#include "../../Source/Application/Sound/Sound.h"
#include "../../Source/Resource/SoundData/SoundData.h"
#include "../../Source/Resource/SaveData/SaveData.h"
namespace obj {
	void ItemStack::initialize() {
		initAll();
		if (GameSceneProp::is_extra)initEx();
		if (GameSceneProp::is_practice)initPractice();
		if (GameSceneProp::is_alice)initAlice();
	}
	void ItemStack::initAll() {
		life = PLAYER_STATES::LIFE;
		bom = PLAYER_STATES::BOM;
		life_fragument = 0;
		bom_fragument = 0;
		power = PLAYER_STATES::POWER;
		point = 0;
		graze = 0;
		score = 0;
		apple = 0;
		is_setted_camp = false;
		camp_fragument = 0;
		roulette_bounus = 0;
		camp_max = 500;
	}
	void ItemStack::initPractice() {
		life = 10;
		bom = 10;
		life_fragument = 0;
		bom_fragument = 0;
		power = 400;
		point = 0;
		graze = 0;
		score = 0;
		apple = 0;
		is_setted_camp = false;
		camp_fragument = 0;
		roulette_bounus = 0;
		camp_max = 500;
	}
	void ItemStack::initEx() {
		life = 5;
		bom = 4;
		life_fragument = 0;
		bom_fragument = 0;
		power = PLAYER_STATES::POWER;
		point = 0;
		graze = 0;
		score = 0;
		apple = 0;
		is_setted_camp = false;
		camp_fragument = 0;
		roulette_bounus = 0;
		camp_max = 500;
	}
	void ItemStack::initAlice() {
		auto weapon = res::SaveData::save_data.weapon[AliceProp::weapon_type];
		life = weapon.life;
		bom = weapon.bom;
		life_fragument = 0;
		bom_fragument = 0;
		power = PLAYER_STATES::POWER;
		point = 0;
		graze = 0;
		score = 0;
		apple = 0;
		is_setted_camp = false;
		camp_fragument = 0;
		roulette_bounus = 0;
		camp_max = 500;
	}
	void ItemStack::initDuel() {
		life = 5;
		bom = 0;
		life_fragument = 0;
		bom_fragument = 0;
		power = 0;
		point = 0;
		graze = 0;
		score = 0;
	}
	void ItemStack::chapterInit() {
		roulette_bounus = 0;
		is_setted_camp = false;
		graze = 0;
		if (GameSceneProp::stage == 6)camp_fragument = 0;
		if (GameSceneProp::is_alice)chapterInitAlice();
	}
	void ItemStack::chapterInitAlice() {
		auto weapon = res::SaveData::save_data.weapon[AliceProp::weapon_type];
		if (weapon.ex_type == 0)power = 400;
		if (weapon.ex_type == 1)apple = 2;
	}
	void ItemStack::deadInit() {
		bom = PLAYER_STATES::BOM;
	}
	void ItemStack::update(int rayer) {
		const int bom_max = 10;
		const int life_max = 10;
		const int pow_max = 400;
		if (life < 10 && life_fragument >= 3) {
			app::Sound::sound.playSE(res::SE::LIFEGET);
			life++;
			life_fragument = 0;
		}
		if (bom < bom_max && bom_fragument >= 7) {
			app::Sound::sound.playSE(res::SE::BOMGET);
			bom++;
			bom_fragument = 0;
		}
		if (score > 9999999999)score = 9999999999;
		if (score < 0)score = 0;
		if (life > life_max)life = life_max;
		if (bom > bom_max)bom = bom_max;
		if (power > pow_max)power = pow_max;
		if (apple > 3)apple = 3;

		if (bom < 0)bom = 0;
		if (life >= 10 || life_fragument < 0)life_fragument = 0;
		if (bom >= 10 || bom_fragument < 0)bom_fragument = 0;
		if (power < 0)power = 0;
		if (apple < 0)apple = 0;
	}
}