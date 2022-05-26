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

		bool m_Is_bullet;//�e���t���O
		bool m_Is_invalid_bom;//�{�������t���O
		bool m_Is_invincible;//�_���[�W�����t���O
		bool m_Is_special_bullet;//�X�y�V�����e���t���O(�w�i���ς��)
		bool m_Is_need_all_kill;//�S���̃{�X��|���K�v�����邩�ǂ���
		bool m_Is_return_back;//�{�X���ꎞ�P�ނ���t���O
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

		//�{�X�̏���
		void summon(int type,int index=0);
		void summon(double x, double y, int type, int index = 0);

		void removeNoLife();

		//�{�X�̐��ɍ��킹�Ĉړ�������
		void changePosition();

		void returnBackPosition();

		//�{�X�e���̊J�n
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

		//�������Ԃ̃J�E���g
		void countTimer();

		//�e���������I���������
		bool isOverParam();

		//���݂̃X�e�[�g�ƈ�v���Ă��邩�ǂ���
		bool isState(int state);
	};
}