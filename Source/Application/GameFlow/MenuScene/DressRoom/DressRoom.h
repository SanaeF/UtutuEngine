#pragma once
#include <memory>
#include "../../Source/Application/GameFlow/Scene/Scene.h"
#include "../../Source/Object/Player/Data/CharaCustom.h"
namespace app {
	class CharaImgManager;
	class DressRoom : public Scene {
	private:
		enum SELECT_TYPE {
			CHARA,
			OUTER_WEAR,
			SKIRT
		};
		char m_Locked_name[128] = "���J���̕��ł�";
		char m_No_name[128] = "�g�Ȃ�";
		char* m_Check_unlocked[2];
		//�̌��ł́A�W���A�����A�����O�R�[�g
		MenuText m_Outer_wear_name[6][5] = {//���T�A�݂��ƁA�ԏ�A�Q�A���q
			//���T�̂݁A�z�[�~���O�߃I�v�V�������t��
			{{ 0, 0, "�W��" },				{ 0, 1, "�W��" },		{ 0, 2, "�W��" },		{ 0, 3, "�W��" },				{ 0, 4, "�W��" }		},
			//���T�Ɛԏ�̂݁A�`���[�W�I�v�V�������t��
			{{ 1, 0, "�Z�[���[��" },		{ 1, 1, "�Z�[���[��" },	{ 1, 2, "�g�Ȃ�" },		{ 1, 3, "�g�Ȃ�" },				{ 1, 4, "�g�Ȃ�" }		},
			//���T�̂݁A���[�U�[�I�v�V�������t��
			{{ 2, 0, "�u���U�[&�Z�[�^�[" },	{ 2, 1, "�g�Ȃ�" },		{ 1, 2, "�g�Ȃ�" },		{ 2, 3, "�u���U�[&�Z�[�^�[" },	{ 2, 4, "�g�Ȃ�" }		},
			//���T�A�݂��ƂɃz�[�~���O�߃I�v�V�������t��
			{{ 3, 0, "����" },				{ 3, 1, "����" },		{ 3, 2, "����" },		{ 3, 3, "����" },				{ 3, 4, "����" }		},
			//���T�̂݁A�z�[�~���O�߃I�v�V�������t��
			{{ 4, 0, "�Ԃ�����" },			{ 4, 1, "�g�Ȃ�" },		{ 1, 2, "�Ԃ�����" },		{ 4, 3, "�g�Ȃ�" },				{ 4, 4, "�g�Ȃ�" }	},
			//���T�ƈ��ǂ̂݁A�z�[�~���O�߃I�v�V�������t��
			{{ 5, 0, "�����O�R�[�g" },		{ 5, 1, "�g�Ȃ�" },		{ 1, 2, "�g�Ȃ�" },		{ 5, 3, "�g�Ȃ�" },				{ 5, 4, "�����O�R�[�g" }},
		};
		MenuText m_Under_wear_name[6] = {
			//���ɂȂ�
			{ 0, 0, "�W��" },
			//�G���痎����p���[�A�C�e����������(+1�`5)//���T�̂�
			{ 2, 0, "�v���[�c�X�J�[�g(���C��)" },
			//�{�����g�킸�ɒe�����U������ƁA�c�@�̌��Ђ𗎂��B���̂����Ɏ����Ă���{���̌��Ђ����ׂď�������
			{ 3, 0, "�v���[�c�X�J�[�g(����)" },
			//��b�Η͂����������グ��//���T�̂�
			{ 4, 0, "�Z�p��" },
			//�ᑬ�łȂ��Ƃ��A�㉺�̈ړ��������Ȃ邪�A���˂��ꂽ�V���b�g�̈З͂����񂾂񉺂���
			{ 5, 0, "�Ԃ��X�J�[�g" },
			//�L�����v��ݒu���邱�Ƃ͂ł��Ȃ����A�{�����g���ƃA�C�e���o���[�����o�ꂷ��
			{ 6, 0, "�o�O�����v���[�c�X�J�[�g" },
		};
		SELECT_TYPE m_Select_type;
		std::shared_ptr<CharaImgManager>m_Img;
		int m_Select_num[5][2];
		int m_Chara_type;
		int m_Count;
	public:
		DressRoom();
		~DressRoom();
		int update()override;
		void draw()override;
		int getCharaType();
	private:
		void initialize();
		void outerText();
		void underText();
		void selectText();
		void select()override;
		void cancel()override;
		void unlock();
		void checkAndReset();
	};
}