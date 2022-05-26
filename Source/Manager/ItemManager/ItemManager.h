#pragma once
#include <vector>

namespace obj {
	class BitItem;
	class GhostItem;
	class ItemManager {
	private:
		static std::vector<BitItem> m_Item;
		static std::vector<GhostItem> m_Item_ghost;
		
	public:
		ItemManager();
		~ItemManager();
		void drop(float x, float y, int num, int type, int layer);
		void dropBoss(int num, int type, int layer);
		void update();
		void draw(double crush_x = 0.f, double crush_y = 0.f);
	private:
		void dropItemForPlayer(int num);
		void dropItemGhostForPlayer(int num);
		void getDropItem(int num);
		void getDropItemGhost(int num);
		template <typename T>int search(T obj);
	};
}