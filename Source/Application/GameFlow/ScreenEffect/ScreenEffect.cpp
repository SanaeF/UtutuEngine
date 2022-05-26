#include "ScreenFade.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/library/Graphics/String/StringDX.h"

namespace app {
	void ScreenEffect::setFade(int type, int time, int R, int G, int B) {
		mColor = lib::GraphicString.color(R, G, B);
		mType = type;
		mTime = time;
		mCount = 0;
		if (mType == FADE_IN)mBright = 255;
		if (mType == FADE_OUT)mBright = 0;
	}
	void ScreenEffect::draw() {
		if (mFlag) {
			drawFade();
		}
	}
	void ScreenEffect::drawFade() {
		lib::Graphics.setBlend(lib::BLEND_MODE::ALPHA, mBright);
		lib::Graphics.box(0, 0, 1920, 1440, mColor, true);
		lib::Graphics.setBlend(lib::BLEND_MODE::NONE, 0);
	}
	void ScreenEffect::update() {
		if (mFlag) {
			updateFadeIn();
			updateFadeOut();
		}
	}
	void ScreenEffect::updateFadeIn() {
		if (mType == FADE_IN) {
			mBright -= 255 / mTime;
			mCount++;
			if (mCount == mTime) {
				mFlag = false;
			}
		}
	}
	void ScreenEffect::updateFadeOut() {
		if (mType == FADE_OUT) {
			mBright += 255 / mTime;
			mCount++;
			if (mCount == mTime) {
				mFlag = false;
			}
		}
	}
}