#pragma once
#include "../../Source/Object/Object/Object.h"

namespace obj{
	enum GRAZE_EFFECT{
		START,
		UPDATE,
	};
	class GrazeEffect :public Object {
	private:
		const int m_Eeff_time = 15;
		const float m_Eff_size = 6.f;
	public:
		GrazeEffect();
		bool isState(int state);
	};
}