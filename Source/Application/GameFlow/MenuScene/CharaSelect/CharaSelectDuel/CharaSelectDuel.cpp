#include "CharaSelectDuel.h"
#include <iostream>
#include"../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include"../../Source/library/Graphics/String/StringDX.h"
#include "../../Source/Resource/GUI/MenuUIImage/MenuUIImage.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"
#include "../../Source/Resource/GUI/SelectUIImage/SelectUIImage.h"
#include "../../Source/Resource/SoundData/SoundData.h"
#include "../../Source/Application/Sound/Sound.h"
#include "../../Source/Application/Key/Key.h"
#include "../../Source/SystemProp/SceneProp.h"

namespace app {
	void CharaSelectDuel::initialize() {
		setHorizontal(0);
		setVertical(0);
		m_State = 0;
		for (int i = 0; i < 2; i++) {
			setHorizontal(0, i);
			setVertical(0, i);
			m_Is_select[i] = false;
		}
	}
	int CharaSelectDuel::update() {
		if (sceneCoolDown(10)) {
			charaSelect();
			startSelect();
			cancel();
			if (m_Is_select[0] && m_Is_select[1]) {
				if (m_State != START_SELECT)resetCoolDown();
				m_State = START_SELECT;
			}
			else m_State = SELECT_CHARA;
			if(m_Is_start)setSceneState(SCENE_TYPE::GAME_MAIN);
		}
		else {
			m_Is_start = false;
			m_Key_lock = false;
			m_Is_host = false;
			setSceneState(SCENE_TYPE::SELECT_CHARA);
		}
		return getSceneState();
	}
	void CharaSelectDuel::draw() {
		lib::Graphics2D::drawRota(480 * 2, 360 * 2, 1.0, 0.0, res::MenuUIImage::menu_ui.title.back, true);
		lib::Graphics2D::draw(0, 0, res::MenuUIImage::menu_ui.gray_box[1], true);
		drawSelectChara();
		drawDuelConf();
	}
	void CharaSelectDuel::drawSelectChara() {
		const int addY = 100;
		const int imgPosDist = 300;
		const int imgPosY = 1440 - imgPosDist;
		const int menuPosX = 700;
		MenuText m_Title_gui[CHARA_NUM] = {
			{ 600, 650 + addY * 0, "ˆ»”T" },
			{ 600, 650 + addY * 1, "‚Ý‚³‚Æ" },
			{ 600, 650 + addY * 2, "Ôé" },
			{ 600, 650 + addY * 3, "•Q" },
			{ 600, 650 + addY * 4, "ˆÁŒÇ"},
			{ 600, 650 + addY * 5, "‚Ü‚É‚í"},
			{ 600, 650 + addY * 6, "ŠC—ÇØ"},
		};

		MenuText StageKnd[] = {
			{ 0, 0, "—ìŠC‚ÆˆÙŠE‚Ì”Þ•û" },
			{ 0, 0, "‹•ŠE‚Ì‘å’Ê‚è" },
			{ 0, 0, "–Ö‚Æ“s‚ÌŒÃ‚«ŠX“¹" }
		};
		if (m_State == START_SELECT)lib::Graphics2D::setBright(100, 100, 100);
		lib::Graphics2D::drawRota(imgPosDist, imgPosY, 0.7, 0, res::SelectUIImage::select_ui.multCharaIcon[m_Chara_type[0]], true);
		lib::Graphics2D::drawRota(1920 - imgPosDist, imgPosY, 0.7, 0, res::SelectUIImage::select_ui.multCharaIcon[m_Chara_type[1]], true);
		if (m_State == SELECT_CHARA) {
			for (int i = 0; i < CHARA_NUM; i++) { // ƒƒjƒ…[€–Ú‚ð•`‰æ//NetWork_Offline
				if (m_Chara_type[0] == i) {
					lib::StringDX::draw(menuPosX - 20 * 2, m_Title_gui[i].y, m_Title_gui[i].name, lib::StringDX::color(233, 233, 233), res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]);
				}
				else {
					if (!m_Is_select[0])lib::StringDX::draw(menuPosX, m_Title_gui[i].y, m_Title_gui[i].name, lib::StringDX::color(120, 120, 120), res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]);
				}
				if (m_Chara_type[1] == i) {
					lib::StringDX::draw(1920 - menuPosX * 1.25 - 20 * 2, m_Title_gui[i].y, m_Title_gui[i].name, lib::StringDX::color(233, 233, 233), res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]);
				}
				else {
					if (!m_Is_select[1])lib::StringDX::draw(1920 - menuPosX * 1.25, m_Title_gui[i].y, m_Title_gui[i].name, lib::StringDX::color(120, 120, 120), res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]);
				}
			}
			lib::StringDX::draw(700, 500, StageKnd[m_Map_type % 3].name, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]);
		}
		if (m_State == START_SELECT)lib::Graphics2D::setBright(255, 255, 255);
	}
	void CharaSelectDuel::drawDuelConf() {
		if (m_State == START_SELECT) {
			MenuText ConfGUI[2] = {
				{ 200, 650, "ƒfƒ…ƒGƒ‹I" },
				{ 200, 800, "ƒLƒƒƒ‰‚ð‘I‚Ñ‚È‚¨‚·" },
			};
			MenuText SoundKnd[5] = {
				{ 0, 0, "ô:ƒŠ[ƒt ƒIƒu ƒqƒƒCƒ“" },
				{ 0, 0, "ô:ƒ}ƒWƒbƒNƒh[ƒ‹" },
				{ 0, 0, "ô:ƒ‚ƒ_ƒ“ƒXƒ^ƒCƒ‹ - Ver.R" },
				{ 0, 0, "ô:—HŠE‚Ì“sA“VŽq - Ver.R" },
				{ 0, 0, "ô:Œ«ŽÒ‘åí‘ˆ" }
			};
			for (int i = 0; i < 2; i++) {// ƒƒjƒ…[€–Ú‚ð•`‰æ
				if (getHorizontal(0) == i) {
					lib::StringDX::draw(ConfGUI[i].x - 20 * 2 + 400, ConfGUI[i].y, ConfGUI[i].name, lib::StringDX::color(233, 233, 233), res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]);
				}
				else {
					lib::StringDX::draw(ConfGUI[i].x + 400, ConfGUI[i].y, ConfGUI[i].name, lib::StringDX::color(120, 120, 120), res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]);
				}
			}
			lib::StringDX::draw(550, 500, SoundKnd[m_Select_sound].name, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]);
		}
	}

	void CharaSelectDuel::charaSelect() {
		if (m_State == SELECT_CHARA) {
			right(0, 3);
			left(0, 3);
			if(!m_Key_lock||m_Is_host)m_Map_type = getVertical(0);
			for (int i = 0; i < 2; i++) {
				bool lock = false;
				if (m_Key_lock) {
					if (m_Is_host && i == 1)lock = true;
					if (!m_Is_host && i == 0)lock = true;
				}
				if (!m_Is_select[i] && !lock) {
					up(i, CHARA_NUM);
					down(i, CHARA_NUM);
					m_Chara_type[i] = getHorizontal(i) % CHARA_NUM;
					select(i);
				}
			}
		}
	}
	void CharaSelectDuel::startSelect() {
		if (m_State == START_SELECT) {
			up(0, 2);
			down(0, 2);
			right(0, 5);
			left(0, 5);
			if (!m_Key_lock || m_Is_host)m_Select_sound = getVertical(0);
			if (m_Select_sound == 0)m_Sound_type = 7;
			if (m_Select_sound == 1)m_Sound_type = 1;
			if (m_Select_sound == 2)m_Sound_type = 4;
			if (m_Select_sound == 3)m_Sound_type = 5;
			if (m_Select_sound == 4)m_Sound_type = 8;
			if (getHorizontal(0) == 0) {
				if (Key::MultPad[0].checkInput(Key::SHOT)) {
					Sound::sound.playSE(res::SE::SELECT_OK);
					initialize();
					resetCoolDown();
					m_Is_start = true;
				}
			}
			if (getHorizontal(0) == 1) {
				if (Key::MultPad[0].checkInput(Key::SHOT)) {
					Sound::sound.playSE(res::SE::SELECT_OK);
					initialize();
				}
			}
		}
	}

	void CharaSelectDuel::select(int key_kind) {
		int keyNum = key_kind;
		int inputNum = key_kind;
		if (m_Key_lock) {
			keyNum = 0;
			if (m_Is_host)inputNum = 0;
			if (!m_Is_host)inputNum = 1;
		}
		if (Key::MultPad[keyNum].checkInput(Key::SHOT)) {
			Sound::sound.playSE(res::SE::SELECT_OK);
			if (!m_Is_select[inputNum])m_Is_select[inputNum] = true;
		}
	}
	void CharaSelectDuel::cancel() {
		if (m_State == SELECT_CHARA) {
			if (Key::MultPad[0].checkInput(Key::BOM)) {
				if (m_Key_lock && !m_Is_host)return;
				m_Is_select[0] = false;
				Sound::sound.playSE(res::SE::SELECT_CANCEL);
			}
			if (Key::MultPad[1].checkInput(Key::BOM)) {
				if (m_Key_lock && m_Is_host)return;
				m_Is_select[1] = false;
				Sound::sound.playSE(res::SE::SELECT_CANCEL);
			}
			if (Key::MultPad[0].checkInput(Key::MENU)) {
				Sound::sound.playSE(res::SE::SELECT_CANCEL);
				initialize();
				resetCoolDown();
				setSceneState(SCENE_TYPE::TITLE);
			}
		}
		if (m_State == START_SELECT) {
			if (Key::MultPad[0].checkInput(Key::MENU)) {
				Sound::sound.playSE(res::SE::SELECT_CANCEL);
				initialize();
				m_Key_lock = false;
				m_Is_host = false;
			}
		}
	}
	void CharaSelectDuel::setServerDataHost(int charaK, int select_num) {
		m_Chara_type[1] = charaK;
		m_Is_select[1] = select_num;
		m_Key_lock = true;
		m_Is_host = true;
		this->setKeyLock(true);
	}
	void CharaSelectDuel::setServerDataConnect(int charaK, int select_num, int sound, int stage, bool start) {
		m_Is_start = start;
		m_Chara_type[0] = charaK;
		m_Is_select[0] = select_num;
		m_Map_type = stage;
		m_Sound_type = sound;
		if (m_Sound_type == 7)m_Select_sound = 0;
		if (m_Sound_type == 1)m_Select_sound = 1;
		if (m_Sound_type == 4)m_Select_sound = 2;
		if (m_Sound_type == 5)m_Select_sound = 3;
		if (m_Sound_type == 8)m_Select_sound = 84;
		m_Key_lock = true;
		m_Is_host = false;
		this->setKeyLock(false);
	}
	void CharaSelectDuel::setState(bool flag) {
		m_Is_start = flag;
	}
	int CharaSelectDuel::getSelectInput(int num) {
		return m_Is_select[num];
	}
	int CharaSelectDuel::getCharaType1() {
		return m_Chara_type[0];
	}
	int CharaSelectDuel::getCharaType2() {
		return m_Chara_type[1];
	}
	int CharaSelectDuel::getMapType() {
		return m_Map_type;
	}
	int CharaSelectDuel::getSoundType() {
		return m_Sound_type;
	}
	bool CharaSelectDuel::isStart() {
		return m_Is_start;
	}
}