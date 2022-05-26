#pragma once
namespace obj {
	class BossMotion {
	private:
		int m_Img_state;
		float m_Img_rotation;
	public:
		BossMotion(int boss_type, int motion_type, float angle, int count);
		int imgState();
		float imgRotation();
	private:
		void bossType0(int motion_type, int count);
		void bossType1(int motion_type, int count);
		void bossType2(int motion_type, int count);
		void bossType3(int motion_type, int count);
		void bossType4(int motion_type, int count);
		void bossType5(int motion_type, int count);
		void bossTypeAlice(int motion_type, int count);
		void bossTypeEx(int motion_type, int count);
	};
}