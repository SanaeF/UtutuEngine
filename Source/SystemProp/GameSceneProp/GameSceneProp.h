#pragma once
class GameSceneProp {
public:
	static int stage;//現在のステージ
	static int difficulty;//ゲームの難易度(0～2)
	static int outer_wear;
	static int under_wear;
	static bool is_practice;//練習モードかどうか
	static bool is_alice;//アリスモードかどうか
	static bool is_extra;//エクストラモードかどうか
	static bool is_use_camp;//キャンプを使うかどうか
	static bool is_replay;//リプレイ中かどうか
	static void initialize();
};