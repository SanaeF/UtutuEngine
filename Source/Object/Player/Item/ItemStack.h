#pragma once
namespace obj {
	class ItemStack {
	public:
		int life;
		int bom;
		int life_fragument;
		int bom_fragument;
		int power;
		int point;
		int graze;
		int score;
		int apple;
		bool is_setted_camp;
		int camp_max;
		int camp_fragument;
		int roulette_bounus;
		void initialize();
		void initDuel();
		void chapterInit();
		void deadInit();
		void update(int rayer);
	private:
		void initAll();
		void initPractice();
		void initEx();
		void initAlice();
		void chapterInitAlice();
	};
}