#pragma once
namespace app {
	class Key {
	public:
		static Key Pad;
		static Key MultPad[2];

		enum PAD_TYPE {
			PLAYER_01,
			PLAYER_02
		};
		enum KEY_TYPE {
			UP,
			DOWN,
			RIGHT,
			LEFT,
			SHOT,
			BOM,
			CHANGE,
			SHIFT,
			MENU,
			KEY_MAX,
			PAD_KEY_MAX = 16
		};
	private:
		int m_Key[KEY_TYPE::KEY_MAX];
		int m_Key_count[KEY_TYPE::PAD_KEY_MAX];
		int m_Debug_key_count;
		unsigned int m_State_key[256];

		int PAD_TYPE;

	public:
		//キーパッド(type)に対する初期化
		void initialize(int type);

		int stateUpdate();
		void keyPadUpdate();

		//自機操作の場合はPlayerクラスかPlayerMoverクラスに追加
		int checkInput(int num);

		void setKeyConfig(
			int type,
			int down,
			int left,
			int right,
			int up,
			int shot,
			int bom,
			int change,
			int shift,
			int menu
		);
		void setKeyCounter(int n, int value);

		void setKey(int num,int key);

		int checkInputedKey();

		int getPadType();
		int getKey(int num);
		bool debugKey();
	private:
		void inputPadAndKey(int* p, int k);
		int checkState(unsigned char num);
	};

	//extern Key_Info KeyPad;
	//extern Key_Info MultKeyPad[2];
}