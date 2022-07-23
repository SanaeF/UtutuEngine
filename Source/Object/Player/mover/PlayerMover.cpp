#include "PlayerMover.h"
#include <iostream>
#include "../../Source/SystemProp/AreaProp.h"
#include "../../Source/Application/Key/Key.h"
#include "../../Source/Application/Replayer/Replayer.h"
#include "../../Source/Resource/PlayerImage/PlayerImage.h"

namespace obj {
	void PlayerMover::initialize(int max_x, int min_x) {
		this->m_Max_x = max_x;
		this->m_Min_x = min_x;
		m_Count = 0;
	}
	PlayerMover::MovedPos 
	PlayerMover::inputPos(int type, double x, double y) {
		m_Pos.x = x;
		m_Pos.y = y;
		switch (type) {
		case res::PLAYER_TYPE::EREMIRA:
			movePattern(1.2f, 1.f, 1.1f, 1.2f);
			break;
		case res::PLAYER_TYPE::MAI:
			movePattern(1.6f, 1.4f, 0.8f, 0.8f);
			break;
		case res::PLAYER_TYPE::MEGU:
			movePattern(1.3f, 1.2f, 1.3f, 1.1f);
			break;
		case res::PLAYER_TYPE::SARA:
			movePattern(1.4f, 1.2f, 2.8f, 1.4f);
			break;
		case res::PLAYER_TYPE::KANA:
			movePattern(1.3f, 1.1f, 1.2, 1.2f);
			break;
		/*case res::PLAYER_TYPE::UZUKI:
			movePattern(1.2, 0.8, 1.7f, 1.8f);
			break;
		case res::PLAYER_TYPE::MANIWA:
			movePattern(1.2, 0.8, 1.7f, 1.8f);
			break;
		case res::PLAYER_TYPE::URANA:
			movePattern(1.2, 0.8, 1.7f, 1.8f);
			break;*/
		}
		return m_Pos;
	}
	void PlayerMover::setKeyPad(int type) {
		m_Pad_type = type;
	}
	void PlayerMover::setBomFlag(bool flag) {
		m_Is_bom = flag;
	}
	void PlayerMover::setImageState(int img) {
		m_Image_state = img;
	}
	void PlayerMover::setSlow(bool flag) {
		m_Is_slow = flag;
	}
	void PlayerMover::movePattern(
		float speed,
		float speed_slowing,
		float speed_bom,
		float speed_bom_slowing
	) {
		if (getKey(app::Key::KEY_TYPE::SHIFT) != 0)m_Is_slow = true;
		else m_Is_slow = false;
		int sayu_flag = 0, joge_flag = 0;
		float x, y, mx = 0, my = 0, naname = 1;
		float move_x[4] = { -4.0,4.0,0,0 }, move_y[4] = { 0,0,4.0,-4.0 };
		int inputpad[4];
		inputpad[0] = getKey(
			app::Key::KEY_TYPE::LEFT
		);
		inputpad[1] = getKey(
			app::Key::KEY_TYPE::RIGHT
		);
		inputpad[2] = getKey(
			app::Key::KEY_TYPE::DOWN
		);
		inputpad[3] = getKey(
			app::Key::KEY_TYPE::UP
		);
		if (inputpad[1] > 0) {
			int a = 0;
		}
		if (getKey(app::Key::KEY_TYPE::LEFT) > 0)
			m_Image_state = 4;
		else if (getKey(app::Key::KEY_TYPE::RIGHT) > 0)
			m_Image_state = 8;
		else m_Image_state = 0;

		for (int i = 0; i < 2; i++)if (inputpad[i] > 0)sayu_flag = 2;
		for (int i = 2; i < 4; i++)if (inputpad[i] > 0)joge_flag = 2;
		if (sayu_flag == 1 && joge_flag == 1)
			naname = sqrt(2.0);

		for (int i = 0; i < 4; i++) {
			if (inputpad[i] > 0) {
				x = m_Pos.x, y = m_Pos.y;
				if (m_Is_bom == false) {
					mx = move_x[i] * 2 * speed;
					my = move_y[i] * 2 * speed;
					if (getKey(app::Key::KEY_TYPE::SHIFT) > 0) {
						mx = move_x[i] * speed_slowing;
						my = move_y[i] * speed_slowing;
					}
				}
				if (m_Is_bom == true) {
					mx = move_x[i] * 2 * speed_bom;
					my = move_y[i] * 2 * speed_bom;
					if (getKey(app::Key::KEY_TYPE::SHIFT) > 0) {
						mx = move_x[i] * speed_bom_slowing;
						my = move_y[i] * speed_bom_slowing;
					}
				}
				x += mx * 1.5 / naname, y += my * 1.5 / naname;
				if (!(x<30 || x>m_Max_x - m_Min_x - 30 || y< 60 || y>AreaProp::max_y - AreaProp::min_y - 60)) {
					m_Pos.x = x;
					m_Pos.y = y;
				}
			}
		}
	}
	bool PlayerMover::isDamageMove() {
		unsigned int push =
			getKey(app::Key::KEY_TYPE::LEFT) +
			getKey(app::Key::KEY_TYPE::RIGHT) +
			getKey(app::Key::KEY_TYPE::UP) +
			getKey(app::Key::KEY_TYPE::DOWN);
		m_Pos.y -= 1.5;
		if (m_Count > 60 || (m_Pos.y < AreaProp::max_y - AreaProp::min_y - 40 && push)) {
			m_Count = 0;
			return false;
		}
		m_Count++;
		return true;
	}
	bool PlayerMover::isSlow() {
		return m_Is_slow;
	}
	int PlayerMover::getKey(int num) {
		if (app::Replayer::GameRecorder.isReplayMode()) {
			return app::Replayer::GameRecorder.getKeyData(num);
		}
		else {
			if (m_Pad_type == 0) {
				app::Replayer::GameRecorder.pushBackKeyInputs(num, app::Key::Pad.checkInput(num));

				return app::Key::Pad.checkInput(num);
			}
			if (m_Pad_type == 1)return app::Key::MultPad[0].checkInput(num);
			if (m_Pad_type == 2)return app::Key::MultPad[1].checkInput(num);
		}
		return 0;
	}
	int PlayerMover::getImageState() {
		return m_Image_state;
	}
}