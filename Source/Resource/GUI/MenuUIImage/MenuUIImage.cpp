#include"MenuUIImage.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
namespace res {
	MenuUIImage MenuUIImage::menu_ui;
	void MenuUIImage::load() {
		menu_ui.icon.clearStamp = lib::Graphics2D::load("./dat/image/GUI/SelectIcon/ClearStamp.png");
		menu_ui.title.back = lib::Graphics2D::load("./dat/image/GUI/Title/back.png");
		menu_ui.title.text = lib::Graphics2D::load("./dat/image/GUI/Title/text.png");
		menu_ui.title.main_chara = lib::Graphics2D::load("./dat/image/GUI/Title/main_chara.png");
		menu_ui.help[0] = lib::Graphics2D::load("./dat/image/GUI/HelpScene/0.png");
		menu_ui.help[1] = lib::Graphics2D::load("./dat/image/GUI/HelpScene/1.png");
		menu_ui.help[2] = lib::Graphics2D::load("./dat/image/GUI/HelpScene/2.png");
		menu_ui.help[3] = lib::Graphics2D::load("./dat/image/GUI/HelpScene/3.png");
		menu_ui.help[4] = lib::Graphics2D::load("./dat/image/GUI/HelpScene/4.png");
		menu_ui.gray_box[0] = lib::Graphics2D::load("./dat/image/GUI/Graybox/0.png");
		menu_ui.gray_box[1] = lib::Graphics2D::load("./dat/image/GUI/Graybox/1.png");
		menu_ui.gray_box[2] = lib::Graphics2D::load("./dat/image/GUI/Graybox/2.png");
		menu_ui.gray_box[3] = lib::Graphics2D::load("./dat/image/GUI/Graybox/3.png");
		menu_ui.gray_box[4] = lib::Graphics2D::load("./dat/image/GUI/Graybox/4.png");
		menu_ui.config[0] = lib::Graphics2D::load("./dat/image/GUI/ConfigScene/ConfigMenu.png");
		menu_ui.config[1] = lib::Graphics2D::load("./dat/image/GUI/ConfigScene/KeyConfig.png");
		menu_ui.musicRoom = lib::Graphics2D::load("./dat/image/GUI/Graybox/musicRoom.png");
		menu_ui.dress_room = lib::Graphics2D::load("./dat/image/GUI/Graybox/dress_room.png");
		menu_ui.achieve = lib::Graphics2D::load("./dat/image/GUI/Graybox/Achieve.png");
		menu_ui.camp_select = lib::Graphics2D::load("./dat/image/GUI/Graybox/CampSelect.png");
		menu_ui.alice_select[0]= lib::Graphics2D::load("./dat/image/GUI/Graybox/AliceSelect.png");
		menu_ui.alice_select[1] = lib::Graphics2D::load("./dat/image/GUI/Graybox/AliceSelect2.png");
		menu_ui.alice_select[2] = lib::Graphics2D::load("./dat/image/GUI/Graybox/AliceSelect3.png");
		menu_ui.alice_select[3] = lib::Graphics2D::load("./dat/image/GUI/Graybox/AliceSelect4.png");
		menu_ui.alice_select[4] = lib::Graphics2D::load("./dat/image/GUI/Graybox/WeaponSelect.png");
	}
}