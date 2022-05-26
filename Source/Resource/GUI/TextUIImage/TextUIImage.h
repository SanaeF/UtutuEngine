#pragma once

namespace res {
	enum {
		START_CALL_TEXT,
		START_TEXT,
		FINISH_TEXT,
		WIN_TEXT,
		LOSE_TEXT
	};
	enum FONT {
		FONT_MINI_LORE,
		FONT_SELECT,//セレクト画面用フォント
		FONT_TITLE_NEWS,//タイトル画面のお知らせ用フォント
		FONT_LORE,
		FONT_SB_SOUND,//スコアボードのサウンドタイトル用フォント
		FONT_SB_BOUNS_SCORE,
		FONT_SB_BOUNS_CALL,
		FONT_SB_ROULETTE,
		FONT_SERIF,
		FONT_SERIF_BULLET,
		FONT_MAX
	};
	class TextUIImage {
	public:
		int number[2][10];
		int fight_massage[8];
		int font[FONT::FONT_MAX];
		static void load();
		static TextUIImage text_ui;
	};
}