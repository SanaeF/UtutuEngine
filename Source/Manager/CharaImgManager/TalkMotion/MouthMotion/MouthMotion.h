#pragma once
#include "../../Source/Manager/CharaImgManager/TalkMotion/TalkMotion.h"

namespace app {
	class MouthMotion {
	private:
		TalkMotion mouth;
		int m_State;
	public:
		void update();
		void setState(int state);
		int getImgState();
	private:
		void close();//����
		void saying();//���J��
		void original();//����
	};
}