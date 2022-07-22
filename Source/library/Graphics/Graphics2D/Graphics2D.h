#pragma once
#include <tchar.h>
namespace lib {
	class ScreenSize {
	public:
		static const int width = 2560;
		static const int height = 1440;
	};
	enum BLEND_MODE {
		NONE = 0,// ノーブレンド
		ALPHA = 1,// αブレンド(知人の名前ではない)
		ADD = 2,// 加算ブレンド
		SUB = 3,// 減算ブレンド
		MUL = 4,// 乗算ブレンド
		INVSRC,
		PMA_ALPHA = 17,
		PMA_ADD = 18,
	};
	
	enum DRAW_MODE {
		NEAREST,
		BILINEAR,
		ANISOTROPIC,
	};

	class Graphics2D {
	public:
		static void triangle(
			int x1, int y1,
			int x2, int y2,
			int x3, int y3,

			unsigned int Color,
			int FillFlag

		);
		static void circleGauge(
			int CenterX,
			int CenterY,
			double Percent,
			int Handle,
			double StartPercent = (0.0)
		);
		static void drawModi(
			float x1, float y1,
			float x2, float y2,
			float x3, float y3,
			float x4, float y4,
			int Handle,
			int TransFlag
		);
		static void drawRota(
			float x,
			float y,
			double size,
			double m_Angle,
			int Handle,
			int TransFlag,
			int ReverseXFlag = 0,
			int ReversYeFlag = 0
		);
		static void draw(
			int x,
			int y,
			int Handle,
			int TransFlag
		);
		static void box(
			int x1, int y1,
			int x2, int y2,
			unsigned int Color,
			int FillFlag
		);
		static void drawCircle(
			float x,
			float y,
			float r,
			int posnum,
			unsigned int Color,
			int FillFlag
		);
		static void setArea(
			int x1, int y1,
			int x2, int y2
		);
		static void drawMode(
			int DrawMode
		);
		static void setBlend(
			int BlendMode,
			int Parameter
		);
		static void setBright(
			int Red,
			int Green,
			int Blue
		);
		static void getSize(int handle, int* size_x, int* size_y);
		static int load(const TCHAR* FileAdress);
		static void loadSplit(
			const TCHAR* FileAdress,
			int AllNum,
			int X_Num,
			int Y_NUM,
			int X_Size,
			int Y_Size,
			int* HandleArray
		);
		static void initialize();
		static int clear(
			int GrHandle,
			int LogOutFlag = 0
		);
	};
}
