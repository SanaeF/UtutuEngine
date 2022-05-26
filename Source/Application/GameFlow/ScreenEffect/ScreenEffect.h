namespace app {
	class ScreenEffect {
	private:
		bool mFlag;
		int mType;
		int mColor;
		int mBright;
		int mTime;
		int mCount;
	public:
		enum {
			FADE_IN,
			FADE_OUT
		};
		void setFade(int type, int time, int R, int G, int B);
		void update();
		void draw();
	private:
		void updateFadeIn();
		void updateFadeOut();
		void drawFade();
	};
}