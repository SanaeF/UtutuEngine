#include "EyeMotion.h"
#include"../../Source/Helper/Helper.h"
#include"../../Source/Resource/CharacterImage/CharacterImage.h"

namespace app {
	void EyeMotion::update() {
		if (m_State == EYE_STATE::NONE)normal();
		if (m_State == EYE_STATE::BLINK)blink();
		if (m_State == EYE_STATE::CLOSING)closing();
		if (m_State == EYE_STATE::SMILE)smile();
		if (m_State == EYE_STATE::ORIGINAL)original();
	}
	void EyeMotion::normal() {
		eye.state = res::CharacterImage::EYE_TYPE::EYE_OPEN;
	}
	void EyeMotion::blink() {
		const int close_dist = 5;
		if (eye.count == 0) {
			eye.random_state = GET_RANDOM(1);
			eye.state = res::CharacterImage::EYE_TYPE::EYE_OPEN;
		}
		eye.count++;
		if (eye.random_state == 0) {
			const int first = 100;
			if (eye.count == first)eye.state = res::CharacterImage::EYE_TYPE::EYE_CLOSE;
			if (eye.count == first + close_dist)eye.state = res::CharacterImage::EYE_TYPE::EYE_OPEN;
			if (eye.count == first + first)eye.count = 0;
		}
		if (eye.random_state == 1) {
			const int first[2] = { 150 ,160 };
			if (eye.count == first[0])eye.state = res::CharacterImage::EYE_TYPE::EYE_CLOSE;
			if (eye.count == first[0] + close_dist)eye.state = res::CharacterImage::EYE_TYPE::EYE_OPEN;
			if (eye.count == first[1])eye.state = res::CharacterImage::EYE_TYPE::EYE_CLOSE;
			if (eye.count == first[1] + close_dist)eye.state = res::CharacterImage::EYE_TYPE::EYE_OPEN;
			if (eye.count == first[1] + close_dist * 2)eye.count = 0;
		}
	}
	void EyeMotion::closing() {
		eye.count = 0;
		eye.random_state = 0;
		eye.state = res::CharacterImage::EYE_CLOSE;
	}
	void EyeMotion::smile() {
		eye.count = 0;
		eye.random_state = 0;
		eye.state = res::CharacterImage::EYE_SMILE;
	}
	void EyeMotion::original() {
		eye.count = 0;
		eye.random_state = 0;
		eye.state = res::CharacterImage::EYE_ORIGINAL;
	}
	void EyeMotion::setState(int state) {
		m_State = state;
	}
	int EyeMotion::getImgState() {
		return eye.state;
	}
}