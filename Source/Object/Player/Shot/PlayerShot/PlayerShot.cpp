#include "PlayerShot.h"
#include <iostream>
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/Resource/BulletImage/BulletImage.h"
#include "../../Source/SystemProp/AreaProp.h"
#include "../../Source/Object/Effect/Effect.h"
namespace obj {
	PlayerShot::PlayerShot() :
		pattern(0),
		power(0),
		angle(0.f),
		speed(0.f),
		is_hitClear(true)
	{
		m_Effect.reset(new Effect());
	}
	void PlayerShot::initialize(int max_x, int min_x) {
		setFlag(false);
		m_Field.m_Max_x = max_x;
		m_Field.m_Min_x = min_x;
	}
	void PlayerShot::update() {
		if (isFlag()) {
			mover();
			outOfBoaderUpdate();
			countUpdate();
		}
	}
	void PlayerShot::draw(double crush_x, double crush_y) {
		if (isFlag()) {
			if (getType() >= res::PLAYER_SHOT_MAX)return;
			if(is_shine)lib::Graphics2D::setBlend(lib::BLEND_MODE::ADD, 255);
			lib::Graphics2D::drawRota(
				getX() + m_Field.m_Min_x + crush_x,//x座標
				getY() + AreaProp::min_y + crush_y,//y座標
				getSize(),//サイズ
				angle + PI / 2 + img_ang,//角度
				res::BulletImage::Bullet.player_shot[getType()],//画像種類
				true
			);
			if (is_shine)lib::Graphics2D::setBlend(lib::BLEND_MODE::NONE, 255);
		}
		if (m_Effect->isFlag())m_Effect->draw(m_Field);
	}
	void PlayerShot::mover() {
		if (pattern == PATTERN::STOP)return;
		this->setX(getX() + cos(angle) * speed);
		this->setY(getY() + sin(angle) * speed);
	}
	void PlayerShot::outOfBoaderUpdate() {
		if (pattern == PATTERN::STOP)return;
		if (getX() < AreaProp::min_x - 120 || getX() > AreaProp::max_x + 120 || getY() < -120 || getY() > double(AreaProp::max_y - AreaProp::min_y + 120)) {
			this->setFlag(false);
		}
	}
	void PlayerShot::setSpawn(
		float x, 
		float y,
		float m_Angle,
		float speed,
		float size,
		int type,
		int pattern,
		int power
	) {
		setFlag(true);
		setX(x);
		setY(y);
		this->setSize(size);
		setType(type);
		setCount(0);
		setState(0);
		this->angle = m_Angle;
		this->speed = speed;
		this->pattern = pattern;
		this->power = power;
		add_x = 0;
		add_y = 0;
		change_type = 0;
		is_shine = false;
		img_ang = 0;
	}
	void PlayerShot::setHitClear(bool flag) {
		this->is_hitClear = flag;
	}
	void PlayerShot::setAddPos(float x, float y) {
		add_x = x;
		add_y = y;
	}
	void PlayerShot::setPower(int power) {
		this->power = power;
	}
	void PlayerShot::setChangeType(int type) {
		this->change_type = type;
	}
	void PlayerShot::clear(bool flag) {
		if (flag) {
			m_Effect->setFlag(true);
			m_Effect->setX(getX());
			m_Effect->setY(getY());
			m_Effect->setColor(0);
			m_Effect->setType(Effect::SHOT_CLEAR);
		}
		setFlag(false);
		setCount(0);
	}
	void PlayerShot::setShine(bool flag) {
		is_shine = flag;
	}
	void PlayerShot::setSpeed(float speed) {
		this->speed = speed;
	}
	void PlayerShot::setAngle(float angle) {
		this->angle = angle;
	}
	void PlayerShot::setImgAng(float angle) {
		img_ang = angle;
	}
	void PlayerShot::setPattern(int type) {
		this->pattern = type;
	}
	int PlayerShot::getPattern() {
		return pattern;
	}
	int PlayerShot::getChangeType() {
		return this->change_type;
	}
	float PlayerShot::getAddX() {
		return this->add_x;
	}
	float PlayerShot::getAddY() {
		return this->add_y;
	}
	float PlayerShot::getSpeed() {
		return speed;
	}
	float PlayerShot::getAngle() {
		return angle;
	}
	float PlayerShot::getImgAng() {
		return img_ang;
	}
	float PlayerShot::getPower() {
		return power;
	}
	bool PlayerShot::isHitClear() {
		return is_hitClear;
	}
	bool PlayerShot::isShine() {
		return is_shine;
	}
	PlayerShot::~PlayerShot() {
	}
}