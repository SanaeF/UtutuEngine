#pragma once
#include "../Object/Object/Parameter/Position/Position.h"
namespace localmap {
	class World {
	private:
		int m_State;
	public:
		enum TYPE{
			FREE,
			AUTO,
			BOSS,
		};
		void setWorldState(int state);
		obj::Position pos0;
	private:
		bool isNotFree();
	};
}