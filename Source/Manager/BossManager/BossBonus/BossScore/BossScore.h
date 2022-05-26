#pragma once
namespace obj {
	class BossScore {
	private:
		static bool m_Is_inter;
		static bool m_is_main_bullet;
		static int m_Boss_type;
		static int m_Bullet_num;
		static int m_Score;
	public:
		static int result(bool is_inter, bool is_main_bullet, int boss_type, int bullet_num);
		static int result(int boss_type, int bullet_num);
	private:
		static void scoreB1();
		static void scoreB2();
		static void scoreB3();
		static void scoreB4();
		static void scoreB5();
		static void scoreB6();
		static void scoreEx();
		static void scoreAlice();
	};
}