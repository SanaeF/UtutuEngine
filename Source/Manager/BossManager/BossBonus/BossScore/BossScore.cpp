#include "BossScore.h"
#include "../../Source/Resource/EnemyImage/EnemyImage.h"

namespace obj {
	void BossScore::scoreB1() {//一般的な合計獲得数1060000
		if (m_Bullet_num == 0)m_Score = 150000;
		if (m_Bullet_num == 1)m_Score = 320000;
		if (m_Bullet_num == 2)m_Score = 160000;
		if (m_Bullet_num == 3)m_Score = 400000;
		if (m_Bullet_num == 4)m_Score = 620000;
	}
	void BossScore::scoreB2() {//一般的な合計獲得数1250000
		if (m_Bullet_num == 0)m_Score = 150000;
		if (m_Bullet_num == 1)m_Score = 320000;
		if (m_Bullet_num == 2)m_Score = 400000;
		if (m_Bullet_num == 3)m_Score = 170000;
		if (m_Bullet_num == 4)m_Score = 420000;
		if (m_Bullet_num == 5)m_Score = 640000;
	}
	void BossScore::scoreB3() {//一般的な合計獲得数1225000
		if (m_Bullet_num == 0)m_Score = 150000;
		if (m_Bullet_num == 1)m_Score = 320000;
		if (m_Bullet_num == 2)m_Score = 170000;
		if (m_Bullet_num == 3)m_Score = 400000;
		if (m_Bullet_num == 4)m_Score = 170000;
		if (m_Bullet_num == 5)m_Score = 450000;
		if (m_Bullet_num == 6)m_Score = 640000;
	}
	void BossScore::scoreB4() {//一般的な合計獲得数1270000
		if (m_Bullet_num == 0)m_Score = 150000;
		if (m_Bullet_num == 1)m_Score = 370000;
		if (m_Bullet_num == 2)m_Score = 170000;
		if (m_Bullet_num == 3)m_Score = 420000;
		if (m_Bullet_num == 4)m_Score = 170000;
		if (m_Bullet_num == 5)m_Score = 450000;
		if (m_Bullet_num == 6)m_Score = 660000;
	}
	void BossScore::scoreB5() {//一般的な合計獲得数1180000
		if (m_Bullet_num == 0)m_Score = 430000;
		if (m_Bullet_num == 1)m_Score = 170000;
		if (m_Bullet_num == 2)m_Score = 460000;
		if (m_Bullet_num == 3)m_Score = 680000;
	}
	void BossScore::scoreB6() {//一般的な合計獲得数2287667
		if (m_Bullet_num == 0)m_Score = 150000;
		if (m_Bullet_num == 1)m_Score = 370000;
		if (m_Bullet_num == 2)m_Score = 170000;
		if (m_Bullet_num == 3)m_Score = 420000;
		if (m_Bullet_num == 4)m_Score = 170000;
		if (m_Bullet_num == 5)m_Score = 450000;
		if (m_Bullet_num == 6)m_Score = 180000;
		if (m_Bullet_num == 7)m_Score = 500000;
		if (m_Bullet_num == 8)m_Score = 666000;
		if (m_Bullet_num == 9)m_Score = 999334;
	}
	void BossScore::scoreEx() {
		if (m_Bullet_num == 0)m_Score = 150000;
		if (m_Bullet_num == 1)m_Score = 370000;
		if (m_Bullet_num == 2)m_Score = 170000;
		if (m_Bullet_num == 3)m_Score = 420000;
		if (m_Bullet_num == 4)m_Score = 170000;
		if (m_Bullet_num == 5)m_Score = 450000;
		if (m_Bullet_num == 6)m_Score = 180000;
		if (m_Bullet_num == 7)m_Score = 500000;
		if (m_Bullet_num == 8)m_Score = 180000;
		if (m_Bullet_num == 9)m_Score = 666000;
		if (m_Bullet_num == 10)m_Score = 999334;
	}
	void BossScore::scoreAlice() {//一般的な合計獲得数1470000
		if (m_Bullet_num == 0)m_Score = 150000;
		if (m_Bullet_num == 1)m_Score = 320000;
		if (m_Bullet_num == 2)m_Score = 170000;
		if (m_Bullet_num == 3)m_Score = 400000;
		if (m_Bullet_num == 4)m_Score = 170000;
		if (m_Bullet_num == 5)m_Score = 450000;
		if (m_Bullet_num == 6)m_Score = 640000*2;
		m_Score = m_Score * 2;
	}

	bool BossScore::m_Is_inter;
	bool BossScore::m_is_main_bullet;
	int BossScore::m_Boss_type;
	int BossScore::m_Bullet_num;
	int BossScore::m_Score;

	int BossScore::result(bool is_inter, bool is_main_bullet, int boss_type, int bullet_num) {
		m_Is_inter = is_inter;
		m_is_main_bullet = is_main_bullet;
		m_Boss_type = boss_type;
		m_Bullet_num = bullet_num;
		m_Score = 0;
		if (m_Is_inter) {
			if (!m_is_main_bullet)m_Score = 150000;
			else m_Score = 320000;
		}
		else {
			if (m_Boss_type == res::BOSS_TYPE::N01_MATUMI)scoreB1();
			if (m_Boss_type == res::BOSS_TYPE::N02_EREMIRA)scoreB2();
			if (m_Boss_type == res::BOSS_TYPE::N03_ALICE)scoreB3();
			if (m_Boss_type == res::BOSS_TYPE::N04_NARSIRU)scoreB4();
			if (m_Boss_type == res::BOSS_TYPE::N05_FEATORIA)scoreB5();
			if (m_Boss_type == res::BOSS_TYPE::N06_SHIENA)scoreB6();
			if (m_Boss_type == res::BOSS_TYPE::N07_ALICE)scoreAlice();
			if (m_Boss_type == res::BOSS_TYPE::N08_KURO)scoreEx();
		}
		return m_Score;
	}
	int BossScore::result(int boss_type, int bullet_num) {
		m_Boss_type = boss_type;
		m_Bullet_num = bullet_num;
		m_Score = 0;
		if (m_Boss_type == res::BOSS_TYPE::N01_MATUMI)scoreB1();
		if (m_Boss_type == res::BOSS_TYPE::N02_EREMIRA)scoreB2();
		if (m_Boss_type == res::BOSS_TYPE::N03_ALICE)scoreB3();
		if (m_Boss_type == res::BOSS_TYPE::N04_NARSIRU)scoreB4();
		if (m_Boss_type == res::BOSS_TYPE::N05_FEATORIA)scoreB5();
		if (m_Boss_type == res::BOSS_TYPE::N06_SHIENA)scoreB6();
		if (m_Boss_type == res::BOSS_TYPE::N07_ALICE)scoreAlice();
		if (m_Boss_type == res::BOSS_TYPE::N08_KURO)scoreEx();
		return m_Score;
	}
}