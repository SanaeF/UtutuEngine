#include "BackGround.h"
#include <iostream>

#include "../../Source/library/Graphics/Graphics3D/Graphics3D.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/SystemProp/AreaProp.h"
#include "../../Source/Resource/MapImage/MapImage.h"

namespace obj {
	void BackGraph::update() {
		if (isFlag()) {
			switch (pattern) {
			case ROOD_2D_SCROLL:
				update2Dscroll();
				break;
			case ROOD_3D_SCROLL:
				lib::Graphics3D::cameraCenter(AREA::FMAX_X / 2 + 50, AREA::FMAX_Y / 1.8);
				update3Dscroll();
				break;
			case BACK_DIST_2D:
				update2Ddist();
				break;
			case STAY_2D:
				update2Dstay();
				break;
			}
		}
		countUpdate();
	}
	void BackGraph::update2Dscroll() {
		if (speed == 0 || length == 0)return;
		setY((getCount() * speed) % length);
	}
	void BackGraph::update3Dscroll() {
		Size.set(200, 200, 200);
		Rotation.set(0.f, 0.f, 0.f);
	}
	void BackGraph::update2Ddist() {
		int handle = res::MapImage::Map.back[getType()];
		int x_max, y_max;
		int x_min;
		lib::Graphics2D::getSize(handle, &x_max, &y_max);//ƒTƒCƒY‚ÌŽæ“¾
		int dist_size = 0;
		if (x_max >= y_max)dist_size = x_max;
		if (x_max < y_max)dist_size = y_max;
		//‰æ–ÊƒTƒCƒY‚©‚çA’[‚ðŒvŽZ
		dist_max = getX() + FMIN_X + (dist_size / 2);
		dist_min = getX() + FMIN_X - (dist_size / 2);
	}
	void BackGraph::update2Dstay() {

	}
	void BackGraph::update3DStay() {

	}

	void BackGraph::draw(double crush_x, double crush_y) {
		if (isFlag()) {
			lib::Graphics2D::setArea(0, 0, 1920, 1440);
			switch (pattern) {
			case ROOD_2D_SCROLL:
				draw2Dscroll(crush_x, crush_y);
				break;
			case ROOD_3D_SCROLL:
				draw3Dscroll(crush_x, crush_y);
				break;
			case BACK_DIST_2D:
				draw2Ddist(crush_x, crush_y);
				break;
			case STAY_2D:
				draw2Dstay(crush_x, crush_y);
				break;
			}
			lib::Graphics2D::setArea(0, 0, 1920, 1440);
		}
	}
	void BackGraph::draw2Dscroll(double cx, double cy) {
		int handle;
		int kind = getType();
		if (kind >= 0&& kind<res::BACK_SCREEN_MAX)handle = res::MapImage::Map.back[kind];
		for (int ii = 0; ii < 2; ii++)
			lib::Graphics2D::drawRota(cx + getX(), cy - length * ii + getY(), getSize(), m_Angle, handle, true);
	}
	void BackGraph::draw3Dscroll(double cx, double cy) {
		int handle = res::MapImage::Map.model[getType()];
		lib::Graphics3D::UseLight(false);
		lib::Graphics3D::CameraPosAndRota(Cam.pos, Cam.m_Angle.x, Cam.m_Angle.y, Cam.m_Angle.z);//(xyz),cŒü‚«‰ñ“],‰¡Œü‚«‰ñ“],•ûŒü‚»‚Ì‚Ü‚ÜƒJƒƒ‰‚ð‰ñ“]
		lib::Graphics3D::ModelScale(handle, Size);
		for (int ii = 0; ii < 4; ii++) {
			if (getCount() == 0 || (speed == 0 || length == 0))return;
			Pos.set(cx + getX(), getY(), getZ() + (ii * length) - ((getCount() * speed) % length));
			lib::Graphics3D::ModelRotate(handle, Rotation);
			lib::Graphics3D::ModelPositioin(handle, Pos);
			lib::Graphics3D::DrawModel(handle);
		}
	}
	void BackGraph::draw2Ddist(double cx, double cy) {
		int handle = res::MapImage::Map.back[getType()];
		for (int ii = dist_min; ii < dist_max; ii++) {
			float distX = distParam(ii, DISTORT_X);
			float distY = distParam(ii, DISTORT_Y);
			lib::Graphics2D::setArea(dist_min, ii, dist_max, ii + 1);
			lib::Graphics2D::drawRota(cx + getX() + FMIN_X + distX, cy + getY() + FMIN_Y + distY, getSize(), m_Angle, handle, true);
		}
	}
	void BackGraph::draw2Dstay(double cx, double cy) {
		int handle = res::MapImage::Map.back[getType()];
		lib::Graphics2D::drawRota(cx + getX(), cy + getY(), getSize(), m_Angle, handle, true);
	}
	void BackGraph::draw3DStay(double cx, double cy) {
		lib::Graphics3D::UseLight(false);
		lib::Graphics3D::CameraPosAndRota(Cam.pos, Cam.m_Angle.x, Cam.m_Angle.y, Cam.m_Angle.z);//(xyz),cŒü‚«‰ñ“],‰¡Œü‚«‰ñ“],•ûŒü‚»‚Ì‚Ü‚ÜƒJƒƒ‰‚ð‰ñ“]
	}

	void BackGraph::create(Position pos, double m_Angle, double size, int speed, int kind, int length, int pattern, int count, int state) {
		setFlag(true);
		setSize(size);
		setX(pos.x);
		setY(pos.y);
		setZ(pos.z);
		setSpeed(speed);
		setAngle(m_Angle);
		setType(kind);
		setLength(length);
		setPattern(pattern);
		setCount(count);
		setState(state);
		update();
		draw(crush_x, crush_y);
	}
	void BackGraph::set_DistX(double delt, int size, int time, int flag) {
		dist[DISTORT_X].thick = delt;
		dist[DISTORT_X].size = size;
		dist[DISTORT_X].time = time;
		dist[DISTORT_X].flag = flag;
	}
	void BackGraph::set_DistY(double delt, int size, int time, int flag) {
		dist[DISTORT_Y].thick = delt;
		dist[DISTORT_Y].size = size;
		dist[DISTORT_Y].time = time;
		dist[DISTORT_Y].flag = flag;
	}
	void BackGraph::set_FadeOut(int flag) {

	}
	void BackGraph::setAngle(float num) {
		m_Angle = num;
	}
	void BackGraph::setSpeed(int num) {
		speed = num;
	}
	void BackGraph::setLength(int num) {
		length = num;
	}
	void BackGraph::setPattern(float num) {
		pattern = num;
	}
	void BackGraph::setCamera(Position pos, Position m_Angle) {
		Cam.pos = pos;
		Cam.m_Angle = m_Angle;
	}
	void BackGraph::setCrush(float cx, float cy) {
		crush_x = cx;
		crush_y = cy;
	}
	void BackGraph::initialize() {
		setFlag(false);
	}

	float BackGraph::distParam(int num, int state) {
		float result = 0.f;
		if (dist[state].flag) {
			result = dist[state].size * sin(PI2 * ((int)(getCount() + num / dist[state].thick) % dist[state].time) / dist[state].time);
		}
		return result;
	}
	BackGraph::BackGraph() :
		distX(0.f),
		distY(0.f),
		speed(0),
		m_Angle(0.f),
		length(0),
		pattern(0)
	{
	}
}