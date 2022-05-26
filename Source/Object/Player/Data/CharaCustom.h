#pragma once
struct CharaCustom {
	int outer_wear_type;
	int under_wear_type;
	bool unlocked_outer_wear[6];
	bool unlocked_under_wear[6];
	void initialize() {
		outer_wear_type = 0;
		under_wear_type = 0;
		for (int ite = 0; ite < 6; ite++) {
			unlocked_outer_wear[ite] = false;
			unlocked_under_wear[ite] = false;
		}
	}
};
