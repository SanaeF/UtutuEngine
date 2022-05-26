#pragma once
#include <memory>
namespace obj {
	class BossItem;
	class BossBonus {
		std::shared_ptr<BossItem>m_Item;
		bool m_Is_flag;
		bool m_Is_start_counter;
		bool m_Is_inter;
		bool m_is_main_bullet;
		bool m_Is_call;
		bool m_Is_failed;
		bool m_Is_no_damage;
		int m_Boss_type;
		int m_Bullet_num;
		int m_Count;
		int m_Bullet_last_time;
		int m_Bounus_score;
	public:
		BossBonus();
		void initialize(bool is_inter, bool is_main_bullet, bool is_no_damage, int boss_type, int bullet_num);
		void initialize(bool is_no_damage, int boss_type, int bullet_num);
		void update();
		void draw();
		void dropItem();
		void setBulletLastTime(int time);
		void setBonusCall(int boss_time);
	private:
		void scoreB1();
		void scoreB2();
		void itemB1();
		void itemB2();
	};
}