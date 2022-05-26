#include "EyeBrowMotion.h"
#include"../../Source/Resource/CharacterImage/CharacterImage.h"

namespace app {
	void EyeBrowMotion::update() {
		if (m_State == BROW_STATE::BROW_NORMAL)normal();
		if (m_State == BROW_STATE::BROW_SAD)sad();
		if (m_State == BROW_STATE::BROW_ANGLY)angly();
		if (m_State == BROW_STATE::BROW_ORIGINAL)original();
	}
	void EyeBrowMotion::normal() {
		eye_brow.state = res::CharacterImage::BROW_TYPE::BROW_NORMAL;
	}
	void EyeBrowMotion::sad() {
		eye_brow.state = res::CharacterImage::BROW_TYPE::BROW_SAD;
	}
	void EyeBrowMotion::angly() {
		eye_brow.state = res::CharacterImage::BROW_TYPE::BROW_ANGLY;
	}
	void EyeBrowMotion::original() {
		eye_brow.state = res::CharacterImage::BROW_TYPE::BROW_ORIGINAL;
	}
	void EyeBrowMotion::setState(int state) {
		m_State = state;
	}
	int EyeBrowMotion::getImgState() {
		return eye_brow.state;
	}
}