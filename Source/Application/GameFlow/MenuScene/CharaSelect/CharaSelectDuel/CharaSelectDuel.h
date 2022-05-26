#pragma once
#include "../../Source/Application/GameFlow/Scene/Scene.h"
namespace app {
	class CharaSelectDuel :public Scene {
	private:
		enum {
			CHARA_NUM = 7
		};
		enum {
			SELECT_CHARA,
			START_SELECT
		};
		int m_Select_sound;
		int m_Sound_type;
		int m_Map_type;
		int m_Stage_type;
		int m_Chara_type[2];
		int m_Select[2];
		int m_State;
		bool m_Is_select[2];
		bool m_Key_lock;
		bool m_Is_host;
		bool m_Is_start;
	public:
		void setServerDataHost(int charaK, int select_num);
		void setServerDataConnect(int charaK, int select_num, int sound, int stage, bool start);
		int update();
		void draw();
		int getCharaType1();
		int getCharaType2();
		int getMapType();
		int getSoundType();
		int getSelectInput(int num);
		void setState(bool flag);
		bool isStart();
	private:
		void initialize();
		void drawSelectChara();
		void drawDuelConf();
		void charaSelect();
		void startSelect();
		
		void select(int key_kind);
		void cancel();
	};
}