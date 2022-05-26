#pragma once
#include <tchar.h>

namespace lib {
	class StringDX {
	public:

		static int loadFont(const TCHAR* FileAdress);

		static void draw(
			int x,
			int y,
			const TCHAR* String,
			int Color,
			int Font,
			unsigned int EdgeColor = 0U,
			int VerticalFlag = 0
		);

		static void drawFormat(
			int x,
			int y,
			int Color,
			const TCHAR* FormatString
		);

		static int createFont(
			const TCHAR* Font,
			int Size,
			int Thick,
			int CharSet = -1,
			int EdgeSize = -1,
			int Italic = 0,
			int Handle = -1
		);

		static int keyboardInput(
			int x,
			int y,
			int CharMaxLength,
			char* StrBuffer,
			int CancelValidFlag
		);

		static int getTextWidth(const TCHAR* text);

		static int getFontTextWidth(const TCHAR* String, int StrLen, int FontHandle);

		static int setFontSize(int size);

		static int color(int Red, int Green, int Blue);

	};
}
