#include "ClothText.h"
#include"../../Source/library/Graphics/String/StringDX.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"
#include "../../Source/Resource/SaveData/SaveData.h"
namespace text {
	void ClothText::drawText(int chara_type, int outer_type, int under_type) {
		if (res::SaveData::save_data.chara_custom[chara_type].unlocked_outer_wear[outer_type])
			outerWearText(chara_type, outer_type);
		else unlockOuterText(outer_type);
		if (res::SaveData::save_data.chara_custom[chara_type].unlocked_under_wear[under_type])
			underWearText(under_type);
		else unlockUnderText(under_type);
	}
	void ClothText::unlockOuterText(int type) {
		if (type == 0)outerWearText(
			"�������:",
			"�ŏ����炠���B",
			"���Ă��A���ꌩ�Ă邠�Ȃ��͊J���ҁH",
			"",
			""
		);
		if (type == 1)outerWearText(
			"�������:",
			"���q��5�ʂ��N���A����",
			"",
			"",
			""
		);
		if (type == 2)outerWearText(
			"�������:",
			"�݂��Ƃ�5�ʂ��N���A����",
			"",
			"",
			""
		);
		if (type == 3)outerWearText(
			"�������:",
			"�A���X���[�h7�ʂ��N���A����",
			"",
			"",
			""
		);
		if (type == 4)outerWearText(
			"�������:",
			"�X�g�[���[���N���A����",
			"",
			"",
			""
		);
		if (type == 5)outerWearText(
			"�������:",
			"�G�L�X�g�����N���A����",
			"",
			"",
			""
		);
	}
	void ClothText::unlockUnderText(int type) {
		if (type == 0)underWearText(
			"�������:",
			"�ŏ����炠��",
			"�����`�o�O��o�O��",
			"",
			""
		);
		if (type == 1)underWearText(
			"�������:",
			"�X�e�[�W2���c�@4�ȏ�ŃN���A����",
			"",
			"",
			""
		);
		if (type == 2)underWearText(
			"�������:",
			"�A���X���[�h�����x��10�ȏ��6�ʂ��N���A����",
			"",
			"",
			""
		);
		if (type == 3)underWearText(
			"�������:",
			"�m�[�}���ȏ���N���A����",
			"",
			"",
			""
		);
		if (type == 4)underWearText(
			"�������:",
			"�A���X���[�h�̃��x��50�ȏ��6�ʂ��N���A����",
			"",
			"",
			""
		);
		if (type == 5)underWearText(
			"�������:",
			"�ǂ̃X�e�[�W�ł��ǂ��̂�",
			"�c�@0�̏�ԂŃN���A����",
			"(���K���[�h�͏���)",
			""
		);
	}
	void ClothText::outerWearText(int chara_type, int wear_type) {
		if (chara_type == 0) {//���T
			if (wear_type == 0)outerWearText(
				"���T���������Ɉ��p���Ă��镞�B",
				"�ʂ��Ă���w�Z�Ŏw�肳��Ă��鍮�F��",
				"�u���U�[�^�C�v�̐����ł���B",
				"���Ȃ݂ɁA�ԃ��{����1�N���炵���B",
				"�@�\: �z�[�~���O�߃I�v�V�������t��"
			);
			if (wear_type == 1)outerWearText(
				"�������đ�l�C(���Д�)�Z�[���[��!",
				"��35�� �|���G�X�e��65���Ƃ����A",
				"���S�n���ǂ��Z�[���[���炵���B",
				"���킢���B",
				"�@�\: �`���[�W�I�v�V�������t��"
			);
			if (wear_type == 2)outerWearText(
				"�w�Z�w��̐����V���c��",
				"�ォ��Z�[�^�[�ł���B",
				"�u�݂��Ɓv�Ɠ����R�[�f�ɂ��Ă݂���I",
				"���킢���I",
				"�@�\: �p��&���[�U�[�I�v�V�������t��"
			);
			if (wear_type == 3)outerWearText(
				"���p�������Ȃ���E�E�E",
				"�������i���Ă��镔��������B",
				"���H�G���Ȃ�(��)",
				"�����āA�����ȊO�킩��Ȃ��񂾂���I",
				"�@�\: �I�v�V�����������_���ŕt��"
			);
			if (wear_type == 4)outerWearText(
				"���̑�e�F�Ƃ�����I",
				"�V�G�i�����Ƃ̋L����",
				"�s�v�c�ƗN���オ���Ă���I",
				"�܂���Ă��ꂵ�������Ȃ��B",
				"�@�\: �z�[�~���O�߃I�v�V�������t��"
			);
			if (wear_type == 5)outerWearText(
				"�w�Z�w��̃R�[�g�ł��B",
				"�~�ł��������i�D�����Ă����̂ŁA",
				"����܂蒅���L�����Ȃ��Ȃ��B",
				"�悭�J���ł����ˁB���߂łƂ�",
				"�@�\: �L�͈̓R���b�g�I�v�V�������t��"
			);
		}
		if (chara_type == 1) {
			if (wear_type == 0)outerWearText(
				"�݂��Ƃ��ʂ��Ă���w�Z�̐����ł��B",
				"���������ӂ��w�Z��������ł��傤���H",
				"����͂Ƃ������A�ޏ��͂��Ȃ�D�G",
				"�Ȃ񂾂��Ă��B�z���g���Ȃ��`�H",
				"�t���˂��`�B�E�E�E�H"
			);
			if (wear_type == 1)outerWearText(
				"�݂��Ƃ悤�ɍ��ꂽ�Z�[���[���ł��B",
				"��35�� �|���G�X�e��65���������ł��B",
				"�ւ��`�A��邶���B",
				"���Ȃ݂ɁA�݂��Ƃ̓Z�[���[���𒅂�",
				"�����Ȃ��񂾂����ł��B"
			);
			if (wear_type == 2)outerWearText(
				"�L�����͂��̕��������Ă��܂���B",
				"",
				"",
				"",
				""
			);
			if (wear_type == 3)outerWearText(
				"�݂��Ƃ̎����E�E�E�H",
				"�����A�����̃o���h�̈ߑ�",
				"���Ǝv���܂��B",
				"���Ă��A���̎q�o���h����Ă���",
				"���b�N�ł��˂��`�B"
			);
			if (wear_type == 4)outerWearText(
				"�L�����͂��̕��������Ă��܂���B",
				"",
				"",
				"",
				""
			);
			if (wear_type == 5)outerWearText(
				"�L�����͂��̕��������Ă��܂���B",
				"",
				"",
				"",
				""
			);
		}
		if (chara_type == 2) {
			if (wear_type == 0)outerWearText(
				"�ԏ邪�w�Z�ŗ��Ă����Ǝv���鐧���B",
				"�����Ȃ��񂾂���A���Z����̐�����",
				"�؂����Ă��ƂȂ񂾂낤���H",
				"�N�A��w�����炢����ˁH",
				"�܂��������B���������B"
			);
			if (wear_type == 1)outerWearText(
				"�L�����͂��̕��������Ă��܂���B",
				"",
				"",
				"",
				""
			);
			if (wear_type == 2)outerWearText(
				"�L�����͂��̕��������Ă��܂���B",
				"",
				"",
				"",
				""
			);
			if (wear_type == 3)outerWearText(
				"�ԏ�̎����ł��B",
				"���ɉ����l�����ɊO�ɏo��Ƃ���",
				"�W���[�W�Ƀp�[�J�[���Ċ����ł��B",
				"���ɋC���g���ĂȂ����t�Ȋ����E�E�E�B",
				"�n�b�n!���J���D�`!(�N�H)"
			);
			if (wear_type == 4)outerWearText(
				"�Ԃ�����݂����ł��ˁB",
				"�����A���ꂾ���ł���H",
				"���ɐ[���Ӗ��͂���܂���B",
				"�����A�e�ߊ����킭�ł��傤�ˁB",
				"�h�b�y���Q���K�[��������|���B"
			);
			if (wear_type == 5)outerWearText(
				"�L�����͂��̕��������Ă��܂���B",
				"",
				"",
				"",
				""
			);
		}
		if (chara_type == 3) {
			if (wear_type == 0)outerWearText(
				"�Q���������݈̂��p���Ă��镞�B",
				"�㒅�͊w�Z�̐����ł͂Ȃ��炵�����A",
				"�Z�[���[���̂悤�ȊO�������Ă���B",
				"�Ƃ��銈���̈ߑ��������񂾂Ƃ��B",
				"�@�\: �ʏ�I�v�V����"
			);
			if (wear_type == 1)outerWearText(
				"�L�����͂��̕��������Ă��܂���B",
				"",
				"",
				"",
				""
			);
			if (wear_type == 2)outerWearText(
				"�ԏ�Ɠ��������ł��B",
				"�����Č�������u���U�[���",
				"�Z�[�^�[�𒅂Ă���炵���B",
				"�w�Z�ł̓u���U�[�����ɔ����Ă���B",
				"�@�\: �ʏ�I�v�V����"
			);
			if (wear_type == 3)outerWearText(
				"���܂蒅���Ȃ��Ȃ����t�Ȏ����B",
				"������Ȃ̂ŔN�������E�E�E",
				"�ł͂Ȃ��悤�ł��B�������ɁB",
				"���Ȃ݂ɁA�����ł�����Ȋ����B",
				"�@�\: �ʏ�I�v�V����"
			);
			if (wear_type == 4)outerWearText(
				"�L�����͂��̕��������Ă��܂���B",
				"",
				"",
				"",
				""
			);
			if (wear_type == 5)outerWearText(
				"�L�����͂��̕��������Ă��܂���B",
				"",
				"",
				"",
				""
			);
		}
		if (chara_type == 4) {
			if (wear_type == 0)outerWearText(
				"佌ς̕W���Z�[���[���ł��B",
				"�ʂɂ��̃R�A�w������Ȃ���ˁH",
				"�Ƃ������Ƃ̓R�X�v���p��",
				"�J���^���ȃZ�[���[���ł��B",
				"�@�\: �ʏ�I�v�V����"
			);
			if (wear_type == 1)outerWearText(
				"�L�����͂��̕��������Ă��܂���B",
				"",
				"",
				"",
				""
			);
			if (wear_type == 2)outerWearText(
				"�L�����͂��̕��������Ă��܂���B",
				"",
				"",
				"",
				""
			);
			if (wear_type == 3)outerWearText(
				"�����ł��B",
				"�T��`�b�N�ȕ����D���Ȃ񂾂Ƃ��B",
				"�Ƃ���ŁA��������̎p",
				"�Ȃ�ł��傤���H",
				"�@�\: �ʏ�I�v�V����"
			);
			if (wear_type == 4)outerWearText(
				"�L�����͂��̕��������Ă��܂���B",
				"",
				"",
				"",
				""
			);
			if (wear_type == 5)outerWearText(
				"���ɂ́A���C�N������",
				"���َq��������Ă��܂��B",
				"�����O�R�[�g�𒅂��Ƃ����",
				"�傫�ȐK���͉B���Ȃ��B",
				"�@�\: �ʏ�I�v�V����"
			);
		}
	}
	void ClothText::underWearText(int type) {
		if (type == 0)underWearText(
			"24���ԂЂ��̃v���[�c�X�J�[�g�B",
			"��ʓI�Ȗ��n�̃E�[��50%�|���G�X�e��50%�ł��B",
			"�ƂĂ��G��S�n���ǂ��炵���B",
			"���킢��(���킢��)",
			"�@�\: ���ɂȂ��B"
		);
		if (type == 1)underWearText(
			"24���ԂЂ��̃v���[�c�X�J�[�g(���C���t��)�B",
			"�������тɂӂ���Ɨh���",
			"�v���[�c�X�J�[�g�͏��̎q�炵�������Ղ�B",
			"�y�����Č����������Ƃ߂��ꂿ�Ⴄ�I(�����)",
			"�@�\: �G���痎����p���[�A�C�e���������B"
		);
		if (type == 2)underWearText(
			"�����鐴�^�n�̃v���[�c�X�J�[�g�B",
			"���������̂��āA�Ђ邪�����đ��肽���Ȃ�񂾂�˂��B",
			"��������ƕG�ӂ肪�������������炵���B",
			"�@�\: �e���̃{�[�i�X���l������ۂ�",
			"�c�@�̌��Ђ�1���Ƃ���������B"
		);
		if (type == 3)underWearText(
			"�w�Z�̑̑���(�Z�p��)�ł��B",
			"�T���߂Ɍ����ĒZ�p���͓����₷���B",
			"�X�|�[�c���\�ȁu�݂��Ɓv�Ə������^�O������B",
			"�@�\: �����蔻�肪������Ƃ����������Ȃ�B",
			""
		);
		if (type == 4)underWearText(
			"�Ԃ��{�b�N�X�X�J�[�g�ł��B",
			"�A���X���[�h��������x��肱�񂾏؁B", //�A���X���[�h����肱�񂾏�
			"�A���X���[�h�̍���Փx���x���Ȃ�",
			"�����z������悤�ȋ@�\�����Ă���B",
			"�@�\: Power��350��艺���Ȃ��Ȃ�B"
		);
		if (type == 5)underWearText(
			"����҂��悭����ނ���^�C�v�̃X�J�[�g",
			"�����̃v���[�c�͗����l���猩�č����������ʂ��B",
			"�܂�A���̎ԂЂ��X�J�[�g�̍��͊Ԉ���Ă���B",
			"�@�\: �L�����v��ݒu���邱�Ƃ͂ł��Ȃ����A",
			"�{�����g���ƃ����S�Q�[�W���}�b�N�X�ɂȂ�"
		);
	}
	void ClothText::outerWearText(
		const char* msg0,
		const char* msg1,
		const char* msg2,
		const char* msg3,
		const char* msg4
	) {
		int pos_x = 850;
		lib::StringDX::draw(pos_x, 425, msg0, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(pos_x, 475, msg1, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(pos_x, 525, msg2, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(pos_x, 575, msg3, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(pos_x, 625, msg4, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
	}
	void ClothText::underWearText(
		const char* msg0,
		const char* msg1,
		const char* msg2,
		const char* msg3,
		const char* msg4
	) {
		int pos_x = 850;
		lib::StringDX::draw(pos_x, 925, msg0, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(pos_x, 975, msg1, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(pos_x, 1025, msg2, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(pos_x, 1075, msg3, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
		lib::StringDX::draw(pos_x, 1125, msg4, lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_LORE]);
	}
}