#pragma once
namespace app {
	class SubTitle {
	private:
		bool m_Is_flag;
		int m_Stage_num;
		int m_Count;
		int m_bright;
	public:
		SubTitle();
		~SubTitle();
		void start(int stage);
		void draw();
		void update();
	private:
		void titleText();
		void drawText(int x1, const char* title, int x2, const char* stage_name);
	};
}