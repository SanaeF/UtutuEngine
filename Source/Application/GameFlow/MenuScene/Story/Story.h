#pragma once
#include "../../Scene/Scene.h"
#include "../../Source/Tools/TimeFader/TimeFader.h"
namespace app {
	class Story : public Scene {
	private:
		enum CHANGE_TYPE {
			NONE,
			SELECT,
			CHANCEL
		};
		/*struct SelectUI{
			int x, y;
			char name[128];
		};*/
		TimeFader m_Fade_leave;
		TimeFader m_Fade_approach;
		float m_Leave_y;
		int m_Change_type;
	public:
		void select()override;
		void cancel()override;
		int update()override;
		void draw()override;
		Story();
		~Story();
	private:
		void sceneChanger();
	};
}