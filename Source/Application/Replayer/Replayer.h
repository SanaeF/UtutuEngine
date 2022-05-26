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

		std::vector<int> m_Data_seed[ALL_STAGE];//��育�Ƃɍs����V�[�h�l�w������ԂɊi�[

		bool m_Is_replay_mode;
		bool m_Is_stop;
		int m_Difficulty;
		int m_Score;
		int m_Stage_id;
		int m_Count;
		int m_End_stage;
		int m_End_count;
		int m_Key_save_count;//���͏����L�^�����񐔂��J�E���g
		int m_Key_call_count;//���͏����Ăяo�����񐔂��J�E���g
		int m_Seed_call_count;//���݂̃V�[�h�Ăяo�������J�E���g
		int m_Player_data[m_Player_data_num];
	public:
		Replayer();

		void initialize();

		//���v���C���������͘^�撆���Ƃ̃V�[�h�l����(��1�����͘^�掞�̂ݗL���A�����������O�ɂ��̊֐����Ăяo����OK)
		void callSeedProcess(int seed_pattern_num, int stage);

		//���v���C���������͘^�撆���Ƃ̃V�[�h�l����(��1�����͘^�掞�̂ݗL���A�����������O�ɂ��̊֐����Ăяo����OK)
		void callSeedProcess(int seed_pattern_num);
		void update();
		void callStop();

		void setReplayMode(bool flag);

		//���v���C�t�@�C����ǂݍ���(�߂�l���G���[�Ȃ�false)
		bool dataInput(int id);

		//�t�@�C�����ēǂݍ��݂���
		void reload();


		//�t�@�C���ɏ����o��
		void dataExport(int id);

		//��育�Ƃɍs����V�[�h�l�w����L�^���Ă���
		void pushBackSeed(int seed_val);

		//�X�e�[�W���ƂɃL�[���͂��L�^���Ă���
		void pushBackKeyInputs(int key_type, int key_count);

		void setScore(int score);
		void setPlayerData(int data, int id);
		bool isReplayMode();
		bool isStop();
		int getSeedVal();
		int getDifficulty();
		int getScore();
		int getPlayerData(int id);
		//�w��X�e�[�W�̓��̓f�[�^���擾����
		int getKeyData(int key_type);
		int getFirstStage();
		static Replayer GameRecorder;

	private:
		//vector�z��̃T�C�Y������Ȃ��Ȃ����Ƃ��ɑ��₵�Ă����
		void addPushBackReSizer(int size_dist);
	};
}