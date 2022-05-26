#pragma once
#include <tchar.h>

namespace lib {
	class MovieDx {
	public:
		static int load(const TCHAR* FileAdress);
		static int setVolume(int volume, int handle);
		static int play(int handle);
		static void draw(
			int x,
			int y,

			int Handle,
			int TransFlag
		);
		static int getState(int handle);
		static int clear(
			int GrHandle,
			int LogOutFlag = 0
		);
	};
}