#pragma once
namespace app {
	class DuelServer {
	public:
		enum TYPE{
			Host,Connecter,DISCONNECCT
		};
	private:
		struct PlayerData {
			float x;
			float y;
			int bom_num;
			int life_num;
			int m_Is_bom;
			int img;
			int m_Slow;
			int knd;
			int state;
			int shot_bullet[3];
		};

		struct NetData {
			bool start;
			int charaK;
			int select_num;//åàíËî‘çÜ
			int sound;
			int stage;
			PlayerData PlayerData;
		};
		NetData m_Out_data;
		NetData m_In_data;
		int m_Handle;
		int m_IP[4];
		int m_Port;
		int m_State;
		bool m_Is_connect;
		bool m_Is_input_port;
	public:
		DuelServer();
		~DuelServer();
		void clearValue();		
		void initHost(int port);
		void initConnect(int ip1, int ip2, int ip3, int ip4, int port);
		void update();
		void finalize();
		void inputParam(int select, int chara, int sound, int stage, bool start);
		void setState(int state);
		void callDisconnect();
		bool getConnecting();
		int getState();
		NetData& getServerData();
	private:
		void sendData();
		void loadData();
		bool isState(int state);
	};
}