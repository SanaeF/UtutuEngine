#include "GameMassage.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/library/Graphics/String/StringDX.h"
#include "../../Source/Application/Key/Key.h"
#include "../../Source/Application/Sound/Sound.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"
#include "../../Source/Resource/GUI/MenuUIImage/MenuUIImage.h"
#include "../../Source/Resource/SoundData/SoundData.h"
namespace app {
	GameMassage::GameMassage() :
		m_State(0),
		m_Is_not_end(false),
		m_Flag(false)
	{
		m_Massage.resize(10);
	}
	void GameMassage::draw() {
		if (m_Massage.size() <= m_State)return;
		if (!m_Massage[m_State].flag)return;
		int alpha_time = 25;
		if(m_Massage[m_State].count<25)lib::Graphics2D::setBlend(lib::BLEND_MODE::ALPHA, (255 / alpha_time) * m_Massage[m_State].count);
		else if (m_Massage[m_State].count > m_Massage[m_State].time - 25)
			lib::Graphics2D::setBlend(
				lib::BLEND_MODE::ALPHA, 
				255 - (255 / alpha_time) * (m_Massage[m_State].count-(m_Massage[m_State].time - 25))
			);
		else lib::Graphics2D::setBlend(lib::BLEND_MODE::NONE,0);
		lib::Graphics2D::draw(0, 0, res::MenuUIImage::menu_ui.achieve, true);
		lib::StringDX::draw(
			300,
			700,
			m_Massage[m_State].text.data(),
			lib::StringDX::color(255, 255, 255),
			res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]
		);
		lib::Graphics2D::setBlend(lib::BLEND_MODE::NONE, 0);
	}
	void GameMassage::update() {
		int flag_count = 0;
		for (int ite = 0; ite < m_Massage.size(); ite++) {
			if (!m_Massage[m_State].flag)flag_count++;
		}
		if(flag_count>= m_Massage.size())m_Is_not_end = false;
		if (m_Massage.size() <= m_State)return;
		if (!m_Massage[m_State].flag)return;
		if (m_Massage[m_State].count == m_Massage[m_State].time) {
			m_Massage[m_State].flag = false;
			m_State++;
		}
		m_Massage[m_State].count++;
	}
	void GameMassage::setText(std::string text, int time) {
		Sound::sound.playSE(res::SE::BOMGET);
		for (int ite = 0; ite < m_Massage.size(); ite++) {
			if (!m_Massage[ite].flag) {
				m_Massage[ite].flag = true;
				m_Massage[ite].text = text;
				m_Massage[ite].time = time;
				m_Massage[ite].count = 0;
				break;
			}
		}
		m_Is_not_end = true;
		m_Flag = true;
	}
	bool GameMassage::isNotEndFlag() {
		return m_Is_not_end;
	}
	bool GameMassage::isFlag() {
		return m_Flag;
	}
}