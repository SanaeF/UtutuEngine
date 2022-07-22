#include "AppManager.h"
#include "DxLib.h"
 
namespace lib {
	int AppManager::initialize() {
		SetWindowIconID(333);
		return DxLib_Init();
	}
	int AppManager::setWindowSize(int width, int height) {
		SetWindowStyleMode(7);
		return SetWindowSize(width, height);
	}
	int AppManager::setPixelSize(int width, int heigth, int bit) {
		return SetGraphMode(width, heigth, bit);
	}
	int AppManager::setWindowTitle(const TCHAR* text) {
		return SetMainWindowText(text);
	}
	int AppManager::setWindowMode(bool flag) {
		return ChangeWindowMode(flag);
	}
	int AppManager::processMessage() {
		return ProcessMessage();
	}
	int AppManager::screenClear() {
		return ClearDrawScreen();
	}
	int AppManager::screenFlip() {
		return ScreenFlip();
	}
	int AppManager::finalize() {
		return DxLib_End();
	}

	int AppManager::setBackGroundProcess(bool flag) {
		return SetAlwaysRunFlag(flag);
	}
	int AppManager::setVerticalSync(bool flag) {
		return SetWaitVSyncFlag(flag);
	}
	int AppManager::setScreen(int type) {
		switch (type) {
		case DrawScreenType::FRONT:
			break;
		case DrawScreenType::BACK:
			return SetDrawScreen(DX_SCREEN_BACK);
			break;
		default:
			break;
		}
		return 0;
	}
	void AppManager::setASyncLoad(bool flag) {
		SetUseASyncLoadFlag(flag);
	}
	int AppManager::getASyncLoadNum() {
		return GetASyncLoadNum();
	}
	bool AppManager::isASyncLoad() {
		return GetUseASyncLoadFlag();
	}
	int AppManager::getNowCount() {
		return GetNowCount();
	}
	void AppManager::sleep(int time) {
		Sleep(time);
	}
	int AppManager::waitKey() {
		return WaitKey();
	}
	int AppManager::setArchive(const TCHAR* text) {
		return SetDXArchiveExtension(text);//アーカイブファイルの拡張子
	}
	AppManager::DATE_DATA AppManager::getDateTime() {
		DATE_DATA result;
		DATEDATA Date;
		GetDateTime(&Date);
		result.day = Date.Day;
		result.hour= Date.Hour;
		result.min = Date.Min;
		result.mon = Date.Mon;
		result.sec = Date.Sec;
		result.year = Date.Year;
		return result;
	}
	AppManager::AppManager() {
		SetWindowIconID(333);
		//SetDoubleStartValidFlag(true);
	}
	AppManager::~AppManager() {
	}
}