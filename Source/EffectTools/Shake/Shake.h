#pragma once
namespace app {
	class Shake {
	private:
		bool m_Flag;
		float m_Px;
		float m_Py;
		int m_Count;
		int m_Time;
		int m_Size;
	public:
		void update();
		void set(int size, int time);
		double get_x();
		double get_y();
		static Shake crush;
	};
}