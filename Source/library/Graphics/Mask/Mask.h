#pragma once
#include <tchar.h>
namespace lib {
	class Mask {
	public:
		static int load(const TCHAR* file);
		static void drawFill(int x1, int y1, int x2, int y2, int handle);
		static void createScreen();
		static void deleteScreen();
	};
}