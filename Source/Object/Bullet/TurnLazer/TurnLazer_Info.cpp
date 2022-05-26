#include"TurnLazer_Info.h"
#include <iostream>

#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/SystemProp/AreaProp.h"
#include "../../Source/Resource/BulletImage/BulletImage.h"
#include "../../Source/Collider/Collider.h"
#include "../../Source/MassageHandle/MassageHandle.h"
#include "../../Source/Object/Effect/Effect.h"

namespace obj {
	TurnLazer_Info::TurnLazer_Info() {
		m_Effect.reset(new Effect());
		length = 0;
	}
	TurnLazer_Info::~TurnLazer_Info() {
		lib::Graphics2D::setBlend(lib::BLEND_MODE::NONE, 0);
	}
	void TurnLazer_Info::update() {
		if (isFlag()) {
			if (getCount() == 0)initTail();
			setTail();
			mover();
			grazeUpdate();
			outOfBoaderUpdate();
			setCount(getCount() + 1);
			Collision();
		}
	}
	void TurnLazer_Info::drawBack(double crush_x, double crush_y) {
		if (isFlag()) {
			int color = getColor();
			if (length <= 0)return;
			//lib::Graphics2D::setBlend(lib::BLEND_MODE::ALPHA, 150);
			for (int num = 0; num < length; num++) {
				double pal = cutPal(m_Last_info[num].number[1], length);
				cutThick(m_Last_info[num], pal);
				lib::Graphics2D::drawModi(//レーザーを描画
					crush_x + disp_x[0] + m_Field.m_Min_x, disp_y[0] + AREA::FMIN_Y + crush_y,
					crush_x + disp_x[1] + m_Field.m_Min_x, disp_y[1] + AREA::FMIN_Y + crush_y,
					crush_x + disp_x[2] + m_Field.m_Min_x, disp_y[2] + AREA::FMIN_Y + crush_y,
					crush_x + disp_x[3] + m_Field.m_Min_x, disp_y[3] + AREA::FMIN_Y + crush_y,
					res::BulletImage::Bullet.shot[res::BULLET_TYPE::TURN_LAZ][res::BULLET_COLOR::BLACKBACK], true
				);
			}
			//lib::Graphics2D::drawMode(lib::DRAW_MODE::NEAREST);
		}
	}
	void TurnLazer_Info::draw(double crush_x, double crush_y) {
		if (isFlag()) {
			int color = getColor();
			if (length <= 0)return;
			lib::Graphics2D::drawMode(lib::DRAW_MODE::BILINEAR);
			for (int num = 0; num < length; num++) {
				double pal = cutPal(m_Last_info[num].number[0], length);
				lib::Graphics2D::setBlend(lib::BLEND_MODE::ADD , 200);
				cutThick(m_Last_info[num], pal);
				lib::Graphics2D::drawModi(//レーザーを描画
					crush_x + disp_x[0] + m_Field.m_Min_x, disp_y[0] + AREA::FMIN_Y + crush_y,
					crush_x + disp_x[1] + m_Field.m_Min_x, disp_y[1] + AREA::FMIN_Y + crush_y,
					crush_x + disp_x[2] + m_Field.m_Min_x, disp_y[2] + AREA::FMIN_Y + crush_y,
					crush_x + disp_x[3] + m_Field.m_Min_x, disp_y[3] + AREA::FMIN_Y + crush_y,
					res::BulletImage::Bullet.shot[res::BULLET_TYPE::TURN_LAZ][color], true
				);
				if(!pause_tail && length > 0)m_Last_info[num].number[0] = (m_Last_info[num].number[0] + 1) % length;
			}
			for (int num = 0; num < length; num++) {
				double pal = cutPal(m_Last_info[num].number[1], length);
				lib::Graphics2D::setBlend(lib::BLEND_MODE::ADD, 150);
				cutThick(m_Last_info[num], pal);
				lib::Graphics2D::drawModi(//レーザーを描画
					crush_x + disp_x[0] + m_Field.m_Min_x, disp_y[0] + AREA::FMIN_Y + crush_y,
					crush_x + disp_x[1] + m_Field.m_Min_x, disp_y[1] + AREA::FMIN_Y + crush_y,
					crush_x + disp_x[2] + m_Field.m_Min_x, disp_y[2] + AREA::FMIN_Y + crush_y,
					crush_x + disp_x[3] + m_Field.m_Min_x, disp_y[3] + AREA::FMIN_Y + crush_y,
					res::BulletImage::Bullet.shot[res::BULLET_TYPE::TURN_LAZ][res::BULLET_COLOR::ORIGINAL], true
				);
				if (!pause_tail) {
					if ((m_Last_info[num].number[1] + 1) > 0 && length > 0)m_Last_info[num].number[1] = (m_Last_info[num].number[1] + 1) % length;
				}
			}
			lib::Graphics2D::setBlend(lib::BLEND_MODE::NONE, 0);
			lib::Graphics2D::drawMode(lib::DRAW_MODE::NEAREST);
		}
		if (m_Effect->isFlag())m_Effect->draw(m_Field);
	}

	void TurnLazer_Info::mover() {
		if (getRayer() == 0) {
			m_Field.m_Min_x = AREA::FMIN_X;
			m_Field.m_Max_x = AREA::FMAX_X;
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
	void TurnLazer_Info::initTail() {
		for (int num = 0; num < length; num++) {
			m_Last_info[num].x = getX();
			m_Last_info[num].y = getY();
			m_Last_info[num].m_Angle = getAngle();
			m_Last_info[num].number[0] = 0;
			m_Last_info[num].number[1] = 0;
		}
	}
	void TurnLazer_Info::setTail() {
		setSize(1);
		m_Last_info[getCount() % length].x = getX();
		m_Last_info[getCount() % length].y = getY();
		m_Last_info[getCount() % length].m_Angle = getAngle();
		m_Last_info[getCount() % length].number[0] = 0;
		m_Last_info[getCount() % length].number[1] = 0;
	}
	void TurnLazer_Info::pause(bool flag) {
		pause_tail = flag;
	}
	void TurnLazer_Info::cleaLastInfo() {
		for (int num = 0; num < length; num++) {
			if (m_Last_info.size() < length)break;
			m_Last_info[num].x = 0;
			m_Last_info[num].y = 0;
			m_Last_info[num].m_Angle = 0;
		}
	}
	void TurnLazer_Info::grazeUpdate() {
		if (getGraze() == 1 && G_Effect.isState(GRAZE_EFFECT::START) == true) {
			setGraze(2);
		}
		if (getGraze() == 2 && G_Effect.isState(GRAZE_EFFECT::UPDATE) == true) {
			setGraze(4);
		}
	}

	void TurnLazer_Info::outOfBoaderUpdate() {
		if (isBound()) {
			if (getX() < 0) {
				setAngle(PI - getAngle());
				bount_area = 1;
				bound_count++;
			}
			if (getX() > double(m_Field.m_Max_x - m_Field.m_Min_x)) {
				setAngle(PI - getAngle());
				bount_area = 2;
				bound_count++;
			}
			if (getY() < 0) {
				setAngle(PI2 - getAngle());
				bount_area = 3;
				bound_count++;
			}
			if (getY() > double(FMAX_Y - FMIN_Y)) {
				setAngle(PI2 - getAngle());
				bount_area = 4;
				bound_count++;
			}
		}
		else {
			if (getX() < -20 * length || 
				getX() > double(m_Field.m_Max_x - m_Field.m_Min_x + (20 * length))  ||
				getY() < -20 * length || 
				getY() > double(FMAX_Y - FMIN_Y + (20 * length))
				) {
				this->setFlag(false);
				cleaLastInfo();
			}
		}
	}
	void TurnLazer_Info::cutThick(Last_Info& data, float thick) {
		data.size = thick/50;
		disp_x[0] = data.x + cos(data.m_Angle + PI / 2) * thick + G_Effect.getX();
		disp_y[0] = data.y + sin(data.m_Angle + PI / 2) * thick + G_Effect.getY();
		disp_x[1] = data.x + cos(data.m_Angle - PI / 2) * thick + G_Effect.getX();
		disp_y[1] = data.y + sin(data.m_Angle - PI / 2) * thick + G_Effect.getY();
		disp_x[2] = data.x + cos(data.m_Angle - PI / 2) * thick + cos(data.m_Angle) * 40 + G_Effect.getX();
		disp_y[2] = data.y + sin(data.m_Angle - PI / 2) * thick + sin(data.m_Angle) * 40 + G_Effect.getY();
		disp_x[3] = data.x + cos(data.m_Angle + PI / 2) * thick + cos(data.m_Angle) * 40 + G_Effect.getX();
		disp_y[3] = data.y + sin(data.m_Angle + PI / 2) * thick + sin(data.m_Angle) * 40 + G_Effect.getY();
		float max_x = -m_Field.m_Min_x;
		float mini_x = m_Field.m_Max_x + m_Field.m_Min_x;
		float max_y = -FMIN_Y;
		float mini_y = FMAX_Y + FMIN_Y;
		for (int ite = 0; ite < 4; ite++) {
			if (max_x < disp_x[ite])max_x = disp_x[ite];
			if (mini_x > disp_x[ite])mini_x = disp_x[ite];
			if (max_y < disp_y[ite])max_y = disp_y[ite];
			if (mini_y > disp_y[ite])mini_y = disp_y[ite];
		}
		data.collision_x = mini_x + (max_x - mini_x) / 2;
		data.collision_y = mini_y + (max_y - mini_y) / 2;
	}
	void TurnLazer_Info::Collision() {
		//std::vector<Collider> collider(Collider::CollisionType::BULLET);
		Collider collider(Collider::TYPE::BULLET);
		//collider.resize(length);
		for (int num = 0; num < length; num++) {
			if (m_Last_info.size() <= num)return;
			if (m_Last_info[num].size < 0.1)continue;
			//lib::Graphics2D::drawRota(
			//	m_Field.m_Min_x + m_Last_info[num].collision_x,
			//	AREA::FMIN_Y + m_Last_info[num].collision_y,
			//	m_Last_info[num].size,//サイズ
			//	0,//角度
			//	res::BulletImage::Bullet.shot[0][0],//画像種類
			//	true
			//);
			int handle = collider.hitBullet(
				m_Last_info[num].collision_x,
				m_Last_info[num].collision_y,
				getType(),
				getSpeed(),
				m_Last_info[num].m_Angle,
				m_Last_info[num].size,
				getGraze(),
				getRayer()
			);
			if (handle == Collider::HIT_TYPE::GRAZE) {
				setGraze(1);
				MassageHandle(PLAYER::GetGraze, getRayer());
				MassageHandleItem(PLAYER::GetGraze, 1, getRayer());
				MassageHandleItem(PLAYER::GetScore, 1, getRayer());
			}
			if (handle == Collider::HIT_TYPE::DAMAGE) {
				MassageHandle(PLAYER::Damage, getRayer());
				clear(true);
			}
		}
	}
	double TurnLazer_Info::cutPal(int num, int length) {
		float length_half = (length / 2);
		float value = 0.f;
		int sub_num = length - num;
		if (num < length_half) {
			value = size / sqrt(length_half) * sqrt(num);
		}
		else {
			value = size / sqrt(length_half) * sqrt(sub_num);
		}
		return value;
	}
	double TurnLazer_Info::cutPalShine(int num, int length) {
		float halfLength = (length / 3);
		int value;
		if (num < 20) {
			value = num * num;
		}
		else if (num > length - 20) {
			value = (length - num) * (length - num);
		}
		else {
			value = 200;
		}
		return value;
	}
	void TurnLazer_Info::clear(bool flag) {
		if (flag) {
			m_Effect->setFlag(true);
			m_Effect->setX(getX());
			m_Effect->setY(getY());
			m_Effect->setColor(getColor());
			m_Effect->setType(Effect::SHOT_CLEAR);
		}
		cleaLastInfo();
		m_Last_info.clear();
		setFlag(false);
	}
	void TurnLazer_Info::setDefault() {
		this->setBound(false);
		this->setState(0);
		this->setStateSub(0);
		this->setCount(0);
		this->setGraze(0);
		bound_count = 0;
		bount_area = 0;
	}
	void TurnLazer_Info::spawnTail(Last_Info& info, int num, int num_max) {

	}
	void TurnLazer_Info::setAngle(double angle) {
		this->angle = angle;
	}
	void TurnLazer_Info::setSpeed(double speed) {
		this->speed = speed;
	}
	void TurnLazer_Info::setSize(double size) {
		this->size = size * 20;
	}
	void TurnLazer_Info::setColor(int color) {
		this->color = color;
	}
	void TurnLazer_Info::setGraze(int num) {
		this->graze = num;
	}
	void TurnLazer_Info::setLength(int length) {
		this->length = length;
		number_max = length;
		m_Last_info.resize(length);
	}
	void TurnLazer_Info::setBound(bool flag) {
		this->bount_flag = flag;
	}
	void TurnLazer_Info::setBoundArea(int area) {
		this->bount_area;
	}
	double TurnLazer_Info::getAngle() {
		return this->angle;
	}
	double TurnLazer_Info::getSpeed() {
		return this->speed;
	}
	double TurnLazer_Info::getSize() {
		return this->size;
	}
	int TurnLazer_Info::getColor() {
		return this->color;
	}
	int TurnLazer_Info::getGraze() {
		return this->graze;
	}
	bool TurnLazer_Info::isBound() {
		return this->bount_flag;
	}
	int TurnLazer_Info::getBoundArea() {
		return this->bount_area;
	}
	int TurnLazer_Info::getBoundCount() {
		return this->bound_count;
	}
	int TurnLazer_Info::getNumber() {
		return this->number;
	}
	int TurnLazer_Info::getNumberMax() {
		return this->number_max;
	}
	TurnLazer_Info::Last_Info
		TurnLazer_Info::getLastInfo() {
		return m_Last_info[0];
	}
	void TurnLazer_Info::ObjClear() {
		valueReset();
		m_Last_info.clear();
		number = false;
		number_max = false;
		angle = false;
		speed = false;
		color = false;
		graze = false;
		bound_count = false;
		length = false;
		bount_flag = false;
		bount_area = false;
		pause_tail = false;
	}
}