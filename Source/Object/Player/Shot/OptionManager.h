#pragma once
#include "../../Source/Object/Player/Shot/PlayerShot/PlayerShot.h"
#include <vector>
#include <memory>
namespace obj {
	class SideOption;
	class OptionManager {
	public:
		static OptionManager Shot;
	private:
		std::shared_ptr<SideOption> m_Side_option;
		//std::vector<Minion>m_Minion;
		std::vector<PlayerShot>m_Shot;
		int ch_type;
		int m_Shot_type;
		int m_Count;
		int m_Charge_count;
		float m_Px;
		float m_Py;
	public:
		OptionManager();
		~OptionManager();
		void initialize(int max_x, int min_x);
		void pattern(int type, bool isSlow, bool is_bom);
		void update(float x, float y, bool is_shoot);
		void draw(double crush_x, double crush_y);
		void clear(bool is_all = true);
		int search();
		std::vector<PlayerShot>& getShot();
	private:
		void patternDef(bool isSlow);
		void patternOrg(bool isSlow);
		void patternA(bool isSlow);
		void patternB(bool isSlow);
		void patternC(bool isSlow);
		void patternD(bool isSlow);
		void patternE(bool isSlow);

		void homingEnemy(int id);
		void circleScramble(int id);
		void damageChanger(int id);
		void anguler(int id);
		void lazer(int id);
	};
}