#pragma once
namespace app {
	class EndingScene{
	private:
		//std::shared_ptr<ScreenFade>mFade;
		enum MOVE_STATE{
			NONE,
			INITIALIZE,
			DRAW,
		};
		MOVE_STATE m_State;
		int m_Handle;
		bool m_Is_ending;
		bool m_Is_movie;
		bool m_Is_end;
	public:
		EndingScene();
		~EndingScene();
		void setEnding();
		void update();
		void draw();
		//�G���f�B���O���I����Ă��邩�ǂ���
		bool isEnded();
	private:
		void drawMovie();
		bool isState(MOVE_STATE state);
	};
}