#pragma once
#include <tchar.h>
#include <memory>

namespace app {
	class FrameManager;
	class SaveDataManager;
	class SceneManager;
	//�Q�[���A�v���P�[�V����
	class Application {
	private:
		const char* mFrame_text = "�������� ";

		enum STATE {
			LOADING,
			MAINLOOP
		};
		int m_Screen_type;
		int m_State;
		bool m_Use_multiplay;
		std::shared_ptr<FrameManager> m_FPS;
		std::shared_ptr<SaveDataManager>m_Save;
		std::shared_ptr<SceneManager> m_Scene;
	public:
		//�A�v���P�[�V�����̏�����
		void initialize();
		//���s
		void run();
		//���C�u�����̏�����
		int libInit();
		//�A�[�J�C�u�g���q�̐ݒ�
		void customArchive();
		//���͑҂��̎擾
		int waitKey();
		//���C�u�����̏C������
		void libEnd();
		Application();
		~Application();
	private:
		bool processLoop();
		void windowProp();
		//�K�v�Œ���̃��\�[�X���[�h
		void loading();
		//�S�Ă̍X�V����
		void update();
	};
}