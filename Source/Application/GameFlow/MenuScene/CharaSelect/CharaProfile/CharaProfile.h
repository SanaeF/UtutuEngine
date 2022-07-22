#pragma once
#include <string>
#include <memory>
namespace app {
	class CharaImgManager;
	class CharaProfile {
	private:
		std::shared_ptr<CharaImgManager>m_Img;
		int m_Type;
		float m_Fade_x;
	public:
		CharaProfile();
		void draw();
		void update();
		void setType(int type);
		void setFadeX(float x);
	private:
		void optionText();
		void profileText();

		void text(
			int type,
			int x,
			int y,
			std::string text0,
			std::string text1, 
			std::string text2,
			std::string text3,
			std::string text4,
			std::string text5,
			std::string text6,
			std::string text7,
			std::string text8,
			std::string text9
		);
	};
}