#pragma once
#include <memory>

namespace obj {
	//class Boss;
	class ItemManager;
}
namespace script {
	class ShotScript;
	class LazerScript;
	class TurnLazerScript;
}
namespace app {
	class SubTitle;
	class ScoreBoard;
	class Sound;
	class GameMassage;
	class TalkSceneManager;
	class StageMap;
	class SaveDataManager;
	class TimeLine;
	class EndingScene;
	class ItemRoulette;
	class StoryMode {
	private:
		//std::shared_ptr<obj::Boss> m_Boss;
		/*std::shared_ptr<script::ShotScript> m_ShotScript;
		std::shared_ptr<script::LazerScript> m_LazerScript;
		std::shared_ptr<script::TurnLazerScript> m_TurnLazerScript;*/
		std::shared_ptr<SubTitle> m_SubTitle;
		std::shared_ptr<ScoreBoard> m_Board;
		std::shared_ptr<TalkSceneManager>m_TalkScene;
		std::shared_ptr<StageMap>m_MapObj;
		std::shared_ptr<SaveDataManager>m_Save;
		std::shared_ptr<TimeLine>m_TL;
		std::shared_ptr<EndingScene>m_Ending;
		std::shared_ptr<obj::ItemManager>m_ItemSpawner;
		std::shared_ptr<ItemRoulette>m_ItemRoulette;
		std::shared_ptr<GameMassage> m_GameMassage;
		bool m_Is_black_out;
		bool m_Is_no_pause;
		bool m_Is_Ending;
		int m_Pause_state;

		int m_Player_type;
		int m_Count;
		int m_Load_time;
		int m_End_time;
	public:
		StoryMode();
		//初期化
		void initialize(int player_type, bool is_first = true);
		void draw();
		void update();
		//ステージが終了したときの処理
		void stageEnd();
		//sharedポインタの初期化
		void sharedReset();
		bool isEnd();
	private:
		void inputCamp();
		void updateGame();
		void gamePhase();
		void acheve();
	};
}