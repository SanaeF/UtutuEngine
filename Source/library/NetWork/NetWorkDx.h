#pragma once
#include <tchar.h>

namespace lib {
	class NetWorkDx {
	private:
	public:
		struct InputIPData {
			unsigned char ip1, ip2, ip3, ip4;
		};
		static int connect(InputIPData ip, int port);
		static int close(int handle);
		static int loadData(int handle, void* buffer, int length);
		static int uploadData(int handle, void* buffer, int length);
		static int stop();

		static int setPort(int port);
		static int getConnecterIP(int handle);
		static int getLost();
		static int getNewAccept();

		NetWorkDx();
		~NetWorkDx();
	};
}