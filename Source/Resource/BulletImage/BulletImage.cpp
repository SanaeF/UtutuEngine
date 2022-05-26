#include "BulletImage.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
namespace res {
	BulletImage BulletImage::Bullet;
	void BulletImage::load() {
		lib::Graphics2D::loadSplit("./dat/image/bullet/shot/Normal.png", 10, 10, 1, 48, 48, Bullet.shot[BULLET_TYPE::NORMAL]);
		lib::Graphics2D::loadSplit("./dat/image/bullet/shot/Scaly.png", 10, 10, 1, 32, 48, Bullet.shot[BULLET_TYPE::SCALY]);
		lib::Graphics2D::loadSplit("./dat/image/bullet/shot/Overlap.png", 10, 10, 1, 48, 48, Bullet.shot[BULLET_TYPE::OVERLAP]);
		lib::Graphics2D::loadSplit("./dat/image/bullet/shot/Rice.png", 10, 10, 1, 48, 48, Bullet.shot[BULLET_TYPE::RICE]);
		lib::Graphics2D::loadSplit("./dat/image/bullet/shot/Poiful.png", 10, 10, 1, 50, 114, Bullet.shot[BULLET_TYPE::POIFUL]);
		lib::Graphics2D::loadSplit("./dat/image/bullet/shot/BigStar.png", 10, 10, 1, 102, 102, Bullet.shot[BULLET_TYPE::BIG_STAR]);
		lib::Graphics2D::loadSplit("./dat/image/bullet/shot/Dust.png", 10, 10, 1, 32, 32, Bullet.shot[BULLET_TYPE::DUST]);
		lib::Graphics2D::loadSplit("./dat/image/bullet/shot/Big.png", 10, 10, 1, 90, 92, Bullet.shot[BULLET_TYPE::BIG]);
		lib::Graphics2D::loadSplit("./dat/image/bullet/shot/Mega.png", 10, 10, 1, 160, 160, Bullet.shot[BULLET_TYPE::MEGA]);
		lib::Graphics2D::loadSplit("./dat/image/bullet/shot/Ammo.png", 10, 10, 1, 48, 48, Bullet.shot[BULLET_TYPE::AMMO]);
		lib::Graphics2D::loadSplit("./dat/image/bullet/shot/MiniStar.png", 10, 10, 1, 32, 32, Bullet.shot[BULLET_TYPE::MINI_STAR]);
		lib::Graphics2D::loadSplit("./dat/image/bullet/shot/Bone.png", 10, 10, 1, 48, 48, Bullet.shot[BULLET_TYPE::BONE]);
		lib::Graphics2D::loadSplit("./dat/image/bullet/shot/Petal.png", 10, 10, 1, 32, 48, Bullet.shot[BULLET_TYPE::PETAL]);
		lib::Graphics2D::loadSplit("./dat/image/bullet/shot/Bfly.png", 10, 10, 1, 84, 84, Bullet.shot[BULLET_TYPE::B_FLY]);
		lib::Graphics2D::loadSplit("./dat/image/bullet/shot/Tramp.png", 10, 10, 1, 48, 48, Bullet.shot[BULLET_TYPE::TRAMP]);
		lib::Graphics2D::loadSplit("./dat/image/bullet/lazer/Normal.png", 10, 10, 1, 50, 114, Bullet.shot[BULLET_TYPE::LAZER]);
		lib::Graphics2D::loadSplit("./dat/image/bullet/lazer/Clock.png", 10, 10, 1, 70, 384, Bullet.shot[BULLET_TYPE::CLOCK_LAZ]);
		lib::Graphics2D::loadSplit("./dat/image/bullet/lazer/ExHand.png", 2, 2, 1, 320, 640, Bullet.shot[BULLET_TYPE::EX_HAND]);
		lib::Graphics2D::loadSplit("./dat/image/bullet/lazer/ExMeta.png", 6, 6, 1, 106, 384, Bullet.shot[BULLET_TYPE::EX_META]);
		lib::Graphics2D::loadSplit("./dat/image/bullet/special/TurnLazer.png", 11, 11, 1, 48, 48, Bullet.shot[BULLET_TYPE::TURN_LAZ]);
		lib::Graphics2D::loadSplit("./dat/image/bullet/special/Moon.png", 1, 1, 1, 128, 128, Bullet.shot[BULLET_TYPE::MOON]);
		lib::Graphics2D::loadSplit("./dat/image/bullet/special/Apple.png", 1, 1, 1, 96, 96, Bullet.shot[BULLET_TYPE::FAKE_APPLE]);
		lib::Graphics2D::loadSplit("./dat/image/bullet/special/Excalibur.png", 2, 2, 1, 320, 640, Bullet.shot[BULLET_TYPE::EXCALIBUR]);
		lib::Graphics2D::loadSplit("./dat/image/bullet/special/Lock.png", 1, 1, 1, 320, 320, Bullet.shot[BULLET_TYPE::LOCK]);
		lib::Graphics2D::loadSplit("./dat/image/bullet/special/StartEffect.png", 1, 1, 1, 96, 96, Bullet.shot[BULLET_TYPE::EFFECT]);
		lib::Graphics2D::loadSplit("./dat/image/bullet/player_shot/ChargeEffect.png", 2, 2, 1, 64, 64, Bullet.charge_effect);
		Bullet.player_shot[PLAYER_SHOT_TYPE::SHOT_BLUE] = lib::Graphics2D::load("./dat/image/bullet/player_shot/ShotBlue.png");
		Bullet.player_shot[PLAYER_SHOT_TYPE::SHOT_CYAN] = lib::Graphics2D::load("./dat/image/bullet/player_shot/ShotCyan.png");
		Bullet.player_shot[PLAYER_SHOT_TYPE::SHOT_POTATO] = lib::Graphics2D::load("./dat/image/bullet/player_shot/ShotPotato.png");
		Bullet.player_shot[PLAYER_SHOT_TYPE::SHOT_COMET] = lib::Graphics2D::load("./dat/image/bullet/player_shot/ShotComet.png");
		Bullet.player_shot[PLAYER_SHOT_TYPE::SHOT_METEO] = lib::Graphics2D::load("./dat/image/bullet/player_shot/ShotMeteo.png");
		Bullet.player_shot[PLAYER_SHOT_TYPE::SHOT_BIRD] = lib::Graphics2D::load("./dat/image/bullet/player_shot/ShotBird.png");
		Bullet.player_shot[PLAYER_SHOT_TYPE::SHOT_MOON] = lib::Graphics2D::load("./dat/image/bullet/player_shot/ShotMoon.png");
		Bullet.player_shot[PLAYER_SHOT_TYPE::LAZ_RED] = lib::Graphics2D::load("./dat/image/bullet/player_shot/LazRed.png");
		Bullet.player_shot[PLAYER_SHOT_TYPE::LAZ_BLUE] = lib::Graphics2D::load("./dat/image/bullet/player_shot/LazBlue.png");
		Bullet.player_shot[PLAYER_SHOT_TYPE::LAZ_THUNDER] = lib::Graphics2D::load("./dat/image/bullet/player_shot/LazThunder.png");
		Bullet.player_shot[PLAYER_SHOT_TYPE::BOM_LAZER] = lib::Graphics2D::load("./dat/image/bullet/player_shot/BomLazer.png");
		Bullet.player_shot[PLAYER_SHOT_TYPE::BOM_MOON] = lib::Graphics2D::load("./dat/image/bullet/player_shot/BomMoon.png");
		Bullet.player_shot[PLAYER_SHOT_TYPE::ONMYOU] = lib::Graphics2D::load("./dat/image/bullet/player_shot/Onmyou.png");
	}
}