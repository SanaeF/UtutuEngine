#include "SelectUIImage.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
namespace res {
	SelectUIImage SelectUIImage::select_ui;
	void SelectUIImage::load() {
		select_ui.chara[0] = lib::Graphics2D::load("./dat/image/GUI/SelectIcon/Chara/0.png");
		select_ui.chara[1] = lib::Graphics2D::load("./dat/image/GUI/SelectIcon/Chara/1.png");

		select_ui.frame[0] = lib::Graphics2D::load("./dat/image/GUI/SelectIcon/Chara/f0.png");
		select_ui.frame[1] = lib::Graphics2D::load("./dat/image/GUI/SelectIcon/Chara/f1.png");
		select_ui.frame[2] = lib::Graphics2D::load("./dat/image/GUI/SelectIcon/Chara/f2.png");
		select_ui.frame[3] = lib::Graphics2D::load("./dat/image/GUI/SelectIcon/Chara/f3.png");
		select_ui.frame[4] = lib::Graphics2D::load("./dat/image/GUI/SelectIcon/Chara/f4.png");
		select_ui.frame[5] = lib::Graphics2D::load("./dat/image/GUI/SelectIcon/Chara/f5.png");

		select_ui.difficulty[0] = lib::Graphics2D::load("./dat/image/GUI/SelectIcon/Difficulty/0.png");
		select_ui.difficulty[1] = lib::Graphics2D::load("./dat/image/GUI/SelectIcon/Difficulty/1.png");
		select_ui.difficulty[2] = lib::Graphics2D::load("./dat/image/GUI/SelectIcon/Difficulty/2.png");

		select_ui.multCharaIcon[0] = lib::Graphics2D::load("./dat/image/GUI/SelectIcon/CharaForMult/0.png");
		select_ui.multCharaIcon[1] = lib::Graphics2D::load("./dat/image/GUI/SelectIcon/CharaForMult/1.png");
		select_ui.multCharaIcon[2] = lib::Graphics2D::load("./dat/image/GUI/SelectIcon/CharaForMult/2.png");
		select_ui.multCharaIcon[3] = lib::Graphics2D::load("./dat/image/GUI/SelectIcon/CharaForMult/3.png");
		select_ui.multCharaIcon[4] = lib::Graphics2D::load("./dat/image/GUI/SelectIcon/CharaForMult/4.png");
		select_ui.multCharaIcon[5] = lib::Graphics2D::load("./dat/image/GUI/SelectIcon/CharaForMult/5.png");
		select_ui.multCharaIcon[6] = lib::Graphics2D::load("./dat/image/GUI/SelectIcon/CharaForMult/6.png");
	}
}