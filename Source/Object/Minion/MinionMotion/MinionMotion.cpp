#include "MinionMotion.h"
#include "../../Source/Object/Object/Object.h"
#include "../../Source/Resource/EnemyImage/EnemyImage.h"
using namespace res;

namespace obj {
	MinionMotion::MinionMotion(int minion_type, int count) :
		m_Img_state(0),
		m_Img_rotation(cos(PI / 25 * count) / 60)
	{
		if (minion_type == ENEMY_TYPE::DEV_ORANGE) {
			type1x3(25, count);
		}
		if (minion_type == ENEMY_TYPE::DEV_GREEN) {
			type1x3(17, count);
		}
		if (minion_type == ENEMY_TYPE::OBJ_ONMYOU) {
			typeRotation(count, 0.047);
		}
		if (minion_type == ENEMY_TYPE::DEV_ITEM_BALLOON) {
			type1x3(10, count);
		}
		if (minion_type == ENEMY_TYPE::FIRE_FEARY) {
			type1x(2, 10, count);
		}
		if (minion_type == ENEMY_TYPE::TRAMP_MATSU) {
			type1x5(6, count);
		}
		if (minion_type == ENEMY_TYPE::TRAMP_ELEMIRA) {
			type1x5(8, count);
		}
		if (minion_type == ENEMY_TYPE::TRAMP_FEATORIA) {
			type1x5(6, count);
		}
	}
	int MinionMotion::imgState() {
		return m_Img_state;
	}
	float MinionMotion::imgRotation() {
		return m_Img_rotation;
	}
	void MinionMotion::type1x(int num, int delay, int count) {
		m_Img_state = (count / delay) % num;
	}
	void MinionMotion::type1x3(int delay, int count) {
		m_Img_state = (count / delay) % 3;
	}
	void MinionMotion::type1x5(int delay, int count) {
		m_Img_state = (count / delay) % 5;
	}
	void MinionMotion::typeRotation(int count, float speed) {
		m_Img_rotation = count * speed;
	}
}