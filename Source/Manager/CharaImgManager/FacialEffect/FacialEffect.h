#pragma once
namespace app {
	class FacialEffect {
	private:
		bool m_Is_flag;
		float m_Pos_x;
		float m_Pos_y;
		float m_Size;
		int m_Count;
		int m_Img_type;
		int m_Type;
		int m_Handle;
	public:
		void spawn(int type, float x, float y);
		void draw(float x, float y);
		void update();
		void reset();
	private:
		void accent();
		void happy();
		void sweat();
		void black();
		void angry();
	};
}