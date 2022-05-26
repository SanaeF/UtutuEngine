#include "StageSelect.h"

#include"../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include"../../Source/library/Graphics/String/StringDX.h"
#include "../../Source/Resource/GUI/MenuUIImage/MenuUIImage.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"
#include "../../Source/Resource/SaveData/SaveData.h"
#include "../../Source/SystemProp/SceneProp.h"
#include "../../Source/Application/Key/Key.h"
#include "../../Source/Application/Sound/Sound.h"
#include "../../Source/Resource/SoundData/SoundData.h"

namespace app {
	void StageSelect::draw() {
		lib::Graphics2D::drawRota(480 * 2, 360 * 2, 1.0, 0.0, res::MenuUIImage::menu_ui.title.back, true);
		if (m_Massage_flag != 0) {
			lib::Graphics2D::draw(0, 0, res::MenuUIImage::menu_ui.gray_box[4], true);
		}
		else {
			lib::Graphics2D::draw(0, 0, res::MenuUIImage::menu_ui.gray_box[0], true);

			MenuText Stage[] = {//�񎟑n��
				{ 0, 0, "Stage1" },
				{ 0, 0, "Stage2" },
				{ 0, 0, "Stage3" },
				{ 0, 0, "Stage4" },
				{ 0, 0, "Stage5" }
			};
			lib::StringDX::draw(
				680,
				1170,
				Stage[getVertical()].name,
				lib::StringDX::color(255, 255, 255),
				res::TextUIImage::text_ui.font[0]
			);
			switch (getVertical()) {
			case 0:
				stageMenu(
					0,
					"�Ղ��[��v",
					"01:�u�S���̃J���X�}�W�J�v",
					"02:�u���C�̃I�[�^���X�g�[���v",
					"03:�u��Ԗڂ̏����A���t�@�v",
					"04:�u�}�W�J�� �G�N�X�v���[�W�����v",
					"05:�u�����̃S�[���h�X�g�[���v"
				);

				break;
			case 1:
				stageMenu(
					1,
					"�������ƃE�T�M",
					"06:�u�A���f�b�h ���C�g �X�e���v",
					"07:�u���z�J���e�b�g�v",
					"08:�u�J�t�F�h �r�b�g�v",
					"09:�u����ῂ��������̒e���v",
					"10:�u���e�o���̒e���v�����v"
				);
				break;
			case 2:
				stageMenu(
					2,
					"�ĉ�!��͒m��Ȃ�",
					"11:�u�G�N�X�b�I�J���o�[�\�\�I�v",
					"12:�u�����̂ӂ����сv",
					"13:�u���ʂ܂���ǃh���v",
					"14:�u��т܂�!�I�v�V������!�v",
					"15:�u���񂢂�p�j�b�N���v"
				);
				break;
			case 3:
				stageMenu(
					3,
					"�߂ɉ����āA�݂�����",
					"16:�u���C�̎���A���ɕ����v",
					"17:�u������T�C�N���C�h�v",
					"18:�u�c����̍ŋ��R���r�v",
					"19:�u��l�Ēe�������v",
					"20:�u���������̑����{�C�v"
				);
				break;
			case 4:
				stageMenu(
					4,
					"���҂͐��܂�A�s�҂͏�����",
					"ex01:�u�e���̐����`���v",
					"ex02:�u�e�ɗ����Ƃ炷�̂͐��v",
					"ex03:�u�}�W�b�N���{�O�v",
					"ex04:�u�ň��̃R���r�v",
					"ex05:�u���͏�ɗ����A�т��͒�߁v"
				);
				break;

			}
		}
	}

	int StageSelect::update() {
		setSceneState(SCENE_TYPE::SELECT_STAGE);
		if (sceneCoolDown(10)) {
			select();

			int num = 0;
			int stageNum = 0;
			for (int stage = 0; stage < 6; stage++) {
				if (res::SaveData::save_data.clear.bullet[stage][0] == 1)stageNum++;
				for (int bKnd = 1; bKnd <= 5; bKnd++) {
					if (res::SaveData::save_data.clear.bullet[stage][bKnd] == 1)num++;
				}
			}
			m_Num[0] = stageNum;//�X�e�[�W�̃`���v�^�[���N���A������
			m_Num[1] = num;//�N���A�����e���̐�

			if (m_Num[0] == 1) {
				if (m_Num[1] >= 3) {
					if (res::SaveData::save_data.clear.stage[0] == 0) {
						m_Massage_flag = 1;
						return getSceneState();
					}
					right(2);
					left(2);
				}
				else {
					right(1);
					left(1);
				}
			}
			if (m_Num[0] == 2) {
				if (m_Num[1] >= 6) {
					if (res::SaveData::save_data.clear.stage[1] == 0) {
						m_Massage_flag = 2;
						return getSceneState();
					}
					right(3);
					left(3);
				}
				else {
					right(2);
					left(2);
				}
			}
			if (m_Num[0] == 3) {
				if (m_Num[1] >= 9) {
					if (res::SaveData::save_data.clear.stage[2] == 0) {
						m_Massage_flag = 3;
						return getSceneState();
					}
					right(4);
					left(4);
				}
				else {
					right(3);
					left(3);
				}
			}

			if (m_Num[0] >= 4) {
				if (m_Num[1] >= 12) {
					if (res::SaveData::save_data.clear.stage[3] == 0) {
						m_Massage_flag = 4;
						return getSceneState();
					}
					right(5);
					left(5);
				}
				else {
					right(4);
					left(4);
				}
			}

			up(6);
			down(6);
			cancel();
			escape();
		}
		else {
			m_Massage_flag = 0;
			if (res::SaveData::save_data.clear.stage[0] == 0)firstStage();
		}
		m_Count++;
		return getSceneState();
	}

	void StageSelect::firstStage() {
		setWorld(0);
		setStage(-1);
		m_Is_select = true;
	}

	void StageSelect::select() {
		//Save_ Save;
		if (Key::Pad.checkInput(Key::KEY_TYPE::SHOT) == 1) {
			Sound::sound.playSE(res::SE::SELECT_OK);
			if (m_Massage_flag != 0) {
				res::SaveData::save_data.clear.stage[m_Massage_flag - 1] = 1;
				//Save.Game.out2();
				m_Massage_flag = 0;

			}
			else {
				//�^�C�g��BGM������Ă�����A�Đ����~�߂�
				Sound::sound.freez();
				setSceneState(SCENE_TYPE::GAME_MAIN);
			}
			m_Is_select = true;
			//mCount = 0;
			//mStage = 0;
			//mBullet_Kind = 0;
			resetCoolDown();

		}

	}

	void StageSelect::cancel() {
		if (Key::Pad.checkInput(Key::KEY_TYPE::BOM) == 1 || Key::Pad.checkInput(Key::KEY_TYPE::MENU) == 1) {
			Sound::sound.playSE(res::SE::SELECT_CANCEL);
			m_Count = 0;
			setSceneState(SCENE_TYPE::TITLE);//�^�C�g�����j���[�ɖ߂�
			resetCoolDown();
		}
	}


	void StageSelect::stageMenu(int stage, const char* prologue, const char* name0, const char* name1, const char* name2, const char* name3, const char* name4) {
		//ch.stageClear[0] = 10;
		const int PosX = 400;
		const int PosY = 250;
		const int PosYDist = 150;
		MenuText m_Title_gui[6] = {//�񎟑n��
				{ PosX, PosY + PosYDist * 0, *prologue },
				{ PosX, PosY + PosYDist * 1, *name0 },
				{ PosX, PosY + PosYDist * 2, *name1 },
				{ PosX, PosY + PosYDist * 3, *name2 },
				{ PosX, PosY + PosYDist * 4, *name3 },
				{ PosX, PosY + PosYDist * 5, *name4 },
		};
		const TCHAR* kind_name[6] = {
			prologue,
			name0,
			name1,
			name2,
			name3,
			name4,
		};
		const int stamp_addPosX = 420;
		const int select_addPosX = 40;
		if (m_Num[0] > stage) {
			if (0 == getHorizontal()) {
				if (res::SaveData::save_data.clear.bullet[stage][0] == 1) {
					lib::Graphics2D::drawRota(
						m_Title_gui[0].x - select_addPosX - stamp_addPosX,
						m_Title_gui[0].y + 20,
						1,
						0.0,
						res::MenuUIImage::menu_ui.icon.clearStamp,
						true
					);
				};

				lib::StringDX::draw(
					m_Title_gui[0].x - select_addPosX,
					m_Title_gui[0].y,
					kind_name[0],
					lib::StringDX::color(233, 233, 233),
					res::TextUIImage::text_ui.font[0]
				);

			}
			else {
				if (res::SaveData::save_data.clear.bullet[stage][0] == 1) {
					lib::Graphics2D::setBright(140, 160, 190);
					lib::Graphics2D::drawRota(
						m_Title_gui[0].x - stamp_addPosX,
						m_Title_gui[0].y + 20,
						1,
						0.0,
						res::MenuUIImage::menu_ui.icon.clearStamp,
						true
					);
					lib::Graphics2D::setBright(255, 255, 255);
				}

				lib::StringDX::draw(
					m_Title_gui[0].x,
					m_Title_gui[0].y,
					kind_name[0],
					lib::StringDX::color(120, 120, 120),
					res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]
				);
			}
			for (int i = 1; i <= 5; i++) { // ���j���[���ڂ�`��
				if (i == getHorizontal()) {
					if (res::SaveData::save_data.clear.bullet[stage][i] == 1) {
						lib::Graphics2D::drawRota(
							m_Title_gui[i].x - select_addPosX - stamp_addPosX,
							m_Title_gui[i].y + 20,
							1,
							0.0,
							res::MenuUIImage::menu_ui.icon.clearStamp,
							true
						);
					};

					lib::StringDX::draw(
						m_Title_gui[i].x - select_addPosX,
						m_Title_gui[i].y,
						kind_name[i],
						lib::StringDX::color(233, 233, 233),
						res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]
					);
				}
				else {
					if (res::SaveData::save_data.clear.bullet[stage][i] == 1) {
						lib::Graphics2D::setBright(140, 160, 190);
						lib::Graphics2D::drawRota(
							m_Title_gui[i].x - stamp_addPosX,
							m_Title_gui[i].y + 20,
							1,
							0.0,
							res::MenuUIImage::menu_ui.icon.clearStamp,
							true
						);
						lib::Graphics2D::setBright(255, 255, 255);
					};

					lib::StringDX::draw(
						m_Title_gui[i].x,
						m_Title_gui[i].y,
						kind_name[i],
						lib::StringDX::color(120, 120, 120),
						res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT]
					);
				}
			}
			setWorld(stage);
			setStage(getHorizontal() - 1);
		}
		else {
			lib::StringDX::draw(
				m_Title_gui[0].x - 20 * 2,
				m_Title_gui[0].y,
				kind_name[0],
				lib::StringDX::color(233, 233, 233),
				res::TextUIImage::text_ui.font[0]
			);
			setWorld(stage);
			setStage(-1);
		}
	}

	void StageSelect::setWorld(int num) {
		m_Stage = num;
	}
	void StageSelect::setStage(int num) {
		m_Bullet_type = num;
	}

	int StageSelect::getWorld() {
		return m_Stage;
	}
	int StageSelect::getStage() {
		return m_Bullet_type;
	}
	bool StageSelect::isSelected() {
		if (m_Is_select) {
			m_Is_select = false;
			return true;
		}
		return false;
	}
	StageSelect::StageSelect():
		m_Num{ 0,0 } ,
		m_Massage_flag(0), 
		m_Count(0),
		m_Stage(0),
		m_Bullet_type(0),
		m_Is_select(false)
	{
	}
	StageSelect::~StageSelect() {

	}
}