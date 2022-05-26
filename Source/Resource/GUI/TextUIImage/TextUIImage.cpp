#include "TextUIImage.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/library/Graphics/String/StringDX.h"
namespace res {
	TextUIImage TextUIImage::text_ui;
	void TextUIImage::load() {
		lib::Graphics2D::loadSplit("./dat/image/GUI/Text/OriginalNumber.png", 10, 10, 1, 40, 45, text_ui.number[0]);
		lib::Graphics2D::loadSplit("./dat/image/GUI/Text/DigitalNumber.png", 16, 16, 1, 48, 36, text_ui.number[1]);
		lib::StringDX::loadFont("./dat/image/Font/rounded-mplus-2c-regular.ttf");//ç◊Çﬂ
		lib::StringDX::loadFont("./dat/image/Font/rounded-mplus-2c-medium.ttf");//ïÅí 
		lib::StringDX::loadFont("./dat/image/Font/rounded-l-mplus-2c-black.ttf");//ã…ëæÅAä€çTÇ¶Çﬂ
		lib::StringDX::loadFont("./dat/image/Font/rounded-l-mplus-2c-bold.ttf");//ã…ëæÅAä€çTÇ¶Çﬂ
		lib::StringDX::loadFont("./dat/image/Font/rounded-l-mplus-2m-bold.ttf");//ëæÇﬂÅAä€çTÇ¶ÇﬂÅAâpêîéöïùÇ¬Çﬂ
		text_ui.font[FONT::FONT_MINI_LORE] = lib::StringDX::createFont("Rounded M+ 2c medium", 27, 7);
		text_ui.font[FONT::FONT_SELECT] = lib::StringDX::createFont("Rounded M+ 2c medium", 50, 10);
		text_ui.font[FONT::FONT_TITLE_NEWS] = lib::StringDX::createFont("Rounded-L M+ 2m bold", 25, 7);
		text_ui.font[FONT::FONT_LORE] = lib::StringDX::createFont("Rounded M+ 2c medium", 28, 14);
		text_ui.font[FONT::FONT_SB_SOUND] = lib::StringDX::createFont("Rounded M+ 2c medium", 25, 7);
		text_ui.font[FONT::FONT_SB_BOUNS_SCORE] = lib::StringDX::createFont("Rounded-L M+ 2m bold", 25, 7);
		text_ui.font[FONT::FONT_SB_BOUNS_CALL] = lib::StringDX::createFont("Rounded-L M+ 2c black", 100, 40);
		text_ui.font[FONT::FONT_SB_ROULETTE] = lib::StringDX::createFont("Rounded M+ 2c medium", 50, 10);
		text_ui.font[FONT::FONT_SERIF] = lib::StringDX::createFont("Rounded M+ 2c regular", 50, 10);
		text_ui.font[FONT::FONT_SERIF_BULLET] = lib::StringDX::createFont("Rounded M+ 2c regular", 25, 14);

		text_ui.fight_massage[START_CALL_TEXT] = lib::Graphics2D::load("./dat/image/GUI/Text/FightGame/StartCall.png");
		text_ui.fight_massage[START_TEXT] = lib::Graphics2D::load("./dat/image/GUI/Text/FightGame/Start.png");
		text_ui.fight_massage[FINISH_TEXT] = lib::Graphics2D::load("./dat/image/GUI/Text/FightGame/Finish.png");
		text_ui.fight_massage[WIN_TEXT] = lib::Graphics2D::load("./dat/image/GUI/Text/FightGame/Win.png");
		text_ui.fight_massage[LOSE_TEXT] = lib::Graphics2D::load("./dat/image/GUI/Text/FightGame/Lose.png");
	}
}