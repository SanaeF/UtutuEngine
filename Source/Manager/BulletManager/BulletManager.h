#pragma once
#include <vector>
namespace obj {
	class Shot_Info;
	class Lazer_Info;
	class TurnLazer_Info;

	//���̃N���X�̓C���X�^���X���擾���Ĉ���
	class BulletManager {
	private:
		static BulletManager m_Bullet_obj;
		std::vector<Shot_Info> m_Shot;
		std::vector<Lazer_Info> m_Laser;
		std::vector<TurnLazer_Info> m_TurnLaser;
		int m_Shot_loop_max;
		int m_Laser_loop_max;
		int m_TurnLaser_loop_max;
		BulletManager();
	public:
		static BulletManager* getInstance();

		void initialize();

		//�e���̒e��S�̍X�V
		void update();

		//�e���̒e��S�̕`��
		void draw(double crush_x, double crush_y);

		void stop();

		//�e���̒e��S�̍폜(�����̓G�t�F�N�g�����邩�ǂ���)
		void clear(bool flag);

		void setShotLoopMax(int max);
		void setLaserLoopMax(int max);
		void setTurnLaserLoopMax(int max);
		
		std::vector<Shot_Info>& getShot();
		std::vector<Lazer_Info>& getLaser();
		std::vector<TurnLazer_Info>& getTurnLaser();
	};
}