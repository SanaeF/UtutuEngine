#pragma once
#include "../../Source/Manager/CharaImgManager/TalkMotion/TalkMotion.h"

namespace app {
	//�ڂ̃A�j���[�V����
	class EyeMotion {
	private:
		TalkMotion eye;
		int m_State;
	public:
		void update();
		void setState(int state);
		int getImgState();
	private:
		void normal();//�ʏ�
		void blink();//�܂΂���
		void closing();//��
		void smile();//�ɂ�����
		void original();//����
	};
}