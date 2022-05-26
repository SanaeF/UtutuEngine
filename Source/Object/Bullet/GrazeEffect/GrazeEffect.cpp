#include "GrazeEffect.h"
#include <iostream>
#include "../../Source/Helper/Helper.h"

namespace obj {
	GrazeEffect::GrazeEffect() {
		this->valueReset();
	}
	bool GrazeEffect::isState(int state) {
		if (state == GRAZE_EFFECT::START) {
			setX(0);
			setY(0);
			setCount(0);
			return true;
		}
		if (state == GRAZE_EFFECT::UPDATE) {
			setX(GET_SEED_RANDOM_F(m_Eff_size));
			setY(GET_SEED_RANDOM_F(m_Eff_size));
			setCount(getCount() + 1);
			if (getCount() > m_Eeff_time) {//w’è‚³‚ê‚½ŠÔ‚ª‚½‚Â‚ÆI‚í‚é
				setX(0);
				setY(0);
				setCount(0);
				return true;
			}
			else return false;
		}
		return false;
	}

}