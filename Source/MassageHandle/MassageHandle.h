#pragma once

namespace obj {
//#define MassageHandle(type) MassageManager::MassageType(type)
//#define MassageHandleItem(type, num) MassageManager::MassageType(type, num)

#define MassageHandle(type,who) MassageManager::PlayersMassage(type, who)
#define MassageHandleItem(type,num,who) MassageManager::ItemsMassage(type, num, who)

	enum PLAYER {
		GetPower,
		GetPoint,
		GetGraze,
		GetLifeFragment,
		GetBomFragment,
		GetLife,
		GetBom,
		GetApple,
		GetScore,
		StartRoulette,
		Damage
	};
	class MassageManager {
	private:
		static void GetPower(int num, int who = 0);
		static void GetPoint(int num, int who = 0);
		static void GetGraze(int num, int who = 0);
		static void GetLife(int num, int who = 0);
		static void GetBom(int num, int who = 0);
		static void GetLifeFragment(int num, int who = 0);
		static void GetBomFragument(int num, int who = 0);
		static void GetApple(int num, int who = 0);
		static void GetScore(int num, int who = 0);

		static void Damage(int who = 0);

	public:
		static void PlayersMassage(int Massage, int who);
		static void ItemsMassage(int Massage, int num, int who);
		static void MassageType(int Massage);
		static void MassageType(int Massage, int num);
	};
}