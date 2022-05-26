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
	) {//�����`���m�̊p�x���l���ɓ���Ȃ��ꍇ
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
	void HitSquare::mSetDistance(Position* diff, const Position* p, const Position* q) {//�x�N�g�� p - q
		diff->x = p->x - q->x;
		diff->y = p->y - q->y;
	}
	float HitSquare::mInnerProduct(const Position* p, const Position* q) {//�x�N�g�� p �� q �̓���
		return p->x * q->x + p->y * q->y;
	}
	float HitSquare::mOuterProduct(const Position* p, const Position* q) {//�x�N�g�� p �� q �̊O��
		return p->x * q->y - p->y * q->x;
	}
	float HitSquare::mGetDistance(float x, float y, float x1, float y1, float x2, float y2) {//�_�Ɛ����Ƃ̋��������߂�
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
	float HitSquare::mGetAngle(Position pt0, Position pt1, Position rpt) {//�R�_����p�x��Ԃ�
		Position c, p, q;// ���̓f�[�^
		Position cp;// �x�N�g�� C��P
		Position cq;// �x�N�g�� C��Q 
		float s;// �O�ρF(C��P) �~ (C��Q) 
		float t;// ���ρF(C��P) �E (C��Q)
		float thet;// �� (���W�A��)
		c.x = pt0.x;    c.y = pt0.y;
		p.x = pt1.x;    p.y = pt1.y;
		q.x = rpt.x;    q.y = rpt.y;
		mSetDistance(&cp, &p, &c);//cp �� p - c
		mSetDistance(&cq, &q, &c);//cq �� q - c
		s = mOuterProduct(&cp, &cq);//s �� cp �~ cq
		t = mInnerProduct(&cp, &cq);//t �� cp �E cq
		thet = atan2(s, t);
		return thet;
	}
	bool HitSquare::between(float data, float min, float max) {
		if (min <= data && data <= max)return true;
		return false;
	}
	bool HitSquare::isPoint_InCircle(Position p, Position rp, float r) {//�_���~�̒��ɂ��邩�ǂ���
		float dx = p.x - rp.x, dy = p.y - rp.y;
		if (dx * dx + dy * dy < r * r)return true;
		else return false;
	}
	bool HitSquare::isHitSquareAndCircle(Position pt[4], Position rpt, float r) {//�����`�Ɖ~�Ƃ̓�����𔻒肷��
		float x = rpt.x, y = rpt.y;
		float theta, theta2;
		for (int i = 0; i < 4; i++) {
			if (isPoint_InCircle(pt[i], rpt, r))return true;
		}
		theta = mGetAngle(pt[0], pt[1], rpt);//3�_�̐����p1
		theta2 = mGetAngle(pt[2], pt[3], rpt);//3�_�̐����p2
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