#pragma once
#include "FadeIn.h"
#include <iostream>

namespace obj {
	FadeIn::FadeIn():
		flag(false),
		count(0),
		count_max(0),
		size(0.f)
	{
	}
	void FadeIn::initialize() {
		flag = false;
		count = 0;
		count_max = 0;
		size = 0.f;
	}
	void FadeIn::setParam(int count) {
		flag = true;
		count_max = count;
	}
	void FadeIn::update() {
		if (flag) {
			count++;
			if (count_max <= count)initialize();
		}
	}
	int FadeIn::getCount() {
		return count;
	}
	bool FadeIn::isFlag() {
		return flag;
	}
	float FadeIn::getSize(float num) {
		if (flag)return (num / count_max) * count;
		else return num;
	}
}