#pragma once
#include "../../Source/Manager/CharaImgManager/TalkMotion/TalkMotion.h"

namespace app {
	//���уA�j���[�V����
	class EyeBrowMotion {
	private:
		TalkMotion eye_brow;
		int m_State;
	public:
		void update();
		void setState(int state);
		int getImgState();
	private:
		void normal();//�ʏ�
		void sad();//����
		void angly();//�L���b
		void original();//����
	};
}