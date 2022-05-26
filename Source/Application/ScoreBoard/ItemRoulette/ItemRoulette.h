#pragma once
#include <memory>
namespace obj {
	class ItemManager;
	class Player;
}
namespace app {
	class ItemRoulette {
	private:
		enum BOX_STATE{
			ROATION,
			STOP,
			DROP
		};
		bool m_Flag;
		int m_Item_table[4];
		int m_Item_type;
		int m_Table_id;
		int m_Roulette_start_num;
		int m_Bounus;
		int m_State;
		int m_Count;
	public:
		ItemRoulette();
		void draw();
		void update(obj::Player& player, std::shared_ptr<obj::ItemManager> item);
	private:
		void spawn();
		void setBounus(int bounus_num);
	};
}