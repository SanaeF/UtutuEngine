#include "DuelServer.h"
#include <iostream>
#include <cassert>
#include "../../Source/Application/GameFlow/MenuScene/Online/OnlineRoom.h"
#include "../../Source/library/NetWork/NetWorkDx.h"
#include "../../Source/Object/Player/Player.h"

namespace app {
	DuelServer::DuelServer() :
		m_Handle(-1) 
	{

	}
	void DuelServer::clearValue() {
		memset(&m_Out_data, 0, sizeof(NetData));
		memset(&m_In_data, 0, sizeof(NetData));
		m_Handle = -1;
		for (int i = 0; i < 4; i++)m_IP[i] = 0;
		m_Port = 0;
		m_Is_connect = false;
	}
	void DuelServer::initHost(int port) {
		int portID = port;
		lib::NetWorkDx::setPort(portID);
	}
	void DuelServer::initConnect(int ip1, int ip2, int ip3, int ip4, int port) {
		lib::NetWorkDx::InputIPData ip;
		ip.ip1 = ip1;
		ip.ip2 = ip2;
		ip.ip3 = ip3;
		ip.ip4 = ip4;
		int portID = port;
		m_Handle = lib::NetWorkDx::connect(ip, portID);
		if (m_Handle != -1)m_Is_connect = true;
	}
	void DuelServer::update() {
		if (m_Handle == -1)m_Handle = lib::NetWorkDx::getNewAccept();
		if (m_Handle != -1)
		{
			if (isState(TYPE::Host)) {
				m_Is_connect = true;
				//assert(0);
				lib::NetWorkDx::stop();
				lib::NetWorkDx::getConnecterIP(m_Handle);
			}
			sendData();
			loadData();
			if (isState(TYPE::Host)) {
				if (m_Handle == lib::NetWorkDx::getLost())m_State = TYPE::DISCONNECCT;
			}
		}
	}
	void DuelServer::finalize() {
		//lib::Server.close(mHandle);
	}
	void DuelServer::sendData() {
		int who = 0;
		if (isState(TYPE::Host))who = 0;
		if (isState(TYPE::Connecter))who = 1;
		m_Out_data.PlayerData.x = obj::Player::PlayersObj[who].getX();
		m_Out_data.PlayerData.y = obj::Player::PlayersObj[who].getY();
		m_Out_data.PlayerData.bom_num = obj::Player::PlayersObj[who].getItemStack().bom;
		m_Out_data.PlayerData.life_num = obj::Player::PlayersObj[who].getItemStack().life;
		m_Out_data.PlayerData.m_Is_bom = obj::Player::PlayersObj[who].isBom();
		m_Out_data.PlayerData.knd = obj::Player::PlayersObj[who].getType();
		m_Out_data.PlayerData.m_Slow = obj::Player::PlayersObj[who].isSlow();
		m_Out_data.PlayerData.img = obj::Player::PlayersObj[who].getImgState();
		m_Out_data.PlayerData.state = obj::Player::PlayersObj[who].getState();
		for (int i = 0; i < 3; i++) {
			m_Out_data.PlayerData.shot_bullet[i] = obj::Player::PlayersObj[who].getKeyInputData(i);
		}
		lib::NetWorkDx::uploadData(m_Handle, &m_Out_data, sizeof(NetData));
	}
	void DuelServer::loadData() {
		int who = 0;
		if (isState(TYPE::Host))who = 1;
		if (isState(TYPE::Connecter))who = 0;
		lib::NetWorkDx::loadData(m_Handle, &m_In_data, sizeof(NetData));
		obj::Player::PlayersObj[who].setServerInputData(
			m_In_data.PlayerData.state,
			m_In_data.PlayerData.m_Is_bom,
			m_In_data.PlayerData.life_num,
			m_In_data.PlayerData.bom_num,
			m_In_data.PlayerData.img,
			m_In_data.PlayerData.m_Slow,
			m_In_data.PlayerData.knd,
			m_In_data.PlayerData.shot_bullet,
			m_In_data.PlayerData.x,
			m_In_data.PlayerData.y
		);
	}
	void DuelServer::inputParam(int select, int chara, int sound, int stage, bool start) {
		m_Out_data.select_num = select;
		m_Out_data.charaK = chara;
		m_Out_data.sound = sound;
		m_Out_data.stage = stage;
		m_Out_data.start = start;
	}
	void DuelServer::setState(int state) {
		m_State = state;
	}
	void DuelServer::callDisconnect() {
		//if (mHandle != -1)lib::Server.close(mHandle);
	}
	bool DuelServer::getConnecting() {
		return m_Is_connect;
	}
	bool DuelServer::isState(int state) {
		if (m_State == state)return true;
		return false;
	}
	int DuelServer::getState() {
		return m_State;
	}
	DuelServer::NetData& DuelServer::getServerData() {
		return m_In_data;
	}

	DuelServer::~DuelServer() {
		lib::NetWorkDx::close(m_Handle);
	}
}