#pragma once
#include <memory>
#include "../../Source/Application/GameFlow/Scene/Scene.h"
#include "../../Source/Tools/TimeFader/TimeFader.h"
namespace app {
	class CharaProfile;
	class CharaSelect : public Scene{
	private:
		enum STATE {
			DEF,
			CAMP,
			GAME
		};
		enum CHANGE_TYPE {
			NONE,
			SELECT,
			BACK
		};
		std::shared_ptr<CharaProfile>m_Profile;
		SelectYN m_Select_YN;
		TimeFader m_Fade_in;
		TimeFader m_Fade_back;
		TimeFader m_Fade_out;
		float m_Add_x;
		int m_Change_type;
		int m_State;
		int m_Select_num;
		int m_Camp_select;
	public:
		CharaSelect();
		int update()override;
		void draw()override;
		void select()override;
		void cancel()override;
		int getCharaType();
	private:
		void sceneChanger();
	};
}