#pragma once

namespace app {
	class SaveDataManager {
	private:
		struct ConfigData {
			bool flag;
			int vol_bgm;
			int vol_se;
			int win_size_type;
			int key[16];
			void initialize() {
				flag = false;
				vol_bgm = false;
				vol_se = false;
				win_size_type = false;
				for (int i = 0; i < 16; i++)key[i] = false;
			}
		};
	public:
		//�Z�[�u�f�[�^(�Q�[���f�[�^)�̓ǂݍ���
		void in_game();
		//�Z�[�u�f�[�^(�Q�[���f�[�^)�̏����o��
		void out_game();
		//�Z�[�u�f�[�^(�ݒ�)�̓ǂݍ���
		void in_config();
		//�Z�[�u�f�[�^(�ݒ�)�̏����o��
		void out_config();
		//�Z�[�u�f�[�^(�J�X�^������)�̓ǂݍ���
		static void in_weapon();
		//�Z�[�u�f�[�^(�J�X�^������)�̓ǂݍ���
		static void out_weapon();
	};
}