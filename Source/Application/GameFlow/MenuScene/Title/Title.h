#pragma once
#include <iostream>
#include "../../Source/Application/GameFlow/Scene/Scene.h"

namespace app {
	const int m_Title_menu = 9;
	class Title : public Scene {
	private:
		const int m_Pos_x = 1400;
		const int m_Pos_y = 300;
		const int m_Tex_while_space = 120;
		MenuText m_Title_gui[m_Title_menu] = {//�񎟑n��
			{ m_Pos_x, m_Pos_y + (m_Tex_while_space * 0), "�X�g�[���[" },
			{ m_Pos_x, m_Pos_y + (m_Tex_while_space * 1), "�G�L�X�g��" },
			{ m_Pos_x, m_Pos_y + (m_Tex_while_space * 2), "���K���[�h" },
			{ m_Pos_x, m_Pos_y + (m_Tex_while_space * 3), "���v���C" },
			{ m_Pos_x, m_Pos_y + (m_Tex_while_space * 4), "�ߑ�����" },
			{ m_Pos_x, m_Pos_y + (m_Tex_while_space * 5), "���y��" },
			{ m_Pos_x, m_Pos_y + (m_Tex_while_space * 6), "�w���v" },
			{ m_Pos_x, m_Pos_y + (m_Tex_while_space * 7), "�ݒ�" },
			{ m_Pos_x, m_Pos_y + (m_Tex_while_space * 8), "�Q�[�����I������"},
		};
		MenuText m_Extra_gui[2] = { 
			{ m_Pos_x, m_Pos_y + (m_Tex_while_space * 1), "�G�L�X�g��(���J��)" } ,
			{ m_Pos_x, m_Pos_y + (m_Tex_while_space * 1), "�G�L�X�g��" }
		};
		int m_Count;
		int m_Text_count;
	public:
		void select()override;
		void cancel()override;
		int update()override;
		void draw()override;
		Title();
		~Title();
	private:
		void scrollText(int x, std::string text);
	};
}