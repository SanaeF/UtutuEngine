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
		lib::StringDX::draw(x, y, "ƒIƒvƒVƒ‡ƒ“", col, font);
		//	"‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ",<-•¶Žš”§ŒÀ
		text(
			res::PLAYER_TYPE::EREMIRA,
			x,
			y,
			"yŠî–{ƒVƒ‡ƒbƒgzŽžŒv‚Ìj",
			"ŽžŒv‚Ìj‚ð³–Ê‚É“Š‚°‚Â‚¯‚é",
			"",//
			"yƒXƒLƒ‹zƒ‹ƒiƒeƒBƒbƒNƒJƒEƒ“ƒ^[",
			"‰ñ“]‚³‚¹‚½j‚ð‹¶‹Có‘Ô‚Ìƒ‚ƒm‚É“–‚Ä‚é‚Æ",
			"ƒz[ƒ~ƒ“ƒOó‘Ô‚Å’µ‚Ë•Ô‚·‚±‚Æ‚ªo—ˆ‚éB",
			"",//
			"y‹¶‹CŠJ•úz—ë‚ÌƒtƒFƒAƒ[ƒŒƒ“",
			"‘S•ûˆÊ‚ÉŽžŒv‚Ìj‚ð¢Š«‚µ‰ñ“]‚³‚¹‚Ä",
			"“G‚Éƒ_ƒ[ƒW‚ð—^‚¦‚éB"
		);
		//	"‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ",<-•¶Žš”§ŒÀ
		text(
			res::PLAYER_TYPE::MAI,
			x,
			y,
			"yŠî–{ƒVƒ‡ƒbƒgz",
			"",
			"",//
			"yƒXƒLƒ‹z",
			"",
			"",
			"",//
			"y‹¶‹CŠJ•úz",
			"",
			""
		);
		//	"‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ",<-•¶Žš”§ŒÀ
		text(
			res::PLAYER_TYPE::MEGU,
			x,
			y,
			"yŠî–{ƒVƒ‡ƒbƒgz",
			"",
			"",//
			"yƒXƒLƒ‹z",
			"",
			"",
			"",//
			"y‹¶‹CŠJ•úz",
			"",
			""
		);
	}

	void CharaProfile::profileText() {
		const float x = m_Fade_x - 1092;
		const float y = 718;
		auto col = lib::StringDX::color(255, 255, 255);
		auto font = res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT];
		lib::StringDX::draw(x, y, "ŒÂlî•ñ", col, font);
		//	"‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ",<-•¶Žš”§ŒÀ
		text(
			res::PLAYER_TYPE::EREMIRA,
			x,
			y,
			"y–¼‘Oz]˜@‹{ ‚Ý‚ç(Eremiya Mira)",
			"y’a¶“úz4ŒŽ28“ú",
			"yD‚«‚È•¨zƒuƒ‹[ƒnƒƒC–¡‚Ìˆù‚Ý•¨A",
			"ƒuƒ‰ƒbƒNƒyƒbƒp[–¡‚Ìƒ|ƒeƒgƒ`ƒbƒvƒX",
			"yŒ™‚¢‚È‚à‚ÌzUŒ‚“I‚È’ŽAƒQƒ‹ó‚Ì•¨‘Ì",
			"A•sŒ‰‚È•¨",
			"yŽï–¡z‹L‰¯‚ªŒ‡—Ž‚µ‚Ä‚¢‚é‚½‚ßA•s–¾B",
			"",
			"",
			""
		);
		//	"‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ",<-•¶Žš”§ŒÀ
		text(
			res::PLAYER_TYPE::MAI,
			x,
			y,
			"y–¼‘Oz“Ï¬–q ‚Ü‚¢(Tmakomai Mai)",
			"y’a¶“úz7ŒŽ14“ú",
			"yD‚«‚È•¨zŒƒh—¿—AƒQ[ƒ€",
			"lŠÔŠÖŒWAl‚Ì‚¤‚í‚³˜b",
			"yŒ™‚¢‚È‚à‚Ìz’†ŠwŽž‘ã‚Ìˆê•”“¯‹‰¶A",
			"ƒgƒ}ƒgA”~Š±‚µ",
			"yŽï–¡z—F’B‚Æ‚µ‚á‚×‚é‚±‚ÆA",
			"‰¹Šy‚ð’®‚­‚±‚ÆA",
			"ƒRƒ“ƒVƒ…[ƒ}[ƒQ[ƒ€‚Å—V‚Ô‚±‚ÆA",
			"‹C‚É‚È‚Á‚½ƒ‚ƒm‚ð’²‚×‚é‚±‚ÆA"
		);
		//	"‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ",<-•¶Žš”§ŒÀ
		text(
			res::PLAYER_TYPE::MEGU,
			x,
			y,
			"y–¼‘Oz”ªŒËŒb ‚ß‚®(Hatomegumi Megu)",
			"y’a¶“úz4ŒŽ10“ú",
			"yD‚«‚È•¨z",
			"",
			"yŒ™‚¢‚È‚à‚Ìz",
			"",
			"yŽï–¡z",
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
