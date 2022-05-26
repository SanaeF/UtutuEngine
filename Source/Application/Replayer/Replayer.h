#pragma once
#include <vector>
#include "KeyCapture/KeyCapture.h"
#include "../../SystemProp/GameStatsProp.h"
namespace app {
	const int m_Player_data_num = 2;
	class Replayer {
	private:
		struct ReplayKeyData {
			int trigger_shot;
			int trigger_bom;
			int trigger_change;
			int trigger_shift;
			int trigger_up;
			int trigger_down;
			int trigger_right;
			int trigger_left;
			void initialize() {
				trigger_shot = 0;
				trigger_bom = 0;
				trigger_change = 0;
				trigger_shift = 0;
				trigger_up = 0;
				trigger_down = 0;
				trigger_right = 0;
				trigger_left = 0;
			}
		};
		struct Export_Data {
			int player_data[m_Player_data_num];
			int difficulty;
			int key_data_size[ALL_STAGE][16];
			int seed_data_size[ALL_STAGE];
			int end_stage;
			int end_count;
			void initialize() {
				for (int i = 0; i < ALL_STAGE; i++) {
					for (int i2 = 0; i2 < 16; i2++)key_data_size[i][i2] = 0;
					seed_data_size[i] = 0;
				}
			}
		};
		KeyCapture m_KeyCapture[ALL_STAGE][16];
		int m_Key_count[16];

		std::vector<int> m_Data_seed[ALL_STAGE];//一定ごとに行われるシード値指定を順番に格納

		bool m_Is_replay_mode;
		bool m_Is_stop;
		int m_Difficulty;
		int m_Score;
		int m_Stage_id;
		int m_Count;
		int m_End_stage;
		int m_End_count;
		int m_Key_save_count;//入力情報を記録した回数をカウント
		int m_Key_call_count;//入力情報を呼び出した回数をカウント
		int m_Seed_call_count;//現在のシード呼び出し順をカウント
		int m_Player_data[m_Player_data_num];
	public:
		Replayer();

		void initialize();

		//リプレイ中もしくは録画中ごとのシード値決定(第1引数は録画時のみ有効、乱数を扱う前にこの関数を呼び出せばOK)
		void callSeedProcess(int seed_pattern_num, int stage);

		//リプレイ中もしくは録画中ごとのシード値決定(第1引数は録画時のみ有効、乱数を扱う前にこの関数を呼び出せばOK)
		void callSeedProcess(int seed_pattern_num);
		void update();
		void callStop();

		void setReplayMode(bool flag);

		//リプレイファイルを読み込む(戻り値がエラーならfalse)
		bool dataInput(int id);

		//ファイルを再読み込みする
		void reload();


		//ファイルに書き出す
		void dataExport(int id);

		//一定ごとに行われるシード値指定を記録していく
		void pushBackSeed(int seed_val);

		//ステージごとにキー入力を記録していく
		void pushBackKeyInputs(int key_type, int key_count);

		void setScore(int score);
		void setPlayerData(int data, int id);
		bool isReplayMode();
		bool isStop();
		int getSeedVal();
		int getDifficulty();
		int getScore();
		int getPlayerData(int id);
		//指定ステージの入力データを取得する
		int getKeyData(int key_type);
		int getFirstStage();
		static Replayer GameRecorder;

	private:
		//vector配列のサイズが足りなくなったときに増やしてくれる
		void addPushBackReSizer(int size_dist);
	};
}