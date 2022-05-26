#pragma once
#include <vector>

namespace obj {
	class BackGraph;
	class Boss;
}
namespace app {
	class StageMap {
	private:
		enum {
			MAP_OBJ_MAX = 10
		};
		bool m_Is_main_bullet;
		int m_Stage;
		int m_Count;
		int m_Stage_count;
	public:
		void update(int stage_count);
		void draw(double cx = 0.f, double cy = 0.f);
		void create(bool isMainBullet, int stage);
		void setCount(int count);
		int getCount();
		StageMap();
	private:
		bool isState(int stage);
		void startForRood();
		void startForBullet();
		bool setMapObjNum(int num);
	};
}