#include "MinionManager.h"
#include "../../Source/Object/Minion/Minion.h"

namespace manager {
	MinionManager MinionManager::m_Instance;
	MinionManager::MinionManager() {
		m_Minion_obj.resize(obj::MINION_NUM_MAX);
	}
	MinionManager* MinionManager::getInstance() {
		return &m_Instance;
	}
	void MinionManager::initialize() {
		for (auto& minion : m_Minion_obj)minion.valueReset();
	}
	void MinionManager::update() {
		for (auto& minion : m_Minion_obj)minion.update();
	}
	void MinionManager::draw(double crush_x, double crush_y) {
		for (auto& minion : m_Minion_obj)minion.draw(crush_x, crush_y);
	}
	void MinionManager::clear(bool flag) {
		for (auto& minion : m_Minion_obj)minion.kill(flag);
	}
	std::vector<obj::Minion>& MinionManager::getMinion() {
		return m_Minion_obj;
	}
}