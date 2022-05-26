#include "BulletManager.h"
#include "../../Source/Object/Bullet/Shot/Shot_Info.h"
#include "../../Source/Object/Bullet/Lazer/Lazer_Info.h"
#include "../../Source/Object/Bullet/TurnLazer/TurnLazer_Info.h"

namespace obj {
	BulletManager BulletManager::m_Bullet_obj;
	BulletManager::BulletManager() {
		m_Shot.resize(obj::BULLET_NUM_MAX);
		m_Laser.resize(obj::LAZER_NUM_MAX);
		m_TurnLaser.resize(obj::T_LAZ_NUM_MAX);
		for (auto& bullet : m_Shot)bullet.ObjClear();
		for (auto& bullet : m_Laser)bullet.ObjClear();
		for (auto& bullet : m_TurnLaser)bullet.ObjClear();
	}
	BulletManager* BulletManager::getInstance() {
		return &m_Bullet_obj;
	}
	void BulletManager::initialize() {
		for (auto& bullet : m_Shot)bullet.ObjClear();
		for (auto& bullet : m_Laser)bullet.ObjClear();
		for (auto& bullet : m_TurnLaser)bullet.ObjClear();
	}
	void BulletManager::update() {
		for (auto& bullet : m_Shot)bullet.update();
		for (auto& bullet : m_Laser)bullet.update();
		for (auto& bullet : m_TurnLaser)bullet.update();
	}
	void BulletManager::draw(double crush_x, double crush_y) {
		for (auto& bullet : m_Shot)bullet.draw(crush_x, crush_y);
		for (auto& bullet : m_Laser)bullet.draw(crush_x, crush_y);
		for (auto& bullet : m_TurnLaser)bullet.drawBack(crush_x, crush_y);
		for (auto& bullet : m_TurnLaser)bullet.draw(crush_x, crush_y);
	}
	void BulletManager::stop() {
		for (auto bullet : m_TurnLaser)bullet.pause(true);
	}
	void BulletManager::clear(bool flag) {
		for (auto& bullet : m_Shot)bullet.clear(flag);
		for (auto& bullet : m_Laser)bullet.clear(flag);
		for (auto& bullet : m_TurnLaser)bullet.clear(flag);
	}
	void BulletManager::setShotLoopMax(int max) {
		m_Shot_loop_max = max;
	}
	void BulletManager::setLaserLoopMax(int max) {
		m_Laser_loop_max = max;
	}
	void BulletManager::setTurnLaserLoopMax(int max) {
		m_TurnLaser_loop_max = max;
	}
	std::vector<Shot_Info>& BulletManager::getShot() {
		return m_Shot;
	}
	std::vector<Lazer_Info>& BulletManager::getLaser() {
		return m_Laser;
	}
	std::vector<TurnLazer_Info>& BulletManager::getTurnLaser() {
		return m_TurnLaser;
	}
}