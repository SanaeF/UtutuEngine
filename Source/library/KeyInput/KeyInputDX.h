#pragma once
#include <tchar.h>
namespace lib {

	class KeyInputDX {
	public:
		static int getHitKey(char* key_state);
		static int getJoypadInput(int input_type);
	};
}

//キーパッドの種類
#define DX_INPUT_KEY_PAD1							(0x1001)		// キー入力とパッド１入力
#define DX_INPUT_PAD1								(0x0001)		// パッド１入力
#define DX_INPUT_PAD2								(0x0002)		// パッド２入力

//キーの種類
#define KEY_INPUT_LSHIFT							(0x2A)			// 左Shiftキー		D_DIK_LSHIFT
#define KEY_INPUT_RSHIFT							(0x36)			// 右Shiftキー		D_DIK_RSHIFT
#define KEY_INPUT_LCONTROL							(0x1D)			// 左Ctrlキー		D_DIK_LCONTROL
#define KEY_INPUT_RCONTROL							(0x9D)			// 右Ctrlキー		D_DIK_RCONTROL
#define KEY_INPUT_ESCAPE							(0x01)			// Escキー			D_DIK_ESCAPE
#define KEY_INPUT_SPACE								(0x39)			// スペースキー		D_DIK_SPACE
#define KEY_INPUT_PGUP								(0xC9)			// PageUpキー		D_DIK_PGUP
#define KEY_INPUT_PGDN								(0xD1)			// PageDownキー		D_DIK_PGDN
#define KEY_INPUT_END								(0xCF)			// Endキー			D_DIK_END
#define KEY_INPUT_HOME								(0xC7)			// Homeキー			D_DIK_HOME
#define KEY_INPUT_LEFT								(0xCB)			// 左キー			D_DIK_LEFT
#define KEY_INPUT_UP								(0xC8)			// 上キー			D_DIK_UP
#define KEY_INPUT_RIGHT								(0xCD)			// 右キー			D_DIK_RIGHT
#define KEY_INPUT_DOWN								(0xD0)			// 下キー			D_DIK_DOWN
#define KEY_INPUT_INSERT							(0xD2)			// Insertキー		D_DIK_INSERT
#define KEY_INPUT_DELETE							(0xD3)			// Deleteキー		D_DIK_DELETE

#define KEY_INPUT_A									(0x1E)			// Ａキー			D_DIK_A
#define KEY_INPUT_B									(0x30)			// Ｂキー			D_DIK_B
#define KEY_INPUT_C									(0x2E)			// Ｃキー			D_DIK_C
#define KEY_INPUT_D									(0x20)			// Ｄキー			D_DIK_D
#define KEY_INPUT_E									(0x12)			// Ｅキー			D_DIK_E
#define KEY_INPUT_F									(0x21)			// Ｆキー			D_DIK_F
#define KEY_INPUT_G									(0x22)			// Ｇキー			D_DIK_G
#define KEY_INPUT_H									(0x23)			// Ｈキー			D_DIK_H
#define KEY_INPUT_I									(0x17)			// Ｉキー			D_DIK_I
#define KEY_INPUT_J									(0x24)			// Ｊキー			D_DIK_J
#define KEY_INPUT_K									(0x25)			// Ｋキー			D_DIK_K
#define KEY_INPUT_L									(0x26)			// Ｌキー			D_DIK_L
#define KEY_INPUT_M									(0x32)			// Ｍキー			D_DIK_M
#define KEY_INPUT_N									(0x31)			// Ｎキー			D_DIK_N
#define KEY_INPUT_O									(0x18)			// Ｏキー			D_DIK_O
#define KEY_INPUT_P									(0x19)			// Ｐキー			D_DIK_P
#define KEY_INPUT_Q									(0x10)			// Ｑキー			D_DIK_Q
#define KEY_INPUT_R									(0x13)			// Ｒキー			D_DIK_R
#define KEY_INPUT_S									(0x1F)			// Ｓキー			D_DIK_S
#define KEY_INPUT_T									(0x14)			// Ｔキー			D_DIK_T
#define KEY_INPUT_U									(0x16)			// Ｕキー			D_DIK_U
#define KEY_INPUT_V									(0x2F)			// Ｖキー			D_DIK_V
#define KEY_INPUT_W									(0x11)			// Ｗキー			D_DIK_W
#define KEY_INPUT_X									(0x2D)			// Ｘキー			D_DIK_X
#define KEY_INPUT_Y									(0x15)			// Ｙキー			D_DIK_Y
#define KEY_INPUT_Z									(0x2C)			// Ｚキー			D_DIK_Z

#define KEY_INPUT_0 								(0x0B)			// ０キー			D_DIK_0
#define KEY_INPUT_1									(0x02)			// １キー			D_DIK_1
#define KEY_INPUT_2									(0x03)			// ２キー			D_DIK_2
#define KEY_INPUT_3									(0x04)			// ３キー			D_DIK_3
#define KEY_INPUT_4									(0x05)			// ４キー			D_DIK_4
#define KEY_INPUT_5									(0x06)			// ５キー			D_DIK_5
#define KEY_INPUT_6									(0x07)			// ６キー			D_DIK_6
#define KEY_INPUT_7									(0x08)			// ７キー			D_DIK_7
#define KEY_INPUT_8									(0x09)			// ８キー			D_DIK_8
#define KEY_INPUT_9									(0x0A)			// ９キー			D_DIK_9