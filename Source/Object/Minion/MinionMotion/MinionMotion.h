#pragma once
namespace obj {
	class MinionMotion {
	private:
		int m_Img_state;
		float m_Img_rotation;
	public:
		MinionMotion(int minion_type, int count);
		int imgState();
		float imgRotation();
	private:
		void type1x(int num, int delay, int count);
		void type1x3(int delay, int count);
		void type1x5(int delay, int count);
		void typeRotation(int count, float speed);
	};
}