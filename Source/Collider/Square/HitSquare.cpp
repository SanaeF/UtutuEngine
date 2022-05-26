#include "HitSquare.h"
#include <iostream>

namespace obj {
	bool HitSquare::isHitSquareNoRotaVect(
		Position obj1[4],
		Position obj2[4]
	) {
		if (isHitSquareAndSquare(obj1, obj2))return true;
		return false;
	}
	bool HitSquare::isHitSquareNoRota(
		float get_x1[4],
		float get_y1[4],
		float get_x2[4],
		float get_y2[4]
	) {//長方形同士の角度を考慮に入れない場合
		Position sqrp1[4] = {
			{get_x1[0],get_y1[0]},
			{get_x1[1],get_y1[1]},
			{get_x1[2],get_y1[2]},
			{get_x1[3],get_y1[3]},
		};
		Position sqrp2[4] = {
			{get_x2[0],get_y2[0]},
			{get_x2[1],get_y2[1]},
			{get_x2[2],get_y2[2]},
			{get_x2[3],get_y2[3]},
		};
		if (isHitSquareAndSquare(sqrp1, sqrp2))return true;
		return false;
	}
	bool HitSquare::isHitCircle(
		float get_x1[4],
		float get_y1[4],
		float get_x2,
		float get_y2,
		float hitRange
	) {
		Position sqrp[4] = {
			{get_x1[0],get_y1[0]},
			{get_x1[1],get_y1[1]},
			{get_x1[2],get_y1[2]},
			{get_x1[3],get_y1[3]},
		};
		Position rpt = { get_x2,get_y2 };
		if (isHitSquareAndCircle(sqrp, rpt, hitRange))return true;
		return false;
	}
	HitSquare::Position* 
		HitSquare::getVector(float x, float y, float W, float H) {
		float halfW = sqrt((W - x) * (W - x));
		float halfH = sqrt((H - y) * (H - y));
		Position pos[4] = {
			{ x - halfW,y - halfH },
			{ x + halfW,y - halfH },
			{ x - halfW,y + halfH },
			{ x + halfW,y + halfH },
		};
		return pos;
	}
	void HitSquare::mSetDistance(Position* diff, const Position* p, const Position* q) {//ベクトル p - q
		diff->x = p->x - q->x;
		diff->y = p->y - q->y;
	}
	float HitSquare::mInnerProduct(const Position* p, const Position* q) {//ベクトル p と q の内積
		return p->x * q->x + p->y * q->y;
	}
	float HitSquare::mOuterProduct(const Position* p, const Position* q) {//ベクトル p と q の外積
		return p->x * q->y - p->y * q->x;
	}
	float HitSquare::mGetDistance(float x, float y, float x1, float y1, float x2, float y2) {//点と線分との距離を求める
		float dx, dy, a, b, t, tx, ty;
		float distance;

		dx = (x2 - x1); dy = (y2 - y1);
		a = dx * dx + dy * dy;
		b = dx * (x1 - x) + dy * (y1 - y);
		t = -b / a;
		if (t < 0) t = 0;
		if (t > 1) t = 1;
		tx = x1 + dx * t;
		ty = y1 + dy * t;
		distance = sqrt((x - tx) * (x - tx) + (y - ty) * (y - ty));

		return distance;
	}
	float HitSquare::mGetAngle(Position pt0, Position pt1, Position rpt) {//３点から角度を返す
		Position c, p, q;// 入力データ
		Position cp;// ベクトル C→P
		Position cq;// ベクトル C→Q 
		float s;// 外積：(C→P) × (C→Q) 
		float t;// 内積：(C→P) ・ (C→Q)
		float thet;// θ (ラジアン)
		c.x = pt0.x;    c.y = pt0.y;
		p.x = pt1.x;    p.y = pt1.y;
		q.x = rpt.x;    q.y = rpt.y;
		mSetDistance(&cp, &p, &c);//cp ← p - c
		mSetDistance(&cq, &q, &c);//cq ← q - c
		s = mOuterProduct(&cp, &cq);//s ← cp × cq
		t = mInnerProduct(&cp, &cq);//t ← cp ・ cq
		thet = atan2(s, t);
		return thet;
	}
	bool HitSquare::between(float data, float min, float max) {
		if (min <= data && data <= max)return true;
		return false;
	}
	bool HitSquare::isPoint_InCircle(Position p, Position rp, float r) {//点が円の中にあるかどうか
		float dx = p.x - rp.x, dy = p.y - rp.y;
		if (dx * dx + dy * dy < r * r)return true;
		else return false;
	}
	bool HitSquare::isHitSquareAndCircle(Position pt[4], Position rpt, float r) {//長方形と円との当たりを判定する
		float x = rpt.x, y = rpt.y;
		float theta, theta2;
		for (int i = 0; i < 4; i++) {
			if (isPoint_InCircle(pt[i], rpt, r))return true;
		}
		theta = mGetAngle(pt[0], pt[1], rpt);//3点の成す角1
		theta2 = mGetAngle(pt[2], pt[3], rpt);//3点の成す角2
		if (0 < theta && theta <= m_PI / 2 && 0 < theta2 && theta2 <= m_PI / 2)return true;
		for (int i = 0; i < 4; i++) {
			if (mGetDistance(rpt.x, rpt.y, pt[i].x, pt[i].y, pt[(i + 1) % 4].x, pt[(i + 1) % 4].y) < r)return true;
		}
		return false;
	}
	bool HitSquare::isHitSquareAndSquare(Position pt1[4], Position pt2[4]) {
		for (int num = 0; num < 4; num++) {
			if (between(pt1[num].x, pt2[0].x, pt2[1].x) && between(pt1[num].y, pt2[0].y, pt2[2].y))return true;
		}
		return false;
	}
}