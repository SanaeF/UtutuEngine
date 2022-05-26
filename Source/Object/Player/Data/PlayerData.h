#pragma once
struct PlayerData {
	int score;
	int life;
	int bom;
	int life_frag;
	int bom_frag;
	int power;
	int point;
	void initialize() {
		score = 0;
		life = 0;
		bom = 0;
		life_frag = 0;
		bom_frag = 0;
		power = 0;
		point = 0;
	}
};