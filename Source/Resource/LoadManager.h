#pragma once
namespace res {
	class LoadManager {
	private:
		bool m_Sound;
		bool m_App_ui;
		bool m_Text_ui;
		bool m_Menu_ui;
		bool m_Game_ui;
		bool m_Chara_img;
		bool m_Shot_img;
		bool m_Effect_img;
		bool m_Talk_chara_img;
		bool m_Is_load_map;
		bool m_Is_game_load;
	public:
		void loadMusic();
		void loadMenuUI();
		void loadAppUI();
		void loadTextUI();
		void loadGameUI();
		void loadCharaObjImg();
		void loadShotImg();
		void loadEffectImg();
		void loadTalkCharaImg();
		void loadTalkBossImg(int stage);//ステージごとに必要な立ち絵素材を読み込めるようにする
		void loadMapModel();
		void setGameLoad();
		bool isGameLoaded();
	public:
		LoadManager(const LoadManager&) = delete;
		LoadManager& operator=(const LoadManager&) = delete;
		LoadManager(LoadManager&&) = delete;
		LoadManager& operator=(LoadManager&&) = delete;
		static LoadManager& get_instance() {
			static LoadManager instance;
			return instance;
		}
	private:
		LoadManager();
		~LoadManager() = default;
	}; 
}