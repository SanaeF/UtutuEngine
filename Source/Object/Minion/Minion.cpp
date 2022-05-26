#include "Minion.h"
#include "MinionMotion/MinionMotion.h"
#include "../../Source/Object/Boss/BossMotion/BossMotion.h"
#include "../../Source/SystemProp/AreaProp.h"
#include "../../Source/SystemProp/AliceProp/AliceProp.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/Resource/EnemyImage/EnemyImage.h"
#include "../../Source/Resource/ItemImage/ItemImage.h"
#include "../../Source/Resource/GUI/BossUIImage/BossUIImage.h"
#include "../../Source/Collider/Collider.h"
#include "../../Source/Object/Effect/Effect.h"
#include "../../Source/Manager/ItemManager/ItemManager.h"
#include "../../Source/MassageHandle/MassageHandle.h"
#include "../../Source/Tools/Transform/Transform.h"

namespace obj {
	Minion::Minion()
	{
		m_Fade_size.initialize();
		m_Effect.reset(new Effect());
		m_ItemSpawner.reset(new ItemManager());
		m_Transform.reset(new Transform());
		m_Fade_time = 30;
		m_Field.m_Max_x = 0;
		m_Field.m_Min_x = 0;
	}
	void Minion::draw(double crush_x, double crush_y) {
		if (isFlag()) {
			lib::Graphics2D::setArea(m_Field.m_Min_x, AREA::FMIN_Y, m_Field.m_Max_x, AREA::FMAX_Y);
			float size = getSize();
			if (AliceProp::flag)size = size + AliceProp::add_size;
			lib::Graphics2D::setBright(200 + m_Fade_size.getSize(55), m_Fade_size.getSize(255), 55 + m_Fade_size.getSize(200));
			lib::Graphics2D::drawRota(
				getX() + m_Field.m_Min_x + crush_x,
				getY() + AREA::FMIN_Y + crush_y,
				m_Fade_size.getSize(size),
				m_Image_rotation,
				res::EnemyImage::enemy.minion[getType()][m_Image_state],
				true
			);
			lib::Graphics2D::setArea(0, 0, 1920, 1440);
			lib::Graphics2D::setBright(255, 255, 255);
		}
	}
	void Minion::update(bool bullet_flag) {
		if (isFlag()) {
			if (getCount() == 0) {
				m_Fade_size.setParam(30);
			}
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
			if (m_Transform->isMove()) {
				m_Transform->update();
				setX(m_Transform->getMoved().x);
				setY(m_Transform->getMoved().y);
			}
			else {
				setX(getX() + (cos(getAngle()) * getSpeed()));
				setY(getY() + (sin(getAngle()) * getSpeed()));
			}
			collision();
			mOutOfBoarder();
			countUpdate();
			m_Fade_size.update();
			MinionMotion motion(getType(), m_Img_count);
			m_Image_state = motion.imgState();
			m_Image_rotation = motion.imgRotation();
			if (m_HP <= 0) {
				killBounus();
			}
			m_Img_count++;
		}
	}
	void Minion::mOutOfBoarder() {
		//‰æ–Ê˜g‚Éo‚½‚çíœ
		if (getX() < -60 ||
			getX() > double(m_Field.m_Max_x - m_Field.m_Min_x + 60) || 
			getY() < -60 || 
			getY() > double(FMAX_Y - FMIN_Y + 60)) {
			this->setFlag(false);
			this->kill();
		}
	}
	void Minion::killBounus() {
		int item_num = m_Item_num;
		if (m_Item == res::ITEM_TYPE::START_ROULETTE)item_num = getCount();
		m_ItemSpawner->drop(getX(), getY(), item_num, m_Item, getRayer());
		setFlag(false);
		this->kill(true);
		m_Effect->setFlag(true);
		m_Effect->setX(getX());
		m_Effect->setY(getY());
		m_Effect->setColor(0);
		m_Effect->setType(Effect::SHOT_CLEAR);
	}
	void Minion::collision() {
		if (!isFlag() && m_Fade_size.isFlag())return;
		if (m_HP_max >= 999999)return;
		Collider collider(Collider::PLAYER_SHOT);
		int hitRange = 40 * getSize();
		auto result = collider.hitPlayerShot(getX(), getY(), hitRange, getRayer());
		if (result != Collider::NONE) {
			this->m_HP -= result;
			MassageHandleItem(PLAYER::GetScore, result, getRayer());
		}
	}
	void Minion::setStage(int stage) {
		m_Stage = stage;
	}
	void Minion::setHP(int hp) {
		m_HP_max = hp;
		m_HP = hp;
	}
	void Minion::setLastHP(int hp) {
		m_HP = hp;
	}
	void Minion::setMoveType(int type) {
		m_Move_type = type;
	}
	void Minion::setBulletType(int type) {
		m_Bullet_type = type;
	}
	void Minion::setItemType(int type) {
		m_Item = type;
	}
	void Minion::setAngle(float angle) {
		m_Angle = angle;
	}
	void Minion::setSpeed(float speed) {
		m_Speed = speed;
	}
	void Minion::setBulletObjColor(int num) {
		m_bulletColor = num;
	}
	void Minion::setBulletObjType(int num) {
		m_bulletType = num;
	}
	void Minion::setMotion(int type) {
		m_Motion_type = type;
	}
	void Minion::setItemNum(int num) {
		m_Item_num = num;
	}
	void Minion::setMove(float target_x, float target_y, int count) {
		m_Transform->setTrans(getX(), getY(), target_x, target_y, count);
	}
	void Minion::setRandMove(float x1, float y1, float x2, float y2, float dist, int t) {
		m_Transform->randMove(getX(), getY(), x1, y1, x2, y2, dist, t);
	}
	float Minion::getAngle() {
		return m_Angle;
	}
	float Minion::getSpeed() {
		return m_Speed;
	}
	int Minion::getHP() {
		return m_HP;
	}
	int Minion::getMaxHP() {
		return m_HP_max;
	}
	int Minion::getItem() {
		return m_Item;
	}
	int Minion::getMoverID() {
		return m_Move_type;
	}
	int Minion::getBulletID() {
		return m_Bullet_type;
	}
	int Minion::getBulletObjColor() {
		return m_bulletColor;
	}
	int Minion::getBulletObjType() {
		return m_bulletType;
	}
	void Minion::kill(bool deathFlag) {
		if(isFlag())killBounus();
		m_Transform->resetParam();
		valueReset(deathFlag);
		m_Fade_size.initialize();
		m_Stage = false;
		m_Angle = false;
		m_Speed = false;
		m_HP = false;
		m_HP_max = false;
		m_Move_type = false;
		m_Bullet_type = false;
		m_Item = false;
		m_File = nullptr;
		m_Image_rotation = 0.f;
		m_Image_state = false;
		m_Img_count = false;
		m_Magring_count = false;
		m_Item_num = 0;
		m_Motion_type = 0;
	}
}