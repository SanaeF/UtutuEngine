#include "NetWorkDx.h"

#include "DxLib.h"

namespace lib {
	IPDATA Ip;
	int NetWorkDx::connect(InputIPData data,int port) {
		Ip.d1 = data.ip1;
		Ip.d2 = data.ip2;
		Ip.d3 = data.ip3;
		Ip.d4 = data.ip4;
		return ConnectNetWork(Ip, port);
	}
	int NetWorkDx::close(int handle) {
		return CloseNetWork(handle);
	}
	int NetWorkDx::setPort(int port) {
		return PreparationListenNetWork(port);
	}
	int NetWorkDx::getConnecterIP(int handle) {
		return GetNetWorkIP(handle, &Ip);
	}
	int NetWorkDx::getLost() {
		return GetLostNetWork();
	}
	int NetWorkDx::getNewAccept() {
		int result = GetNewAcceptNetWork();
		//printfDx("%d", result);
		if (result != -1) {
			//printfDx("\n%d", result);
		}
		return result;
	}
	int NetWorkDx::loadData(int handle,void *buffer,int length) {
		return NetWorkRecv(handle, buffer, length);
	}
	int NetWorkDx::uploadData(int handle, void* buffer, int length) {
		return NetWorkSend(handle, buffer, length);
	}
	int NetWorkDx::stop() {
		return StopListenNetWork();
	}
	NetWorkDx::NetWorkDx() {
	}
	NetWorkDx::~NetWorkDx() {
	}
}