#pragma once
namespace app {
	class Scene {
	public:
		struct MenuText {
			int x, y;
			char name[128];
		};
	private:
		int m_Select_vertical;
		int m_Select_horizontal;
		int m_Select_verticals[2];
		int m_Select_horizontals[2];
		const int m_Cool_down = 6;
		int m_Scene_state;
		int m_Time;
		bool m_Key_lock;
		bool m_Is_host;
	public:
		void setKeyLock(bool isHost);
		void up(int max);
		void down(int max);
		void right(int max);
		void left(int max);
		void up(int Key_num, int max);
		void down(int Key_num, int max);
		void right(int Key_num, int max);
		void left(int Key_num, int max);
		virtual void select();
		virtual void cancel();
		virtual void escape();
		virtual int update();
		virtual void draw();

		bool sceneCoolDown(int time);
		void resetCoolDown();
		void setVertical(int num);
		void setVertical(int num, int key_kind);
		void setHorizontal(int num);
		void setHorizontal(int num, int key_kind);
		void setSceneState(int state);
		int getVertical();
		int getHorizontal();
		int getVertical(int key_kind);
		int getHorizontal(int key_kind);
		int getSceneState();
		bool isRight();
		bool isLeft();
		Scene();
		virtual ~Scene() = default;
	};
}
#include "SelectYN/SelectYN.h"