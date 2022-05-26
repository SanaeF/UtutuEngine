#include "Scene.h"

#include "../../Source/Application/Key/Key.h"
#include "../../Source/Application/Sound/Sound.h"
#include "../../Source/Resource/SoundData/SoundData.h"

namespace app {
	Scene::Scene() :
		m_Time(0),
		m_Select_verticals{ 0,0 },
		m_Select_horizontals{ 0,0 },
		m_Scene_state(0),
		m_Select_vertical(0),
		m_Select_horizontal(0)
	{
	}
	int Scene::update() {

		return 0;
	}
	void Scene::draw() {
	}
	bool Scene::sceneCoolDown(int time) {
		if (m_Time == time)return true;
		else {
			m_Time++;
		}
		return false;
	}
	void Scene::resetCoolDown() {
		m_Time = 0;
	}
	void Scene::setKeyLock(bool isHost) {
		m_Is_host = isHost;
		m_Key_lock = true;
	}
	void Scene::select() {
	}
	void Scene::cancel() {
	}
	void Scene::escape() {
	}
	void Scene::up(int max) {
		if (Key::Pad.checkInput(Key::KEY_TYPE::UP) == 1) {
			Sound::sound.playSE(res::SE::SELECT);
			m_Select_horizontal = (m_Select_horizontal + (max - 1)) % max;
		}
		else if (Key::Pad.checkInput(Key::KEY_TYPE::UP) > 12 && Key::Pad.checkInput(Key::KEY_TYPE::UP) % m_Cool_down == 1) {
			Sound::sound.playSE(res::SE::SELECT);
			m_Select_horizontal = (m_Select_horizontal + (max - 1)) % max;
		}
	}
	void Scene::down(int max) {
		if (Key::Pad.checkInput(Key::KEY_TYPE::DOWN) == 1) {
			Sound::sound.playSE(res::SE::SELECT);
			m_Select_horizontal = (m_Select_horizontal + 1) % max;
		}
		else if (Key::Pad.checkInput(Key::KEY_TYPE::DOWN) > 12 && Key::Pad.checkInput(Key::KEY_TYPE::DOWN) % m_Cool_down == 1) {
			Sound::sound.playSE(res::SE::SELECT);
			m_Select_horizontal = (m_Select_horizontal + 1) % max;
		}
	}
	void Scene::right(int max) {
		if (Key::Pad.checkInput(Key::KEY_TYPE::RIGHT) == 1) {
			Sound::sound.playSE(res::SE::SELECT);
			m_Select_vertical = (m_Select_vertical + 1) % max;
		}
		else if (Key::Pad.checkInput(Key::KEY_TYPE::RIGHT) > 12 && Key::Pad.checkInput(Key::KEY_TYPE::RIGHT) % m_Cool_down == 1) {
			Sound::sound.playSE(res::SE::SELECT);
			m_Select_vertical = (m_Select_vertical + 1) % max;
		}
	}
	void Scene::left(int max) {
		if (Key::Pad.checkInput(Key::KEY_TYPE::LEFT) == 1) {
			Sound::sound.playSE(res::SE::SELECT);
			m_Select_vertical = (m_Select_vertical + (max - 1)) % max;
		}
		else if (Key::Pad.checkInput(Key::KEY_TYPE::LEFT) > 12 && Key::Pad.checkInput(Key::KEY_TYPE::LEFT) % m_Cool_down == 1) {
			Sound::sound.playSE(res::SE::SELECT);
			m_Select_vertical = (m_Select_vertical + (max - 1)) % max;
		}
	}

	void Scene::up(int Key_num, int max) {
		int key_num = Key_num;
		int input_num = Key_num;
		if (m_Key_lock) {
			key_num = 0;
			if (m_Is_host)input_num = 0;
			if (!m_Is_host)input_num = 1;
		}
		if (Key::MultPad[key_num].checkInput(Key::KEY_TYPE::UP) == 1) {
			Sound::sound.playSE(res::SE::SELECT);
			m_Select_horizontals[input_num] = (m_Select_horizontals[input_num] + (max - 1)) % max;

		}
		else if (Key::MultPad[key_num].checkInput(Key::KEY_TYPE::UP) > 12 && Key::MultPad[key_num].checkInput(Key::KEY_TYPE::UP) % m_Cool_down == 1) {
			Sound::sound.playSE(res::SE::SELECT);
			m_Select_horizontals[input_num] = (m_Select_horizontals[input_num] + (max - 1)) % max;
		}
	}
	void Scene::down(int Key_num, int max) {
		int key_num = Key_num;
		int input_num = Key_num;
		if (m_Key_lock) {
			key_num = 0;
			if (m_Is_host)input_num = 0;
			if (!m_Is_host)input_num = 1;
		}
		if (Key::MultPad[key_num].checkInput(Key::KEY_TYPE::DOWN) == 1) {
			Sound::sound.playSE(res::SE::SELECT);
			m_Select_horizontals[input_num] = (m_Select_horizontals[input_num] + 1) % max;
		}
		else if (Key::MultPad[key_num].checkInput(Key::KEY_TYPE::DOWN) > 12 && Key::MultPad[key_num].checkInput(Key::KEY_TYPE::DOWN) % m_Cool_down == 1) {
			Sound::sound.playSE(res::SE::SELECT);
			m_Select_horizontals[input_num] = (m_Select_horizontals[input_num] + 1) % max;
		}
	}
	void Scene::right(int Key_num, int max) {
		int key_num = Key_num;
		int input_num = Key_num;
		if (m_Key_lock) {
			key_num = 0;
			if (m_Is_host)input_num = 0;
			if (!m_Is_host)input_num = 1;
		}
		if (Key::MultPad[key_num].checkInput(Key::KEY_TYPE::RIGHT) == 1) {
			Sound::sound.playSE(res::SE::SELECT);
			m_Select_verticals[input_num] = (m_Select_verticals[input_num] + 1) % max;
		}
		else if (Key::MultPad[key_num].checkInput(Key::KEY_TYPE::RIGHT) > 12 && Key::MultPad[key_num].checkInput(Key::KEY_TYPE::RIGHT) % m_Cool_down == 1) {
			Sound::sound.playSE(res::SE::SELECT);
			m_Select_verticals[input_num] = (m_Select_verticals[input_num] + 1) % max;
		}
	}
	void Scene::left(int Key_num, int max) {
		int key_num = Key_num;
		int input_num = Key_num;
		if (m_Key_lock) {
			key_num = 0;
			if (m_Is_host)input_num = 0;
			if (!m_Is_host)input_num = 1;
		}
		if (Key::MultPad[key_num].checkInput(Key::KEY_TYPE::LEFT) == 1) {
			Sound::sound.playSE(res::SE::SELECT);
			m_Select_verticals[input_num] = (m_Select_verticals[input_num] + (max - 1)) % max;
		}
		else if (Key::MultPad[key_num].checkInput(Key::KEY_TYPE::LEFT) > 12 && Key::MultPad[key_num].checkInput(Key::KEY_TYPE::LEFT) % m_Cool_down == 1) {
			Sound::sound.playSE(res::SE::SELECT);
			m_Select_verticals[input_num] = (m_Select_verticals[input_num] + (max - 1)) % max;
		}
	}

	void Scene::setVertical(int num) {
		m_Select_vertical = num;
	}
	void Scene::setVertical(int num, int key_kind) {
		m_Select_verticals[key_kind] = num;
	}
	void Scene::setHorizontal(int num) {
		m_Select_horizontal = num;
	}
	void Scene::setHorizontal(int num, int key_kind) {
		m_Select_horizontals[key_kind] = num;
	}
	void Scene::setSceneState(int state) {
		m_Scene_state = state;
	}
	int Scene::getVertical() {
		return m_Select_vertical;
	}
	int Scene::getHorizontal() {
		return m_Select_horizontal;
	}
	int Scene::getVertical(int key_kind) {
		return m_Select_verticals[key_kind];
	}
	int Scene::getHorizontal(int key_kind) {
		return m_Select_horizontals[key_kind];
	}
	int Scene::getSceneState() {
		return m_Scene_state;
	}
	bool Scene::isRight() {
		if (Key::Pad.checkInput(Key::KEY_TYPE::RIGHT) == 1) {
			Sound::sound.playSE(res::SE::SELECT);
			return true;
		}
		else if (Key::Pad.checkInput(Key::KEY_TYPE::RIGHT) > 12 && Key::Pad.checkInput(Key::KEY_TYPE::RIGHT) % m_Cool_down == 1) {
			Sound::sound.playSE(res::SE::SELECT);
			return true;
		}
		return false;
	}
	bool Scene::isLeft() {
		if (Key::Pad.checkInput(Key::KEY_TYPE::LEFT) == 1) {
			Sound::sound.playSE(res::SE::SELECT);
			return true;
		}
		else if (Key::Pad.checkInput(Key::KEY_TYPE::LEFT) > 12 && Key::Pad.checkInput(Key::KEY_TYPE::LEFT) % m_Cool_down == 1) {
			Sound::sound.playSE(res::SE::SELECT);
			return true;
		}
		return false;
	}
}