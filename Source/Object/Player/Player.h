#pragma once
#include "../../Source/Object/Object/Object.h"
#include "../../Source/Object/Player/mover/PlayerMover.h"
#include "../../Source/Object/Player/Item/ItemStack.h"
#include <memory>
#include <vector>

#define HitRange 4.0
namespace obj {
	class Bom_Info;
	class Boss;
	class Effect;
	class Minion;
	class PlayerShot;
	class OptionManager;
	class Player : public Object {
	public:
		static Player PlayerObj;
		static Player PlayersObj[2];
		enum PAD_TYPE {
			DEF, P1, P2, NONEP
		};
	private:
		enum STATE {
			NONE,
			INVINCIBLE,
			DAMAGE
		};
		enum {
			INVINCIBLE_COUNT = 180,
		};
		Field m_Field;
		PlayerMover m_Mover;
		ItemStack m_Item;
		std::shared_ptr<Bom_Info> m_Bom;
		std::shared_ptr<Effect> m_Effect;
		int m_Slow;
		int PAD_TYPE;
		int m_Image_state;
		int m_Invincible_count;
		int m_After_life;
		int m_After_power;
		int m_Graze_bounus;
		int m_Draw_bright;
		int m_Key_input_data[3];
		int m_Bom_time[6];
		int m_Graze_count;
		bool m_Is_roulette;
		bool m_Is_damage;
		bool m_Is_bom;
		bool m_Is_vs_mode;
		bool m_Is_hide;
		bool m_Is_connecting;
		bool m_Is_graze;
		bool m_Is_no_shoot;
	public:
		Player();
		~Player();
		void initialize(int type, int max_x, int min_x,bool m_Is_vs_mode = false);
		void loadState(int type);
		void update();
		void draw(double crush_x, double crush_y);
		void drawHitbox();
		void damage();
		void setKeyPad(int type);
		void setBomFlag(bool flag);
		void setHide();
		void setRoulette(bool flag);
		void setIsGraze(bool flag);
		void setServerInputData(
			int state,
			int m_Is_bom,
			int life_num,
			int bom_num,
			int img,
			int m_Slow,
			int knd,
			int shot_bullet[3],
			float x,
			float y
		);
		void initOption();
		void setNoShoot(bool flag);
		int getKeyInputData(int num);
		int getImgState();
		int getHitRange();
		bool isRoulette();
		bool isBom();
		bool isHideMode();
		bool isSlow();
		bool isDamageNow();
		bool isGraze();
		PlayerShot& getShot(int num);
		ItemStack& getItemStack();
	private:
		void damageUpdate();
		void invincibleUpdate();
		void moveUpdate();
		void bomUpdate();
		void shootUpdate();
		void keyInputUpdate();
		int getKey(int num);
		bool isKeyIn(int num);
	};
}

