#pragma once
#include <memory>
namespace obj {
	class ItemManager;
	class BossItem {
	private:
		std::shared_ptr<ItemManager> m_Item;
		bool m_Is_inter;
		bool m_is_main_bullet;
		int m_Boss_type;
		int m_Bullet_num;
		int m_Bonus_scale;
	public:
		BossItem();
		void drop(bool is_damage, bool is_inter, bool is_main_bullet, int boss_type, int bullet_num);
	private:
		void itemB1();
		void itemB2();
		void itemB3();
		void itemB4();
		void itemB5();
		void itemB6();
		void itemEx();
		void itemAlice();
	};
}