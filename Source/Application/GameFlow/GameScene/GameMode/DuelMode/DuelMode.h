#pragma once
#include <memory>

namespace obj {
	class Boss;
	class ItemManager;
}
namespace script {
	class ShotScript;
	class LazerScript;
	class TurnLazerScript;
}
namespace app {
	class ScoreBoard;
	class Sound;
	class TalkSceneManager;
	class Shake;
	class StageMap;
	class SaveDataManager;
	class TimeLine;
	class EndingScene;
	class DuelMode {
	private:
		std::shared_ptr<obj::Boss> m_Boss;
		std::shared_ptr<script::ShotScript> m_ShotScript;
		std::shared_ptr<script::LazerScript> m_LazerScript;
		std::shared_ptr<script::TurnLazerScript> m_TurnLazerScript;
		std::shared_ptr<ScoreBoard> m_Board;
		std::shared_ptr<TalkSceneManager>m_TalkScene;
		std::shared_ptr<Shake>m_Shake;
		std::shared_ptr<StageMap>m_MapObj;
		std::shared_ptr<SaveDataManager>m_Save;
		std::shared_ptr<TimeLine>m_TL;
		std::shared_ptr<EndingScene>m_Ending;
		std::shared_ptr<obj::ItemManager>m_ItemSpawner;
		bool m_Is_end;
		bool m_Is_no_pause;
		int m_Pause_state;

		int m_Difficulty;
		int m_Stage_type;
		int m_Player_type;
		int m_Count;
		int m_Load_time;
	public:
		DuelMode(int difficulty = 1);
		//初期化
		void initialize(int sound_type, int stage_type);
		void draw();
		void update();
		//sharedポインタの初期化
		void sharedReset();
		//プレイヤーの初期情報を特別指定
		void setupPlayer(bool is_host, int type1, int type2);
		bool isEnd();
	private:
		void updateGame();
	};
}