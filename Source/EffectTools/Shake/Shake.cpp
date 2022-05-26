#include "Shake.h"
#include "../../Source/Helper/Helper.h"

namespace app {
	Shake Shake::crush;
	void Shake::update() {
		if (m_Flag) {
			this->m_Px = GET_SEED_RANDOM_F(this->m_Size % 200);
			this->m_Py = GET_SEED_RANDOM_F(this->m_Size % 200);
			this->m_Count++;
			if (m_Count > m_Time) {//Žw’è‚³‚ê‚½ŽžŠÔ‚ª‚½‚Â‚ÆI‚í‚é
				m_Flag = false;
				this->m_Px = 0.f;
				this->m_Py = 0.f;
			}
		}
		else {
			this->m_Px = 0.f;
			this->m_Py = 0.f;
			this->m_Count = 0;
			this->m_Size = 0;
			this->m_Time = 0;
		}
	}

	void Shake::set(int size, int time) {
		m_Flag = true;
		this->m_Count = 0;
		this->m_Size = size;
		this->m_Time = time;
	}

	double Shake::get_x() {
		return this->m_Px;
	}

	double Shake::get_y() {
		return this->m_Py;
	}
}