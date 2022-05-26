#pragma once
#include "../../Source/Application/GameFlow/Scene/Scene.h"
#include <memory>

namespace app {
	enum GAME_MODE {
		NO_MODE,
		STORY,
		SINGLE,
		DOUBLES,
	};
	class StoryMode;
	//class SingleMode;
	//class DuelMode;
	class EndingTalk;
	class EndingScene;
	class GameScene : public Scene {
	private:
		std::shared_ptr<StoryMode> m_Story;
		//std::shared_ptr<SingleMode> m_Single;
		//std::shared_ptr<DuelMode> m_Duel;
		std::shared_ptr<EndingTalk>m_ED_talk;
		std::shared_ptr<EndingScene>m_Ending;
		SelectYN m_Select_YN;
		enum GAME_STATE {
			INITIALIZE,
			LOOP,
			STAGE_END,
			END_SCENE,
			ENDING,
			SAVE_REPLAY_MENU,
			CHECK_SAVE_REPLAY
		};
		int m_State;
		int m_Game_type;
		int m_Player_type;
		int m_Sound_type;
		int m_Bullet_type;
		int m_Count;
		int m_Pause_state;
		bool m_Is_no_pause;
		bool m_Is_host;
	public:
		int update();
		void draw();
		void setGameType(GAME_MODE type);
		//一人用の自機の種類
		void setPlayerType(int type);
		//二人対戦用の自機の種類
		void setPlayerType(int type, int type2);
		void setSoundType(int type);
		void setBulletType(int type);
		void setLockPose(bool flag, bool isHost);
		GameScene();
		~GameScene();
	private:
		//ゲームステータスが初期化される
		void sharedReset();
		void stageEnd();
		//ポーズ画面によるシーンの移行を行う
		void pauseState();
		void finalize();
	};
}