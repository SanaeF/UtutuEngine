#pragma once
#include <iostream>
#include "../../Source/Application/GameFlow/Scene/Scene.h"
#include "WeaponSelect/WeaponSelect.h"
namespace app {
	class AliceSelect : public Scene {
	private:
		enum SELECT_STATE {
			NONE,
			LEVEL,
			WEAPON,
		};
		WeaponSelect m_WeaponSelect;
		bool m_Is_locked;
		int m_Level;
		int m_Lv_select;
		int m_Weapon_type;
		int m_Menu_type;
		int m_State;
	public:
		AliceSelect();
		void select()override;
		void cancel()override;
		int update()override;
		void draw()override;
	private:
		void menuSelect();
		void levelSelect();
	};
}