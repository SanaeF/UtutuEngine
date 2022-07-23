#include"Lazer_Info.h"
#include <iostream>

#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/SystemProp/AreaProp.h"
#include "../../Source/Collider/Collider.h"
#include "../../Source/Resource/BulletImage/BulletImage.h"
#include "../../Source/MassageHandle/MassageHandle.h"
#include "../../Source/Object/Effect/Effect.h"

namespace obj {
	Lazer_Info::Lazer_Info() {
		m_Effect.reset(new Effect());
	}
	Lazer_Info::~Lazer_Info() {
		lib::Graphics2D::setBlend(lib::BLEND_MODE::NONE, 0);
	}
	void Lazer_Info::update() {
		if (isFlag()) {
			mover();
			lengthUpdate();
			outOfBoaderUpdate();
			setCount(getCount() + 1);
			Collision();
		}
	}
	void Lazer_Info::setField(Field& field) {
		m_Field = field;
	}
	void Lazer_Info::draw(double crush_x, double crush_y) {
		if (isFlag()) {
			int color = getColor();
			int kind = getType();
			int laz_col = getMainColor();
			int laz_type = getMainType();

			double rotaAngle = getAngle() + PI / 2;
			lib::Graphics2D::setArea(m_Field.m_Min_x, AreaProp::min_y, m_Field.m_Max_x, AreaProp::max_y);
			lib::Graphics2D::drawMode(lib::DRAW_MODE::BILINEAR);
			lib::Graphics2D::setBlend(lib::BLEND_MODE::ADD, 255);
			lib::Graphics2D::drawRota(
				getX() + m_Field.m_Min_x + crush_x + G_Effect.getX(),//x座標
				getY() + AreaProp::min_y + crush_y + G_Effect.getY(),//y座標
				1,//サイズ
				rotaAngle,//角度
				res::BulletImage::Bullet.shot[kind][color],//画像種類
				true
			);
			lib::Graphics2D::drawModi(//レーザーを描画
				crush_x + disp_x[0] + m_Field.m_Min_x, disp_y[0] + AreaProp::min_y + crush_y,
				crush_x + disp_x[1] + m_Field.m_Min_x, disp_y[1] + AreaProp::min_y + crush_y,
				crush_x + disp_x[2] + m_Field.m_Min_x, disp_y[2] + AreaProp::min_y + crush_y,
				crush_x + disp_x[3] + m_Field.m_Min_x, disp_y[3] + AreaProp::min_y + crush_y,
				res::BulletImage::Bullet.shot[laz_type][laz_col], true
			);
			lib::Graphics2D::setBlend(lib::BLEND_MODE::NONE, 0);
			lib::Graphics2D::drawMode(lib::DRAW_MODE::NEAREST);
			if (isShine() == true)lib::Graphics2D::setBlend(lib::BLEND_MODE::NONE, 0);
			lib::Graphics2D::setArea(0, 0, lib::ScreenSize::width, lib::ScreenSize::height);
		}
	}
	void Lazer_Info::mover() {
		if (getRayer() == 0) {
			m_Field.m_Min_x = AreaProp::min_x;
			m_Field.m_Max_x = AreaProp::max_x;
		}
		if (getRayer() == 1) {
			m_Field.m_Min_x = AreaProp::p1_min_x;
			m_Field.m_Max_x = AreaProp::p1_max_x;
		}
		if (getRayer() == 2) {
			m_Field.m_Min_x = AreaProp::p2_min_x;
			m_Field.m_Max_x = AreaProp::p2_max_x;
		}
		this->setX(getX() + cos(getAngle()) * getSpeed());
		this->setY(getY() + sin(getAngle()) * getSpeed());
	}
	void Lazer_Info::lengthUpdate() {
		if (getGraze() == 1 && G_Effect.isState(GRAZE_EFFECT::START) == true) {
			setShine(true);
			setGraze(2);
		}
		if (getGraze() == 2 && G_Effect.isState(GRAZE_EFFECT::UPDATE) == true) {
			//set_shine(false);
			setGraze(3);
		}
		int collider;
		if (isCollision())collider = 1;
		else collider = 0;

		//表示位置を設定
		disp_x[0] = getX() + cos(getAngle() + getLengthAngle() + PI / 2) * getThick();
		disp_y[0] = getY() + sin(getAngle() + getLengthAngle() + PI / 2) * getThick();
		disp_x[1] = getX() + cos(getAngle() + getLengthAngle() - PI / 2) * getThick();
		disp_y[1] = getY() + sin(getAngle() + getLengthAngle() - PI / 2) * getThick();
		disp_x[2] = getX() + cos(getAngle() + getLengthAngle() - PI / 2) * getThick() + cos(getAngle() + getLengthAngle()) * getLength();
		disp_y[2] = getY() + sin(getAngle() + getLengthAngle() - PI / 2) * getThick() + sin(getAngle() + getLengthAngle()) * getLength();
		disp_x[3] = getX() + cos(getAngle() + getLengthAngle() + PI / 2) * getThick() + cos(getAngle() + getLengthAngle()) * getLength();
		disp_y[3] = getY() + sin(getAngle() + getLengthAngle() + PI / 2) * getThick() + sin(getAngle() + getLengthAngle()) * getLength();

		//あたり範囲を設定
		debug_x[0] = getX() + cos(getAngle() + PI / 2) * (getThick() * collider) + cos(getAngle()) * getLength() * ((1 - collider) / 2);
		debug_y[0] = getY() + sin(getAngle() + PI / 2) * (getThick() * collider) + sin(getAngle()) * getLength() * ((1 - collider) / 2);
		debug_x[1] = getX() + cos(getAngle() - PI / 2) * (getThick() * collider) + cos(getAngle()) * getLength() * ((1 - collider) / 2);
		debug_y[1] = getY() + sin(getAngle() - PI / 2) * (getThick() * collider) + sin(getAngle()) * getLength() * ((1 - collider) / 2);
		debug_x[2] = getX() + cos(getAngle() - PI / 2) * (getThick() * collider) + cos(getAngle()) * getLength() * collider + cos(getAngle()) * getLength() * ((1 - collider) / 2);
		debug_y[2] = getY() + sin(getAngle() - PI / 2) * (getThick() * collider) + sin(getAngle()) * getLength() * collider + sin(getAngle()) * getLength() * ((1 - collider) / 2);
		debug_x[3] = getX() + cos(getAngle() + PI / 2) * (getThick() * collider) + cos(getAngle()) * getLength() * collider + cos(getAngle()) * getLength() * ((1 - collider) / 2);
		debug_y[3] = getY() + sin(getAngle() + PI / 2) * (getThick() * collider) + sin(getAngle()) * getLength() * collider + sin(getAngle()) * getLength() * ((1 - collider) / 2);

	}
	void Lazer_Info::outOfBoaderUpdate() {
		if (getSpeed() == 0)return;
		if (isBound()) {
			if (getX() < 0) {
				if(!is_bount_no_angle)setAngle(PI - getAngle());
				setBoundArea(1);
				bound_count++;
			}
			if (getX() > double(m_Field.m_Max_x - m_Field.m_Min_x)) {
				if (!is_bount_no_angle)setAngle(PI - getAngle());
				setBoundArea(2);
				bound_count++;
			}
			if (getY() < 0) {
				if (!is_bount_no_angle)setAngle(PI2 - getAngle());
				setBoundArea(3);
				bound_count++;
			}
			if (getY() > double(AreaProp::max_y - AreaProp::min_y)) {
				if (!is_bount_no_angle)setAngle(PI2 - getAngle());
				setBoundArea(4);
				bound_count++;
			}
		}
		else {
			if (getX() < -(20 * length) || getX() > double(m_Field.m_Max_x - m_Field.m_Min_x + (20 * length)) || getY() < -(20 * length) || getY() > double(AreaProp::max_y - AreaProp::min_y + (20 * length))) {
				this->setFlag(false);
			}
		}
	}
	void Lazer_Info::Collision() {
		if (hit_flag == false)return;
		Collider collider(Collider::TYPE::BULLET);
		float r = collider.getBulletRange(getType());
		float c_x[4], c_y[4];
		c_x[0] = getX() + cos(getAngle() + getLengthAngle() + PI / 2) * getThick() * (r / 50);
		c_y[0] = getY() + sin(getAngle() + getLengthAngle() + PI / 2) * getThick() * (r / 50);
		c_x[1] = getX() + cos(getAngle() + getLengthAngle() - PI / 2) * getThick() * (r / 50);
		c_y[1] = getY() + sin(getAngle() + getLengthAngle() - PI / 2) * getThick() * (r / 50);
		c_x[2] = getX() + cos(getAngle() + getLengthAngle() - PI / 2) * getThick() * (r / 50) + cos(getAngle() + getLengthAngle()) * getLength();
		c_y[2] = getY() + sin(getAngle() + getLengthAngle() - PI / 2) * getThick() * (r / 50) + sin(getAngle() + getLengthAngle()) * getLength();
		c_x[3] = getX() + cos(getAngle() + getLengthAngle() + PI / 2) * getThick() * (r / 50) + cos(getAngle() + getLengthAngle()) * getLength();
		c_y[3] = getY() + sin(getAngle() + getLengthAngle() + PI / 2) * getThick() * (r / 50) + sin(getAngle() + getLengthAngle()) * getLength();
		int handle = collider.hitLazer(c_x, c_y, getType(), getSpeed(), getAngle(), getGraze(), getRayer());
		if (handle == Collider::HIT_TYPE::GRAZE) {
			setGraze(1);
			MassageHandle(PLAYER::GetGraze, getRayer());
			MassageHandleItem(PLAYER::GetGraze, 1, getRayer());
			MassageHandleItem(PLAYER::GetScore, 1, getRayer());
		}
		if (handle == Collider::HIT_TYPE::DAMAGE) {
			MassageHandle(PLAYER::Damage, getRayer());
			if (!no_delete&&getSpeed() != 0.f)this->setFlag(false);
			setGraze(0);
		}
	}
	void Lazer_Info::clear(bool flag) {
		if (flag) {
			m_Effect->setFlag(true);
			m_Effect->setX(getX());
			m_Effect->setY(getY());
			m_Effect->setColor(getColor());
			m_Effect->setType(Effect::SHOT_CLEAR);
		}
		this->setFlag(false);
	}
	void Lazer_Info::setDefault() {
		this->setRota(false);
		this->setShine(false);
		this->setBound(false);
		this->setBoundNoAngle(false);
		this->setNoDelete(false);
		this->setThick(0);
		this->setLength(0);
		this->setState(0);
		this->setStateSub(0);
		this->setCount(0);
		this->setGraze(0);
		length_rota = 0;
		bound_count = 0;
	}
	void Lazer_Info::setAngle(double angle) {
		this->angle = angle;
	}
	void Lazer_Info::setLengthAngle(double angle) {
		this->length_rota = angle;
	}
	void Lazer_Info::setSpeed(double speed) {
		this->speed = speed;
	}
	void Lazer_Info::setThick(double dist) {
		this->dist = dist;
	}
	void Lazer_Info::setLength(double length) {
		this->length = length;
	}
	void Lazer_Info::setColor(int color) {
		this->color = color;
	}
	void Lazer_Info::setGraze(int num) {
		this->graze = num;
	}
	void Lazer_Info::setMainColor(int color) {
		this->laz_color = color;
	}
	void Lazer_Info::setMainType(int type) {
		this->laz_type = type;
	}
	void Lazer_Info::setRota(bool flag) {
		this->rota_flag = flag;
	}
	void Lazer_Info::setShine(bool flag) {
		this->shine_flag = flag;
	}
	void Lazer_Info::setBound(bool flag) {
		this->bount_flag = flag;
	}
	void Lazer_Info::set_collision(bool flag) {
		this->hit_flag = flag;
	}
	void Lazer_Info::setBoundArea(int area) {
		this->bount_area = area;
	}
	void Lazer_Info::setBoundNoAngle(bool flag) {
		this->is_bount_no_angle = flag;
	}
	void Lazer_Info::setNoDelete(bool flag) {
		this->no_delete = flag;
	}
	double Lazer_Info::getAngle() {
		return this->angle;
	}
	double Lazer_Info::getLengthAngle() {
		return this->length_rota;
	}
	double Lazer_Info::getSpeed() {
		return this->speed;
	}
	double Lazer_Info::getThick() {
		return this->dist;
	}
	double Lazer_Info::getLength() {
		return this->length;
	}
	int Lazer_Info::getColor() {
		return this->color;
	}
	int Lazer_Info::getGraze() {
		return this->graze;
	}
	int Lazer_Info::getMainColor() {
		return this->laz_color;
	}
	int Lazer_Info::getMainType() {
		return this->laz_type;
	}
	bool Lazer_Info::isRota() {
		return this->rota_flag;
	}
	bool Lazer_Info::isShine() {
		return this->shine_flag;
	}
	bool Lazer_Info::isBound() {
		return this->bount_flag;
	}
	bool Lazer_Info::isCollision() {
		return this->hit_flag;
	}
	bool Lazer_Info::isNoDelete() {
		return this->no_delete;
	}
	int Lazer_Info::getBoundArea() {
		return this->bount_area;
	}
	int Lazer_Info::getBoundCount() {
		return this->bound_count;
	}
	void Lazer_Info::ObjClear() {
		valueReset();
		for (int point = 0; point < 4; point++) {
			disp_x[point] = false;
			disp_y[point] = false;
			debug_x[point] = false;
			debug_y[point] = false;
		}
		angle = false;
		length_rota = 0;
		speed = false;
		dist = false;
		length = false;
		color = false;
		graze = false;
		bound_count = false;
		laz_type = false;
		laz_color = false;
		rota_flag = false;
		shine_flag = false;
		bount_flag = false;
		bount_area = false;
		hit_flag = false;
		is_bount_no_angle = false;
		no_delete = false;
	}
}