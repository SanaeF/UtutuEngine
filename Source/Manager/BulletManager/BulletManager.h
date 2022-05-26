#pragma once
#include <vector>
namespace obj {
	class Shot_Info;
	class Lazer_Info;
	class TurnLazer_Info;

	//このクラスはインスタンスを取得して扱う
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

		//弾幕の弾を全体更新
		void update();

		//弾幕の弾を全体描画
		void draw(double crush_x, double crush_y);

		void stop();

		//弾幕の弾を全体削除(引数はエフェクトをつけるかどうか)
		void clear(bool flag);

		void setShotLoopMax(int max);
		void setLaserLoopMax(int max);
		void setTurnLaserLoopMax(int max);
		
		std::vector<Shot_Info>& getShot();
		std::vector<Lazer_Info>& getLaser();
		std::vector<TurnLazer_Info>& getTurnLaser();
	};
}