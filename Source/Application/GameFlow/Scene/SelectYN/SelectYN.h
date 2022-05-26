#pragma once
#include "../Scene.h"
#include <string>
namespace app {
	//<Yes/No>�̑I�����N���X
	enum SELECT_LR {
		LEFT_STATE,
		RIGHT_STATE,
		NONE_STATE
	};
	class SelectYN : Scene {
	private:
		bool m_Is_flag;//�I�����̕\���t���O
		int m_State;//�I����
		int m_Num;//�L�[�ɂ��I��ԍ�
	public:
		SelectYN();
		//�����̑I���ʒu���w�肵�đI������\��
		void initialize(SELECT_LR state);
		void selectReset();
		int update();

		//�I�����̕\��(1:�^�C�g��,2:�^�C�g���̐F,3:���̕���,4:�E�̕���)
		void draw(std::string text, int color, std::string left, std::string right);

		void select()override;
		void cancel()override;

		//�I������\�����Ă��邩�ǂ������擾
		bool isFlag();

		//�I�����̌��ʂ��擾
		int getState();
	};
}