#pragma once
#include "../../Source/Manager/CharaImgManager/TalkMotion/TalkMotion.h"

namespace app {
	//眉毛アニメーション
	class EyeBrowMotion {
	private:
		TalkMotion eye_brow;
		int m_State;
	public:
		void update();
		void setState(int state);
		int getImgState();
	private:
		void normal();//通常
		void sad();//困り
		void angly();//キリッ
		void original();//特殊
	};
}