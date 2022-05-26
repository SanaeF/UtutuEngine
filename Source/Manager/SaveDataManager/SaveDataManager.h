#pragma once

namespace app {
	class SaveDataManager {
	private:
		struct ConfigData {
			bool flag;
			int vol_bgm;
			int vol_se;
			int win_size_type;
			int key[16];
			void initialize() {
				flag = false;
				vol_bgm = false;
				vol_se = false;
				win_size_type = false;
				for (int i = 0; i < 16; i++)key[i] = false;
			}
		};
	public:
		//セーブデータ(ゲームデータ)の読み込み
		void in_game();
		//セーブデータ(ゲームデータ)の書き出し
		void out_game();
		//セーブデータ(設定)の読み込み
		void in_config();
		//セーブデータ(設定)の書き出し
		void out_config();
		//セーブデータ(カスタム武器)の読み込み
		static void in_weapon();
		//セーブデータ(カスタム武器)の読み込み
		static void out_weapon();
	};
}