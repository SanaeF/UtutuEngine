#include "Effect.h"

#include "../../Source/SystemProp/AreaProp.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include"../../Source/library/Graphics/String/StringDX.h"
#include "../../Source/Resource/ParticleImage/ParicleImage.h"

#include "../../Source/Helper/Helper.h"

namespace obj {
	void Effect::none() {
		setState(0);
		setType(0);
	}
	void Effect::drawPlayerDeath(Field field) {
		lib::Graphics2D::drawRota(getX() + field.m_Min_x, getY(), 0.1f + getCount() * 0.175f, getCount() * 0.175, res::ParticleImage::effect.player.kill, true);
		if (getCount() > 30) {
			setFlag(false);
			setState(0);
			setCount(0);
		}
		countUpdate();
	}
	void Effect::drawBossCrush(Field field) {
		if (getState() == 0) {
			setCount(0);
			setState(1);
			setSize(5);
			m_Bright = 190;
		}
		if (getState() == 1) {
			lib::Graphics2D::setBlend(lib::BLEND_MODE::ALPHA, m_Bright);
			lib::Graphics2D::drawRota(getX() + field.m_Min_x, getY(), getSize(), getCount() * PI / 2.f / 12.f, res::ParticleImage::effect.m_Boss.kill[0], true);
			lib::Graphics2D::setBlend(lib::BLEND_MODE::ALPHA, m_Bright);
			lib::Graphics2D::box(field.m_Min_x - 80, FMIN_Y - 80, field.m_Min_x + field.m_Max_x + 80, FMIN_Y + FMAX_Y + 80, lib::StringDX::color(173, 73, 119), true);
			lib::Graphics2D::setBlend(lib::BLEND_MODE::NONE, 0);
			setSize(getSize() + 0.3);
			if (BEDWEEN(getCount(), 10, 20)) m_Bright -= 150 / 10;
			if (getCount() == 20) {
				setState(2);
				setCount(0);
				setSize(0);
			}
		}
		if (getState() == 2) {
			lib::Graphics2D::setBlend(lib::BLEND_MODE::ALPHA, m_Bright);
			lib::Graphics2D::drawCircle(getX() + field.m_Min_x, getY(), getSize(), 64, lib::StringDX::color(255, 255, 255), true);
			lib::Graphics2D::setBlend(lib::BLEND_MODE::NONE, 0);
			setSize(getSize() + 2000.f / 30.f);
			if (getCount() > 30) {
				setFlag(false);
				setState(0);
				setCount(0);
			}
		}
		countUpdate();
	}
	void Effect::drawBossCharge(Field field) {
		double size = getSize();
		lib::Graphics2D::setBlend(lib::BLEND_MODE::ADD, 155);
		lib::Graphics2D::drawRota(getX() + field.m_Min_x, getY(), size, getCount() * 0.175f, res::ParticleImage::effect.m_Boss.charge, true);
		lib::Graphics2D::setBlend(lib::BLEND_MODE::NONE, 0);
		setSize(getSize() - (3.f / 30.f));
		if (getCount() > 30) {
			setState(0);
			setCount(0);
			setSize(0);
			setFlag(false);
		}
		countUpdate();
	}
	void Effect::drawShotKill(Field field) {
		if (getState() == 0) {
			setCount(0);
			setState(1);
			setSize(2);
			m_Bright = 190;
		}
		if (getState() == 1) {
			lib::Graphics2D::setBlend(lib::BLEND_MODE::ADD, 220);
			lib::Graphics2D::drawRota(getX() + field.m_Min_x, getY(), getSize(), getCount() * PI / 12.f, res::ParticleImage::effect.shot.kill[m_Shot_color], true);
			lib::Graphics2D::setBlend(lib::BLEND_MODE::NONE, 0);
			if (getSize() > 0)setSize(getSize() - 0.1);
			else {
				setFlag(false);
				setState(0);
				setCount(0);
			}
		}
		countUpdate();
	}
	void Effect::draw(Field field) {
		if (isType(BOSS_CRUSH))drawBossCrush(field);
		if (isType(BOSS_CHARGE))drawBossCharge(field);
		if (isType(SHOT_CLEAR))drawShotKill(field);
		if (isType(PLAYER_DEATH))drawPlayerDeath(field);
	}
	void Effect::update() {

	}
	void Effect::setColor(int color) {
		m_Shot_color = color;
	}
	void Effect::setAngle(float num) {
		m_Angle = num;
	}
	bool Effect::isType(int num) {
		if (getType() == num)return true;
		return false;
	}
}