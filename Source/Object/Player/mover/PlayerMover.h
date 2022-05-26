#pragma once
namespace obj {
	class PlayerMover {
	private:
		struct MovedPos {
			double x;
			double y;
		};
		MovedPos m_Pos;
		int m_Max_x;
		int m_Min_x;
		int m_Pad_type;
		int m_Count;
		int m_Image_state;
		bool m_Is_slow;
		bool m_Is_bom;
	public:
		void initialize(int max_x, int min_x);
		MovedPos inputPos(int type, double x, double y);
		void setKeyPad(int type);
		void setBomFlag(bool flag);
		void setImageState(int img);
		void setSlow(bool flag);
		int getImageState();
		bool isDamageMove();
		bool isSlow();
	private:
		void movePattern(
			float speed,
			float speed_slowing,
			float speed_bom,
			float speed_bom_slowing
		);
		int getKey(int num);
	};
}