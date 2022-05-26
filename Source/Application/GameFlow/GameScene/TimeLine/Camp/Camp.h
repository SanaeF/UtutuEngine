#pragma once
namespace app {
	class Camp {
	private:
		bool m_Is_lock;
		bool m_Is_saving;
		int m_Count;
	public:
		void update(int time, int map_time);
		void draw();
		void setIsLock(bool flag);
	private:
		void output(int time, int map_time);
		void campGetterKey();
	};
}