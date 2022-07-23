#include "SubTitle.h"
#include <string>
#include "../../Source/SystemProp/AreaProp.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/library/Graphics/String/StringDX.h"
#include "../../Source/Resource/GUI/GameUIImage/GameUIImage.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"
namespace app {
	void SubTitle::start(int stage) {
		m_Is_flag = true;
		m_Stage_num = stage;
		m_Count = 0;
		m_bright = 0;
	}
	void SubTitle::titleText() {
		if (m_Stage_num == 0) {
			drawText(
				0, "�C��邤�~�ς͉��y�Ƌ��ɖ�����",
				0, "���E�̐�{���X��353��"
			);
		}
		if (m_Stage_num == 1) {
			drawText(
				0, "�g�D�C���N���E�[��",
				0, "���v���O�ʂ�"
			);
		}
		if (m_Stage_num == 2) {
			drawText(
				0, "�s�v�c�ȋ��E",
				0, "�V���s�Q���r���[�l"
			);
		}
		if (m_Stage_num == 3) {
			drawText(
				0, "�����������͍����ɂ��炸",
				0, "�p�郉�{���g��"
			);
		}
		if (m_Stage_num == 4) {
			drawText(
				0, "�ق�A���E�͂���Ȃɍg��",
				0, "�p�郉�{���g���ŉʂ�"
			);
		}
		if (m_Stage_num == 5) {
			drawText(
				0, "���x�ڂ́w�͂��߂܂��āx",
				0, "���o���̂���X"
			);
		}
		if (m_Stage_num == 6) {
			drawText(
				0, "�O�����A�E�I�u�E�G�L�V�r�W����",
				0, "���"
			);
		}
		if (m_Stage_num == 7) {
			drawText(
				0, "�ޗ����ӂ��ċ�ɎU��",
				0, "�ꖳ���̓V��"
			);
		}
	}
	void SubTitle::draw() {
		if (!m_Is_flag)return;
		lib::Graphics2D::setBlend(lib::BLEND_MODE::ALPHA, m_bright);
		lib::Graphics2D::draw(
			0, 0,
			res::GameUIImage::game_ui.sub_title,
			true
		);
		titleText();
		lib::Graphics2D::setBlend(lib::BLEND_MODE::NONE, 0);
	}
	void SubTitle::update() {
		if (!m_Is_flag)return;
		const int grow_time = 90;
		//�ŏ���128�̊Ԓi�X���邭
		if (m_Count < grow_time)m_bright += 3;
		//�i�X�Â�
		if (m_Count > grow_time * 2)m_bright -= 3;
		//�l�␳
		if (m_bright > 255)m_bright = 255;
		if (m_bright < 0)m_bright = 0;
		//�I��
		if (m_Count > grow_time * 3) {
			m_Count = 0;
			m_bright = 0;
			m_Is_flag = false;
			return;
		}
		m_Count++;
	}
	void SubTitle::drawText(int x1, const char* title, int x2, const char* stage_name) {
		std::string title_text = title;
		std::string stage_text = stage_name;
		auto font1 = res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT];
		auto font2 = res::TextUIImage::text_ui.font[res::FONT::FONT_TITLE_NEWS];
		float title_x = AreaProp::min_x + (AreaProp::max_x - AreaProp::min_x) / 2 - lib::StringDX::getFontTextWidth(title_text.data(), title_text.length(), font1) / 2;
		float stage_x = AreaProp::max_x - 50 - lib::StringDX::getFontTextWidth(stage_text.data(), stage_text.length(), font2);
		lib::StringDX::draw(title_x + x1, 680, title, lib::StringDX::color(255, 200, 250), font1);
		lib::StringDX::draw(stage_x - x2, 780, stage_name, lib::StringDX::color(255, 255, 255), font2);
	}
	SubTitle::SubTitle() :
		m_Is_flag(false),
		m_Stage_num(0),
		m_bright(0),
		m_Count(0)
	{
	}
	SubTitle::~SubTitle() {

	}
}