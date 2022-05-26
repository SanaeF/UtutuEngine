#pragma once
#include <memory>

#include "../../Source/Object/Object/Object.h"

class Transform;
namespace obj {
	class Effect;
	class BossScriptManager;
	class Boss : public  Object {
	private:
		std::shared_ptr<Effect> m_KillEffect;
		std::shared_ptr<Effect> m_ChargeEffect;
		std::shared_ptr<Transform>m_Transform;
		FadeIn m_Fade_size;
		int m_HP;
		int m_HP_max;
		int m_State;
		int m_Img_state;
		int m_Dist_max;
		int m_Dist_min;
		float m_Img_rotation;
		int m_Image_count;
		int m_Motion_type;
		float m_Angle;
		bool m_Is_motion;
		bool m_Is_death_effect;
	public:
		enum EFFECT_TYPE {
			DEAD,CHARGE
		};
		void setFadeIN();

		void draw(double crush_x = 0.f, double crush_y = 0.f);
		void update();
		void setDamage(int damage);


		void statsReset();
		void setAnimationType(int type);
		void summonEffect(int type);
		void moveRand(float x0, float y0, float x1, float y1, float dist, int time);
		void movePos(float px, float py, int time);
		void collision(bool is_invalid_bom);
		void setHP(int hp);
		void setHPMax(int hp);
		void setDeathEffect(bool flag);
		int getHP();
		int getHPMax();
		bool isDeathEffect();
		Boss();
		~Boss();
	private:
		void move();
		//スクリプトによるランダム移動
		bool isState(int state);
	};


}