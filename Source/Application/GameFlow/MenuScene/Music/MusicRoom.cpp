#pragma once
#include "MusicRoom.h"
#include <iostream>
#include"../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include"../../Source/library/Graphics/String/StringDX.h"
#include "../../Source/Resource/GUI/MenuUIImage/MenuUIImage.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"
#include "../../Source/Resource/EnemyImage/EnemyImage.h"
#include "../../Source/Resource/SoundData/SoundData.h"
#include "../../Source/SystemProp/SceneProp.h"
#include "../../Source/Application/Key/Key.h"
#include "../../Source/Application/Sound/Sound.h"
#include "../../Source/Application/GameFlow/EndingScene/EndingScene.h"
#include "../../Source/Helper/Helper.h"
#include "../../Source/Object/Object/Object.h"
#include "../../Source/Resource/SaveData/SaveData.h"

namespace app {
	void MusicRoom::draw() {
		if (m_State == STATE::BGM) {
			lib::Graphics2D::drawRota(1920 / 2, 1440 / 2, 1.0, 0.0, res::MenuUIImage::menu_ui.title.back, true);
			lib::Graphics2D::drawRota(1920 / 2, 1440 / 2, 1.0, 0.0, res::MenuUIImage::menu_ui.musicRoom, true);
			//lib::Graphics.drawRota(1920 / 2, 1440 / 2, 1.0, 0.0, diffback[3], true);
			//lib::Graphics.drawRota(1920 / 2, 1440 / 2, 1.0, 0.0, musicroom_imf[getHorizontal()], true);
			lib::Graphics2D::drawMode(lib::DRAW_MODE::NEAREST);//���`�⊮�`��
			int img_state = 0;
			switch (getHorizontal()) {
			case 0://title
				musicText
				(
					"�^�C�g���̃e�[�}�ł�",
					"���悢�惉�X�g�����ł��B",
					"",
					"",
					"",
					"",
					"",
					"",
					"",
					"",
					""
				);
				break;
			case 1://1rood
				musicText
				(
					"1�ʓ����̃e�[�}�ł��B",
					"",
					"�t�Ɏc������ƍ��̖؂�",
					"�C���[�W�����Ȃł��B",
					"�����ėǂ���ˁB",
					"",
					"�t�Ȃ̂Ɋ�������������̂́A",
					"�����ɂ���N���̊���Ƃ�",
					"�`������炢���Ȃ��B",
					"���ƁA",
					"������Ƃ��킢���Ȃ���ˁB"
				);
				break;
			case 2://1boss
				if (res::SaveData::save_data.clear.clear_story_num >= 1) {
					img_state = (int(m_Count / 24)) % 2;
					lib::Graphics2D::drawRota(900, 1070, 1.5f, 0 + cos(PI / 25 * m_Count) / 60, res::EnemyImage::enemy.boss[res::BOSS_TYPE::N01_MATUMI][img_state], true);
					musicText
					(
						"��������̂ɍ������߂��A",
						"�ޏ��͑��d�l�i�ŋꂵ�񂾁B",
						"����A�V���ɉ��y��������̂́A",
						"���C�Ɉς˂����ɂ����Ȃ��B",
						"",
						"1�ʃ{�X�A����̃e�[�}�ł��B",
						"�u����v���u�z���v���u���]�v",
						"�̂悤�Ȋ��o�ō��܂����B",
						"����Ă���Ԃ��A�����������",
						"�i�j�R���݂����ȋC���ł��B",
						"��������͓̂���ł��ˁ`�B"
					);
				}
				else {
					musicText("�܂��N���A���Ă��܂���B", "��1�ʂ��N���A���悤�I",
						"", "", "", "", "", "", "", "", ""
					);
				}
				break;
			case 3://2rood
				musicText
				(
					"2�ʓ����̃e�[�}�ł��B",
					"",
					"���v���̏��������悤��",
					"���Ԕ���z�����Ă����̂ŁA",
					"���̂悤�ȋȂɂȂ�܂����B",
					"",
					"���Ȃ݂ɁA�e���Ă�Ƃ��́A",
					"���v�̐j����������",
					"�m���m���ł����B",
					"���g���m�[�����特����",
					"�Ȃ邩���ˁi�΁j"
				);
				break;
			case 4://2boss
				if (res::SaveData::save_data.clear.clear_story_num >= 2) {
					img_state = (int(m_Count / 60)) % 2;
					lib::Graphics2D::drawRota(900, 1070, 1.5f, 0 + cos(PI / 25 * m_Count) / 60, res::EnemyImage::enemy.boss[res::BOSS_TYPE::N02_EREMIRA][img_state * 2], true);
					musicText
					(
						"�V���f�����Ƃ����΃A�C�h���B",
						"���Y�����́A�Ȃ���ł���?",
						"���A���̖�����...�B",
						"2�ʃ{�X�A�G���~���̃e�[�}�B",
						"�߂����Ȃ��Ăǂ����J�b�R�C�C!",
						"���A����܂��I",
						"������A�A�C�h�����ۂ���",
						"�炵���Ǝ׈��ȃJ�b�R�ǂ���",
						"���w�������������Ȃ�",
						"�Ȃ�܂����B�������ł���H",
						"���Ƃ��C�ɓ���ł��B"
					);
				}
				else {
					musicText("�܂��N���A���Ă��܂���B", "��2�ʂ��N���A���悤�I",
						"", "", "", "", "", "", "", "", ""
					);
				}
				break;
			case 5://3rood
				musicText
				(
					"3�ʓ����̃e�[�}�ł��B",
					"����́E�E�E����H",
					"�����̊����̋Ȃł��˂��B",
					"����ȋC�����܂��B",
					"�����ł̓A���X�̎���",
					"�C���[�W���Ȃ��悤�ɂ��܂����B",
					"1�ʁA2�ʂ̕s�v�c�ȋC������",
					"�����ɗ��ė������������Ȃ̂�",
					"���邢�ݕs�C���ł����ˁH",
					"�l�Ȃ�̃t�@���^�W�[�ł��B",
					"�D���ȕ��̃t�@���^�W�[�ł��B"
				);
				break;
			case 6://3boss
				if (res::SaveData::save_data.clear.clear_story_num >= 3) {
					img_state = (int(m_Count / 60)) % 2;
					lib::Graphics2D::drawRota(900, 1070, 1.5f, 0 + cos(PI / 25 * m_Count) / 60, res::EnemyImage::enemy.boss[res::BOSS_TYPE::N03_ALICE][img_state * 2], true);
					musicText
					(
						"�A���X�E�V���b�g",
						"�̃e�[�}�ł͖����ł��B",
						"",
						"�J�[�h�Ŏg������",
						"���F�B�𕡐������Ⴂ�܂��B",
						"���̎��_�ł͂��܂���Ȃ���",
						"����Ȃ��E�E�E�B",
						"���\�����������ȁA�C��������",
						"�l�ȋȂɂȂ�܂����B",
						"������ԔY�񂾁B",
						"�����ɂ��G�I����ˁB"
					);
				}
				else {
					musicText("�܂��N���A���Ă��܂���B", "��3�ʂ��N���A���悤�I",
						"", "", "", "", "", "", "", "", ""
					);
				}
				break;
			case 7://4rood
				musicText
				(
					"4�ʓ����ł��B",
					"���C�ɐ��܂������",
					"�ԈÂ�",
					"��������Δ�r�I�V�����p��",
					"�����͈�ԋ��C�Z�x������",
					"�����{�݂̐ՁA�댯�n�тł��B",
					"",
					"����́A�������Ȃ��",
					"�����̋Ȃ��",
					"�ɂȂ�܂����B",
					"�{���͐��m���ɂ����������B"
				);

				break;
			case 8://4boss
				if (res::SaveData::save_data.clear.clear_story_num >= 4) {
					img_state = (int(m_Count / 60)) % 3;
					lib::Graphics2D::drawRota(900, 1070, 1.5f, 0 + cos(PI / 25 * m_Count) / 60, res::EnemyImage::enemy.boss[res::BOSS_TYPE::N04_NARSIRU][img_state * 2], true);
					musicText
					(
						"�i���V���̃e�[�}�ł��B",
						"��肽���҂����邾���ŁA",
						"�����Ȃ�A�키���R�����܂�܂��B",
						"�ǂ�ȋ����A���̐l�ׂ̈�",
						"����Ă����񂾂Ǝv���܂��B",
						"",
						"���Ȃ݂ɁA�l�͏��̎q����Ȃ��̂�",
						"�����鉳���̋C�����Ȃ�āA",
						"����������x�̗����ł��B",
						"����́A����ȗ��S�ȋC����",
						"���䌀�̂悤�Ȏd�オ��ł����B"
					);
				}
				else {
					musicText("�܂��N���A���Ă��܂���B", "��4�ʂ��N���A���悤�I",
						"", "", "", "", "", "", "", "", ""
					);
				}
				break;
			case 9://5boss
				if (res::SaveData::save_data.clear.clear_story_num >= 5) {
					img_state = (int(m_Count / 60)) % 2;
					lib::Graphics2D::drawRota(900, 1070, 1.5f, 0 + cos(PI / 25 * m_Count) / 60, res::EnemyImage::enemy.boss[res::BOSS_TYPE::N05_FEATORIA][img_state * 2], true);
					musicText
					(
						"�t�F�A�g���A�̃e�[�}�ł��B",
						"�����A�{�X�Ȃł��B",
						"",
						"���̖��ɃL�m�R��A���t�����A�C�c",
						"�[�b�e�[�����ˁ[����ȁI�I",
						"�Ƃ܂��A�����������Ɏ��s����",
						"��l�̔�Q�҂��C���[�W����",
						"�Ȃł��B",
						"�}�c�~�̃����f�B�[���g���Ă���",
						"�Ǝv���������̂��Ȃ��A",
						"�Ȃ����܂���o����ł�����ˁB"
					);
				}
				else {
					musicText("�܂��N���A���Ă��܂���B", "��5�ʂ��N���A���悤�I",
						"", "", "", "", "", "", "", "", ""
					);
				}
				break;
			case 10://5rood
				musicText
				(
					"6�ʓ����̃e�[�}�ł����A",
					"��e���1�ʓ����̃A�����W�ł��B",
					"�����̊��o�ō��܂�����B",
					"���S���đ厖�炵�������H",
					"(���ド�X�{�X�̋Ȃ�4�������Ăċ���)",
					"���̌�o�Ă���q���ǂ������",
					"�҂��\������悤�ɁA",
					"�܂��A�{���������߂ɃC���[�W",
					"���܂����B",
					"���H���e�[�}�ł��B",
					""
				);
				break;
			case 11://6boss
				if (res::SaveData::save_data.clear.clear_story_num >= 6) {
					img_state = (int(m_Count / 60)) % 2;
					lib::Graphics2D::drawRota(900, 1070, 1.5f, 0 + cos(PI / 25 * m_Count) / 60, res::EnemyImage::enemy.boss[res::BOSS_TYPE::N06_SHIENA][img_state * 2], true);
					musicText
					(
						"�V�G�i�̃e�[�}�ł��B",
						"�����ȍĉ�ƃ����w���ȐԂ�����",
						"���C���[�W�����悤�ȋȂł��B",
						"",
						"�ǂ������߂����������Ă���̂�",
						"����ς�₵�������񂾂낤�Ȃ�",
						"�v�킹�܂��ˁB",
						"�����w���`�b�N�Ŗ��邢�Ԃ�����",
						"���������ǁA�~�ނ��o���Ńh�X����",
						"�����w���Ԃ�������ǂ��Ȃ����āA",
						"����͂���ȃe�[�}�ł����B"
					);
				}
				else {
					musicText("�X�g�[���[���N���A���悤�I", "���K���o��",
						"", "", "", "", "", "", "", "", ""
					);
				}
				break;
			case 12://7boss
				if (res::SaveData::save_data.clear.clear_story_num >= 7) {
					lib::Graphics2D::drawRota(900, 1070, 1.5f, 0 + cos(PI / 25 * m_Count) / 60, res::EnemyImage::enemy.boss[res::BOSS_TYPE::N07_ALICE][0], true);
					musicText
					(
						"�A���X���[�h7�ʂ̃e�[�}�ł��B",
						"�A���X�����ɍ��܂����B",
						"���ԓI�ɂ��ꂪ��ԍŌ�ɍ����",
						"�ȂȂ�ł���˂��B",
						"�Ԃ����Ⴏ�A�ǂ�ȋȂɂ��悤��",
						"�܂������v���t�������āA",
						"�I�n�^�S�ËS�ɂȂ�Ȃ��特��",
						"�炵�Ă��܂����B",
						"�����A���̊Ԃɂ�����ȋȂ�",
						"�o���Ă����̂ł��I",
						"�R�r�g���񂪍���Ă��ꂽ�̂��ȁB"
					);
				}
				else {
					musicText("�A���X���[�hLv.10�ȏ�ŏo������", "7�ʂ��N���A���悤",
						"", "", "", "", "", "", "", "", ""
					);
				}
				break;
			case 13://Ex rood
				musicText
				(
					"�G�L�X�g�������̃e�[�}�ł��B",
					"�ȈĂ�3�p�^�[���l���Ă����̂�",
					"�h���ōs�������Y�݂܂������A",
					"�G�L�X�g�����Ė{�҂���Ȃ�����",
					"�C���ō���ėǂ��񂶂�ˁH����",
					"���ƂŁA�F�X�����܂����B",
					"�ߔ}���E�ł��̋Ȃ�������",
					"���A�c����ˁH���Ďv���Ă��z�ł��B",
					"",
					"���Ȃ��Ƃ����^������n�Y���ꂽ",
					"��l�̏����݂����Ȋ���������B"
				);
				break;
			case 14://Ex boss
				if (res::SaveData::save_data.clear.difficulty[3]) {
					img_state = (int(m_Count / 60)) % 2;
					lib::Graphics2D::drawRota(900, 1070, 1.5f, 0 + cos(PI / 25 * m_Count) / 60, res::EnemyImage::enemy.boss[res::BOSS_TYPE::N08_KURO][img_state * 2], true);
					musicText
					(
						"�G�L�X�g���{�X�̃e�[�}�ł��B",
						"������ƕ|�����Ȃ��H",
						"���b�̂悤�ȕ��͋C���C���[�W",
						"���܂����B",
						"������A�����Ő키�̂�",
						"�����̍����Ȃ̂ŁA",
						"���X�g�ɑ��������Ќ���������",
						"�ȂɎd�グ�Ă��܂��B",
						"�㔼�ł����ʂ�ȋȒ���",
						"�Ȃ邩��A�Â����͋C���ɘa",
						"�ł���Ǝv���܂���B"
					);
				}
				else {
					musicText("�G�L�X�g�����N���A���悤�I", "���K���o��",
						"", "", "", "", "", "", "", "", ""
					);
				}
				break;
			case 15://ED
				if (res::SaveData::save_data.clear.clear_story_num >= 6) {
					musicText
					(
						"�G���f�B���O�ł��B",
						"����p�̃A�j���������",
						"������ł����A�����łł�",
						"�������ŏo�����ɂȂ���",
						"���܂��܂����B�g�z�z",
						"",
						"",
						"",
						"++����<<  �܂��ˁB>>����++",
						"",
						""
					);
				}
				else {
					musicText("�X�g�[���[���N���A���悤�I", "���K���o��",
						"", "", "", "", "", "", "", "", ""
					);
				}
				break;
			case 16://AL
				musicText
				(
					"���߂܂��āAAL�Ɛ\���܂��B",
					"���̃Q�[���̐���҂ɗ��܂�A",
					"�ʂ̃Q�[���Ɏg����\��",
					"�������Ȃł��B",
					"���̃Q�[���͂���ōŏI���",
					"�\��ł����A��i���{����",
					"�I�����}����̂́A",
					"�N����i��n��Ȃ��Ȃ���",
					"���ł��B�ł�����F����",
					"��i��n��܂��傤�B",
					"���b�c�N���G�C�g�I"
				);
				break;
			default:
				break;
			}
			for (int i = 0; i < m_BGM_max; i++) {
				if (i == getHorizontal()) {
					lib::StringDX::draw(
						460 * 4 - m_Music_name[0].x - 60,
						m_Music_name[0].y,
						Sound::sound.m_Title[i].name,
						lib::StringDX::color(255, 255, 255),
						res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]
					);
				}
				else {
					lib::StringDX::draw(
						460 * 4 - m_Music_name[1 + ((m_BGM_max - 1) - getHorizontal() + i) % m_BGM_max].x,
						m_Music_name[1 + ((m_BGM_max - 1) - getHorizontal() + i) % m_BGM_max].y,
						Sound::sound.m_Title[i].name,
						lib::StringDX::color(133, 133, 133),
						res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]
					);
				}
			}
		}
		if (m_State == STATE::MOVIE) {
			m_Ending->draw();
		}
	}

	int MusicRoom::update() {
		setSceneState(SCENE_TYPE::MUSIC);
		if (sceneCoolDown(10)) {
			if (m_State == STATE::BGM) {
				up(m_BGM_max);
				down(m_BGM_max);
				select();
				cancel();
			}
			if (m_State == STATE::MOVIE) {
				m_Ending->update();
				if (m_Ending->isEnded()) {
					m_State = STATE::BGM;
					Sound::sound.unFreez();
				}
			}
			m_Count++;
		}
		else {
			m_State = STATE::BGM;
		}
		return getSceneState();
	}

	void MusicRoom::select() {
		if (Key::Pad.checkInput(Key::KEY_TYPE::SHOT) == 1) {
			Sound::sound.playSE(res::SE::SELECT_OK);
			if (getHorizontal() == 15) {
				Sound::sound.freez();
				m_Ending->setEnding();
				m_State = STATE::MOVIE;
			}
			else {
				Sound::sound.playBGM(getHorizontal());
			}
			m_Count = 0;
		}
	}

	void MusicRoom::cancel() {
		if (Key::Pad.checkInput(Key::KEY_TYPE::BOM) == 1 || Key::Pad.checkInput(Key::KEY_TYPE::MENU) == 1) {
			Sound::sound.playSE(res::SE::SELECT_CANCEL);
			Sound::sound.playBGM(0);
			resetCoolDown();
			setSceneState(SCENE_TYPE::TITLE);
		}

	}

	void MusicRoom::musicText(
		const char* msg0,
		const char* msg1,
		const char* msg2,
		const char* msg3,
		const char* msg4,
		const char* msg5,
		const char* msg6,
		const char* msg7,
		const char* msg8,
		const char* msg9,
		const char* msg10
	) {
		lib::StringDX::draw(30, 725, msg0, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(30, 775, msg1, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(30, 825, msg2, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(30, 875, msg3, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(30, 925, msg4, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(30, 975, msg5, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(30, 1025, msg6, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(30, 1075, msg7, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(30, 1125, msg8, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(30, 1175, msg9, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(30, 1225, msg10, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
	}
	MusicRoom::MusicRoom() {
		m_Count = 0;
		m_Ending.reset(new EndingScene());
	}
}