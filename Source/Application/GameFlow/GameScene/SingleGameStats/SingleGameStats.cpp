#include "SingleGameStats.h"
#include <iostream>
#include "../../Source/Resource/EnemyImage/EnemyImage.h"
#include "../../Source/Application/Sound/Sound.h"
using namespace res;

namespace app {
	SingleGameStats::SingleGameStats(int stage, int bullet_type) {
	}
	void SingleGameStats::playSound() {
		Sound::sound.playBGM(m_Sound_type);
	}
	int SingleGameStats::getBossType() {
		return m_Boss_type;
	}
	int SingleGameStats::getMapType() {
		return m_Map_type;
	}
	bool SingleGameStats::isBulletMap() {
		return m_BulletMap_type;
	}
}