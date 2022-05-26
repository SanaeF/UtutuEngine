#pragma once
namespace app {
	class SingleGameStats {
	private:
		int m_Boss_type;
		int m_Map_type;
		int m_Sound_type;
		bool m_BulletMap_type;
	public:
		SingleGameStats(int stage, int bullet_type);
		void playSound();
		int getBossType();
		int getMapType();
		bool isBulletMap();
	};
}