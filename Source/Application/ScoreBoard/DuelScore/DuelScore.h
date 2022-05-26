#pragma once
namespace obj {
	class Player;
	class Boss;
}
namespace app {
	//対戦モード用のスコアボード
	class DuelScore {
	public:
		//デュエルスクリーン中のUI
		static void drawRoodModeUI(obj::Player player1, obj::Player player2);
		//直接対決中のUI
		static void drawBomModeUI(obj::Player player1, obj::Player player2);
		//スコアボードによるプレイヤーの位置をボス戦仕様にする。
		static void changeBossMode(obj::Player& player1, obj::Player& player2, int& bom_type, int& rayer);
		//スコアボードによるプレイヤーの位置を通常仕様にする。
		static void changeNormalMode(obj::Player& player1, obj::Player& player2, obj::Boss& boss);
	};
}