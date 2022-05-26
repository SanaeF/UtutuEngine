#include "Boss.h"
#include <iostream>
#include "BossMotion/BossMotion.h"
#include "../../Source/SystemProp/AreaProp.h"
#include "../../Source/SystemProp/AliceProp/AliceProp.h"
#include "../../Source/Application/Sound/Sound.h"
#include "../../Source/Application/Replayer/Replayer.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/Script/Manager/BossScript/BossScript.h"
#include "../../Source/Script/Manager/BulletScript/Shot/ShotScript.h"
#include "../../Source/Script/Manager/BulletScript/Lazer/LazerScript.h"
#include "../../Source/Script/Manager/BulletScript/TurnLazer/TurnLazerScript.h"
#include "../../Source/Collider/Collider.h"
#include "../../Source/Manager/BulletManager/BulletManager.h"
#include "../../Source/Object/Effect/Effect.h"
#include "../../Source/Resource/EnemyImage/EnemyImage.h"
#include "../../Source/Resource/GUI/BossUIImage/BossUIImage.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"
#include "../../Source/Resource/SoundData/SoundData.h"
#include "../../Source/Tools/Transform/Transform.h"
#include "../../Source/EffectTools/Shake/Shake.h"
#include "../../Source/Helper/Helper.h"

namespace obj {
	void Boss::setFadeIN() {
		m_Fade_size.initialize();
		m_Fade_size.setParam(30);
	}
	void Boss::draw(double crush_x, double crush_y) {
		if (!isFlag())return;
		lib::Graphics2D::setBright(200 + m_Fade_size.getSize(55), m_Fade_size.getSize(255), 55 + m_Fade_size.getSize(200));
		//if (isFlag())drawMagicRing(crush_x, crush_y);
		float size = getSize();
		if (AliceProp::flag)size = size + AliceProp::add_size;
		lib::Graphics2D::drawRota(
			getX() + AREA::FMIN_X + crush_x,
			getY() + AREA::FMIN_Y + crush_y,
			m_Fade_size.getSize(size),
			m_Img_rotation,
			res::EnemyImage::enemy.boss[getType()][m_Img_state],
			true
		);
		lib::Graphics2D::setBright(255, 255, 255);
		Field field;
		field.m_Min_x = AREA::FMIN_X;
		field.m_Max_x = AREA::FMAX_X;
		if (m_KillEffect->isFlag())m_KillEffect->draw(field);
		if (m_ChargeEffect->isFlag()) {
			m_ChargeEffect->setX(getX());
			m_ChargeEffect->setY(getY());
			m_ChargeEffect->draw(field);
		}
	}
	
	void Boss::update() {
		if (!isFlag())return;
		m_Fade_size.update();
		BossMotion motion(getType(), m_Motion_type, m_Angle, m_Image_count);
		m_Img_state = motion.imgState();
		m_Img_rotation = motion.imgRotation();
		m_Image_count++;
		if (m_Transform->isMove())move();
		if (!m_Transform->isMove())m_Angle = 0.f;
		countUpdate();
	}

	void Boss::statsReset() {
		m_Img_state = 0;
		m_Motion_type = 0;
		m_Is_death_effect = false;
		setCount(0);
		BulletManager::getInstance()->clear(true);
	}
	void Boss::move() {
		m_Transform->update();
		if (m_Transform->isRight())m_Angle = PI / 18;
		if (m_Transform->isLeft())m_Angle = -PI / 18;
		setX(m_Transform->getMoved().x);
		setY(m_Transform->getMoved().y);
	}
	void Boss::setAnimationType(int type) {
		m_Motion_type = type;
	}
	void Boss::summonEffect(int type) {
		if (type == EFFECT_TYPE::DEAD) {
			if (m_Is_death_effect) {
				app::Sound::sound.playSE(res::SE::BOSSBREAK);
				app::Shake::crush.set(5, 50);
				m_KillEffect->setX(getX());
				m_KillEffect->setY(getY());
				m_KillEffect->setType(Effect::BOSS_CRUSH);
				m_KillEffect->setFlag(true);
			}
		}
		if (type == EFFECT_TYPE::CHARGE) {
			m_ChargeEffect->setX(getX());
			m_ChargeEffect->setY(getY());
			m_ChargeEffect->setType(Effect::BOSS_CHARGE);
			m_ChargeEffect->setSize(3);
			m_ChargeEffect->setFlag(true);
		}
	}
	void Boss::moveRand(float x0, float y0, float x1, float y1,float dist, int time) {
		m_Transform->randMove(getX(), getY(), x0, y0, x1, y1, dist, time);
	}
	void Boss::movePos(float px, float py, int time) {
		m_Transform->setTrans(getX(), getY(), px, py, time);
	}
	void Boss::collision(bool is_invalid_bom) {
		Collider collider(Collider::PLAYER_SHOT);
		int hitRange = 130;
		collider.setInvPlayerBom(is_invalid_bom);
		auto result = collider.hitPlayerShot(getX(), getY(), hitRange);
		if (result != Collider::NONE) {
			this->m_HP -= result;
		}
	}
	void Boss::setDamage(int damage) {
		this->m_HP -= damage;
	}
	void Boss::setHP(int hp) {
		m_HP = hp;
	}
	void Boss::setDeathEffect(bool flag) {
		m_Is_death_effect = flag;
	}
	void Boss::setHPMax(int hp) {
		m_HP_max = hp;
	}
	int Boss::getHP() {
		return m_HP;
	}
	int Boss::getHPMax() {
		return m_HP_max;
	}
	bool Boss::isDeathEffect() {
		return m_Is_death_effect;
	}
	bool Boss::isState(int state) {
		if (getState() == state)return true;
		return false;
	}
	Boss::Boss() :
		m_HP(0),
		m_HP_max(0),
		m_State(0),
		m_Img_state(0),
		m_Angle(0.f),
		m_Motion_type(0),
		m_Is_motion(false),
		m_Is_death_effect(false)
	{
		setX(-FMIN_X);
		setY(-FMIN_Y);
		m_KillEffect.reset(new Effect());
		m_ChargeEffect.reset(new Effect());
		m_Transform.reset(new Transform());
	}
	Boss::~Boss() {
	}
}