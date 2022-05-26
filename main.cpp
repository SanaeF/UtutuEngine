#include <windows.h>
#include "Source/Application/Application/Application.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	app::Application application;
	application.initialize();
	if (application.libInit() == -1) return -1;
	application.customArchive();
	application.run();
	application.waitKey();
	application.libEnd();
	return 0;
}