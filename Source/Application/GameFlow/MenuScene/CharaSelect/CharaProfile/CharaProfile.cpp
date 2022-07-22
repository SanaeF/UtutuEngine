#include "CharaProfile.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include"../../Source/library/Graphics/String/StringDX.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"
#include "../../Source/Manager/CharaImgManager/CharaImgManager.h"
#include "../../Source/Resource/GUI/SelectUIImage/SelectUIImage.h"
#include "../../Source/Resource/PlayerImage/PlayerImage.h"
namespace app {
	CharaProfile::CharaProfile():
		m_Type(0),
		m_Fade_x(0)
	{
		m_Img.reset(new CharaImgManager());
	}
	void CharaProfile::draw() {
		m_Img->draw();
		lib::Graphics2D::drawRota(m_Fade_x, 360 * 2, 1.0, 0.0, res::SelectUIImage::select_ui.chara[0], true);
		optionText();
		profileText();
	}
	void CharaProfile::update() {
		m_Img->setEyeState(EYE_STATE::BLINK);
		m_Img->setMouthState(MOUTH_STATE::MOUTH_CLOSE);
		m_Img->summon(m_Type, m_Fade_x, 1000, 1.f, 0.f);
		m_Img->draw();
		m_Img->update();
	}
	void CharaProfile::setType(int type) {
		m_Type = type;
	}
	void CharaProfile::setFadeX(float x) {
		m_Fade_x = x;
	}

	void CharaProfile::optionText() {
		const float x = 443 + m_Fade_x;
		const float y = 718;
		auto col = lib::StringDX::color(255, 255, 255);
		auto font = res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT];
		lib::StringDX::draw(x, y, "�I�v�V����", col, font);
		//	"��������������������������������������",<-����������
		text(
			res::PLAYER_TYPE::EREMIRA,
			x,
			y,
			"�y��{�V���b�g�z���v�̐j",
			"���v�̐j�𐳖ʂɓ�������",
			"",//
			"�y�X�L���z���i�e�B�b�N�J�E���^�[",
			"��]�������j�����C��Ԃ̃��m�ɓ��Ă��",
			"�z�[�~���O��ԂŒ��˕Ԃ����Ƃ��o����B",
			"",//
			"�y���C�J���z�덏�̃t�F�A���[����",
			"�S���ʂɎ��v�̐j����������]������",
			"�G�Ƀ_���[�W��^����B"
		);
		//	"��������������������������������������",<-����������
		text(
			res::PLAYER_TYPE::MAI,
			x,
			y,
			"�y��{�V���b�g�z",
			"",
			"",//
			"�y�X�L���z",
			"",
			"",
			"",//
			"�y���C�J���z",
			"",
			""
		);
		//	"��������������������������������������",<-����������
		text(
			res::PLAYER_TYPE::MEGU,
			x,
			y,
			"�y��{�V���b�g�z",
			"",
			"",//
			"�y�X�L���z",
			"",
			"",
			"",//
			"�y���C�J���z",
			"",
			""
		);
	}

	void CharaProfile::profileText() {
		const float x = m_Fade_x - 1092;
		const float y = 718;
		auto col = lib::StringDX::color(255, 255, 255);
		auto font = res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT];
		lib::StringDX::draw(x, y, "�l���", col, font);
		//	"��������������������������������������",<-����������
		text(
			res::PLAYER_TYPE::EREMIRA,
			x,
			y,
			"�y���O�z�]�@�{ �݂�(Eremiya Mira)",
			"�y�a�����z4��28��",
			"�y�D���ȕ��z�u���[�n���C���̈��ݕ��A",
			"�u���b�N�y�b�p�[���̃|�e�g�`�b�v�X",
			"�y�����Ȃ��́z�U���I�Ȓ��A�Q����̕���",
			"�A�s���ȕ�",
			"�y��z�L�����������Ă��邽�߁A�s���B",
			"",
			"",
			""
		);
		//	"��������������������������������������",<-����������
		text(
			res::PLAYER_TYPE::MAI,
			x,
			y,
			"�y���O�z�Ϗ��q �܂�(Tmakomai Mai)",
			"�y�a�����z7��14��",
			"�y�D���ȕ��z���h�����A�Q�[��",
			"�l�Ԋ֌W�A�l�̂��킳�b",
			"�y�����Ȃ��́z���w����̈ꕔ�������A",
			"�g�}�g�A�~����",
			"�y��z�F�B�Ƃ���ׂ邱�ƁA",
			"���y�𒮂����ƁA",
			"�R���V���[�}�[�Q�[���ŗV�Ԃ��ƁA",
			"�C�ɂȂ������m�𒲂ׂ邱�ƁA"
		);
		//	"��������������������������������������",<-����������
		text(
			res::PLAYER_TYPE::MEGU,
			x,
			y,
			"�y���O�z���ˌb �߂�(Hatomegumi Megu)",
			"�y�a�����z4��10��",
			"�y�D���ȕ��z",
			"",
			"�y�����Ȃ��́z",
			"",
			"�y��z",
			"",
			"",
			""
		);
	}

	void CharaProfile::text(
		int type,
		int x,
		int y,
		std::string text0,
		std::string text1,
		std::string text2,
		std::string text3,
		std::string text4,
		std::string text5,
		std::string text6,
		std::string text7,
		std::string text8,
		std::string text9
	) {
		if (m_Type != type)return;
		const int distance = 41;
		const int standard_y = y + 125;
		auto col = lib::StringDX::color(255, 255, 255);
		auto font = res::TextUIImage::text_ui.font[res::FONT::FONT_LORE];
		lib::StringDX::draw(x, standard_y + distance * 0, text0.c_str(), col, font);
		lib::StringDX::draw(x, standard_y + distance * 1, text1.c_str(), col, font);
		lib::StringDX::draw(x, standard_y + distance * 2, text2.c_str(), col, font);
		lib::StringDX::draw(x, standard_y + distance * 3, text3.c_str(), col, font);
		lib::StringDX::draw(x, standard_y + distance * 4, text4.c_str(), col, font);
		lib::StringDX::draw(x, standard_y + distance * 5, text5.c_str(), col, font);
		lib::StringDX::draw(x, standard_y + distance * 6, text6.c_str(), col, font);
		lib::StringDX::draw(x, standard_y + distance * 7, text7.c_str(), col, font);
		lib::StringDX::draw(x, standard_y + distance * 8, text8.c_str(), col, font);
		lib::StringDX::draw(x, standard_y + distance * 9, text9.c_str(), col, font);
	}
}
