#include "World.h"
#include <iostream>

namespace localmap {
	void World::setWorldState(int state) {
		this->m_State = state;
	}
	bool World::isNotFree() {
		if (m_State == TYPE::AUTO)return true;
		if (m_State == TYPE::BOSS)return true;
		return false;
	}
}