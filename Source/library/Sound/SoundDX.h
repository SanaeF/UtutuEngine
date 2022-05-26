#pragma once
#include <tchar.h>

namespace lib {
	enum SOUND_TYPE {
		NORMAL,
		BACK,
		LOOP,
	};
	class SoundDX {
	public:
		static int check(int Handle);

		static void play(int Handle,int PlayType,int Flag = 1);

		static void stop(int Handle);

		static void changeVolume(int Volume, int Handle);

		static void setLoopPos(int LoopTime,int Handle);

		static void setSoundPosition(int hz_count, int Handle);

		static int getSoundPosition(int Handle);

		static void drawCount(int Handle);

		static int load(const TCHAR* FileAdress);

		static void clear(int Handle);

		static void initialize();
	};
}