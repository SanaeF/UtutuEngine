#pragma once
namespace res {
	struct BossEffect {
		int kill[5];
		int charge;
	};
	struct ShotEffect {
		int kill[10];
	};
	struct PlayerEffect {
		int kill;
	};
	class ParticleImage {
	public:
		BossEffect m_Boss;
		ShotEffect shot;
		PlayerEffect player;
		static void load();
		static ParticleImage effect;
	};
}