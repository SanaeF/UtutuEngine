#pragma once
#include "../../Source/Application/GameFlow/Scene/Scene.h"
#include "../../Source/Tools/TextInput/TextInputer.h"
namespace app {
	enum REPLAY_ROOM {
		READ_STATE,
		WRITE_STATE
	};
	class ReplayRoom :public Scene {
	private:
		struct TitleList {
			char title[21];
			int diff;
			int score;
			int year;
			int month;
			int day;
		};
		TitleList m_TitleList[20];
		SelectYN m_Select_YN;
		TextInputer m_TextInputer;
		int m_Select_num;
		int m_State;
		bool m_Is_wrote;//書き出しが終わった時にフラグが立つ
	public:
		ReplayRoom();
		~ReplayRoom();

		int update()override;
		void draw()override;
		void select()override;
		void cancel()override;

		//リプレイモードの設定(再生か書き込みか)
		void setState(int state);

		int getState();
	private:
		void importTitleList();
		void exportTitleList();
	};
}