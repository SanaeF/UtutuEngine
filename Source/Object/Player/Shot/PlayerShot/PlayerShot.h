#pragma once
#include "../../Source/Object/Object/Object.h"

namespace obj {
	enum {
		PLAYER_SHOT_MAX = 200
	};
	enum PATTERN {
		NONE,//通常
		LAZER,//レーザー
		ANGULAR,//湾曲
		CIRCLE_SCRAMBLE,//円形変曲
		DAMAGE_CHANGER,//距離で弱体化
		HOMING,//ホーミング
		CHANGE_HOMING,//途中からホーミング
		STOP//移動の計算をしない
	};
	class Effect;
	class PlayerShot:public Object {
	private:
		Field m_Field;
		std::shared_ptr<Effect>m_Effect;
		int pattern;
		int power;
		int change_type;
		float add_x;
		float add_y;
		float angle;
		float img_ang;
		float speed;
		bool is_hitClear;
		bool is_shine;
	public:
		PlayerShot();
		~PlayerShot();
		void initialize(int max_x, int min_x);
		void update();
		void draw(double crush_x, double crush_y);
		void setSpawn(float x, float y, float m_Angle, float speed, float size, int type, int pattern, int power);
		void setHitClear(bool flag);
		void setAddPos(float x, float y);
		void setPower(int power);
		void setChangeType(int type);
		void doChange();
		void clear(bool flag);
		void setShine(bool flag);
		void setSpeed(float speed);
		void setAngle(float angle);
		void setImgAng(float angle);
		void setPattern(int type);
		int getPattern();
		int getChangeType();
		float getAddX();
		float getAddY();
		float getSpeed();
		float getAngle();
		float getImgAng();
		float getPower();
		bool isHitClear();
		bool isShine();
	private:
		void mover();
		void outOfBoaderUpdate();
	};
}