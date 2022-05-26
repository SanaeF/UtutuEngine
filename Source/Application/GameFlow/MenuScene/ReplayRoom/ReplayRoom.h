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
		bool m_Is_wrote;//�����o�����I��������Ƀt���O������
	public:
		ReplayRoom();
		~ReplayRoom();

		int update()override;
		void draw()override;
		void select()override;
		void cancel()override;

		//���v���C���[�h�̐ݒ�(�Đ����������݂�)
		void setState(int state);

		int getState();
	private:
		void importTitleList();
		void exportTitleList();
	};
}