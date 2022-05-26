#include "Object.h"

namespace obj {
	Object::Object() {
		obj_flag = false;
		x = false;
		y = false;
		z = false;
		size = false;
		type = false;
		count = false;
		state[0] = false;
		state[1] = false;
	}
	void Object::valueReset(bool DeathFlag) {
		obj_flag = false;
		x = false;
		y = false;
		z = false;
		size = false;
		type = false;
		count = false;
		state[0] = false;
		state[1] = false;
		if (DeathFlag) {
			state[0] = -1;
			state[1] = -1;
		}
		else rayer = 0;
	}
	void Object::countUpdate() {
		this->count++;
	}
	void Object::setFlag(bool flag) {
		this->obj_flag = flag;
	}
	void Object::setX(double x) {
		this->x = x;
	}
	void Object::setY(double y) {
		this->y = y;
	}
	void Object::setZ(double z) {
		this->z = z;
	}
	void Object::setSize(double size) {
		this->size = size;
	}
	void Object::setType(int type) {
		this->type = type;
	}
	void Object::setState(int state1) {
		this->state[0] = state1;
	}
	void Object::setStateSub(int state2) {
		this->state[1] = state2;
	}
	void Object::setCount(int count) {
		this->count = count;
	}
	void Object::setRayer(int num) {
		this->rayer = num;
	}
	bool Object::isFlag() {
		return this->obj_flag;
	}
	double Object::getX() {
		return this->x;
	}
	double Object::getY() {
		return this->y;
	}
	double Object::getZ() {
		return this->z;
	}
	double Object::getSize() {
		if (this->size < 0)this->size = 0;
		return this->size;
	}
	int Object::getType() {
		if (this->type < 0)this->type = 0;
		return this->type;
	}
	int Object::getState() {
		return this->state[0];
	}
	int Object::getStateSub() {
		return this->state[1];
	}
	int Object::getCount() {
		return this->count;
	}
	int Object::getRayer() {
		return this->rayer;
	}
	std::shared_ptr<app::Shake>& Object::getShake() {
		return m_Shake;
	}
}