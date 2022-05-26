#include "StringDX.h"
#include <memory>
#include "DxLib.h"
#include "../../FileManager/FileManager.h"
namespace std {
	enum class byte : unsigned char {};
}
namespace lib {
	int StringDX::loadFont(const TCHAR* FileAdress) {
		// もし非同期読み込み状態なら無効にする
		int async_flag = GetUseASyncLoadFlag();
		if (async_flag) SetUseASyncLoadFlag(FALSE);
		int FontFileSize = FileRead_size(FileAdress);
		// フォントファイルを開く
		int FontFileHandle = FileRead_open(FileAdress);
		void* Buffer = new void* [FontFileSize];
		FileRead_read(Buffer, FontFileSize, FontFileHandle);

		// AddFontMemResourceEx引数用
		DWORD font_num = 0;

		// メモリに読み込んだフォントデータをシステムに追加
		if (AddFontMemResourceEx(Buffer, FontFileSize, NULL, &font_num) == 0){
			return 0;
		}

		FileRead_close(FontFileHandle);
		delete[] Buffer;
		if (async_flag) SetUseASyncLoadFlag(TRUE);
		return 0;
	}
	void StringDX::draw(
		int x,
		int y,
		const TCHAR* String,
		int Color,
		int Font,
		unsigned int EdgeColor,
		int VerticalFlag
	) {
		DrawStringToHandle(x, y, String, Color, Font, EdgeColor, VerticalFlag);
	}

	void StringDX::drawFormat(
		int x,
		int y,
		int Color,
		const TCHAR* FormatString
	) {
		DrawFormatString(x, y, Color, FormatString);
	}

	int StringDX::keyboardInput(
		int x, 
		int y,
		int CharMaxLength, 
		char* StrBuffer,
		int CancelValidFlag
	) {
		return KeyInputString(x, y, CharMaxLength, StrBuffer, CancelValidFlag);
	}

	int StringDX::createFont(
		const TCHAR* Font,
		int Size,
		int Thick,
		int CharSet,
		int EdgeSize,
		int Italic,
		int Handle
	) {
		return CreateFontToHandle(Font, Size, Thick, DX_FONTTYPE_ANTIALIASING_EDGE, CharSet, EdgeSize, Italic, Handle);
	}
	int StringDX::getTextWidth(const TCHAR* text) {
		return GetDrawStringWidth(text, -1);
	}
	int StringDX::getFontTextWidth(const TCHAR* String, int StrLen, int FontHandle) {
		return GetDrawStringWidthToHandle(String, StrLen, FontHandle);
	}
	int StringDX::setFontSize(int size) {
		return SetFontSize(size);
	}

	int StringDX::color(
		int Red,
		int Green,
		int Blue
	) {
		return GetColor(Red, Green, Blue);
	}
}