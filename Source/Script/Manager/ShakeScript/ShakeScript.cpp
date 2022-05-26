#pragma once
#include "ShakeScript.h"
#include <iostream>
#include "../../Source/EffectTools/Shake/Shake.h"

namespace script {
	bool ShakeScript::m_Flag;
	int ShakeScript::m_Time;
	float ShakeScript::m_Size;
	ShakeScript::ShakeScript(lua_State* L){
		m_Flag = false;
		m_Time = false;
		m_Size = false;
		lua_register(L, "ShakeFunc", l_Shake);
	}
	int ShakeScript::l_Shake(lua_State* L) {
		m_Flag = true;
		m_Time = lua_tonumber(L, -2);
		m_Size = lua_tonumber(L, -1);
		return 1;
	}
	void ShakeScript::setShake(std::shared_ptr<app::Shake>& m_Shake) {
		if (m_Shake == nullptr)return;
		if (m_Flag) {
			m_Shake->set(m_Size, m_Time);
			m_Flag = false;
		}
	}
	ShakeScript::~ShakeScript() {
	}
}