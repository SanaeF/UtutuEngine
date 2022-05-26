#pragma once
#include "../../Source/Application/GameFlow/Scene/Scene.h"
#include <memory>

namespace app {
	class EndingScene;
	class MusicRoom :public Scene {
	private:
		enum STATE {
			BGM,
			MOVIE,
		};
		MenuText m_Music_name[17] = {
		{ (440) * 2, 370 * 2, "0" },//ëŒè€
		{ (440 - 2 * 1) * 2, 410 * 2, "0" },
		{ (440 - 4 * 2) * 2, 450 * 2, "0" },
		{ (440 - 6 * 3) * 2, 490 * 2, "0" },
		{ (440 - 8 * 4) * 2, 530 * 2, "0" },
		{ (440 - 10 * 5) * 2, 570 * 2, "0" },
		{ (440 - 12 * 6) * 2, 610 * 2, "0" },//àÍî‘â∫

		{ (440 - 18 * 10) * 2, -30 * 2, "0" },//àÍî‘è„
		{ (440 - 16 * 8) * 2, 10 * 2, "0" },
		{ (440 - 14 * 7) * 2, 50 * 2, "0" },
		{ (440 - 12 * 6) * 2, 90 * 2, "0" },
		{ (440 - 10 * 5) * 2, 130 * 2, "0" },
		{ (440 - 8 * 4) * 2, 170 * 2, "0" },
		{ (440 - 6 * 3) * 2, 210 * 2, "0" },
		{ (440 - 4 * 2) * 2, 250 * 2, "0" },
		{ (440 - 2 * 1) * 2, 290 * 2, "0" },
		{ (440 - 0 * 1) * 2, 330 * 2, "0" }
		};
		std::shared_ptr<EndingScene>m_Ending;
		int m_Select;
		int m_Count;
		int m_State;
		const int m_BGM_max = 17;
		void musicText(
			const char* msg0,
			const char* msg1,
			const char* msg2,
			const char* msg3,
			const char* msg4,
			const char* msg5,
			const char* msg6,
			const char* msg7,
			const char* msg8,
			const char* msg9,
			const char* msg10
		);
	public:

		int update()override;
		void draw()override;
		void select()override;
		void cancel()override;
		MusicRoom();
	};
}