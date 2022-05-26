#pragma once
namespace obj {
	class Position {
	public:
		float x;
		float y;
		float z;
		Position(float x, float y, float z);
		Position();
		void set(float x, float y, float z);
	};
}