#pragma once

namespace res {
	class SelectUIImage {
	public:
		int chara[2];
		int frame[6];
		int difficulty[4];
		int multCharaIcon[7];
		static void load();
		static SelectUIImage select_ui;
	};
}