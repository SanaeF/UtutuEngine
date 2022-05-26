#include "Helper.h"

#include "../../Source/Application/Replayer/Replayer.h"
namespace helper_class {
	int Helper::m_Time = 0;
	std::mt19937 Helper::m_Mt19937;
	bool Helper::condition(int value, int num1, int num2) {
		if (num1 <= value && value < num2)return true;
		return false;
	}
	bool Helper::coolCounter(int cooltime) {
		if (cooltime == m_Time)return true;
		else m_Time++;
		return false;
	}

	void Helper::setTime(int time) {
		m_Time = time;
	}
	void Helper::setSeed(int seed) {
		m_Mt19937.seed(seed);
	}
	int Helper::setRandomSeed(int max) {
		int seed = getRand(max);
		setSeed(seed);
		return seed;
	}
	int Helper::getRand(int max) {
		std::random_device rnd;
		std::mt19937 mt;
		mt.seed(rnd());
		std::uniform_int_distribution<> random(0, max);
		return random(mt);
	}
	int Helper::getSRand(int max) {
		std::uniform_int_distribution<> random(0, max);
		return random(m_Mt19937);
	}
}