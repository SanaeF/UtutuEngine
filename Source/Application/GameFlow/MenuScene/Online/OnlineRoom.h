#pragma once
#include "../../Source/Application/GameFlow/Scene/Scene.h"
#include "../../Source/Application/Server/DuelServer.h"

namespace app {
	class Online :public Scene {
	private:
		enum oSTATE{
			NONE,
			IP_HOST,
			IP_CONNECTER,
			PORT_HOST,
			PORT_CONNECTER,
			ON_HOST,
			HOST_INIT,
			ON_CONNECTER,
			CONNECTER_INIT,
			DISCONNECCT
		};
		struct Info_t {
			int ip[4];
			int port;
		};
		Info_t m_Info = {
		{192,168,10,80},9850
		};
		DuelServer m_Server;
		char m_Data_buffer[256];    // データバッファ
		int m_IP_num[12];
		int m_Port_num[5];
		int m_Net_Handle;
		int m_Lost_Handle;
		int m_Data_length;
		int m_Online_state;
		int m_Count;
		int m_Chara[2];
		int m_State;
		bool m_Is_host;
	public:
		void draw()override;
		int update()override;
		void serverProp();
		bool isHost();
		Info_t m_Input_info();
		DuelServer& getServer();
		Online() :
			m_IP_num{ 0,0,0,0,0,0,0,0,0,0,0,0 },
			m_Port_num{ 2,5,5,6,5 },
			m_Chara{ 0,0 },
			m_Data_buffer{ 0 }
		{

			m_Online_state = 0;
			m_Net_Handle = 0;
			m_Lost_Handle = 0;
			m_Data_length = 0;
			m_Count = 0;
		}
	private:
		void select()override;
		void cancel()override;
		void up_num();
		void down_num();
		void drawNone();
		void drawIP();
		void drawPort();
		bool isState(int state);
	};
}