#pragma once
#include <memory>


namespace script {
	class TalkScript;
}
namespace app {
	class ScreenFade;
	class TalkSceneManager {
	private:
		enum {
			eTk_FALSE,
			eTk_TRUE
		};
		enum {
			MSG_BOX_POS_NULL,
			MSG_BOX_POS_1 = 282,
			MSG_BOX_POS_2 = -282
		};
		enum {
			MSG_R,
			MSG_L
		};
		std::shared_ptr<script::TalkScript>m_Script;
		std::shared_ptr<ScreenFade>m_saveFade[2];
		int m_Count;
		int m_Wait_count;
		bool m_Is_serif_scene;
		bool m_Is_scene_end;
	public:
		TalkSceneManager();
		~TalkSceneManager();
		void initialize();
		void startEnding();
		void start(int id);
		void draw();
		void update();
		int calledBossType();
		int bulletNum();
		bool isSummonBoss();
		bool isSummonInterBoss();
		bool isTalkState();
		bool isJoinBullet();
		bool isSceneEnd();
		bool isGoEnding();
	private:
		int nextScene();
	};
}