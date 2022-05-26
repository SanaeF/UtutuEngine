#pragma once
#include "../../Source/Object/Object/Object.h"

namespace obj {
	class BackGraph :public Object {
	private:
		struct BackCamera {
			Position pos;
			Position m_Angle;
		};
		struct Distort {
			bool flag;
			int size;
			int time;
			float thick;
			double m_Angle;
		};
		BackCamera Cam;
		Position Size;
		Position Pos;
		Position Rotation;
		Distort dist[2];
		float crush_x;
		float crush_y;
		float distX;
		float distY;
		int speed;
		float m_Angle;
		int length;
		int pattern;
		int dist_max;
		int dist_min;
	public:
		BackGraph();
		void setCrush(float cx, float cy);
		void draw(double crush_x = 0.f, double crush_y = 0.f);
		void update();
		void create(Position pos, double m_Angle, double size, int speed, int kind, int length, int pattern, int count, int state = 0);
		void set_FadeOut(int flag);
		void set_DistX(double delt, int size, int time, int flag = 1);
		void set_DistY(double delt, int size, int time, int flag = 1);
		void setAngle(float num);
		void setSpeed(int num);
		void setLength(int num);
		void setPattern(float num);
		void setCamera(Position pos, Position m_Angle);
		void initialize();
	private:
		void update2Dscroll();
		void update3Dscroll();
		void update2Ddist();
		void update2Dstay();
		void update3DStay();
		void draw2Dscroll(double cx = 0.f, double cy = 0.f);
		void draw3Dscroll(double cx = 0.f, double cy = 0.f);
		void draw2Ddist(double cx = 0.f, double cy = 0.f);
		void draw2Dstay(double cx = 0.f, double cy = 0.f);
		void draw3DStay(double cx = 0.f, double cy = 0.f);
		float distParam(int num, int state);
	public:
		enum {
			ROOD_2D_SCROLL,
			ROOD_3D_SCROLL,
			BACK_DIST_2D,
			STAY_2D,
			STAY_3D
		};
		enum {
			DISTORT_X,
			DISTORT_Y,
			DISTORT_ALL
		};
	};
}