#include "BossMotion.h"
#include "../../Source/Object/Object/Object.h"
#include "../../Source/Resource/EnemyImage/EnemyImage.h"

using namespace res;

namespace obj {
	BossMotion::BossMotion(int boss_type, int motion_type, float angle, int count):
		m_Img_state(0),
		m_Img_rotation(angle)
	{
		if (boss_type == BOSS_TYPE::N01_MATUMI|| boss_type == BOSS_TYPE::N03_MATUMI)bossType0(motion_type, count);
		if (boss_type == BOSS_TYPE::N02_EREMIRA|| boss_type == BOSS_TYPE::N03_EREMIRA)bossType1(motion_type, count);
		if (boss_type == BOSS_TYPE::N03_ALICE)bossType2(motion_type, count);
		if (boss_type == BOSS_TYPE::N04_NARSIRU)bossType3(motion_type, count);
		if (boss_type == BOSS_TYPE::N05_BLACK || boss_type == BOSS_TYPE::N05_FEATORIA || boss_type == BOSS_TYPE::N07_FEATORIA)
			bossType4(motion_type, count);
		if (boss_type == BOSS_TYPE::N06_SHIENA)bossType5(motion_type, count);
		if (boss_type == BOSS_TYPE::N07_ALICE)bossTypeAlice(motion_type, count);
		if (boss_type == BOSS_TYPE::N08_KURO)bossTypeEx(motion_type, count);
	}
	int BossMotion::imgState() {
		return m_Img_state;
	}
	float BossMotion::imgRotation() {
		return m_Img_rotation;
	}
	void BossMotion::bossType0(int motion_type, int count) {
		if (motion_type == 0) {
			m_Img_state = (int(count / 24)) % 2;
			m_Img_rotation = m_Img_rotation + cos(PI / 25 * count) / 60;
		}
		if (motion_type == 1) {
			m_Img_state = 2 + (int(count / 24)) % 2;
			m_Img_rotation = m_Img_rotation + cos(PI / 25 * count) / 60;
		}
		if (motion_type == 2) {
			m_Img_state = 2 + (int(count / 24)) % 2;
			m_Img_rotation = 0;
		}
	}
	void BossMotion::bossType1(int motion_type, int count) {
		if (motion_type == 0) {
			m_Img_state = (int(count / 12)) % 2;
			m_Img_rotation = m_Img_rotation + cos(PI / 25 * count) / 60;
		}
		if (motion_type == 1) {
			m_Img_state = 2 + (int(count / 12)) % 2;
			m_Img_rotation = m_Img_rotation + cos(PI / 25 * count) / 60;
		}
		if (motion_type == 2) {
			m_Img_state = 1;
			m_Img_rotation = m_Img_rotation + cos(PI / 25 * count) / 60;
		}
		if (motion_type == 3) {
			m_Img_state = 3;
			m_Img_rotation = m_Img_rotation + cos(PI / 25 * count) / 60;
		}
	}
	void BossMotion::bossType2(int motion_type, int count) {
		if (motion_type == 0) {
			m_Img_state = (int(count / 24)) % 2;
			m_Img_rotation = m_Img_rotation + cos(PI / 25 * count) / 60;
		}
		if (motion_type == 1) {
			m_Img_state = 2 + (int(count / 24)) % 2;
			m_Img_rotation = m_Img_rotation + cos(PI / 25 * count) / 60;
		}
		if (motion_type == 2) {
			m_Img_state = 2 + (int(count / 24)) % 2;
			m_Img_rotation = 0;
		}
	}
	void BossMotion::bossType3(int motion_type, int count) {
		if (motion_type == 0) {
			m_Img_state = (int(count / 16)) % 3;
			m_Img_rotation = m_Img_rotation + cos(PI / 18 * count) / 80;
		}
		if (motion_type == 1) {
			m_Img_state = 4 + (int(count / 16)) % 3;
			m_Img_rotation = m_Img_rotation + cos(PI / 18 * count) / 80;
		}
		if (motion_type == 2) {
			m_Img_state = 0;
			m_Img_rotation = 0;
		}
		if (motion_type == 3) {
			m_Img_state = 4;
			m_Img_rotation = 0;
		}
	}
	void BossMotion::bossType4(int motion_type, int count) {
		if (motion_type == 0) {
			m_Img_state = (int(count / 20)) % 2;
			m_Img_rotation = m_Img_rotation + cos(PI / 25 * count) / 60;
		}
		if (motion_type == 1) {
			m_Img_state = 2 + (int(count / 30)) % 2;
			m_Img_rotation = m_Img_rotation + cos(PI / 25 * count) / 60;
		}
		if (motion_type == 2) {
			m_Img_state = (int(count / 20)) % 2;
			m_Img_rotation = 0;
		}
	}
	void BossMotion::bossType5(int motion_type, int count) {
		if (motion_type == 0) {
			m_Img_state = (int(count / 20)) % 2;
			m_Img_rotation = m_Img_rotation + cos(PI / 25 * count) / 60;
		}
		if (motion_type == 1) {
			m_Img_state = 2 + (int(count / 30)) % 2;
			m_Img_rotation = m_Img_rotation + cos(PI / 25 * count) / 60;
		}
		if (motion_type == 2) {
			m_Img_state = (int(count / 20)) % 2;
			m_Img_rotation = 0;
		}
	}
	void BossMotion::bossTypeAlice(int motion_type, int count) {
		m_Img_state = 0;
		if (motion_type == 0)m_Img_rotation = m_Img_rotation + cos(PI / 25 * count) / 120;
		if (motion_type == 1)m_Img_rotation = 0;
	}
	void BossMotion::bossTypeEx(int motion_type, int count) {
		m_Img_rotation = 0;
		if (motion_type == 0) {
			m_Img_state = (int(count / 40)) % 2;
		}
		if (motion_type == 1) {
			m_Img_state = 2 + (int(count / 40)) % 2;
		}
	}
}