#include "ScreenFade.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/library/Graphics/String/StringDX.h"

namespace app {
	ScreenFade ScreenFade::BackDirect;
	ScreenFade ScreenFade::Direct;
	ScreenFade ScreenFade::Screen;
	void ScreenFade::reset() {
		m_Flag = false;
		m_Bright_flag = false;
		mType = 0;
		m_Fade_type = 0;
		int mColor = 0;
		int m_Time = 0;
		int m_Count = 0;
		m_Max_bright = 0;
		mBright = 0.f;
	}
	void ScreenFade::setFade(int type, int time, int R, int G, int B) {
		if (m_Flag)return;
		m_Fade_type = 0;
		mColor = lib::StringDX::color(R, G, B);
		mType = type;
		m_Time = time;
		m_Count = 0;
		m_Flag = true;
		m_Bright_flag = true;
		if (mType == FADE_IN)mBright = 255.f;
		if (mType == FADE_OUT)mBright = 0.f;
	}
	void ScreenFade::setFadeBright(int type, int time, int max_bright) {
		if (m_Flag)return;
		mColor = lib::StringDX::color(0, 0, 0);
		m_Fade_type = 1;
		mType = type;
		m_Time = time;
		m_Count = 0;
		m_Flag = true;
		m_Bright_flag = true;
		m_Max_bright = max_bright;
		if (mType == FADE_IN)mBright = 0.f;
		if (mType == FADE_OUT)mBright = max_bright;
	}
	void ScreenFade::setBright(bool flag, int bright) {
		mBright = bright;
		m_Bright_flag = flag;
	}
	void ScreenFade::draw() {
		if (m_Bright_flag) {
			drawFade();
		}
	}
	void ScreenFade::drawFade() {
		lib::Graphics2D::setBlend(lib::BLEND_MODE::ALPHA, mBright);
		lib::Graphics2D::box(0, 0, 1920, 1440, mColor, true);
		lib::Graphics2D::setBlend(lib::BLEND_MODE::NONE, 0);
	}
	void ScreenFade::update() {
		if (m_Flag) {
			updateFadeIn();
			updateFadeOut();
		}
	}
	void ScreenFade::updateFadeIn() {
		if (mType == FADE_IN) {
			if (m_Fade_type == 0)mBright -= 255.f / m_Time;
			if (m_Fade_type == 1)mBright += m_Max_bright / m_Time;
			m_Count++;
			if (m_Count == m_Time) {
				m_Bright_flag = false;
				m_Flag = false;
			}
		}
	}
	void ScreenFade::updateFadeOut() {
		if (mType == FADE_OUT) {
			if (m_Fade_type == 0)mBright += 255.f / m_Time;
			if (m_Fade_type == 1)mBright -= (m_Max_bright / m_Time);
			m_Count++;
			if (m_Count == m_Time) {
				m_Bright_flag = false;
				m_Flag = false;
			}
		}
	}
	bool ScreenFade::isRun() {
		return m_Flag;
	}
	bool ScreenFade::isEnd(int type) {
		bool result = false;
		if (type == mType) {
			if (m_Count == m_Time) {
				result = true;
			}
		}
		return result;
	}
}