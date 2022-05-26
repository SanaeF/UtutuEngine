#include "FacialEffectImage.h"
#include <iostream>
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#pragma warning(disable : 4996)
namespace res {
	FacialEffectImage FacialEffectImage::facial_eff;
	void FacialEffectImage::load() {
		facial_eff.accent[0] = lib::Graphics2D::load("./dat/image/CharaModel/FacialEffect/accent0.png");
		facial_eff.accent[1] = lib::Graphics2D::load("./dat/image/CharaModel/FacialEffect/accent1.png");
		facial_eff.happy[0] = lib::Graphics2D::load("./dat/image/CharaModel/FacialEffect/happy0.png");
		facial_eff.happy[1] = lib::Graphics2D::load("./dat/image/CharaModel/FacialEffect/happy1.png");
		facial_eff.sweat = lib::Graphics2D::load("./dat/image/CharaModel/FacialEffect/sweat.png");
		facial_eff.black = lib::Graphics2D::load("./dat/image/CharaModel/FacialEffect/black.png");
		facial_eff.angry = lib::Graphics2D::load("./dat/image/CharaModel/FacialEffect/angry.png");
	}
}