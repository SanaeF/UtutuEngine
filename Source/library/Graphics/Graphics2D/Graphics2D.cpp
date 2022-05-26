#include "Graphics2D.h"
#include "DxLib.h"

namespace lib {
	void Graphics2D::triangle(
		int x1, int y1,
		int x2, int y2,
		int x3, int y3,
		unsigned int Color,
		int FillFlag
	) {DrawTriangle(x1, y1, x2, y2, x3, y3, Color, FillFlag);}

	void Graphics2D::circleGauge(
		int CenterX,
		int CenterY,
		double Percent,
		int Handle,
		double StartPercent
	) {DrawCircleGauge(CenterX, CenterY, Percent, Handle, StartPercent);}

	void Graphics2D::drawModi(
		float x1, float y1,
		float x2, float y2,
		float x3, float y3,
		float x4, float y4,
		int Handle,
		int TransFlag
	) {DrawModiGraphF(x1, y1, x2, y2, x3, y3, x4, y4, Handle, TransFlag);}

	void Graphics2D::drawRota(
		float x,
		float y,
		double size,
		double m_Angle,
		int Handle,
		int TransFlag,
		int ReverseXFlag,
		int ReversYeFlag
	) {DrawRotaGraphF(x, y, size, m_Angle, Handle, TransFlag, ReverseXFlag, ReversYeFlag);}

	void Graphics2D::draw(
		int x,
		int y,
		int Handle,
		int TransFlag
	) {DrawGraph(x, y, Handle, TransFlag);}

	void Graphics2D::box(
		int x1, int y1,
		int x2, int y2,
		unsigned int Color,
		int FillFlag
	) {DrawBox(x1, y1, x2, y2, Color, FillFlag);}

	void Graphics2D::drawCircle(
		float x,
		float y,
		float r,
		int posnum,
		unsigned int Color,
		int FillFlag
	) {DrawCircleAA(x, y, r, posnum, Color, FillFlag);}

	void Graphics2D::setArea(
		int x1, int y1,
		int x2, int y2
	) {SetDrawArea(x1, y1, x2, y2);}

	void Graphics2D::drawMode(
		int DrawMode
	) {SetDrawMode(DrawMode);}

	void Graphics2D::setBlend(
		int BlendMode,
		int Parameter
	) {SetDrawBlendMode(BlendMode, Parameter);}

	void Graphics2D::setBright(
		int Red,
		int Green,
		int Blue
	) {SetDrawBright(Red, Green, Blue);}
	void Graphics2D::getSize(
		int handle, int* size_x, int* size_y
	) {
		GetGraphSize(handle, size_x, size_y);
	}
	int Graphics2D::load(
		const TCHAR* FileAdress
	) {return LoadGraph(FileAdress);}

	void Graphics2D::loadSplit(
		const TCHAR* FileAdress,
		int AllNum,
		int X_Num,
		int Y_NUM,
		int X_Size,
		int Y_Size,
		int* HandleArray
	) {LoadDivGraph(FileAdress, AllNum, X_Num, Y_NUM, X_Size, Y_Size, HandleArray);}

	void Graphics2D::initialize() {InitGraph();}

	int Graphics2D::clear(
		int GrHandle,
		int LogOutFlag
	) {return DeleteGraph(GrHandle);}
}