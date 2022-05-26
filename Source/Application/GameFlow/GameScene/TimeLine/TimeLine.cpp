#include "TimeLine.h"
#include <iostream>
#include "Camp/Camp.h"
#include "../../Source/Script/TimeLineScript/TimeLineScript.h"
#include "../../Source/SystemProp/GameSceneProp/GameSceneProp.h"
#pragma warning(disable : 4996)
namespace app {
	TimeLine::TimeLine() :
		m_Flag(false)
	{
		m_Script.reset(new script::TimeLineScript());
		m_Camp.reset(new Camp());
	}
	void TimeLine::initialize() {
		if (GameSceneProp::stage < 0)return;
		char* fp = new char[38];
		sprintf(fp, "./dat/Script/TimeLine/Stage%d.lua", GameSceneProp::stage);
		m_Script->initialize(fp);
		delete[] fp;
		m_Flag = true;
	}
	void TimeLine::update(int count, int map_count) {
		if (!m_Flag)return;
		m_Script->update(count);
		m_Camp->update(count, map_count);
	}
	void TimeLine::setFlag(bool flag) {
		m_Flag = flag;
	}
	void TimeLine::draw(double crush_x, double crush_y) {
		if (!m_Flag)return;
		m_Camp->draw();
	}
	void TimeLine::setCampLock(bool flag) {
		m_Camp->setIsLock(flag);
	}
	int TimeLine::getBossType() {
		return m_Script->pInterBoss()->boss_type;
	}
	int TimeLine::getBulletNum() {
		return m_Script->pInterBoss()->bullet_num;
	}
	int TimeLine::getTalkID() {
		return m_Script->getTalkID();
	}
	bool TimeLine::isTalkScene() {
		auto result = m_Script->isTalkScene();
		m_Script->setTalkScene(false);
		return result;
	}
	bool TimeLine::isSubTitle() {
		auto result = m_Script->isSubTitle();
		m_Script->setSubTitle(false);
		return result;
	}
	bool TimeLine::isInterSummon() {
		auto result = m_Script->pInterBoss()->is_summon;
		m_Script->pInterBoss()->is_summon = false;
		return result;
	}
	bool TimeLine::isRood() {
		return m_Script->isRoad();
	}
	bool TimeLine::isEndingPhase() {
		return m_Script->isEndingPhase();
	}
	TimeLine::~TimeLine() {
	}
}