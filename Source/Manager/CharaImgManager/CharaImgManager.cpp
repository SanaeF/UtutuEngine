#include "CharaImgManager.h"
#include<iostream>
#include "../../Source/SystemProp/AreaProp.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/Manager/CharaImgManager/TalkMotion/EyeMotion/EyeMotion.h"
#include "../../Source/Manager/CharaImgManager/TalkMotion/EyeBrowMotion/EyeBrowMotion.h"
#include "../../Source/Manager/CharaImgManager/TalkMotion/MouthMotion/MouthMotion.h"
#include "../../Source/Manager/CharaImgManager/FacialEffect/FacialEffect.h"
#include "../../Source/Helper/Helper.h"
#include "../../Source/Resource/SaveData/SaveData.h"
#include "../../Source/Resource/CharacterImage/CharacterImage.h"
#define PI 3.1415926535898

namespace app {

	CharaImgManager::CharaImgManager():
		m_Is_flag(false)
	{
		m_EyeMotion.reset(new EyeMotion());
		m_EyeBrowMotion.reset(new EyeBrowMotion());
		m_MouthMotion.reset(new MouthMotion());
		m_Facial.reset(new FacialEffect());
		m_Body_state = 0;
	}
	CharaImgManager::~CharaImgManager() {
	}
	void CharaImgManager::noImage() {
		lib::Graphics2D::drawRota(
			m_Px, m_Py, m_Size, m_Angle,
			res::CharacterImage::no_image,
			true
		);
	}
	void CharaImgManager::summon(int type, float x, float y, float size, float angle) {
		m_Is_flag = true;
		m_Type = type;
		m_Px = x;
		m_Py = y;
		m_Pre_size = size;
		m_Pre_angle = angle;
		m_Count = 0;
	}
	void CharaImgManager::summonFacial(int type, float x, float y) {
		m_Facial->spawn(type, x, y);
	}
	void CharaImgManager::update() {
		if (m_Is_flag) {
			mBody();
			mMotion();
			m_Facial->update();
			m_Count++;
		}
	}
	void CharaImgManager::draw() {
		if (m_Is_flag) {
			float add_x = 0.f;
			if (m_Is_back)lib::Graphics2D::setBright(100, 100, 100);
			//本体
			draw(res::CharacterImage::TalkChara[m_Type].body[m_Body_state]);
			if (m_Body_state != res::CharacterImage::POSE_TYPE::SPECIAL) {
				//顔パーツ
				draw(res::CharacterImage::TalkChara[m_Type].eye[m_EyeMotion->getImgState()]);
				draw(res::CharacterImage::TalkChara[m_Type].eyebrow[m_EyeBrowMotion->getImgState()]);
				draw(res::CharacterImage::TalkChara[m_Type].mouth[m_MouthMotion->getImgState()]);
				//衣装パーツ
				if (m_Type < res::CHARA_PL) {
					int outer = res::SaveData::save_data.chara_custom[m_Type].outer_wear_type;
					int under = res::SaveData::save_data.chara_custom[m_Type].under_wear_type;
					if (outer != 6)draw(res::CharacterImage::TalkChara[m_Type].socks_wear[outer]);//靴下
					draw(res::CharacterImage::TalkChara[m_Type].under_wear[under]);//腰辺り
					draw(res::CharacterImage::TalkChara[m_Type].outer_wear[outer]);//上着
				}
			}
			m_Facial->draw(m_Px, m_Py);
			if (m_Is_back)lib::Graphics2D::setBright(255, 255, 255);
		}
	}
	void CharaImgManager::mMotion() {
		m_EyeMotion->update();
		m_EyeBrowMotion->update();
		m_MouthMotion->update();
	}
	void CharaImgManager::mAnimationState(int state) {

	}
	void CharaImgManager::mBody() {
		m_Size = m_Pre_size;
		m_Angle = m_Pre_angle;
	}
	void CharaImgManager::draw(int handle) {
		lib::Graphics2D::drawRota(
			m_Px, m_Py, m_Size, m_Angle,
			handle,
			true
		);
	}
	void CharaImgManager::setFlag(bool flag) {
		m_Pre_angle = 0;
		this->m_Is_flag = flag;
	}
	void CharaImgManager::setBack(bool flag) {
		m_Is_back = flag;
	}
	void CharaImgManager::setType(int type) {
		this->m_Type = type;
	}
	void CharaImgManager::setSize(float size) {
		this->m_Pre_size = size;
	}
	void CharaImgManager::setOuterType(int type) {
		res::SaveData::save_data.chara_custom[m_Type].outer_wear_type = type;
	}
	void CharaImgManager::setUnderType(int type) {
		res::SaveData::save_data.chara_custom[m_Type].under_wear_type = type;
	}
	void CharaImgManager::setPos(float x, float y){
		this->m_Px = x;
		this->m_Py = y;
	}
	void CharaImgManager::setBodyState(int state) {
		m_Body_state = state;
	}
	void CharaImgManager::setEyeState(int state) {
		m_EyeMotion->setState(state);
	}
	void CharaImgManager::setBrowState(int state) {
		m_EyeBrowMotion->setState(state);
	}
	void CharaImgManager::setMouthState(int state) {
		m_MouthMotion->setState(state);
	}
	bool CharaImgManager::isFlag() {
		return m_Is_flag;
	}
	bool CharaImgManager::isBack() {
		return m_Is_back;
	}
}