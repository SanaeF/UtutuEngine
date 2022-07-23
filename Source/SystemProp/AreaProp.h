#pragma once
//ゲーム枠内のオブジェクトの制限と初期位置
class AreaProp {
private:
	struct ResizeAreaProp {
		int min_x;//フレーム横幅の最小座標
		int max_x;//フレーム横幅の最大座標
		int min_y;//フレーム高さの最小座標
		int max_y;//フレーム高さの最大座標
	};
public:
	static const int frame_width = 1200;//横幅
	static const int frame_hight = 1400;//高さ

	static const int min_x = (2560 / 2) - (frame_width / 2);//フレーム横幅の最小座標
	static const int max_x = (2560 / 2) + (frame_width / 2);//フレーム横幅の最大座標
	static const int min_y = (1440 / 2) - (frame_hight / 2);//フレーム高さの最小座標
	static const int max_y = (1440 / 2) + (frame_hight / 2);//フレーム高さの最大座標

	static const int def_player_x = (max_x - min_x) / 2;
	static const int def_player_y = max_y * 3 / 4;

	static const int deff_boss_x = (max_x - min_x) / 2;
	static const int deff_boss_y = 450;

	static const int p1_min_x = 30;
	static const int p1_max_x = 946;
	static const int p2_min_x = 974;
	static const int p2_max_x = 1890;

	static ResizeAreaProp resizeFrame(float size_w, float size_h) {
		ResizeAreaProp result;
		result.min_x = (2560 / 2) - (size_w / 2);//フレーム横幅の最小座標
		result.max_x = (2560 / 2) + (size_w / 2);//フレーム横幅の最大座標
		result.min_y = (1440 / 2) - (size_h / 2);//フレーム高さの最小座標
		result.max_y = (1440 / 2) + (size_h / 2);//フレーム高さの最大座標
		return result;
	}
};