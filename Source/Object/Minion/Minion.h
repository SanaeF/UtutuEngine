#pragma once
#include "../../Source/Object/Object/Object.h"
#include <memory>
namespace script {
	class MinionBulletScript;
	class MinionMoverScript;
}
class Transform;
namespace obj {
	enum {
		MINION_NUM_MAX = 500,
	};
	class Effect;
	class ItemManager;
	class Minion : public  Object {
	private:
		std::shared_ptr<Transform>m_Transform;
		std::shared_ptr<ItemManager> m_ItemSpawner;
		std::shared_ptr<Effect>m_Effect;
		FadeIn m_Fade_size;
		Field m_Field;
		int m_Stage;
		float m_Angle;
		float m_Speed;
		int m_HP;
		int m_HP_max;
		int m_Move_type;
		int m_Bullet_type;
		int m_Motion_type;
		int m_Item;
		int m_Item_num;
		char* m_File;
		float m_Image_rotation;
		int m_Image_state;
		int m_Img_count;
		int m_Magring_count;
		int m_bulletColor;
		int m_bulletType;//m_Bullet_typeÇ∆ÇÕï ï®Ç»ÇÃÇ≈íçà”
		int m_Fade_time;
	public:
		Minion();
		void kill(bool deathFlag = false);
		void draw(double crush_x = 0.f, double crush_y = 0.f);
		void update(bool bullet_flag = true);
		void collision();
		void killBounus();
		void setStage(int stage);
		void setHP(int hp);
		void setLastHP(int hp);
		void setMoveType(int type);
		void setBulletType(int type);
		void setItemType(int type);
		void setItemNum(int num);
		void setAngle(float angle);
		void setSpeed(float speed);
		void setBulletObjColor(int num);
		void setBulletObjType(int num);
		void setMotion(int type);
		void setMove(float target_x, float target_y, int count);
		void setRandMove(float x1, float y1, float x2, float y2, float dist, int t);
		float getAngle();
		float getSpeed();
		int getHP();
		int getMaxHP();
		int getMoverID();
		int getBulletID();
		int getItem();
		int getBulletObjColor();
		int getBulletObjType();
	private:
		void mOutOfBoarder();
	};
}