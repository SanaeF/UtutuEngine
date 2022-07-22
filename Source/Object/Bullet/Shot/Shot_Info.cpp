#include"Shot_Info.h"
#include <iostream>

#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/SystemProp/AreaProp.h"
#include "../../Source/SystemProp/AliceProp/AliceProp.h"
#include "../../Source/Resource/BulletImage/BulletImage.h"
#include "../../Source/Collider/Collider.h"
#include "../../Source/MassageHandle/MassageHandle.h"
#include "../../Source/Object/Effect/Effect.h"

namespace obj {
	Shot_Info::Shot_Info()
	{
		m_Effect.reset(new Effect());
	}
	Shot_Info::~Shot_Info() {
		lib::Graphics2D::setBlend(lib::BLEND_MODE::NONE, 0);
	}
	void Shot_Info::update() {
		if (isFlag()) {
			if (getSize() <= 0)setSize(1);
			mover();
			grazeUpdate();
			outOfBoaderUpdate();
			setCount(getCount() + 1);
			Collision();
		}
	}
	void Shot_Info::setField(Field& field) {
		m_Field = field;
	}
	void Shot_Info::draw(double crush_x, double crush_y) {
		if (isFlag()) {
			if (is_hide)return;
			lib::Graphics2D::setArea(m_Field.m_Min_x, AREA::FMIN_Y, m_Field.m_Max_x, AREA::FMAX_Y);
			int color = getColor();
			int kind = getType();
			double rotaAngle;
			if (isShine() == true)lib::Graphics2D::setBlend(lib::BLEND_MODE::ADD, 255);
			if (isRota() == true)rotaAngle = PI2 * (getCount() % 120) / 120;
			else rotaAngle = getAngle() + PI / 2;
			if (getCount() <= EFFECT::CREATE_COUNT) {
				lib::Graphics2D::drawRota(
					getX() + m_Field.m_Min_x + crush_x,//x座標
					getY() + AREA::FMIN_Y + crush_y,//y座標
					1.0,//サイズ
					getCount(),//角度
					res::BulletImage::Bullet.shot[res::BULLET_TYPE::EFFECT][0],//画像種類
					true
				);
			}
			else {
				float size = getSize();
				if (AliceProp::flag)size = size + AliceProp::add_size;
				lib::Graphics2D::drawRota(
					getX() + m_Field.m_Min_x + crush_x + G_Effect.getX(),//x座標
					getY() + AREA::FMIN_Y + crush_y + G_Effect.getY(),//y座標
					size,//サイズ
					rotaAngle,//角度
					res::BulletImage::Bullet.shot[kind][color],//画像種類
					true
				);
			}
			if (isShine() == true)lib::Graphics2D::setBlend(lib::BLEND_MODE::NONE, 0);
		}
		if (m_Effect->isFlag())m_Effect->draw(m_Field);
		lib::Graphics2D::setArea(0, 0, lib::ScreenSize::width, lib::ScreenSize::height);
	}
	
	void Shot_Info::mover() {
		if (getRayer() == 0) {
			m_Field.m_Min_x=AREA::FMIN_X;
			m_Field.m_Max_x=AREA::FMAX_X;
		}
		if (getRayer() == 1) {
			m_Field.m_Min_x = AREA::P1_MIN_X;
			m_Field.m_Max_x = AREA::P1_MAX_X;
		}
		if (getRayer() == 2) {
			m_Field.m_Min_x = AREA::P2_MIN_X;
			m_Field.m_Max_x = AREA::P2_MAX_X;
		}
		this->setX(getX() + cos(getAngle()) * getSpeed());
		this->setY(getY() + sin(getAngle()) * getSpeed());
	}
	
	void Shot_Info::grazeUpdate() {
		if (getGraze() == 1 && G_Effect.isState(GRAZE_EFFECT::START) == true) {
			if (isShine())set_shine(false);
			else set_shine(true);
			setGraze(2);
		}
		if (getGraze() == 2 && G_Effect.isState(GRAZE_EFFECT::UPDATE) == true) {
			if (isShine())set_shine(false);
			else set_shine(true);
			setGraze(3);
		}
	}
	
	void Shot_Info::outOfBoaderUpdate() {
		if (isBound()) {
			if (getX() < -40) {
				setAngle(PI - getAngle());
				setBoundArea(AREA_LEFT);
				bound_count++;
			}
			if (getX() > double(m_Field.m_Max_x - m_Field.m_Min_x + 40)) {
				setAngle(PI - getAngle());
				setBoundArea(AREA_RIGHT);
				bound_count++;
			}
			if (getY() < double(FMIN_Y - 40)) {
				setAngle(PI2 - getAngle());
				setBoundArea(AREA_UP);
				bound_count++;
			}
			if (getY() > double(FMAX_Y - FMIN_Y + 40)) {
				setAngle(PI2 - getAngle());
				setBoundArea(AREA_DOWN);
				bound_count++;
			}
		}
		else {
			if (getX() < -120 || getX() > double(m_Field.m_Max_x - m_Field.m_Min_x + 120) || getY() < -120 || getY() > double(FMAX_Y - FMIN_Y + 120)) {
				this->setFlag(false);
			}
		}
	}

	void Shot_Info::Collision() {
		Collider collider(Collider::TYPE::BULLET);
		int handle = collider.hitBullet(getX(), getY(), getType(), 0, getAngle(), getSize(), getGraze(), getRayer());
		if (handle == Collider::HIT_TYPE::GRAZE) {
			setGraze(1);
			MassageHandle(PLAYER::GetGraze, getRayer());
			MassageHandleItem(PLAYER::GetGraze, 1, getRayer());
			MassageHandleItem(PLAYER::GetScore, 1, getRayer());
		}
		if (handle == Collider::HIT_TYPE::DAMAGE) {
			MassageHandle(PLAYER::Damage, getRayer());
			this->setGraze(0);
			if(!no_delete)this->setFlag(false);
		}
	}

	void Shot_Info::clear(bool flag) {
		if (flag) {
			m_Effect->setFlag(true);
			m_Effect->setX(getX());
			m_Effect->setY(getY());
			m_Effect->setColor(getColor());
			m_Effect->setType(Effect::SHOT_CLEAR);
		}
		setFlag(false);
	}
	void Shot_Info::setDefault() {
		this->set_rota(false);
		this->set_shine(false);
		this->setBound(false);
		this->setHide(false);
		this->setNoDelete(false);
		this->setState(0);
		this->setStateSub(0);
		this->setCount(0);
		this->setGraze(0);
		bound_count = 0;
	}
	void Shot_Info::setAngle(double angle) {
		this->angle = angle;
	}
	void Shot_Info::setSpeed(double speed) {
		this->speed = speed;
	}
	void Shot_Info::setColor(int color) {
		this->color = color;
	}
	void Shot_Info::setGraze(int num) {
		this->graze = num;
	}
	void Shot_Info::set_rota(bool flag) {
		this->rota_flag = flag;
	}
	void Shot_Info::set_shine(bool flag) {
		this->shine_flag = flag;
	}
	void Shot_Info::setBound(bool flag) {
		if (flag == false)bound_count = 0;
		this->bount_flag = flag;
	}
	void Shot_Info::setBoundArea(int area) {
		this->bount_area = area;
	}
	void Shot_Info::setBoundCount(int count) {
		bound_count = count;
	}
	void Shot_Info::setHide(bool flag) {
		this->is_hide = flag;
	}
	void Shot_Info::setNoDelete(bool flag) {
		this->no_delete = flag;
	}
	double Shot_Info::getAngle() {
		return this->angle;
	}
	double Shot_Info::getSpeed() {
		return this->speed;
	}
	int Shot_Info::getColor() {
		return this->color;
	}
	int Shot_Info::getGraze() {
		return this->graze;
	}
	bool Shot_Info::isRota() {
		return this->rota_flag;
	}
	bool Shot_Info::isShine() {
		return this->shine_flag;
	}
	bool Shot_Info::isBound() {
		return this->bount_flag;
	}
	bool Shot_Info::isHide() {
		return this->is_hide;
	}
	bool Shot_Info::isNoDelete() {
		return this->no_delete;
	}
	int Shot_Info::getBoundArea() {
		return this->bount_area;
	}
	int Shot_Info::getBoundCount() {
		return this->bound_count;
	}
	void Shot_Info::ObjClear() {
		valueReset();
		angle = false;
		speed = false;
		color = false;
		graze = false;
		bound_count = false;
		rota_flag = false;
		shine_flag = false;
		bount_flag = false;
		bount_area = 0;
		is_hide = false;
		no_delete = false;
	}
}