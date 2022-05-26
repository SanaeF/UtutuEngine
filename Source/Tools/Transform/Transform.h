#pragma once
class Transform {
private:
	struct Position {
		float x;
		float y;
		float z;
		void set(float x, float y, float z = 0.f) {
			this->x = x;
			this->y = y;
			this->z = z;
		}
	};
	Position pos;
	Position mFirst;
	Position mInit_vel;
	Position mAcceleration;
	int move_time;
	int m_Count;

	bool move_flag;
	bool right;
	bool left;
public:
	void resetParam();
	void setTrans(double obj_x, double obj_y, float target_x, float target_y, int count);
	void update();
	void randMove(float obj_x, float obj_y, float x1, float y1, float x2, float y2, float dist, int t);
	bool isMove();
	bool isRight();
	bool isLeft();
	Position getMoved();
};