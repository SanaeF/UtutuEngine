#pragma once
#include "../../Source/Application/GameFlow/Scene/Scene.h"

namespace app {
	class StageSelect : public Scene {
	private:
		bool m_Is_select;
		int m_Count;
		int m_Stage;
		int m_Bullet_type;
		int m_Num[2];
		int m_Massage_flag;
	public:
		int update()override;
		void draw()override;
		void select()override;
		void cancel()override;
		void firstStage();
		void setWorld(int world);
		void setStage(int stage);
		int getWorld();
		int getStage();
		bool isSelected();
		StageSelect();
		~StageSelect();
	private:
		void stageMenu(
			int stage,
			const char* prologue,
			const char* name0, 
			const char* name1, 
			const char* name2, 
			const char* name3, 
			const char* name4
		);
	};
}