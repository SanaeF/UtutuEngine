#pragma once
#include <memory>
namespace obj {
	class Player;
	class Boss;
}
namespace app {
	class StartingCall;
	class ScoreBoard {
	private:
		enum BOARD {
			DUEL,
			SINGLE,
		};
		std::shared_ptr<StartingCall>m_StCall;
		int m_State;
		int m_Count;
		int m_Bom_type;
		int m_Bom_who;
		bool m_Is_change;
		bool m_Is_change_back;
		bool m_Is_bom_scene;
		bool m_Is_scene_out;
	public:
		ScoreBoard();
		void draw(obj::Player& player);
		void draw_single(obj::Player& player, obj::Boss& m_Boss);
		void draw_vs(obj::Player& player1, obj::Player& player2, obj::Boss& m_Boss);
		void endBom();
		void sceneIsNotOut();
		bool isBom();
		bool isSceneOut();
		int getBomWho();
		int getPlayerType();
		std::shared_ptr<StartingCall> getStartCall();
	private:
		void entity_pos();
		void changeBoard(int type);
		void drawAliceLevel();
		void drawSoundTitle();
	};

}