#pragma once
#include <memory>

namespace script {
	class TimeLineScript;
}
namespace app {
	class Camp;
	class TimeLine {
	public:
		enum {
			STORY,
			SINGLE,
			DOUBLES
		};
	private:
		std::shared_ptr<script::TimeLineScript> m_Script;
		std::shared_ptr<Camp>m_Camp;
		int m_State;
		bool m_Flag;
	public:
		TimeLine();
		~TimeLine();
		void initialize();
		void update(int count, int map_count = 0);
		void draw(double crush_x = 0.f, double crush_y = 0.f);
		void setFlag(bool flag);
		void setCampLock(bool flag);
		int getBossType();
		int getBulletNum();
		int getTalkID();
		bool isTalkScene();
		bool isSubTitle();
		bool isInterSummon();
		bool isRood();
		bool isEndingPhase();
	private:
	};
}