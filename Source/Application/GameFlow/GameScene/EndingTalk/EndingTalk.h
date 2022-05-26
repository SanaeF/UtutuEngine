#pragma once
#include <memory>

namespace app {
	class TalkSceneManager;
	class EndingTalk {
	private:
		std::shared_ptr<TalkSceneManager>m_TalkScene;
		bool m_Flag;
	public:
		EndingTalk();
		void start();
		void draw();
		void update();
		bool isFlag();
	private:
		void stop();
	};
}