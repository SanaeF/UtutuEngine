#include "Collider.h"
#include <iostream>

#include "../../Source/Helper/Helper.h"
#include "../../Source/Collider/Square/HitSquare.h"
#include "../../Source/Object/Player/Shot/PlayerShot/PlayerShot.h"
#include "../../Source/Object/Player/Player.h"
#include "../../Source/SystemProp/AliceProp/AliceProp.h"
#include "../../Source/SystemProp/GameSceneProp/GameSceneProp.h"
#include "../../Source/Resource/SaveData/SaveData.h"
#include "../../Source/Resource/PlayerImage/PlayerImage.h"
namespace obj {
	void Collider::inputInfo() {
		inputBulletInfo(&m_Bullet[res::BULLET_TYPE::NORMAL		], 48,	48,		10, 17.0);
		inputBulletInfo(&m_Bullet[res::BULLET_TYPE::SCALY		], 32,	48,		10, 10.0);
		inputBulletInfo(&m_Bullet[res::BULLET_TYPE::OVERLAP		], 48,	48,		10, 15.0);
		inputBulletInfo(&m_Bullet[res::BULLET_TYPE::RICE		], 48,	48,		10, 8.0	);
		inputBulletInfo(&m_Bullet[res::BULLET_TYPE::POIFUL		], 50,	114,	10, 22.0);
		inputBulletInfo(&m_Bullet[res::BULLET_TYPE::BIG_STAR	], 102, 102,	10, 22.0);
		inputBulletInfo(&m_Bullet[res::BULLET_TYPE::DUST		], 32,	32,		10, 7.0	);
		inputBulletInfo(&m_Bullet[res::BULLET_TYPE::BIG			], 90,	92,		10, 27.0);
		inputBulletInfo(&m_Bullet[res::BULLET_TYPE::MEGA		], 103, 103,	10, 20.0);
		inputBulletInfo(&m_Bullet[res::BULLET_TYPE::AMMO		], 48,	48,		10, 10.0);
		inputBulletInfo(&m_Bullet[res::BULLET_TYPE::MINI_STAR	], 32,	32,		10, 6.0	);
		inputBulletInfo(&m_Bullet[res::BULLET_TYPE::BONE		], 32,	32,		10, 7.0	);
		inputBulletInfo(&m_Bullet[res::BULLET_TYPE::PETAL		], 32,	32,		10, 12.0	);
		inputBulletInfo(&m_Bullet[res::BULLET_TYPE::TRAMP		], 48,	48,		10, 15.0);
		inputBulletInfo(&m_Bullet[res::BULLET_TYPE::B_FLY		], 84,  84,		10, 27.0);
		inputBulletInfo(&m_Bullet[res::BULLET_TYPE::MOON		], 128, 128,	1,	27.0);
		inputBulletInfo(&m_Bullet[res::BULLET_TYPE::FAKE_APPLE	], 96,	96,		1,	30.0);
		inputBulletInfo(&m_Bullet[res::BULLET_TYPE::TURN_LAZ	], 32,	32,		10, 1.0	);
		inputBulletInfo(&m_Bullet[res::BULLET_TYPE::CLOCK_LAZ	], 32,	32,		10, 9.0	);
		inputBulletInfo(&m_Bullet[res::BULLET_TYPE::LAZER		], 50,	114,	10, 22.0);
		inputBulletInfo(&m_Bullet[res::BULLET_TYPE::EX_HAND		], 50,	114,	2,	60.0);
		inputBulletInfo(&m_Bullet[res::BULLET_TYPE::EX_META		], 50,	114,	6,	45.0);
		inputBulletInfo(&m_Bullet[res::BULLET_TYPE::EXCALIBUR	], 160, 320,	2,	60.0);
		inputBulletInfo(&m_Bullet[res::BULLET_TYPE::LOCK		], 160, 160,	0,	1.0	);
		inputBulletInfo(&m_Bullet[res::BULLET_TYPE::EFFECT		], 24,	24,		0,	16.0);
	}
	void Collider::inputPlayerShotInfo() {
		m_Player_shot_range[res::PLAYER_SHOT_TYPE::SHOT_BLUE] = 1;
		m_Player_shot_range[res::PLAYER_SHOT_TYPE::SHOT_CYAN] = 1;
		m_Player_shot_range[res::PLAYER_SHOT_TYPE::SHOT_POTATO] = 1;
		m_Player_shot_range[res::PLAYER_SHOT_TYPE::SHOT_COMET] = 1;
		m_Player_shot_range[res::PLAYER_SHOT_TYPE::SHOT_METEO] = 1;
		m_Player_shot_range[res::PLAYER_SHOT_TYPE::SHOT_BIRD] = 48;
		m_Player_shot_range[res::PLAYER_SHOT_TYPE::SHOT_MOON] = 50;
		m_Player_shot_range[res::PLAYER_SHOT_TYPE::LAZ_RED] = 1;
		m_Player_shot_range[res::PLAYER_SHOT_TYPE::LAZ_BLUE] = 1;
		m_Player_shot_range[res::PLAYER_SHOT_TYPE::LAZ_THUNDER] = 1;
	}
	void Collider::setInvPlayerBom(bool flag) {
		m_Is_inv_bom = flag;
	}
	int Collider::hitPlayerShot(float x, float y, float obj_size, int who) {
		if ((Player::PlayerObj.isBom()&& Player::PlayerObj.getType()!=res::PLAYER_TYPE::KANA) && m_Is_inv_bom)return HIT_TYPE::NONE;
		for (int num = 0; num < PLAYER_SHOT_MAX; num++) {
			PlayerShot* shot;
			shot = &Player::PlayerObj.getShot(num);
			if (who == 1)shot = &Player::PlayersObj[0].getShot(num);
			if (who == 2)shot = &Player::PlayersObj[1].getShot(num);
			if (shot->isFlag()) {
				float pos_x[2] = { shot->getX(),x };
				float pos_y[2] = { shot->getY(),y };
				float speed = shot->getSpeed();
				float m_Angle = shot->getAngle();
				int type = shot->getType();
				if (type >= res::PLAYER_SHOT_MAX)type = 0;
				float hit_range[2] = { m_Player_shot_range[type] * shot->getSize() ,obj_size };

				if (hitCircle(pos_x, pos_y, speed, m_Angle, hit_range)) {
					if (shot->isHitClear())shot->clear(true);
					int add_damage = 0;
					if (AliceProp::flag && GameSceneProp::stage != 6)add_damage = res::SaveData::save_data.weapon[AliceProp::weapon_type].strength / 10;
					return shot->getPower() + Player::PlayerObj.getItemStack().power / 100 + add_damage;
				}
			}
		}
		return HIT_TYPE::NONE;
	}
	int Collider::hitBullet(
		float get_x,
		float get_y,
		int get_type,
		float getSpeed,
		float getAngle,
		float size,
		int graze,
		int who
	) {
		Player* ch;
		ch = &Player::PlayerObj;
		if (who == 1)ch = &Player::PlayersObj[0];
		if (who == 2)ch = &Player::PlayersObj[1];
		if (Player::PlayersObj[0].isHideMode())ch = &Player::PlayersObj[1];
		if (Player::PlayersObj[1].isHideMode())ch = &Player::PlayersObj[0];
		float pos_x[2] = { get_x,ch->getX() };
		float pos_y[2] = { get_y,ch->getY() };
		if (graze == 0 || graze == 4) {
			float hit_range[2] = { m_Bullet[get_type].range * size ,ch->getHitRange() * 25 };
			if (hitCircle(pos_x, pos_y, getSpeed, getAngle, hit_range))return HIT_TYPE::GRAZE;
		}
		else {
			float hitRange[2] = { m_Bullet[get_type].range * size ,ch->getHitRange() };
			if (hitCircle(pos_x, pos_y, getSpeed, getAngle, hitRange))return HIT_TYPE::DAMAGE;
		}
		return HIT_TYPE::NONE;
	}
	int Collider::hitLazer(
		float get_x[4],
		float get_y[4],
		int get_type,
		float getSpeed,
		float getAngle,
		int graze,
		int who
	) {
		Player* ch;
		ch = &Player::PlayerObj;
		if (Player::PlayersObj[0].isHideMode())ch = &Player::PlayersObj[1];
		if (Player::PlayersObj[1].isHideMode())ch = &Player::PlayersObj[0];
		HitSquare square;
		if (graze == 0 || graze == 4) {
			if (square.isHitCircle(get_x, get_y, ch->getX(), ch->getY(), ch->getHitRange() * 25))return HIT_TYPE::GRAZE;
		}
		else {
			if (square.isHitCircle(get_x, get_y, ch->getX(), ch->getY(), ch->getHitRange()))return HIT_TYPE::DAMAGE;
		}
		return HIT_TYPE::NONE;
	}
	bool Collider::hitCircle(
		float get_x[2],
		float get_y[2],
		float getSpeed,
		float getAngle,
		float hit_range[2]
	) {
		float x = get_x[0] - get_x[1];		float y = get_y[0] - get_y[1];
		float r = hit_range[0] + hit_range[1];

		if (getSpeed > r) {//ÇPÉtÉåÅ[ÉÄëOÇ…Ç¢ÇΩà íuÇäiî[Ç∑ÇÈ
			float pre_x = get_x[0] + cos(getAngle + PI) * getSpeed;
			float pre_y = get_y[0] + sin(getAngle + PI) * getSpeed;
			float px = 0, py = 0;

			for (int j = 0; j < getSpeed / r; j++) {
				px = pre_x - get_x[1];			py = pre_y - get_y[1];
				if (FACT(px) + FACT(py) < FACT(r))return 1;
				pre_x += cos(getAngle) * r;	pre_y += sin(getAngle) * r;
			}
		}
		if (FACT(x) + FACT(y) < FACT(r))return true;
		return false;
	}
	int Collider::getBulletRange(int num) {
		return m_Bullet[num].range;
	}
	void Collider::inputBulletInfo(BulletObjInfo* binfo, int size_x, int size_y, int col_num, double range) {
		binfo->size_x = size_x;	binfo->size_y = size_y;
		binfo->col_num = col_num;
		binfo->range = range;
	}
	Collider::Collider(int type) {
		m_Is_inv_bom = false;
		if (type == TYPE::BULLET)inputInfo();
		if (type == TYPE::PLAYER_SHOT)inputPlayerShotInfo();
	}
}