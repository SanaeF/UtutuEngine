#pragma once
#include <memory>

namespace app {
	class Title;

	class Story;
	class StorySelect;
	class AliceSelect;
	class ReplayRoom;
	class DressRoom;
	class Online;
	class MusicRoom;
	class HelpRoom;
	class ConfigMenu;

	class CharaSelect;
	class CharaSelectDuel;
	class StageSelect;
	class GameScene;
	class SceneManager {
	private:
		std::shared_ptr<Title>m_Title;

		std::shared_ptr<Story>m_Story;
		std::shared_ptr<ReplayRoom>m_ReplayRoom;
		std::shared_ptr<StorySelect>m_StorySelect;
		std::shared_ptr<AliceSelect>m_Alice;
		std::shared_ptr<DressRoom>m_DressRoom;
		std::shared_ptr<Online>m_Online;
		std::shared_ptr<MusicRoom>m_MusicRoom;
		std::shared_ptr<HelpRoom>m_Help;
		std::shared_ptr<ConfigMenu>m_Config;

		std::shared_ptr<CharaSelect>m_CharaSelect;
		std::shared_ptr<CharaSelectDuel>m_VS_Player;
		std::shared_ptr<StageSelect>m_StageSelect;
		std::shared_ptr<GameScene>m_Game;
		bool m_Is_connecting;
		int m_State;
	public:
		SceneManager();
		~SceneManager();
		void draw();
		void update();
		//スレッド外で行う更新
		void NoThreadUptdate();
		//サーバー接続中の更新
		void serverUpdate();
	private:
		bool isState(int state);
	};
}