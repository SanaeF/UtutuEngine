#include "EndingTalk.h"
#include "../../Source/Manager/TalkSceneManager/TalkSceneManager.h"
#include "../../Source/EffectTools/ScreenFade/ScreenFade.h"
#include"../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/Resource/OnePictureImage/OnePictureImage.h"
namespace app {
	EndingTalk::EndingTalk() {
		m_TalkScene.reset(new TalkSceneManager());
	}
	void EndingTalk::start() {
		m_Flag = true;
		m_TalkScene->initialize();
		m_TalkScene->startEnding();
		ScreenFade::Screen.setFade(ScreenFade::FADE_IN, 120);
	}
	void EndingTalk::draw() {
		if (!m_Flag)return;
		lib::Graphics2D::drawRota(480 * 2, 360 * 2, 1.0, 0.0, res::OnePictureImage::one_picture.end_card[res::END_CARD_TYPE::STORY], true);
		m_TalkScene->draw();
		ScreenFade::Screen.draw();
	}
	void EndingTalk::update() {
		if (!m_Flag)return;
		if (ScreenFade::Screen.isRun()) {
			ScreenFade::Screen.update();
			//会話シーンとフェードアウトが終了したらエンディングトークを終了
			if (ScreenFade::Screen.isEnd(ScreenFade::FADE_OUT))stop();
			return;
		}
		m_TalkScene->update();
		//会話シーンが終わったらフェードアウトの設定
		if (m_TalkScene->isSceneEnd()) {
			//会話シーンが終わったらフェードアウトの設定
			ScreenFade::Screen.setFade(ScreenFade::FADE_OUT, 180);
		}
	}
	void EndingTalk::stop() {
		m_Flag = false;
	}
	bool EndingTalk::isFlag() {
		return m_Flag;
	}
}