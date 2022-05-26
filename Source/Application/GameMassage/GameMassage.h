#pragma once
#include<iostream>
#include<vector>
namespace app {
	class GameMassage {
	private:
		struct Massage {
			int count;
			int time;
			bool flag;
			std::string text;
		};
		int m_State;
		bool m_Is_not_end;
		bool m_Flag;
		std::vector<Massage> m_Massage;
	public:
		GameMassage();
		void draw();
		void update();
		void setText(std::string text, int time);
		bool isNotEndFlag();
		bool isFlag();
	};
}