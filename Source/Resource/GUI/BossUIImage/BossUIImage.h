#pragma once
namespace res {
	class BossUIImage{
	public:
		int magic_ring;
		int hp;
		int hp_back;
		int bullet_num;
		int serif_box;
		static void load();
		static BossUIImage boss_ui;
	};
}