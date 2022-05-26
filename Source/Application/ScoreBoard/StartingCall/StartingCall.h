#pragma once
namespace obj {
	class Player;
}
namespace app {
	class StartingCall {
	public:
		enum {
			REVIW_SHOUT,
			START_SHOUT,
			FINISH_SHOUT,
			RESULT_SHOUT,
			SHOUTGAME_OVER,
			SHOUT_NULL = -1
		};
	private:
		int m_Count;
		int m_State;
		float m_Size_x;
		float m_Size_y;
	public:
		StartingCall();
		~StartingCall();
		void update();
		void draw(obj::Player& player1, obj::Player& player2);
		void setState(int num);
		void resetState();
		int getState();
	};
}