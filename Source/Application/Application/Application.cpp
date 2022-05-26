#include "Application.h"
#include <thread>
#include "../../Source/library/AppManager/AppManager.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/Manager/FrameManager/FrameManager.h"
#include "../../Source/Manager/SceneManager/SceneManager.h"
#include "../../Source/Application/Application/LoadScene/LoadScene.h"
#include "../../Source/Application/Sound/Sound.h"
#include "../../Source/Resource/LoadManager.h"
#include "../../Source/Resource/GUI/LoadUIImage/LoadUIImage.h"
#include "../../Source/Resource/SaveData/SaveData.h"
#include "../../Source/Application/Key/Key.h"
#include "../../Source/Manager/SaveDataManager/SaveDataManager.h"
#include "../../Source/Helper/Helper.h"

namespace app {
	Application::Application():
		m_Screen_type(0),
		m_State(STATE::LOADING)
	{
		m_Use_multiplay = true;
		//キーパッド初期化
		Key::Pad.initialize(Key::PAD_TYPE::PLAYER_01);
		//2人対専用のキーパッド初期化
		if (m_Use_multiplay) {
			Key::MultPad[0].initialize(Key::PAD_TYPE::PLAYER_01);
			Key::MultPad[1].initialize(Key::PAD_TYPE::PLAYER_02);
		}
		m_FPS.reset(new FrameManager(60));
		m_Save.reset(new SaveDataManager());
		m_Scene.reset(new SceneManager());
		SaveDataManager::in_weapon();
		m_Save->in_config();
		m_Save->in_game();
	}
	Application::~Application() {

	}
	
	void Application::windowProp() {
		switch (m_Screen_type) {
		case 0:
			lib::AppManager::setWindowSize(640, 480);
			break;
		case 1:
			lib::AppManager::setWindowSize(960, 720);
			break;
		case 2:
			lib::AppManager::setWindowSize(1280, 960);
			break;
		case 3:
			lib::AppManager::setWindowSize(1920, 1440);
			break;
		case 4:
			lib::AppManager::setWindowMode(false);
			break;
		default:
			break;
		}

	}
	void Application::initialize() {
		lib::AppManager::setBackGroundProcess(true);
		//lib::AppManager::setVerticalSync(true);
		lib::AppManager::setWindowTitle(mFrame_text);
		lib::AppManager::setPixelSize(1920, 1440, 32);
		lib::AppManager::setWindowMode(true);
		//セーブデータに保存されているウィンドウサイズの代入
		m_Screen_type = res::SaveData::save_data.config.winType;
		windowProp();
	}
	
	bool Application::processLoop() {
		if (lib::AppManager::processMessage() != 0)return false;
		if (lib::AppManager::screenClear() != 0)return false;
		//キー入力は常に実行
		Key::Pad.stateUpdate();
		Key::Pad.keyPadUpdate();
		if (m_Use_multiplay) {
			for (int i = 0; i < 2; i++) {
				Key::MultPad[i].stateUpdate();
				Key::MultPad[i].keyPadUpdate();
			}
		}
		return true;
	}
	
	void Application::run() {
		lib::AppManager::setScreen(lib::DrawScreenType::BACK);
		LoadScene::left();
		while (processLoop()) {
			//リソースのロード
			if (m_State == STATE::LOADING) {
				loading();
				if (lib::AppManager::getASyncLoadNum() == 0) {
					Sound::sound.setVolume(
						res::SaveData::save_data.config.vol_bgm,
						res::SaveData::save_data.config.vol_se
					);
					Sound::sound.playBGM(0);

					m_State = STATE::MAINLOOP;
					END_SCENE();
				}
				else {
					m_FPS->update();
				}
			}
			//全ての更新
			if (m_State == STATE::MAINLOOP) {
				update();
			}
		}
	}
	void Application::loading() {
		res::LoadManager &load = res::LoadManager::get_instance();
		lib::AppManager::setASyncLoad(true);
		load.loadAppUI();
		load.loadMusic();
		load.loadTextUI();
		load.loadMenuUI();
		load.loadTalkCharaImg();
		load.loadCharaObjImg();
		lib::AppManager::setASyncLoad(false);
		lib::AppManager::screenClear();
		//ゲーム初期画面の簡易描画
		lib::Graphics2D::drawRota(
			480 * 2,
			340 * 2,
			2.0,
			0.0,
			res::LoadUIImage::load_ui.setupApp,
			true
		);
		lib::AppManager::screenFlip();
	}
	void Application::update() {
		lib::AppManager::screenClear();
		m_FPS->update();
		m_Scene->update();
		m_Scene->draw();
		if (!LoadScene::isDraw())m_FPS->draw(1850, 1400);
		LoadScene::draw();
		m_Scene->NoThreadUptdate();
		lib::AppManager::screenFlip();
	}
	int Application::libInit() {
		return lib::AppManager::initialize();
	}
	void Application::customArchive() {
		lib::AppManager::setArchive("sanaeF");
	}
	int Application::waitKey() {
		return lib::AppManager::waitKey();
	}
	void Application::libEnd() {
		lib::AppManager::finalize();
	}
}