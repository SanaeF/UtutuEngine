#include"EnemyImage.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
namespace res {
	EnemyImage EnemyImage::enemy;
	void EnemyImage::load() {
		lib::Graphics2D::loadSplit("./dat/image/Enemy/Boss01/0.png", 4, 2, 2, 128, 200, enemy.boss[BOSS_TYPE::N01_MATUMI]);
		lib::Graphics2D::loadSplit("./dat/image/Enemy/Boss02/0.png", 4, 2, 2, 128, 200, enemy.boss[BOSS_TYPE::N02_EREMIRA]);
		lib::Graphics2D::loadSplit("./dat/image/Enemy/Boss03/0.png", 4, 2, 2, 128, 200, enemy.boss[BOSS_TYPE::N03_ALICE]);
		lib::Graphics2D::loadSplit("./dat/image/Enemy/Boss03/1.png", 4, 2, 2, 128, 200, enemy.boss[BOSS_TYPE::N03_EREMIRA]);
		lib::Graphics2D::loadSplit("./dat/image/Enemy/Boss03/2.png", 4, 2, 2, 128, 200, enemy.boss[BOSS_TYPE::N03_MATUMI]);
		lib::Graphics2D::loadSplit("./dat/image/Enemy/Boss04/0.png", 8, 4, 2, 128, 200, enemy.boss[BOSS_TYPE::N04_NARSIRU]);
		lib::Graphics2D::loadSplit("./dat/image/Enemy/Boss05/1.png", 4, 2, 2, 128, 200, enemy.boss[BOSS_TYPE::N05_BLACK]);
		lib::Graphics2D::loadSplit("./dat/image/Enemy/Boss05/0.png", 4, 2, 2, 128, 200, enemy.boss[BOSS_TYPE::N05_FEATORIA]);
		lib::Graphics2D::loadSplit("./dat/image/Enemy/Boss06/0.png", 4, 2, 2, 128, 200, enemy.boss[BOSS_TYPE::N06_SHIENA]);
		lib::Graphics2D::loadSplit("./dat/image/Enemy/Boss07/0.png", 1, 1, 1, 128, 200, enemy.boss[BOSS_TYPE::N07_ALICE]);
		lib::Graphics2D::loadSplit("./dat/image/Enemy/Boss07/1.png", 4, 2, 2, 128, 200, enemy.boss[BOSS_TYPE::N07_FEATORIA]);
		lib::Graphics2D::loadSplit("./dat/image/Enemy/Boss08/0.png", 4, 2, 2, 178, 225, enemy.boss[BOSS_TYPE::N08_KURO]);

		lib::Graphics2D::loadSplit("./dat/image/Enemy/Minion/WetDevYoung.png", 2, 2, 1, 112, 112, enemy.minion[DEV_NORMAL]);
		lib::Graphics2D::loadSplit("./dat/image/Enemy/Minion/WetDevMinakami.png", 3, 3, 1, 112, 112, enemy.minion[DEV_ORANGE]);
		lib::Graphics2D::loadSplit("./dat/image/Enemy/Minion/WetDevIsesaki.png", 3, 3, 1, 112, 112, enemy.minion[DEV_GREEN]);
		lib::Graphics2D::loadSplit("./dat/image/Enemy/Minion/WetDevHack.png", 2, 2, 1, 112, 112, enemy.minion[DEV_HACK]);
		lib::Graphics2D::loadSplit("./dat/image/Enemy/Minion/DevItemBalloon.png", 3, 3, 1, 112, 214, enemy.minion[DEV_ITEM_BALLOON]);
		lib::Graphics2D::loadSplit("./dat/image/Enemy/Minion/DevilBone.png", 1, 1, 1, 112, 112, enemy.minion[DEV_BONE]);
		lib::Graphics2D::loadSplit("./dat/image/Enemy/Minion/Lninyo.png", 6, 6, 1, 80, 80, enemy.minion[DEV_Lninyo]);
		lib::Graphics2D::loadSplit("./dat/image/Enemy/Minion/Feary.png", 2, 2, 1, 96, 96, enemy.minion[FIRE_FEARY]);
		lib::Graphics2D::loadSplit("./dat/image/Enemy/Minion/OnmyouBall.png", 1, 1, 1, 80, 80, enemy.minion[OBJ_ONMYOU]);
		lib::Graphics2D::loadSplit("./dat/image/Enemy/Minion/ShadowWing.png", 1, 1, 1, 600, 700, enemy.minion[OBJ_SHADOWWING]);

		lib::Graphics2D::loadSplit("./dat/image/Enemy/Minion/CardMatsu.png", 5, 5, 1, 152, 214, enemy.minion[TRAMP_MATSU]);
		lib::Graphics2D::loadSplit("./dat/image/Enemy/Minion/CardElemira.png", 5, 5, 1, 152, 214, enemy.minion[TRAMP_ELEMIRA]);
		lib::Graphics2D::loadSplit("./dat/image/Enemy/Minion/CardFeatoria.png", 5, 5, 1, 152, 214, enemy.minion[TRAMP_FEATORIA]);
	}
}