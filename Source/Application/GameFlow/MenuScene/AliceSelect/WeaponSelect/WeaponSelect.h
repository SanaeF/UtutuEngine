#pragma once
#include <iostream>
#include "../../Source/Application/GameFlow/Scene/Scene.h"
namespace app {
	class WeaponSelect : public Scene {
	private:
		enum {
			WP_SELECT,
			DEL_SELECT
		};
		SelectYN m_Select_YN;
		int m_Scene_type;
		int m_Last_id;
		int m_Weapon_id;
		bool m_Is_select;
	public:
		void initialize();
		void initialize(int id);
		void draw();
		int update();
		void select()override;
		void cancel()override;
		int getID();
		bool isSelect();
	};
}