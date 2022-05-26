#include "BossItem.h"
#include "../../Source/SystemProp/GameSceneProp/GameSceneProp.h"
#include "../../Source/Manager/ItemManager/ItemManager.h"
#include "../../Source/Resource/EnemyImage/EnemyImage.h"
#include "../../Source/Resource/ItemImage/ItemImage.h"
using namespace res;
namespace obj {
	void BossItem::itemB1() {
		if (m_Is_inter) {
			if (m_Bullet_num == 0)m_Item->dropBoss(5 * m_Bonus_scale, ITEM_TYPE::POWER_GHOST, 0);
			if (m_Bullet_num == 1) {
				m_Item->dropBoss(5 * m_Bonus_scale, ITEM_TYPE::POINT_GHOST, 0);
				m_Item->dropBoss(1 * m_Bonus_scale, ITEM_TYPE::BOM_PEACE, 0);
			}
		}
		else {
			if (m_Bullet_num == 0)m_Item->dropBoss(7 * m_Bonus_scale, ITEM_TYPE::POWER_GHOST, 0);
			if (m_Bullet_num == 1) {
				m_Item->dropBoss(12 * m_Bonus_scale, ITEM_TYPE::POWER_GHOST, 0);
				m_Item->dropBoss(7 * m_Bonus_scale, ITEM_TYPE::POINT_GHOST, 0);
				m_Item->dropBoss(1 * m_Bonus_scale, ITEM_TYPE::BOM_PEACE, 0);
			}
			if (m_Bullet_num == 2)m_Item->dropBoss(10 * m_Bonus_scale, ITEM_TYPE::POWER_GHOST, 0);
			if (m_Bullet_num == 3) {
				m_Item->dropBoss(16 * m_Bonus_scale, ITEM_TYPE::POWER_GHOST, 0);
				m_Item->dropBoss(7 * m_Bonus_scale, ITEM_TYPE::POINT_GHOST, 0);
				m_Item->dropBoss(1 * m_Bonus_scale, ITEM_TYPE::BOM_PEACE, 0);
			}
			if (m_Bullet_num == 4) {
				m_Item->dropBoss(20 * m_Bonus_scale, ITEM_TYPE::POWER_GHOST, 0);
				m_Item->dropBoss(7 * m_Bonus_scale, ITEM_TYPE::POINT_GHOST, 0);
				m_Item->dropBoss(1, ITEM_TYPE::LIFE_PEACE, 0);
			}
		}
	}
	void BossItem::itemB2() {
		if (m_Is_inter) {
		}
		else {
			if (m_Bullet_num == 0)m_Item->dropBoss(7 * m_Bonus_scale, ITEM_TYPE::POWER_GHOST, 0);
			if (m_Bullet_num == 1) {
				m_Item->dropBoss(12 * m_Bonus_scale, ITEM_TYPE::POWER_GHOST, 0);
				m_Item->dropBoss(7 * m_Bonus_scale, ITEM_TYPE::POINT_GHOST, 0);
				m_Item->dropBoss(1 * m_Bonus_scale, ITEM_TYPE::BOM_PEACE, 0);
			}
			if (m_Bullet_num == 2)m_Item->dropBoss(1, ITEM_TYPE::LIFE_UP, 0);
			if (m_Bullet_num == 3)m_Item->dropBoss(7 * m_Bonus_scale, ITEM_TYPE::POWER_GHOST, 0);
			if (m_Bullet_num == 4) {
				m_Item->dropBoss(16 * m_Bonus_scale, ITEM_TYPE::POWER_GHOST, 0);
				m_Item->dropBoss(7 * m_Bonus_scale, ITEM_TYPE::POINT_GHOST, 0);
				m_Item->dropBoss(1 * m_Bonus_scale, ITEM_TYPE::BOM_PEACE, 0);
			}
			if (m_Bullet_num == 5) {
				m_Item->dropBoss(16 * m_Bonus_scale, ITEM_TYPE::POWER_GHOST, 0);
				m_Item->dropBoss(7 * m_Bonus_scale, ITEM_TYPE::POINT_GHOST, 0);
				m_Item->dropBoss(1, ITEM_TYPE::LIFE_PEACE, 0);
			}
		}
	}
	void BossItem::itemB3() {
		if (m_Is_inter) {
			m_Item->dropBoss(1, ITEM_TYPE::LIFE_PEACE, 0);
		}
		else {
			if (m_Bullet_num == 0)m_Item->dropBoss(7 * m_Bonus_scale, ITEM_TYPE::POINT_GHOST, 0);
			if (m_Bullet_num == 1) {
				m_Item->dropBoss(7 * m_Bonus_scale, ITEM_TYPE::POWER_GHOST, 0);
				m_Item->dropBoss(1 * m_Bonus_scale, ITEM_TYPE::BOM_PEACE, 0);
			}
			if (m_Bullet_num == 2)m_Item->dropBoss(7 * m_Bonus_scale, ITEM_TYPE::POINT_GHOST, 0);
			if (m_Bullet_num == 3) {
				m_Item->dropBoss(7 * m_Bonus_scale, ITEM_TYPE::POWER_GHOST, 0);
				m_Item->dropBoss(1 * m_Bonus_scale, ITEM_TYPE::BOM_PEACE, 0);
			}
			if (m_Bullet_num == 4)m_Item->dropBoss(7 * m_Bonus_scale, ITEM_TYPE::POINT_GHOST, 0);
			if (m_Bullet_num == 5) {
				m_Item->dropBoss(1, ITEM_TYPE::LIFE_UP, 0);
			}
			if (m_Bullet_num == 6) {
				m_Item->dropBoss(16 * m_Bonus_scale, ITEM_TYPE::POWER_GHOST, 0);
				m_Item->dropBoss(7 * m_Bonus_scale, ITEM_TYPE::POINT_GHOST, 0);
				m_Item->dropBoss(1, ITEM_TYPE::LIFE_PEACE, 0);
			}
		}

	}
	void BossItem::itemB4() {
		if (m_Is_inter) {
			if (m_Bullet_num == 0) {
				m_Item->dropBoss(7 * m_Bonus_scale, ITEM_TYPE::POWER_GHOST, 0);
				m_Item->dropBoss(1 * m_Bonus_scale, ITEM_TYPE::BOM_PEACE, 0);
			}
		}
		else {
			if (m_Bullet_num == 0)m_Item->dropBoss(7 * m_Bonus_scale, ITEM_TYPE::POINT_GHOST, 0);
			if (m_Bullet_num == 1) {
				m_Item->dropBoss(7 * m_Bonus_scale, ITEM_TYPE::POWER_GHOST, 0);
				m_Item->dropBoss(1 * m_Bonus_scale, ITEM_TYPE::BOM_PEACE, 0);
			}
			if (m_Bullet_num == 2)m_Item->dropBoss(7 * m_Bonus_scale, ITEM_TYPE::POINT_GHOST, 0);
			if (m_Bullet_num == 3) {
				m_Item->dropBoss(7 * m_Bonus_scale, ITEM_TYPE::POWER_GHOST, 0);
				m_Item->dropBoss(1 * m_Bonus_scale, ITEM_TYPE::BOM_PEACE, 0);
			}
			if (m_Bullet_num == 4)m_Item->dropBoss(7 * m_Bonus_scale, ITEM_TYPE::POINT_GHOST, 0);
			if (m_Bullet_num == 5) {
				m_Item->dropBoss(7 * m_Bonus_scale, ITEM_TYPE::POWER_GHOST, 0);
				m_Item->dropBoss(1 * m_Bonus_scale, ITEM_TYPE::BOM_PEACE, 0);
			}
			if (m_Bullet_num == 6) {
				m_Item->dropBoss(16 * m_Bonus_scale, ITEM_TYPE::POWER_GHOST, 0);
				m_Item->dropBoss(7 * m_Bonus_scale, ITEM_TYPE::POINT_GHOST, 0);
				m_Item->dropBoss(1 * m_Bonus_scale, ITEM_TYPE::LIFE_PEACE, 0);
			}
		}

	}
	void BossItem::itemB5() {
		if (m_Is_inter) {
			if (m_Bullet_num == 0)m_Item->dropBoss(7 * m_Bonus_scale, ITEM_TYPE::POINT_GHOST, 0);
			if (m_Bullet_num == 1) {
				m_Item->dropBoss(7 * m_Bonus_scale, ITEM_TYPE::POWER_GHOST, 0);
				m_Item->dropBoss(1 * m_Bonus_scale, ITEM_TYPE::BOM_PEACE, 0);
			}
			if (m_Bullet_num == 2)m_Item->dropBoss(7 * m_Bonus_scale, ITEM_TYPE::POINT_GHOST, 0);
		}
		else {
			if (m_Bullet_num == 0)m_Item->dropBoss(1, ITEM_TYPE::LIFE_UP, 0);
			if (m_Bullet_num == 1)m_Item->dropBoss(7 * m_Bonus_scale, ITEM_TYPE::POINT_GHOST, 0);
			if (m_Bullet_num == 2) {
				m_Item->dropBoss(7 * m_Bonus_scale, ITEM_TYPE::POWER_GHOST, 0);
				m_Item->dropBoss(1 * m_Bonus_scale, ITEM_TYPE::BOM_PEACE, 0);
			}
			if (m_Bullet_num == 3) {
				m_Item->dropBoss(16, ITEM_TYPE::POWER_GHOST, 0);
				m_Item->dropBoss(7 * m_Bonus_scale, ITEM_TYPE::POINT_GHOST, 0);
				m_Item->dropBoss(1, ITEM_TYPE::LIFE_PEACE, 0);
			}
		}
	}
	void BossItem::itemB6() {
		if (m_Is_inter) {
		}
		else {
			if (m_Bullet_num == 0)m_Item->dropBoss(7 * m_Bonus_scale, ITEM_TYPE::POINT_GHOST, 0);
			if (m_Bullet_num == 1) {
				m_Item->dropBoss(4 * m_Bonus_scale, ITEM_TYPE::POINT_GHOST, 0);
				m_Item->dropBoss(1 * m_Bonus_scale, ITEM_TYPE::BOM_PEACE, 0);
			}
			if (m_Bullet_num == 2)m_Item->dropBoss(7, ITEM_TYPE::POINT_GHOST, 0);
			if (m_Bullet_num == 3) {
				m_Item->dropBoss(5 * m_Bonus_scale, ITEM_TYPE::POINT_GHOST, 0);
				m_Item->dropBoss(1, ITEM_TYPE::LIFE_PEACE, 0);
			}
			if (m_Bullet_num == 4)m_Item->dropBoss(7, ITEM_TYPE::POINT_GHOST, 0);
			if (m_Bullet_num == 5) {
				m_Item->dropBoss(5 * m_Bonus_scale, ITEM_TYPE::POINT_GHOST, 0);
				m_Item->dropBoss(1 * m_Bonus_scale, ITEM_TYPE::BOM_PEACE, 0);
			}
			if (m_Bullet_num == 6)m_Item->dropBoss(7, ITEM_TYPE::POINT_GHOST, 0);
			if (m_Bullet_num == 7) {
				m_Item->dropBoss(5 * m_Bonus_scale, ITEM_TYPE::POINT_GHOST, 0);
				m_Item->dropBoss(3 * m_Bonus_scale, ITEM_TYPE::BOM_PEACE, 0);
			}
			if (m_Bullet_num == 8) {
				m_Item->dropBoss(5 * m_Bonus_scale, ITEM_TYPE::POINT_GHOST, 0);
				m_Item->dropBoss(1, ITEM_TYPE::LIFE_UP, 0);
			}
		}
	}
	void BossItem::itemEx() {
		if (m_Is_inter) {
			if (m_Bullet_num == 0)m_Item->dropBoss(1, ITEM_TYPE::LIFE_UP, 0);
			if (m_Bullet_num == 1)m_Item->dropBoss(1 * m_Bonus_scale, ITEM_TYPE::LIFE_UP, 0);
		}
		else {
			m_Item->dropBoss(8 * m_Bonus_scale, ITEM_TYPE::POINT_GHOST, 0);
			m_Item->dropBoss(1, ITEM_TYPE::LIFE_PEACE, 0);
		}
	}
	void BossItem::itemAlice() {
		if (m_Is_inter) {
		}
		else {
			if (m_Bullet_num == 0)m_Item->dropBoss(50 * m_Bonus_scale, ITEM_TYPE::POINT_GHOST, 0);
			if (m_Bullet_num == 1) {
				m_Item->dropBoss(7 * m_Bonus_scale, ITEM_TYPE::POWER_GHOST, 0);
				m_Item->dropBoss(1 * m_Bonus_scale, ITEM_TYPE::BOM_PEACE, 0);
			}
			if (m_Bullet_num == 2)m_Item->dropBoss(50 * m_Bonus_scale, ITEM_TYPE::POINT_GHOST, 0);
			if (m_Bullet_num == 3) {
				m_Item->dropBoss(7 * m_Bonus_scale, ITEM_TYPE::POWER_GHOST, 0);
				m_Item->dropBoss(1 * m_Bonus_scale, ITEM_TYPE::BOM_PEACE, 0);
			}
			if (m_Bullet_num == 4)m_Item->dropBoss(50 * m_Bonus_scale, ITEM_TYPE::POINT_GHOST, 0);
			if (m_Bullet_num == 5) {
				m_Item->dropBoss(7 * m_Bonus_scale, ITEM_TYPE::POWER_GHOST, 0);
				m_Item->dropBoss(1 * m_Bonus_scale, ITEM_TYPE::BOM_PEACE, 0);
			}
			if (m_Bullet_num == 6) {
				m_Item->dropBoss(16 * m_Bonus_scale, ITEM_TYPE::POWER_GHOST, 0);
				m_Item->dropBoss(50 * m_Bonus_scale, ITEM_TYPE::POINT_GHOST, 0);
			}
		}
	}
	BossItem::BossItem() {
		m_Item.reset(new ItemManager());
	}
	void BossItem::drop(bool is_damage, bool is_inter, bool is_main_bullet, int boss_type, int bullet_num) {
		m_Is_inter = is_inter;
		m_is_main_bullet = is_main_bullet;
		m_Boss_type = boss_type;
		m_Bullet_num = bullet_num;
		m_Bonus_scale = 1;
		if (!is_damage)m_Bonus_scale = 2;
		if (GameSceneProp::stage == 0)itemB1();
		if (GameSceneProp::stage == 1)itemB2();
		if (GameSceneProp::stage == 2)itemB3();
		if (GameSceneProp::stage == 3)itemB4();
		if (GameSceneProp::stage == 4)itemB5();
		if (GameSceneProp::stage == 5)itemB6();
		if (GameSceneProp::stage == 6)itemAlice();
		if (GameSceneProp::stage==7)itemEx();
		if (!is_damage && GameSceneProp::under_wear == 2) {
			m_Item->dropBoss(1, ITEM_TYPE::LIFE_PEACE, 0);
		}
	}
}