#include "Mask.h"
#include "DxLib.h"
namespace lib {
	int Mask::load(const TCHAR* file) {
		return LoadMask(file);
	}
	void Mask::drawFill(int x1, int y1, int x2, int y2, int handle) {
		DrawFillMask(x1, y1,x2, y2, handle);
	}
	void Mask::createScreen() {
		CreateMaskScreen();
	}
	void Mask::deleteScreen() {
		DeleteMaskScreen();
	}
}