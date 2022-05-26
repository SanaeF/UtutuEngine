#include "StartingCall.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"
#include "../../Source/SystemProp/AreaProp.h"
#include "../../Source/Object/Player/Player.h"

namespace app {
	StartingCall::StartingCall() {
		m_Count = 0;
		m_State = 0;
		m_Size_x = 0.f;
		m_Size_y = 0.f;
	}
	void StartingCall::draw(obj::Player& player1, obj::Player& player2) {
		const float PosX0 = 512.f;
		const float PosY0 = 520.5f;
		if (m_State == REVIW_SHOUT) {
			lib::Graphics2D::drawModi(
				PosX0 + 448.f - m_Size_x, PosY0 + 199.5f - m_Size_y,
				1920.f - 448.f - PosX0 + m_Size_x, PosY0 + 199.5f - m_Size_y,
				1920.f - 448.f - PosX0 + m_Size_x, 1440.f - 199.5f - PosY0 + m_Size_y,
				PosX0 + 448.f - m_Size_x, 1440.f - 199.5f - PosY0 + m_Size_y,
				res::TextUIImage::text_ui.fight_massage[res::START_CALL_TEXT],
				true
			);
		}
		if (m_State == START_SHOUT) {
			lib::Graphics2D::drawModi(
				PosX0 + 448.f - m_Size_x, PosY0 + 199.5f - m_Size_y,
				1920.f - 448.f - PosX0 + m_Size_x, PosY0 + 199.5f - m_Size_y,
				1920.f - 448.f - PosX0 + m_Size_x, 1440.f - 199.5f - PosY0 + m_Size_y,
				PosX0 + 448.f - m_Size_x, 1440.f - 199.5f - PosY0 + m_Size_y,
				res::TextUIImage::text_ui.fight_massage[res::START_TEXT],
				true
			);
		}

		if (m_State == FINISH_SHOUT) {
			lib::Graphics2D::drawModi(
				PosX0 + 448.f - m_Size_x, PosY0 + 199.5f - m_Size_y,
				1920.f - 448.f - PosX0 + m_Size_x, PosY0 + 199.5f - m_Size_y,
				1920.f - 448.f - PosX0 + m_Size_x, 1440.f - 199.5f - PosY0 + m_Size_y,
				PosX0 + 448.f - m_Size_x, 1440.f - 199.5f - PosY0 + m_Size_y,
				res::TextUIImage::text_ui.fight_massage[res::FINISH_TEXT],
				true
			);
		}
		int addX[2] = { 0,0 };
		if (m_State == RESULT_SHOUT) {
			if (player1.getItemStack().life < 0) {
				addX[0] = P1_MIN_X;
				addX[1] = P2_MIN_X;
			}
			if (player2.getItemStack().life < 0) {
				addX[1] = P1_MIN_X;
				addX[0] = P2_MIN_X;
			}
			lib::Graphics2D::draw(addX[1], 0, res::TextUIImage::text_ui.fight_massage[res::WIN_TEXT], true);
			lib::Graphics2D::draw(addX[0], 0, res::TextUIImage::text_ui.fight_massage[res::LOSE_TEXT], true);
		}
	}
	void StartingCall::update() {
		const int firstTime = 50;
		const int endTime = 150;
		const int longer = 15;

		if (m_State == REVIW_SHOUT) {
			if (firstTime <= m_Count && m_Count < firstTime + longer) {
				m_Size_x += 448.f / longer;
				m_Size_y += 199.5f / longer;
			}

			if (endTime <= m_Count && m_Count < endTime + longer) {
				m_Size_y -= 199.5f / longer;
			}
			if (m_Count >= endTime + longer) {
				m_State = START_SHOUT;
				m_Count = 0;
			}

		}

		if (m_State == START_SHOUT) {
			if (firstTime - 20 <= m_Count && m_Count < firstTime - 20 + longer) {
				m_Size_x = 448.f;
				m_Size_y += 199.5f / longer;
			}

			if (endTime <= m_Count && m_Count < endTime + longer) {
				m_Size_x += (448.f / longer) / 2;
				m_Size_y -= 199.5f / longer;
			}
			if (m_Count >= endTime + longer) {
				m_State = SHOUT_NULL;
				m_Count = 0;
			}
		}
		if (m_State == FINISH_SHOUT) {
			if (firstTime - 20 <= m_Count && m_Count < firstTime - 20 + longer) {
				m_Size_x = 448.f;
				m_Size_y += 199.5f / longer;
			}

			if (endTime <= m_Count && m_Count < endTime + longer) {
				m_Size_x += (448.f / longer) / 2;
				m_Size_y -= 199.5f / longer;
			}
			if (m_Count >= endTime + longer) {
				m_State = RESULT_SHOUT;
				m_Count = 0;
			}
		}
		if (m_State == RESULT_SHOUT) {
			if (m_Count > 200)m_State = SHOUTGAME_OVER;
		}

		if (m_State != SHOUT_NULL)m_Count++;

	}
	void StartingCall::resetState() {
		m_Count = 0;
		m_State = 0;
		m_Size_x = 0.f;
		m_Size_y = 0.f;
	}
	void StartingCall::setState(int num) {
		m_State = num;
	}
	int StartingCall::getState() {
		return m_State;
	}
	StartingCall::~StartingCall() {
	}
}