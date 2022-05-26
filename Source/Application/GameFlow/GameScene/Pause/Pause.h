#pragma once
#include "../../Source/Application/GameFlow/Scene/Scene.h"

namespace app {
	class Pause : public Scene {
	public:
		enum PauseMenu {
			PUT_START,
			STAGE_CLEAR,
			NO_LIFE,
			GAME_OVER,
			REPLAY,
			REPLAY_END,
		};
		enum PauseState{
			NONE,
			UN_PAUSE,
			RETRY,
			GAME_END,
			NEXT_STAGE,
			SELECT_CHARA,
			CAMP,
			SET_SAVE_REPLAY_MODE,
			SET_REPLAY_ROOM
		};
	private:
		typedef struct {
			int x, y;
			char menu[128];
		} GameMenu_t;
		bool m_Scene_flag;
		bool m_Is_Camp_setted;
		int m_Count;
		int m_State;
		int m_Stage;
		int m_Menu_Num;
		int m_Type;
	public:
		void initialize();
		int update()override;
		void draw()override;
		void select()override;
		void cancel()override;
		void setScene(int type);
		void setCamp(int flag);
		void checkPauseMode();
		void setFlag(bool flag);
		int getState();
		bool isFlag();
		bool isState(PauseState state);
		static Pause Menu;
	private:
		void finalize();
	};
}