#pragma once
#include <memory>
#include "../../Source/Manager/CharaImgManager/TalkMotion/TalkMotion.h"
namespace app {
	class EyeMotion;
	class EyeBrowMotion;
	class MouthMotion;
	class FacialEffect;
	class CharaImgManager {
	private:
		std::shared_ptr<EyeMotion> m_EyeMotion;
		std::shared_ptr<EyeBrowMotion> m_EyeBrowMotion;
		std::shared_ptr<MouthMotion> m_MouthMotion;
		std::shared_ptr<FacialEffect> m_Facial;
		bool m_Is_flag;
		bool m_Is_back;
		int m_Type;
		int m_Body_state;
		int m_Cloth_type[2];
		float m_Px;
		float m_Py;
		double m_Pre_angle;
		double m_Pre_size;
		double m_Angle;
		double m_Size;
		int m_Count;
	public:
		CharaImgManager();
		~CharaImgManager();
		void noImage();
		void summon(int type, float x, float y, float size, float angle);
		void summonFacial(int type, float x, float y);
		void update();
		void draw();
		void setFlag(bool flag);
		void setBack(bool flag);
		void setType(int type);
		void setSize(float  size);
		void setOuterType(int type);
		void setUnderType(int type);
		void setPos(float x, float y);
		void setBodyState(int state);
		void setEyeState(int state);
		void setBrowState(int state);
		void setMouthState(int state);
		bool isFlag();
		bool isBack();
	private:
		void mMotion();
		void mAnimationState(int state);
		void mBody();
		void draw(int handle);
	};
}