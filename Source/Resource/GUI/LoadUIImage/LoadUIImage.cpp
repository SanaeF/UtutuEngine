#include "LoadUIImage.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
namespace res {
	LoadUIImage LoadUIImage::load_ui;
	void LoadUIImage::load() {
		load_ui.setupApp = lib::Graphics2D::load("./dat/image/GUI/LoadScene/setupApp.png");
		load_ui.setGame = lib::Graphics2D::load("./dat/image/GUI/LoadScene/Loading.png");
	}
}