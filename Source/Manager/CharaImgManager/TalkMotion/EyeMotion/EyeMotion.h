#pragma once
#include "../../Source/Manager/CharaImgManager/TalkMotion/TalkMotion.h"

namespace app {
	//目のアニメーション
	class EyeMotion {
	private:
		TalkMotion eye;
		int m_State;
	public:
		void update();
		void setState(int state);
		int getImgState();
	private:
		void normal();//通常
		void blink();//まばたき
		void closing();//閉じ
		void smile();//にっこり
		void original();//特殊
	};
}