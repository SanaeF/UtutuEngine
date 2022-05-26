#include "SelectYN.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/library/Graphics/String/StringDX.h"
#include "../../Source/Application/Key/Key.h"
#include "../../Source/Application/Sound/Sound.h"
#include "../../Source/Resource/SoundData/SoundData.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"
//修正が必要な内容
//選択肢の文字数に応じて中心からの距離とボックスの横幅を自動で調整させる。
namespace app {
	SelectYN::SelectYN():
		m_Is_flag(false),
		m_Num(0),
		m_State(SELECT_LR::NONE_STATE)
	{

	}
	void SelectYN::initialize(SELECT_LR state) {
		m_Is_flag = true;
		m_State = state;
		setVertical(state);
		if (m_State == SELECT_LR::LEFT_STATE)m_Num = 0;
		if (m_State == SELECT_LR::RIGHT_STATE)m_Num = 1;
	}
	void SelectYN::selectReset() {
		m_Is_flag = false;
		m_Num = 0;
		m_State = SELECT_LR::NONE_STATE;
	}
	int SelectYN::update() {
		if (!m_Is_flag)return 0;
		if (sceneCoolDown(10)) {
			right(2);
			left(2);
			m_Num = getVertical();
			select();
			cancel();
			if (m_State != SELECT_LR::NONE_STATE) {
				if (m_Num == 0)m_State = SELECT_LR::LEFT_STATE;
				else m_State = SELECT_LR::RIGHT_STATE;
			}
		}
		return 0;
	}
	void SelectYN::draw(std::string text, int color, std::string left, std::string right) {
		if (!m_Is_flag)return;
		auto font = res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT];
		int text_add_size1 = lib::StringDX::getFontTextWidth(left.data(), left.length(), font);
		int text_add_size2 = lib::StringDX::getFontTextWidth(right.data(), right.length(), font);
		int most_size = 0;
		if (text_add_size1 > text_add_size2)most_size = text_add_size1;
		else most_size = text_add_size2;
		lib::Graphics2D::setBlend(lib::BLEND_MODE::ALPHA, 120);
		lib::Graphics2D::box(1920 / 2 - 210 - 150 - (most_size / 2), 1440 / 2 - 210, 1920 / 2 + 210 + 150 + (most_size / 2), 1440 / 2 + 210, lib::StringDX::color(20, 100, 230), true);
		lib::Graphics2D::setBlend(lib::BLEND_MODE::ALPHA, 200);
		lib::Graphics2D::box(1920 / 2 - 200 - 150 - (most_size / 2), 1440 / 2 - 200, 1920 / 2 + 200 + 150 + (most_size / 2), 1440 / 2 + 200, lib::StringDX::color(29, 39, 55), true);
		lib::Graphics2D::setBlend(lib::BLEND_MODE::NONE, 0);
		int color_ny[2] = { 0,0 };
		if (m_State == SELECT_LR::LEFT_STATE) {
			color_ny[0] = lib::StringDX::color(255, 255, 255);
			color_ny[1] = lib::StringDX::color(133, 133, 133);
		}
		if (m_State == SELECT_LR::RIGHT_STATE) {
			color_ny[0] = lib::StringDX::color(133, 133, 133);
			color_ny[1] = lib::StringDX::color(255, 255, 255);
		}
		//タイトル
		lib::StringDX::draw(
			(1920 / 2) - (lib::StringDX::getFontTextWidth(text.data(), text.length(), font) / 2),
			(1440 / 2) - 100,
			text.data(),
			color,
			font
		);
		//左
		lib::StringDX::draw(
			(1920 / 2) - text_add_size1-100,
			(1440 / 2) + 60,
			left.data(),
			color_ny[0],
			font
		);
		//右
		lib::StringDX::draw(
			(1920 / 2) + 100,
			(1440 / 2) + 60,
			right.data(),
			color_ny[1],
			font
		);
	}
	void SelectYN::select() {
		if (Key::Pad.checkInput(Key::KEY_TYPE::SHOT) == 1) {
			Sound::sound.playSE(res::SE::SELECT_OK);
			resetCoolDown();
			m_Is_flag = false;
		}
	}
	void SelectYN::cancel() {
		if (Key::Pad.checkInput(Key::KEY_TYPE::BOM) == 1 || Key::Pad.checkInput(Key::KEY_TYPE::MENU) == 1) {
			Sound::sound.playSE(res::SE::SELECT_CANCEL);
			resetCoolDown();
			m_State = SELECT_LR::NONE_STATE;
			m_Is_flag = false;
		}

	}
	bool SelectYN::isFlag() {
		return m_Is_flag;
	}
	int SelectYN::getState() {
		return m_State;
	}
}