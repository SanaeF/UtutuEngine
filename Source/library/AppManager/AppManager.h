#pragma once
#include <tchar.h>
namespace lib {
	enum DrawScreenType {
		FRONT,
		BACK,
		WORK,
		TEMPFRONT,
		OTHER	
	};

	class AppManager {
	private:
		struct DATE_DATA {
			int year;	// ”N
			int mon;	// ŒŽ
			int day;	// “ú
			int hour;	// ŽžŠÔ
			int min;	// •ª
			int sec;	// •b
		};
	public:
		static int initialize();

		static int setWindowSize(int width, int heigth);
		static int setPixelSize(int width, int heigth, int bit);
		static int setWindowTitle(const TCHAR* text);
		static int setWindowMode(bool flag);

		static int setBackGroundProcess(bool flag);
		static int setVerticalSync(bool flag);
		static int setScreen(int type);

		static int processMessage();
		static int screenClear();
		static int screenFlip();

		static void setASyncLoad(bool flag);
		static int getASyncLoadNum();
		static bool isASyncLoad();

		static int getNowCount();
		static void sleep(int time);

		static int waitKey();

		static int finalize();
		static int setArchive(const TCHAR* text);

		static DATE_DATA getDateTime();
		AppManager();
		~AppManager();
	};
}