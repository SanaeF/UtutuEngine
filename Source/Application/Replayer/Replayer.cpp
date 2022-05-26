#include "Replayer.h"
#include "../../Source/Helper/Helper.h"
#include "../../Application/Key/Key.h"
#include "../../Source/SystemProp/GameSceneProp/GameSceneProp.h"

#pragma warning(disable : 4996)
namespace app {
	Replayer Replayer::GameRecorder;
	Replayer::Replayer() :
		m_Stage_id(0),
		m_Count(0),
		m_Score(0),
		m_Key_save_count(0),
		m_Key_call_count(0),
		m_Seed_call_count(0),
		m_Is_replay_mode(false),
		m_Is_stop(false)
	{

	}
	void Replayer::initialize() {
		if (!isReplayMode()) {
			for (int i = 0; i < 16; i++) {
				m_KeyCapture[m_Stage_id][i].setDataSize(0);
			}
		}
		for (int i = 0; i < 16; i++) {
			m_KeyCapture[m_Stage_id][i].setCount(0);
			m_Key_count[i] = 0;
		}
	}
	void Replayer::callSeedProcess(int seed_pattern_num, int stage) {
		int seed = SET_RANDOM_SEED(seed_pattern_num);
		if (isReplayMode()) {//ƒŠƒvƒŒƒC’†
			m_Stage_id = getFirstStage();
			GameSceneProp::stage = m_Stage_id;
			GameSceneProp::difficulty = m_Difficulty;
			seed = getSeedVal();
		}
		else {//‹L˜^’†
			m_Stage_id = GameSceneProp::stage;
			m_Difficulty = GameSceneProp::difficulty;
			pushBackSeed(seed);
		}
		addPushBackReSizer(100);//Ši”[”‚ÌŠm•Û
		SET_SEED(seed);
	}
	void Replayer::callSeedProcess(int seed_pattern_num) {
		callSeedProcess(seed_pattern_num, m_Stage_id);
	}
	void Replayer::update() {
		m_Count++;
		if (m_Is_replay_mode) {
			if ((m_Stage_id == m_End_stage) && (m_End_count <= m_Count))m_Is_stop = true;
		}
		addPushBackReSizer(100);//Ši”[”‚ÌŠm•Û
	}
	void Replayer::callStop() {
		m_End_stage = m_Stage_id;
		m_End_count = m_Count;
		m_Stage_id = 0;
		m_Count = 0;
		m_Key_save_count = 0;
		m_Key_call_count = 0;
		m_Seed_call_count = 0;
		m_Is_replay_mode = false;
	}
	void Replayer::setReplayMode(bool flag) {
		m_Is_replay_mode = flag;
	}
	bool Replayer::dataInput(int id) {
		m_Is_stop = false;
		char* file_name = new char[20];
		if (id < 10)sprintf(file_name, "./replay/0%d.history", id);
		else sprintf(file_name, "./replay/%d.history", id);
		Export_Data exp_dat;
		exp_dat.initialize();
		FILE* fp = fopen(file_name, "rb");
		if (fp == nullptr) {
			return false;
		}
		for (int i = 0; i < ALL_STAGE; i++) {
			m_Data_seed[i].clear();
		}
		fread(&exp_dat, sizeof(Export_Data), 1, fp);
		m_Difficulty = exp_dat.difficulty;
		m_End_count = exp_dat.end_count;
		m_End_stage = exp_dat.end_stage;
		for (int i = 0; i < m_Player_data_num; i++)m_Player_data[i] = exp_dat.player_data[i];
		for (int i = 0; i < ALL_STAGE; i++) {
			m_Data_seed[i].resize(exp_dat.seed_data_size[i]);
			for (int i2 = 0; i2 < 16; i2++)
				m_KeyCapture[i][i2].setDataSize(exp_dat.key_data_size[i][i2]);
		}
		for (int i = 0; i < ALL_STAGE; i++) {
			if (exp_dat.seed_data_size[i] != 0) fread(m_Data_seed[i].data(), sizeof(int), exp_dat.seed_data_size[i], fp);
			for (int i2 = 0; i2 < 16; i2++) {
				std::vector<KeyCapture::CaptureData>
					key_data(exp_dat.key_data_size[i][i2]);
				if (key_data.size() != 0) {
					fread(
						key_data.data(),
						sizeof(KeyCapture::CaptureData),
						key_data.size(),
						fp
					);
					m_KeyCapture[i][i2].setData(key_data);
				}
			}
		}
		fclose(fp);
		return true;
	}
	void Replayer::reload() {
		callStop();
		dataInput(m_Stage_id);
		m_Is_replay_mode = true;
	}
	void Replayer::dataExport(int id) {
		char* file_name = new char[20];
		if (id < 10)sprintf(file_name, "./replay/0%d.history", id);
		else sprintf(file_name, "./replay/%d.history", id);
		Export_Data exp_dat;
		exp_dat.difficulty = m_Difficulty;
		exp_dat.end_count = m_End_count;
		exp_dat.end_stage = m_End_stage;
		for (int i = 0; i < m_Player_data_num; i++)exp_dat.player_data[i] = m_Player_data[i];
		for (int i = 0; i < ALL_STAGE; i++) {
			exp_dat.seed_data_size[i] = m_Data_seed[i].size();
			for (int i2 = 0; i2 < 16; i2++) {
				exp_dat.key_data_size[i][i2] = m_KeyCapture[i][i2].getData().size();
			}
		}
		FILE* fp = fopen(file_name, "wb");
		fwrite(&exp_dat, sizeof(Export_Data), 1, fp);
		for (int i = 0; i < ALL_STAGE; i++) {
			if (m_Data_seed[i].size() != 0) {
				fwrite(m_Data_seed[i].data(), sizeof(int), m_Data_seed[i].size(), fp);
			}
			for (int i2 = 0; i2 < 16; i2++) {
				if (m_KeyCapture[i][i2].getData().size() != 0) {
					fwrite(
						m_KeyCapture[i][i2].getData().data(),
						sizeof(KeyCapture::CaptureData),
						m_KeyCapture[i][i2].getData().size(),
						fp
					);
				}
			}
		}
		fclose(fp);
	}
	void Replayer::pushBackSeed(int seed_val) {
		m_Data_seed[m_Stage_id].push_back(seed_val);
	}
	void Replayer::pushBackKeyInputs(int key_type, int key_count){
		if (key_type == Key::KEY_TYPE::SHOT) {
			if (key_count != 0) {
				int a = 0;
			}
		}
		if (key_count > 0)m_KeyCapture[m_Stage_id][key_type].checkInput(m_Count, true);
		if (key_count == 0)m_KeyCapture[m_Stage_id][key_type].checkInput(m_Count, false);
	}
	void Replayer::addPushBackReSizer(int size_dist) {
	}
	void Replayer::setScore(int score) {
		m_Score = score;
	}
	void Replayer::setPlayerData(int data, int id) {
		m_Player_data[id] = data;
	}
	bool Replayer::isReplayMode() {
		return m_Is_replay_mode;
	}
	bool Replayer::isStop() {
		return m_Is_stop;
	}
	int Replayer::getSeedVal() {
		int count = m_Seed_call_count;
		m_Seed_call_count++;
		return m_Data_seed[m_Stage_id][count];
	}
	int Replayer::getDifficulty() {
		return m_Difficulty;
	}
	int Replayer::getScore() {
		return m_Score;
	}
	int Replayer::getPlayerData(int id) {
		return m_Player_data[id];
	}
	int Replayer::getKeyData(int key_type) {
		if (m_KeyCapture[m_Stage_id][key_type].isInputed(m_Count)) {
			m_Key_count[key_type]++;
		}
		else m_Key_count[key_type] = 0;
		return m_Key_count[key_type];
	}
	int Replayer::getFirstStage() {
		int result = 0;
		for (int i = 0; i < ALL_STAGE; i++) {
			if (m_Data_seed[i].size() != 0) {
				result = i;
				break;
			}
		}
		return result;
	}
}