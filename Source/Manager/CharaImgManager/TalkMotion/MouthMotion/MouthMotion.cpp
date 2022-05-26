#include "MouthMotion.h"
#include"../../Source/Helper/Helper.h"
#include"../../Source/Resource/CharacterImage/CharacterImage.h"
#define PI 3.1415926535898

namespace app {
	void MouthMotion::update() {
		if (m_State == MOUTH_STATE::MOUTH_CLOSE)close();
		if (m_State == MOUTH_STATE::MOUTH_SAY)saying();
		if (m_State == MOUTH_STATE::MOUTH_ORIGINAL)original();
	}
	void MouthMotion::close() {
		mouth.state = res::CharacterImage::MOUTH_TYPE::MOUTH_CLOSE;
	}
	void MouthMotion::saying() {
		const int close_dist = 25;
		if (mouth.count == 0) {
			mouth.random_state = GET_RANDOM(2);
			mouth.state = res::CharacterImage::MOUTH_TYPE::MOUTH_OPEN;
		}
		if (mouth.random_state == 0) {
			const int first = 60;
			if (mouth.count == first)mouth.state = res::CharacterImage::MOUTH_TYPE::MOUTH_CLOSE;
			if (mouth.count == first + close_dist)mouth.state = res::CharacterImage::MOUTH_TYPE::MOUTH_OPEN;
			if (mouth.count == first + first)mouth.count = 0;
		}
		if (mouth.random_state == 1) {
			const int first[2] = { 60 ,150 };
			if (mouth.count == first[0])mouth.state = res::CharacterImage::MOUTH_TYPE::MOUTH_CLOSE;
			if (mouth.count == first[0] + close_dist)mouth.state = res::CharacterImage::MOUTH_TYPE::MOUTH_OPEN;
			if (mouth.count == first[1])mouth.state = res::CharacterImage::MOUTH_TYPE::MOUTH_CLOSE;
			if (mouth.count == first[1] + close_dist)mouth.state = res::CharacterImage::MOUTH_TYPE::MOUTH_OPEN;
			if (mouth.count == first[0] + first[1])mouth.count = 0;
			mouth.count++;
		}
	}
	void MouthMotion::original() {
		mouth.count = 0;
		mouth.random_state = 0;
		mouth.state = res::CharacterImage::MOUTH_TYPE::MOUTH_ORIGINAL;
	}
	void MouthMotion::setState(int state) {
		m_State = state;
	}
	int MouthMotion::getImgState() {
		return mouth.state;
	}
}