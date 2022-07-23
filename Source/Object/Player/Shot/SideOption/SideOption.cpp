#include "SideOption.h"
#include "../../Source/SystemProp/AreaProp.h"
#include "../../Source/Collider/Collider.h"
#include "../../Source/Collider/Square/HitSquare.h"
#include "../../Source/Manager/BulletManager/BulletManager.h"
#include "../../Source/Object/Bullet/Shot/Shot_Info.h"
#include "../../Source/Resource/BulletImage/BulletImage.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"

namespace obj {
	SideOption::SideOption() {

	}
	SideOption::~SideOption() {

	}
	void SideOption::initialize() {
		setThick(50);
		setLength(150);
	}
	void SideOption::update(float x, float y, std::vector<PlayerShot>& player_shot) {
		m_Player_x=x-30;
		m_Player_y=y-90;

		setAngle(getAngle() + PI2 / 90);
		setVertex();

		collision(player_shot);
	}
	void SideOption::draw(double crush_x, double crush_y) {
		lib::Graphics2D::drawModi(//ÉåÅ[ÉUÅ[Çï`âÊ
			crush_x + m_Pos_x[0] + AreaProp::min_x, m_Pos_y[0] + crush_y + AreaProp::min_y,
			crush_x + m_Pos_x[1] + AreaProp::min_x, m_Pos_y[1] + crush_y + AreaProp::min_y,
			crush_x + m_Pos_x[2] + AreaProp::min_x, m_Pos_y[2] + crush_y + AreaProp::min_y,
			crush_x + m_Pos_x[3] + AreaProp::min_x, m_Pos_y[3] + crush_y + AreaProp::min_y,
			res::BulletImage::Bullet.shot[0][0], true
		);
	}
	void SideOption::setVertex() {
		float r = 9;
		m_Pos_x[0] = m_Player_x + cos(getAngle() + PI / 2) * getThick() * (r / 50);
		m_Pos_y[0] = m_Player_y + sin(getAngle() + PI / 2) * getThick() * (r / 50);
		m_Pos_x[1] = m_Player_x + cos(getAngle() - PI / 2) * getThick() * (r / 50);
		m_Pos_y[1] = m_Player_y + sin(getAngle() - PI / 2) * getThick() * (r / 50);
		m_Pos_x[2] = m_Player_x + cos(getAngle() - PI / 2) * getThick() * (r / 50) + cos(getAngle()) * getLength();
		m_Pos_y[2] = m_Player_y + sin(getAngle() - PI / 2) * getThick() * (r / 50) + sin(getAngle()) * getLength();
		m_Pos_x[3] = m_Player_x + cos(getAngle() + PI / 2) * getThick() * (r / 50) + cos(getAngle()) * getLength();
		m_Pos_y[3] = m_Player_y + sin(getAngle() + PI / 2) * getThick() * (r / 50) + sin(getAngle()) * getLength();
	}
	void SideOption::collision(std::vector<PlayerShot>& player_shot) {
		Collider collider(Collider::TYPE::BULLET);
		HitSquare hit_sq;
		for (auto& shot : BulletManager::getInstance()->getShot()) {
			if (hit_sq.isHitCircle(m_Pos_x, m_Pos_y, shot.getX(), shot.getY(), collider.getBulletRange(shot.getType()) * shot.getSize())){
				int k;
				if ((k = search(player_shot)) != -1) {
					player_shot[k].setSpawn(shot.getX(), shot.getY(), 0, 17, 1, res::PLAYER_SHOT_TYPE::SHOT_COMET, PATTERN::HOMING, 5);
				}
			}
		}
	}
	int SideOption::search(std::vector<PlayerShot>& player_shot) {
		for (int i = 0; i < PLAYER_SHOT_MAX; i++) {
			if (!player_shot[i].isFlag()) {
				return i;
			}
		}
		return -1;
	}
	void SideOption::setAngle(float angle) {
		m_Angle = angle;
	}
	void SideOption::setLength(float length) {
		m_Length = length;
	}
	void SideOption::setThick(float thick) {
		m_Thick = thick;
	}
	float SideOption::getAngle() {
		return m_Angle;
	}
	float SideOption::getLength() {
		return m_Length;
	}
	float SideOption::getThick() {
		return m_Thick;
	}
}