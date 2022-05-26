#pragma once
#include "Position.h"
#include <iostream>

namespace obj {
	Position::Position(float x, float y, float z):
		x(x),
		y(y),
		z(z)
	{
	}
	Position::Position():
		x(0.f),
		y(0.f),
		z(0.f)
	{
	}
	void Position::set(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
}