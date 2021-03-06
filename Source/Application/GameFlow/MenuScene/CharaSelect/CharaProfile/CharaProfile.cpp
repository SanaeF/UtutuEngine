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
		m_Img->summon(m_Type, m_Fade_x, 800, 1.f, 0.f);
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
		auto col = lib::StringDX::color(255, 255, 255);
		auto font = res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT];
		lib::StringDX::draw(260 + m_Fade_x, 300, "オプション", col, font);
		const float x = 260 + m_Fade_x;
		//	"あああああああああああああああああああ",<-文字数制限
		text(
			res::PLAYER_TYPE::EREMIRA,
			x,
			"【基本ショット】時計の針",
			"時計の針を正面に投げつける",
			"",//
			"【スキル】ルナティックカウンター",
			"回転させた針を狂気状態のモノに当てると",
			"ホーミング状態で跳ね返すことが出来る。",
			"",//
			"【狂気開放】零刻のフェアローレン",
			"全方位に時計の針を召喚し回転させて",
			"敵にダメージを与える。"
		);
		//	"あああああああああああああああああああ",<-文字数制限
		text(
			res::PLAYER_TYPE::MAI,
			x,
			"【基本ショット】",
			"",
			"",//
			"【スキル】",
			"",
			"",
			"",//
			"【狂気開放】",
			"",
			""
		);
		//	"あああああああああああああああああああ",<-文字数制限
		text(
			res::PLAYER_TYPE::MEGU,
			x,
			"【基本ショット】",
			"",
			"",//
			"【スキル】",
			"",
			"",
			"",//
			"【狂気開放】",
			"",
			""
		);
	}

	void CharaProfile::profileText() {
		auto col = lib::StringDX::color(255, 255, 255);
		auto font = res::TextUIImage::text_ui.font[res::FONT::FONT_SELECT];
		lib::StringDX::draw(m_Fade_x - 910, 300, "個人情報", col, font);
		const float x = m_Fade_x - 910;
		//	"あああああああああああああああああああ",<-文字数制限
		text(
			res::PLAYER_TYPE::EREMIRA,
			x,
			"【名前】江蓮宮 みら(Eremiya Mira)",
			"【誕生日】4月28日",
			"【好きな物】ブルーハワイ味の飲み物、",
			"ブラックペッパー味のポテトチップス",
			"【嫌いなもの】攻撃的な虫、ゲル状の物体",
			"、不潔な物",
			"【趣味】記憶が欠落しているため、不明。",
			"",
			"",
			""
		);
		//	"あああああああああああああああああああ",<-文字数制限
		text(
			res::PLAYER_TYPE::MAI,
			x,
			"【名前】苫小牧 まい(Tmakomai Mai)",
			"【誕生日】7月14日",
			"【好きな物】激辛料理、ゲーム",
			"人間関係、人のうわさ話",
			"【嫌いなもの】中学時代の一部同級生、",
			"トマト、梅干し",
			"【趣味】友達としゃべること、",
			"音楽を聴くこと、",
			"コンシューマーゲームで遊ぶこと、",
			"気になったモノを調べること、"
		);
		//	"あああああああああああああああああああ",<-文字数制限
		text(
			res::PLAYER_TYPE::MEGU,
			x,
			"【名前】八戸恵 めぐ(Hatomegumi Megu)",
			"【誕生日】4月10日",
			"【好きな物】",
			"",
			"【嫌いなもの】",
			"",
			"【趣味】",
			"",
			"",
			""
		);
	}

	void CharaProfile::text(
		int type,
		int x,
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
		const int standard_y = 425;
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
