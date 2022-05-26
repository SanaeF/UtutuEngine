#pragma once
#include <tchar.h>
namespace lib {

	class KeyInputDX {
	public:
		static int getHitKey(char* key_state);
		static int getJoypadInput(int input_type);
	};
}

//�L�[�p�b�h�̎��
#define DX_INPUT_KEY_PAD1							(0x1001)		// �L�[���͂ƃp�b�h�P����
#define DX_INPUT_PAD1								(0x0001)		// �p�b�h�P����
#define DX_INPUT_PAD2								(0x0002)		// �p�b�h�Q����

//�L�[�̎��
#define KEY_INPUT_LSHIFT							(0x2A)			// ��Shift�L�[		D_DIK_LSHIFT
#define KEY_INPUT_RSHIFT							(0x36)			// �EShift�L�[		D_DIK_RSHIFT
#define KEY_INPUT_LCONTROL							(0x1D)			// ��Ctrl�L�[		D_DIK_LCONTROL
#define KEY_INPUT_RCONTROL							(0x9D)			// �ECtrl�L�[		D_DIK_RCONTROL
#define KEY_INPUT_ESCAPE							(0x01)			// Esc�L�[			D_DIK_ESCAPE
#define KEY_INPUT_SPACE								(0x39)			// �X�y�[�X�L�[		D_DIK_SPACE
#define KEY_INPUT_PGUP								(0xC9)			// PageUp�L�[		D_DIK_PGUP
#define KEY_INPUT_PGDN								(0xD1)			// PageDown�L�[		D_DIK_PGDN
#define KEY_INPUT_END								(0xCF)			// End�L�[			D_DIK_END
#define KEY_INPUT_HOME								(0xC7)			// Home�L�[			D_DIK_HOME
#define KEY_INPUT_LEFT								(0xCB)			// ���L�[			D_DIK_LEFT
#define KEY_INPUT_UP								(0xC8)			// ��L�[			D_DIK_UP
#define KEY_INPUT_RIGHT								(0xCD)			// �E�L�[			D_DIK_RIGHT
#define KEY_INPUT_DOWN								(0xD0)			// ���L�[			D_DIK_DOWN
#define KEY_INPUT_INSERT							(0xD2)			// Insert�L�[		D_DIK_INSERT
#define KEY_INPUT_DELETE							(0xD3)			// Delete�L�[		D_DIK_DELETE

#define KEY_INPUT_A									(0x1E)			// �`�L�[			D_DIK_A
#define KEY_INPUT_B									(0x30)			// �a�L�[			D_DIK_B
#define KEY_INPUT_C									(0x2E)			// �b�L�[			D_DIK_C
#define KEY_INPUT_D									(0x20)			// �c�L�[			D_DIK_D
#define KEY_INPUT_E									(0x12)			// �d�L�[			D_DIK_E
#define KEY_INPUT_F									(0x21)			// �e�L�[			D_DIK_F
#define KEY_INPUT_G									(0x22)			// �f�L�[			D_DIK_G
#define KEY_INPUT_H									(0x23)			// �g�L�[			D_DIK_H
#define KEY_INPUT_I									(0x17)			// �h�L�[			D_DIK_I
#define KEY_INPUT_J									(0x24)			// �i�L�[			D_DIK_J
#define KEY_INPUT_K									(0x25)			// �j�L�[			D_DIK_K
#define KEY_INPUT_L									(0x26)			// �k�L�[			D_DIK_L
#define KEY_INPUT_M									(0x32)			// �l�L�[			D_DIK_M
#define KEY_INPUT_N									(0x31)			// �m�L�[			D_DIK_N
#define KEY_INPUT_O									(0x18)			// �n�L�[			D_DIK_O
#define KEY_INPUT_P									(0x19)			// �o�L�[			D_DIK_P
#define KEY_INPUT_Q									(0x10)			// �p�L�[			D_DIK_Q
#define KEY_INPUT_R									(0x13)			// �q�L�[			D_DIK_R
#define KEY_INPUT_S									(0x1F)			// �r�L�[			D_DIK_S
#define KEY_INPUT_T									(0x14)			// �s�L�[			D_DIK_T
#define KEY_INPUT_U									(0x16)			// �t�L�[			D_DIK_U
#define KEY_INPUT_V									(0x2F)			// �u�L�[			D_DIK_V
#define KEY_INPUT_W									(0x11)			// �v�L�[			D_DIK_W
#define KEY_INPUT_X									(0x2D)			// �w�L�[			D_DIK_X
#define KEY_INPUT_Y									(0x15)			// �x�L�[			D_DIK_Y
#define KEY_INPUT_Z									(0x2C)			// �y�L�[			D_DIK_Z

#define KEY_INPUT_0 								(0x0B)			// �O�L�[			D_DIK_0
#define KEY_INPUT_1									(0x02)			// �P�L�[			D_DIK_1
#define KEY_INPUT_2									(0x03)			// �Q�L�[			D_DIK_2
#define KEY_INPUT_3									(0x04)			// �R�L�[			D_DIK_3
#define KEY_INPUT_4									(0x05)			// �S�L�[			D_DIK_4
#define KEY_INPUT_5									(0x06)			// �T�L�[			D_DIK_5
#define KEY_INPUT_6									(0x07)			// �U�L�[			D_DIK_6
#define KEY_INPUT_7									(0x08)			// �V�L�[			D_DIK_7
#define KEY_INPUT_8									(0x09)			// �W�L�[			D_DIK_8
#define KEY_INPUT_9									(0x0A)			// �X�L�[			D_DIK_9