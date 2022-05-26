#include "TextInputer.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/library/Graphics/String/StringDX.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"
//修正が必要な内容
//UIがないので分かりにくい。
//出来れば入力中の文字を大きく表示する。

TextInputer::TextInputer():
	m_Is_flag(false),
	m_Inputed_text(""),
	m_Input_result(0)
{

}
void TextInputer::initialize() {
	m_Input_result = KeyboardResult::INPUT_NONE;
	m_Is_flag = true;
}
void TextInputer::update() {
	if (!m_Is_flag)return;
	if (m_Input_result != KeyboardResult::INPUT_NONE) {
		m_Inputed_text = m_Text;
		m_Is_flag = false;
	}
}
void TextInputer::draw(std::string title) {
	if (!m_Is_flag)return;
	lib::Graphics2D::setBlend(lib::BLEND_MODE::ALPHA, 120);
	lib::Graphics2D::box(1920 / 2 - 610, 1440 / 2 - 310, 1920 / 2 + 610, 1440 / 2 + 110, lib::StringDX::color(20, 100, 230), true);
	lib::Graphics2D::setBlend(lib::BLEND_MODE::ALPHA, 200);
	lib::Graphics2D::box(1920 / 2 - 600, 1440 / 2 - 300, 1920 / 2 + 600, 1440 / 2 + 100, lib::StringDX::color(29, 39, 55), true);
	lib::Graphics2D::setBlend(lib::BLEND_MODE::NONE, 0);
	auto font = res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT];
	lib::StringDX::draw(
		(1920 / 2) - (lib::StringDX::getFontTextWidth(title.data(), title.length(), font) / 2),
		(1440 / 2) - 200,
		title.data(),
		lib::StringDX::color(255, 255, 255),
		font
	);
	int x = (1920 / 2) - 175;
	int y = (1440 / 2);
	lib::Graphics2D::box(x - 15, y - 15, x + 350 + 15, y + 38 + 15, lib::StringDX::color(255, 255, 255), true);
	lib::Graphics2D::box(x - 10, y - 10, x + 350 + 10, y + 38 + 10, lib::StringDX::color(0, 0, 0), true);
	m_Input_result = lib::StringDX::keyboardInput(x, y, 20, m_Text, true);
}
bool TextInputer::isFlag() {
	return m_Is_flag;
}
int TextInputer::getInputResult() {
	auto result = m_Input_result;
	m_Input_result = KeyboardResult::INPUT_NONE;
	return result;
}
char* TextInputer::getCharText() {
	return m_Text;
}
std::string TextInputer::getText() {
	m_Inputed_text = m_Text;
	return m_Inputed_text;
}