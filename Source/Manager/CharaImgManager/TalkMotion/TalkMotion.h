#pragma once
namespace app {
	enum EYE_STATE {
		NONE, BLINK, CLOSING, SMILE, ORIGINAL
	};
	enum BROW_STATE {
		BROW_NORMAL, BROW_SAD, BROW_ANGLY, BROW_ORIGINAL
	};
	enum MOUTH_STATE {
		MOUTH_CLOSE, MOUTH_SAY, MOUTH_ORIGINAL
	};
	class TalkMotion {
	public:
		float x;
		float y;
		double m_Angle;
		double size;
		int animation_state;
		int random_state;
		int state;
		int count;
	};
}