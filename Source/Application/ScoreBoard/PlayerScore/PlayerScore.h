#pragma once
namespace obj {
	class Player;
}
namespace app {
	class PlayerScore {
	private:
		static float m_P_y[8];
	public:
		static void drawLevel(int diff);
		//プレイヤーのスコアを描画
		static void drawScore(obj::Player player, int ID_y1, int ID_y2);
		//プレイヤーの残機や欠片の数を描画
		static void drawLife(obj::Player player, int ID_y);
		//プレイヤーのボムや欠片の数を描画
		static void drawBom(obj::Player player, int ID_y);
		//プレイヤーのパワー値を描画
		static void drawPower(obj::Player player, int ID_y);
		//プレイヤーのポイント数を描画
		static void drawPoint(obj::Player player, int ID_y);
		//プレイヤーのグレイズ数を描画
		static void drawGraze(obj::Player player, int ID_y);
		//プレイヤーのオプションを描画
		static void drawOption(obj::Player player, int ID_y);
		//プレイヤーのリンゴ数を描画(零刻のメーティオで使用)
		static void drawApple(obj::Player player);

		static void drawCamp(obj::Player player);
		//プレイヤーのクラッシュゲージを描画(At作品で使用)
		static void drawCrush(obj::Player player);
	};
}