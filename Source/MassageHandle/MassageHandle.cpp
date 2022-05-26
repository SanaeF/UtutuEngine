#include "MassageHandle.h"
#include "../../Source/Object/Player/Player.h"
#include "../../Source/Application/Sound/Sound.h"
#include "../../Source/Resource/SoundData/SoundData.h"
#include "../../Source/SystemProp/GameStatsProp.h"
#include "../../Source/SystemProp/AliceProp/AliceProp.h"
namespace obj {
	void MassageManager::PlayersMassage(int Massage, int who) {
		if (Massage == PLAYER::Damage)Damage(who);
	}
	void MassageManager::ItemsMassage(int Massage, int num, int who) {
		if (Massage == PLAYER::GetPower)GetPower(num, who);
		if (Massage == PLAYER::GetPoint)GetPoint(num, who);
		if (Massage == PLAYER::GetGraze)GetGraze(num, who);
		if (Massage == PLAYER::GetLife)GetLife(num, who);
		if (Massage == PLAYER::GetBom)GetBom(num, who);
		if (Massage == PLAYER::GetLifeFragment)GetLifeFragment(num, who);
		if (Massage == PLAYER::GetBomFragment)GetBomFragument(num, who);
		if (Massage == PLAYER::GetApple)GetApple(num, who);
		if (Massage == PLAYER::GetScore)GetScore(num, who);
		if (Massage == PLAYER::StartRoulette) {
			if (who == 0) {
				Player::PlayerObj.setRoulette(true);
				Player::PlayerObj.getItemStack().roulette_bounus += 1;
			}
			if (who == 1) {
				Player::PlayersObj[0].setRoulette(true);
				Player::PlayersObj[0].getItemStack().roulette_bounus += 1;
			}
			if (who == 2) {
				Player::PlayersObj[1].setRoulette(true);
				Player::PlayersObj[1].getItemStack().roulette_bounus += 1;
			}
		}
	}
	void MassageManager::MassageType(int Massage) {
		if (Massage == PLAYER::Damage)Damage();
	}

	void MassageManager::MassageType(int Massage, int num) {
		if (Massage == PLAYER::GetPower)GetPower(num);
		if (Massage == PLAYER::GetPoint)GetPoint(num);
		if (Massage == PLAYER::GetGraze)GetGraze(num);
		if (Massage == PLAYER::GetLife)GetLife(num);
		if (Massage == PLAYER::GetBom)GetBom(num);
		if (Massage == PLAYER::GetLifeFragment)GetLifeFragment(num);
		if (Massage == PLAYER::GetBomFragment)GetBomFragument(num);
		if (Massage == PLAYER::GetApple)GetApple(num);
		if (Massage == PLAYER::GetScore)GetScore(num);
		if (Massage == PLAYER::StartRoulette) {
			Player::PlayerObj.setRoulette(true);
			Player::PlayerObj.getItemStack().roulette_bounus += 1;
		}
	}

	void MassageManager::GetPower(int num, int who) {
		if (who == 0)Player::PlayerObj.getItemStack().power += num;
		if (who == 1)Player::PlayersObj[0].getItemStack().power += num;
		if (who == 2)Player::PlayersObj[1].getItemStack().power += num;
	}
	void MassageManager::GetPoint(int num, int who) {
		int add_lv_0 = 1;
		if (AliceProp::flag)add_lv_0 = AliceProp::level_num;
		if (who == 0)Player::PlayerObj.getItemStack().point += num + add_lv_0;
		if (who == 1)Player::PlayersObj[0].getItemStack().point += num;
		if (who == 2)Player::PlayersObj[1].getItemStack().point += num;
	}
	void MassageManager::GetGraze(int num, int who) {
		app::Sound::sound.playSE(res::SE::GRAZE);
		if (who == 0) {
			Player::PlayerObj.getItemStack().graze += num;
			Player::PlayerObj.setIsGraze(true);
			Player::PlayerObj.getItemStack().camp_fragument += num;
		}
		if (who == 1)Player::PlayersObj[0].getItemStack().graze += num;
		if (who == 2)Player::PlayersObj[1].getItemStack().graze += num;
	}
	void MassageManager::GetLife(int num, int who) {
		app::Sound::sound.playSE(res::SE::LIFEGET);
		if (who == 0)Player::PlayerObj.getItemStack().life += num;
		if (who == 1)Player::PlayersObj[0].getItemStack().life += num;
		if (who == 2)Player::PlayersObj[1].getItemStack().life += num;
	}
	void MassageManager::GetBom(int num, int who) {
		app::Sound::sound.playSE(res::SE::BOMGET);
		if (who == 0)Player::PlayerObj.getItemStack().bom += num;
		if (who == 1)Player::PlayersObj[0].getItemStack().bom = +num;
		if (who == 2)Player::PlayersObj[1].getItemStack().bom = +num;
	}
	void MassageManager::GetLifeFragment(int num, int who) {
		app::Sound::sound.playSE(res::SE::GOT_ITEM);
		if (who == 0)Player::PlayerObj.getItemStack().life_fragument += num;
		if (who == 1)Player::PlayersObj[0].getItemStack().life_fragument += num;
		if (who == 2)Player::PlayersObj[1].getItemStack().life_fragument += num;
	}
	void MassageManager::GetBomFragument(int num, int who) {
		app::Sound::sound.playSE(res::SE::GOT_ITEM);
		if (who == 0)Player::PlayerObj.getItemStack().bom_fragument += num;
		if (who == 1)Player::PlayersObj[0].getItemStack().bom_fragument += num;
		if (who == 2)Player::PlayersObj[1].getItemStack().bom_fragument += num;
	}
	void MassageManager::GetApple(int num, int who) {
		app::Sound::sound.playSE(res::SE::GOT_ITEM);
		if (who == 0)Player::PlayerObj.getItemStack().apple += num;
		if (who == 1)Player::PlayersObj[0].getItemStack().apple += num;
		if (who == 2)Player::PlayersObj[1].getItemStack().apple += num;
	}
	void MassageManager::GetScore(int num, int who) {
		int add_lv_0 = 1;
		if (AliceProp::flag)add_lv_0 = AliceProp::level_num / 5;
		if (who == 0)Player::PlayerObj.getItemStack().score += num + add_lv_0;
		if (who == 1)Player::PlayersObj[0].getItemStack().score += num;
		if (who == 2)Player::PlayersObj[1].getItemStack().score += num;
	}
	void MassageManager::Damage(int who) {
		if(USE_DEBUGLOG)return;
		if (who == 0) {
			Player::PlayerObj.damage();
			if (!Player::PlayersObj[0].isHideMode())Player::PlayersObj[0].damage();
			if (!Player::PlayersObj[1].isHideMode())Player::PlayersObj[1].damage();
		}
		if (who == 1)Player::PlayersObj[0].damage();
		if (who == 2)Player::PlayersObj[1].damage();
	}

}