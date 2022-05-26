#pragma once
#include <tchar.h>
#include <memory>

namespace app {
	class FrameManager;
	class SaveDataManager;
	class SceneManager;
	//ゲームアプリケーション
	class Application {
	private:
		const char* mFrame_text = "現風少女 ";

		enum STATE {
			LOADING,
			MAINLOOP
		};
		int m_Screen_type;
		int m_State;
		bool m_Use_multiplay;
		std::shared_ptr<FrameManager> m_FPS;
		std::shared_ptr<SaveDataManager>m_Save;
		std::shared_ptr<SceneManager> m_Scene;
	public:
		//アプリケーションの初期化
		void initialize();
		//実行
		void run();
		//ライブラリの初期化
		int libInit();
		//アーカイブ拡張子の設定
		void customArchive();
		//入力待ちの取得
		int waitKey();
		//ライブラリの修了処理
		void libEnd();
		Application();
		~Application();
	private:
		bool processLoop();
		void windowProp();
		//必要最低限のリソースロード
		void loading();
		//全ての更新処理
		void update();
	};
}