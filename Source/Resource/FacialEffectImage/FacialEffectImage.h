#pragma once
namespace res {
	//�����G�ɕt����\��G�t�F�N�g
	enum FACIAL_EFFECT_TYPE {
		ACCENT, HAPPY, SWEAT, BLACK, ANGRY, STOP
	};
	class FacialEffectImage{
	private:
	public:
		int accent[2];//�C���t�������̔���
		int happy[2];//�E�L�E�L���Ă�Ƃ�
		int sweat;
		int black;//�Â��\��̎�
		int angry;//�{��}�[�N
		static void load();
		static FacialEffectImage facial_eff;
	};
}