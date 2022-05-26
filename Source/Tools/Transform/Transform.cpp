#include "Transform.h"
#include <iostream>
#include "../../Source/Helper/Helper.h"
#include "../../Source/Object/Object/Object.h"

void Transform::resetParam() {
	m_Count = 0;
	move_time = 0;
	right = false;
	left = false;
	move_flag = false;
	mFirst.set(0, 0);
	mInit_vel.set(0, 0);
	mAcceleration.set(0, 0);
}
void Transform::setTrans(double obj_x, double obj_y, float target_x, float target_y, int count) {
	//if (move_flag || count <= 0)return;
	if ((target_x - obj_x) < 0) {
		right = false;
		left = true;
	}
	else {
		right = true;
		left = false;
	}
	move_flag = true;
	m_Count = 0;
	move_time = count;
	float ymax_x = obj_x - target_x;
	float ymax_y = obj_y - target_y;
	mFirst.set(obj_x, obj_y);
	mInit_vel.set(2 * ymax_x / count, 2 * ymax_y / count);
	mAcceleration.set(2 * ymax_x / (count * count), 2 * ymax_y / (count * count));
}
void Transform::update() {
	if (!move_flag)return;
	pos.x = mFirst.x - ((mInit_vel.x * m_Count) - 0.5f * mAcceleration.x * m_Count * m_Count);
	pos.y = mFirst.y - ((mInit_vel.y * m_Count) - 0.5f * mAcceleration.y * m_Count * m_Count);
	m_Count++;
	if (m_Count >= move_time) {
		resetParam();
	}
}
void Transform::randMove(float obj_x, float obj_y, float x1, float y1, float x2, float y2, float dist, int t) {
	double x = obj_x;
	double y = obj_y;
	double m_Angle = GET_SEED_RANDOM_F(PI);
	x += cos(m_Angle) * dist;//‚»‚¿‚ç‚ÉˆÚ“®‚³‚¹‚é
	y += sin(m_Angle) * dist;
	if (x1 <= x && x <= x2 && y1 <= y && y <= y2) {//‚»‚Ì“_‚ªˆÚ“®‰Â”\”ÍˆÍ‚È‚ç
		setTrans(obj_x, obj_y, x, y, t);
	}
}
bool Transform::isMove() {
	return move_flag;
}
bool Transform::isRight() {
	return right;
}
bool Transform::isLeft() {
	return left;
}
Transform::Position 
Transform::getMoved() {
	return pos;
}