#include "AliceProp.h"
#include "../../Source/Helper/Helper.h"
#include <iostream>
bool AliceProp::flag = false;
int AliceProp::weapon_type;
int AliceProp::level_num = 0;
float AliceProp::add_size = 0;
float AliceProp::add_speed = 0;

void AliceProp::invalid() {
	flag = false;
	add_size=0;
	add_speed=0;
	weapon_type = 0;
}
void AliceProp::recreate() {
	setup(level_num);
}
void AliceProp::noParamater() {
	add_size = 0;
	add_speed = 1;
}
void AliceProp::setup(int level) {
	level_num = level;
	int rest = 0;
	if (BEDWEEN(level, 1, 30))rest = 0;
	if (BEDWEEN(level, 31, 70))rest = -31;
	if (level > 70)rest = -71;
	if (level > 100)rest = -GET_RANDOM(100);
	flag = true;
	float lv_size = (level + rest);
	float rand_size = GET_RANDOM_F(lv_size);
	lv_size = (lv_size / 2) + (rand_size / 2);
	add_size = (1.7f / 100.f) * lv_size;
	add_speed = 1 + (1.5f / 100.f) * lv_size;
}