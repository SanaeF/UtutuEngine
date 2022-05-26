#pragma once

namespace res {
	struct TitleUI {
		int back;
		int main_chara;
		int text;
	};
	struct IconUI {
		int clearStamp;
	};
	class MenuUIImage {
	public:
		TitleUI title;
		IconUI icon;
		int achieve;
		int config[2];
		int help[5];
		int gray_box[5];
		int camp_select;
		int alice_select[5];
		int musicRoom;
		int dress_room;
		static void load();
		static MenuUIImage menu_ui;
	};
}