#include"ParicleImage.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
namespace res {
	ParticleImage ParticleImage::effect;
	void ParticleImage::load() {
		lib::Graphics2D::loadSplit("./dat/image/Effect/Boss/kill.png", 5, 5, 1, 150, 150, effect.m_Boss.kill);
		lib::Graphics2D::loadSplit("./dat/image/Effect/Shot/kill.png", 10, 10, 1, 64, 64, effect.shot.kill);
		effect.m_Boss.charge = lib::Graphics2D::load("./dat/image/Effect/Boss/charge.png");
		effect.player.kill = lib::Graphics2D::load("./dat/image/Effect/Player/death.png");
	}
}