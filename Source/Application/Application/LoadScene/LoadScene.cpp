#include "LoadScene.h"

#include"../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/Resource/GUI/LoadUIImage/LoadUIImage.h"

namespace app {
	bool LoadScene::m_Is_load = false;
	int LoadScene::m_Load_count;
	void LoadScene::join() {
		m_Is_load = true;
		draw();
	}
	void LoadScene::left() {
		m_Is_load = false;
	}
	bool LoadScene::isDraw() {
		//lib::Graphics2D::draw(0, 0, res::LoadUIImage::load_ui.setGame, true);
		return m_Is_load;
	}
	void LoadScene::draw() {
		if(m_Is_load)lib::Graphics2D::draw(0, 0, res::LoadUIImage::load_ui.setGame, true);
	}
	void LoadScene::draw(int count) {

	}

}