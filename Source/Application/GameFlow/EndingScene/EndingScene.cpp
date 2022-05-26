#include "EndingScene.h"
#include <iostream>
#include "../../Source/library/Graphics/Movie/MovieDX.h"
#include "../../Source/Resource/SaveData/SaveData.h"
#include "../../Source/Application/Sound/Sound.h"
#include "../../Source/Application/Key/Key.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"

namespace app {
	EndingScene::EndingScene() :
		m_Handle(0),
		m_State(MOVE_STATE::NONE),
		m_Is_ending(false),
		m_Is_movie(false),
		m_Is_end(false)
	{
		//mFade.reset(new ScreenFade());
	}
	EndingScene::~EndingScene() {

	}
	void EndingScene::setEnding() {
		if ( m_Is_movie)return;
		m_State = MOVE_STATE::INITIALIZE;
		m_Is_end = false;
		m_Is_movie = true;
	}
	void EndingScene::update() {
	}
	void EndingScene::draw() {
		drawMovie();
	}
	void EndingScene::drawMovie() {
		if (m_Is_movie) {
			lib::Graphics2D::box(0, 0, 1920, 1440, 0, true);
			if (isState(MOVE_STATE::INITIALIZE)) {
				Sound::sound.freez();
				/*m_Handle = lib::MovieDx::load("./DLC/dat/movie/Ending.mp4");
				if (m_Handle == -1)m_Handle = lib::MovieDx::load("./dat/movie/Ending.mp4");*/
				m_Handle = lib::MovieDx::load("./dat/movie/Ending.mp4");
				lib::MovieDx::setVolume(10000 - res::SaveData::save_data.config.vol_bgm * 10, m_Handle);
				lib::MovieDx::play(m_Handle);
				m_State = MOVE_STATE::DRAW;
			}
			if (isState(MOVE_STATE::DRAW)) {
				lib::MovieDx::draw(0, 0, m_Handle, false);
			}
			if (lib::MovieDx::getState(m_Handle) != 1 || Key::Pad.checkInput(Key::KEY_TYPE::MENU)) {
				lib::MovieDx::clear(m_Handle);
				m_Is_end = true;
				m_Is_movie = false;
			}
		}
	}
	bool EndingScene::isState(MOVE_STATE state) {
		if (m_State == state)return true;
		return false;
	}
	bool EndingScene::isEnded() {
		return m_Is_end;
	}
}