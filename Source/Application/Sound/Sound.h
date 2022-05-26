#pragma once

namespace app {
	class Sound {
	public:
		static Sound sound;
	private:
		struct TitleText {
			char name[128];
		};
		int loop_time[18] = {
			0,//title
			0,//rood1
			0,//boss1
			0,//rood2
			0,//boss2
			0,//rood3
			0,//boss4
			0,//rood5
			0,//boss6
			0,//rood7
			0,//boss7
			0,//rood8
			0,//boss8
			0,//AL
		};
		int m_Vol_bgm;
		int m_Vol_se;

		int m_Output_se;
		int m_Output_bgm;
		int m_Playing_music;
		int m_Play_pos;
		bool m_Stop;
		bool m_Is_input_pos;
	public:
		TitleText m_Title[17] = {
			{"��:�t��ڂ��o�܂�" },
			{"��:�ЂƂւ𓱂ɍ��斾��" },//
			{"��:����������Đ��܂ꂵ��" },//
			{"��:Traum ZeitBegrenzung;23h59m" },//
			{"��:�O���X�̊D���A�C�h��" },//
			{"��:�I�[�g�}�C���h�E�}�C�t�����h" },//
			{"��:���ȋ��E�̃W���[�J�[" },//
			{"��:�▽������̈Â��閾��" },//
			{"��:����搂������̐n" },
			{"��:�ӓׂə�L�m��" },
			{"��:�_��Ȃ�ĂȂ����A�_������" },
			{"��:�����̔ޕ��A�����w���ь�" },
			{"��:16�N�̃S�[���f���^�C��" },
			{"��:���~�������͚����`Present Dream" },
			{"��:�G���n���X�E���[�����g" },
			{"��:ED" },
			{"��:New Moon Simulacra" }
		};
	public:
		void initializeMemory();
		void drawDebugString();
		void setVolume(int bgm, int se);
		void playStageBGM(int stage_num);
		void setPosition(int count);
		int playSE(int number);
		int playBGM(int number);
		int getNowPlayBGM();
		void handleReset();
		void freez();
		void unFreez();
		Sound();
	};
}