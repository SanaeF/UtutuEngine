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
		MenuText m_Title_gui[m_Title_menu] = {//二次創作
			{ m_Pos_x, m_Pos_y + (m_Tex_while_space * 0), "ストーリー" },
			{ m_Pos_x, m_Pos_y + (m_Tex_while_space * 1), "エキストラ" },
			{ m_Pos_x, m_Pos_y + (m_Tex_while_space * 2), "練習モード" },
			{ m_Pos_x, m_Pos_y + (m_Tex_while_space * 3), "リプレイ" },
			{ m_Pos_x, m_Pos_y + (m_Tex_while_space * 4), "衣装部屋" },
			{ m_Pos_x, m_Pos_y + (m_Tex_while_space * 5), "音楽室" },
			{ m_Pos_x, m_Pos_y + (m_Tex_while_space * 6), "ヘルプ" },
			{ m_Pos_x, m_Pos_y + (m_Tex_while_space * 7), "設定" },
			{ m_Pos_x, m_Pos_y + (m_Tex_while_space * 8), "ゲームを終了する"},
		};
		MenuText m_Extra_gui[2] = { 
			{ m_Pos_x, m_Pos_y + (m_Tex_while_space * 1), "エキストラ(未開放)" } ,
			{ m_Pos_x, m_Pos_y + (m_Tex_while_space * 1), "エキストラ" }
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