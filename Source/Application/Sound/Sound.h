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
			{"♪:青春よ目を覚ませ" },
			{"♪:ひとつ椿を導に桜よ明け" },//
			{"♪:自我を持って生まれし駒" },//
			{"♪:Traum ZeitBegrenzung;23h59m" },//
			{"♪:グラスの灰被りアイドル" },//
			{"♪:オートマインド・マイフレンド" },//
			{"♪:鏡な虚界のジョーカー" },//
			{"♪:絶命した城の暗き夜明け" },//
			{"♪:恋に謳った命の刃" },
			{"♪:渾沌に呻くキノ娘" },
			{"♪:神霊なんてないし、神も無い" },
			{"♪:導きの彼方、メルヘン林檎" },
			{"♪:16年のゴールデンタイム" },
			{"♪:現ミル少女は囁く～Present Dream" },
			{"♪:エンハンス・モーメント" },
			{"♪:ED" },
			{"♪:New Moon Simulacra" }
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