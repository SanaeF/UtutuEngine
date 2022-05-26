#pragma once
namespace app {
	class ScreenFade {
	public:
		static ScreenFade BackDirect;
		static ScreenFade Direct;
		static ScreenFade Screen;
	private:
		bool m_Flag;
		bool m_Bright_flag;
		int mType;
		int m_Fade_type;
		int mColor;
		int m_Time;
		int m_Count;
		float m_Max_bright;
		float mBright;
	public:
		enum {
			FADE_IN,
			FADE_OUT,
		};
		void reset();
		void setFade(int type, int time, int R = 0, int G = 0, int B = 0);
		void setFadeBright(int type, int time, int max_bright);
		void setBright(bool flag, int bright = 0);
		void update();
		void draw();
		bool isRun();
		bool isEnd(int type);
	private:
		void updateFadeIn();
		void updateFadeOut();
		void drawFade();
	};
}