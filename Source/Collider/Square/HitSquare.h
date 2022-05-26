#pragma once

namespace obj {
	class HitSquare {
	private:
		struct Position {
			float x;
			float y;
		};
		const float m_PI = 3.14159f;
	public:
		//回転しないベクター的な四角形の当たり判定
		bool isHitSquareNoRotaVect(
			Position obj1[4],
			Position obj2[4]
		);
		//回転しない四角形の当たり判定
		bool isHitSquareNoRota(
			float get_x1[4],
			float get_y1[4],
			float get_x2[4],
			float get_y2[4]
		);
		//円形のあたり判定
		bool isHitCircle(
			float get_x1[4],
			float get_y1[4],
			float get_x2,
			float get_y2,
			float hitRange
		);
		Position* getVector(float x, float y, float W, float H);
	private:
		void mSetDistance(Position* diff, const Position* p, const Position* q);
		float mInnerProduct(const Position* p, const Position* q);
		float mOuterProduct(const Position* p, const Position* q);
		float mGetDistance(float x, float y, float x1, float y1, float x2, float y2);
		float mGetAngle(Position pt0, Position pt1, Position rpt);
		bool between(float data, float min, float max);
		bool isPoint_InCircle(Position p, Position rp, float r);
		bool isHitSquareAndCircle(Position pt[4], Position rpt, float r);
		bool isHitSquareAndSquare(Position pt1[4], Position pt2[4]);
	};
}