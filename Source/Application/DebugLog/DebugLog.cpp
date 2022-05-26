#include "DebugLog.h"
#include <iostream>
#include "../../Source/library/Graphics/String/StringDX.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"
#pragma warning(disable : 4996)
namespace app {
	void DebugLog::draw(int count) {
		char text[128];
		sprintf(text, "stage_count: %d", count);
		lib::StringDX::draw(
			800, 10,
			text,
			lib::StringDX::color(255, 255, 255),
			res::TextUIImage::text_ui.font[res::FONT::FONT_SB_SOUND]
		);
	}
}