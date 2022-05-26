#pragma once
#include "../../Source/Object/Boss/Boss.h"
#include "BossHP/BossHP.h"
#include "MagicRingEffect/MagicRingEffect.h"
#include <memory>
#include <vector>
namespace obj {
	class Boss;
	class BossHP;
	class BossUI;
	class BossBonus;
	class MagicRingEffect;
}
namespace script {
	class BulletScript;
}
namespace manager {
	class BossManager {
	private:
		enum PHASE {
			NONE,
			WAIT,
			BULLET,
			END,
			AFTER
		};
		struct BossObj{
			obj::Boss boss;
			obj::BossHP hp;
			obj::MagicRingEffect magic_ring;
		};
		static BossManager m_Instance;
		std::vector<BossObj> m_Boss_obj;
		std::shared_ptr<obj::BossUI> m_UI;
		std::shared_ptr<obj::BossBonus> m_Bonus;

		std::shared_ptr<script::BulletScript> m_Script;

		bool m_Is_bullet;//弾幕フラグ
		bool m_Is_invalid_bom;//ボム無効フラグ
		bool m_Is_invincible;//ダメージ無効フラグ
		bool m_Is_special_bullet;//スペシャル弾幕フラグ(背景が変わる)
		bool m_Is_need_all_kill;//全部のボスを倒す必要があるかどうか
		bool m_Is_return_back;//ボスが一時撤退するフラグ
		int m_First_bullet;
		int m_End_bullet;
		int m_Bullet_type;
		int m_Time;
		int m_Time_max;
		int m_Wait_time;
		int m_State;
		int m_Count;
		BossManager();
	public:
		static BossManager* getInstance();

		void initialize();

		//ボスの召喚
		void summon(int type,int index=0);
		void summon(double x, double y, int type, int index = 0);

		void removeNoLife();

		//ボスの数に合わせて移動させる
		void changePosition();

		void returnBackPosition();

		//ボス弾幕の開始
		void startBullet(int start_num, int end_num);

		void update();
		void draw(double crush_x, double crush_y);
		void drawUI(double crush_x = 0.f, double crush_y = 0.f);

		void setTimer(int time);
		void setWaitTime(int time);
		void setInvalidBom(bool flag);
		void setInvincible(bool flag);
		void setSpecialBullet(bool flag);
		void setReturnBack(bool flag);

		bool isFlag();
		bool isSpecialBullet();
		int getTime();
		int getCount();
		std::vector<BossObj>& getBossList();
		std::shared_ptr<obj::BossUI>& getUIInstance();
	private:
		void resetBossBulletFlag();
		void loadScript();

		//制限時間のカウント
		void countTimer();

		//弾幕を強制終了する条件
		bool isOverParam();

		//現在のステートと一致しているかどうか
		bool isState(int state);
	};
}