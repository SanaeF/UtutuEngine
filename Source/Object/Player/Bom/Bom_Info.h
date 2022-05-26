#pragma once
#include <vector>
#include <memory>
namespace app {
	class Shake;
}
namespace obj {
	class Shot_Info;
	class PlayerShot;
	class OptionManager;
	class Bom_Info {
	private:
		std::shared_ptr<app::Shake>m_Shake;
		float m_Px;
		float m_Py;
		bool m_Is_end;
		int m_Count;
		bool m_Is_no_damage;
	public:
		Bom_Info();
		void initialize();
		void update(float x, float y, int type, bool is_damage);
		void clear();
		bool isEndTime();
		bool isNoDamage();
		std::shared_ptr<app::Shake>getShake();
	private:
		void fadeEffect();
		void patternVS();
		void patternOrg();
		void patternA();
		void patternB();
		void patternC();
		void patternD();
		void patternE();
		void shotInit(int num);
	};
}