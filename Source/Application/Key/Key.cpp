#include "Key.h"
#include <iostream>
#include "../../Source/library/KeyInput/KeyInputDX.h"

namespace app {
	Key Key::Pad;
	Key Key::MultPad[2];
	void Key::initialize(int type)
	{
		//キーコンフィグのデフォルト値を設定
		for (int num = 0; num < KEY_TYPE::PAD_KEY_MAX; num++)setKeyCounter(num, 0);
		setKeyConfig(type, 2, 1, 3, 0, 7, 6, 11, 10, 13);
	}
	void Key::setKeyConfig(
		int type,
		int down,
		int left,
		int right,
		int up,
		int shot,
		int bom,
		int change,
		int shift,
		int menu
	) {
		PAD_TYPE = type;
		m_Key[KEY_TYPE::RIGHT] = right;
		m_Key[KEY_TYPE::LEFT] = left;
		m_Key[KEY_TYPE::DOWN] = down;
		m_Key[KEY_TYPE::UP] = up;
		m_Key[KEY_TYPE::SHOT] = shot;
		m_Key[KEY_TYPE::BOM] = bom;
		m_Key[KEY_TYPE::CHANGE] = change;
		m_Key[KEY_TYPE::SHIFT] = shift;
		m_Key[KEY_TYPE::MENU] = menu;
	}
	int Key::stateUpdate() {
		char key_state[256];
		lib::KeyInputDX::getHitKey(key_state);
		for (int i = 0; i < 256; i++) {
			if (key_state[i] == 1)m_State_key[i]++;
			else m_State_key[i] = 0;
		}
		return 0;
	}
	void Key::keyPadUpdate() {
		int mul[3] = { 1,1 ,1 }, pad_input;
		if (PAD_TYPE == PAD_TYPE::PLAYER_01)pad_input = lib::KeyInputDX::getJoypadInput(DX_INPUT_PAD1);
		if (PAD_TYPE == PAD_TYPE::PLAYER_02)pad_input = lib::KeyInputDX::getJoypadInput(DX_INPUT_PAD2);
		for (int i = 0; i < KEY_TYPE::PAD_KEY_MAX; i++) {
			if (pad_input & mul[0])m_Key_count[i]++;
			else m_Key_count[i] = 0;
			mul[0] *= 2;
		}
		for(int ite = 0;ite< KEY_TYPE::KEY_MAX;ite++)if(m_Key[ite] > KEY_TYPE::PAD_KEY_MAX)return;

		if (PAD_TYPE == PAD_TYPE::PLAYER_01) {
			inputPadAndKey(&m_Key_count[m_Key[KEY_TYPE::LEFT]], checkState(KEY_INPUT_LEFT));
			inputPadAndKey(&m_Key_count[m_Key[KEY_TYPE::UP]], checkState(KEY_INPUT_UP));
			inputPadAndKey(&m_Key_count[m_Key[KEY_TYPE::RIGHT]], checkState(KEY_INPUT_RIGHT));
			inputPadAndKey(&m_Key_count[m_Key[KEY_TYPE::DOWN]], checkState(KEY_INPUT_DOWN));
			inputPadAndKey(&m_Key_count[m_Key[KEY_TYPE::SHOT]], checkState(KEY_INPUT_Z));
			inputPadAndKey(&m_Key_count[m_Key[KEY_TYPE::BOM]], checkState(KEY_INPUT_X));
			inputPadAndKey(&m_Key_count[m_Key[KEY_TYPE::CHANGE]], checkState(KEY_INPUT_C));
			inputPadAndKey(&m_Key_count[m_Key[KEY_TYPE::SHIFT]], checkState(KEY_INPUT_LSHIFT));
			inputPadAndKey(&m_Key_count[m_Key[KEY_TYPE::MENU]], checkState(KEY_INPUT_ESCAPE));
		}
		if (PAD_TYPE == PAD_TYPE::PLAYER_02) {
			inputPadAndKey(&m_Key_count[m_Key[KEY_TYPE::LEFT]], checkState(KEY_INPUT_A));
			inputPadAndKey(&m_Key_count[m_Key[KEY_TYPE::UP]], checkState(KEY_INPUT_W));
			inputPadAndKey(&m_Key_count[m_Key[KEY_TYPE::RIGHT]], checkState(KEY_INPUT_D));
			inputPadAndKey(&m_Key_count[m_Key[KEY_TYPE::DOWN]], checkState(KEY_INPUT_S));
			inputPadAndKey(&m_Key_count[m_Key[KEY_TYPE::SHOT]], checkState(KEY_INPUT_I));
			inputPadAndKey(&m_Key_count[m_Key[KEY_TYPE::BOM]], checkState(KEY_INPUT_O));
			inputPadAndKey(&m_Key_count[m_Key[KEY_TYPE::CHANGE]], checkState(KEY_INPUT_P));
			inputPadAndKey(&m_Key_count[m_Key[KEY_TYPE::SHIFT]], checkState(KEY_INPUT_SPACE));
			inputPadAndKey(&m_Key_count[m_Key[KEY_TYPE::MENU]], checkState(KEY_INPUT_ESCAPE));
		}
	}
	int Key::checkInput(int num) {
		if (0 <= num && num < 16) {
			int val = m_Key[num];
			if (val > 16)return 0;
			return m_Key_count[val];
		}
		else {
			std::cout << "Key Over\n" << std::endl;
			return -1;
		}
	}
	int Key::checkInputedKey() {
		for (int key_num = 0; key_num < 16; key_num++) {
			if (m_Key_count[key_num] == 1)return key_num;
		}
		return -1;
	}
	int Key::checkState(unsigned char num) {
		return m_State_key[num];
	}
	void Key::inputPadAndKey(int* p, int k) {
		*p = *p > k ? *p : k;
	}
	void Key::setKeyCounter(int n, int value) {
		m_Key_count[n] = value;
	}
	void Key::setKey(int num, int key) {
		m_Key[num] = key;
	}
	int Key::getPadType() {
		return PAD_TYPE;
	}
	int Key::getKey(int num) {
		return m_Key[num];
	}
	bool Key::debugKey() {
		if (checkState(KEY_INPUT_D) != 0 && checkState(KEY_INPUT_B) != 0)return true;
		return false;
	}
	Key KeyPad;
	Key MultKeyPad[2];
}