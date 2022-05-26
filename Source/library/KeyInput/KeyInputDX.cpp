#include "KeyInputDX.h"
#include "DxLib.h"

namespace lib {
	int KeyInputDX::getHitKey(
		char* key_state
	) {
		return GetHitKeyStateAll(key_state);
	}
	int KeyInputDX::getJoypadInput(
		int input_type
	) {
		return GetJoypadInputState(input_type);
	}
}