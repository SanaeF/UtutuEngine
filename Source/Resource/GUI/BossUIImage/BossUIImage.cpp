#include "BossUIImage.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
namespace res {
	BossUIImage BossUIImage::boss_ui;
	void BossUIImage::load() {
		boss_ui.hp = lib::Graphics2D::load("./dat/image/GUI/BossUI/hp_parameter.png");
		boss_ui.hp_back = lib::Graphics2D::load("./dat/image/GUI/BossUI/hp_Ring.png");
		boss_ui.bullet_num = lib::Graphics2D::load("./dat/image/GUI/BossUI/bulletNum.png");
		boss_ui.magic_ring = lib::Graphics2D::load("./dat/image/GUI/BossUI/MagicRing.png");
		boss_ui.serif_box = lib::Graphics2D::load("./dat/image/GUI/BossUI/SerifBox.png");
	}
}