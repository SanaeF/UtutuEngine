#pragma once

class AliceProp {
public:
	static bool flag;
	static int weapon_type;
	static int level_num;
	static float add_size;
	static float add_speed;
public:
	static void invalid();
	static void recreate();
	static void noParamater();
	static void setup(int level);
};