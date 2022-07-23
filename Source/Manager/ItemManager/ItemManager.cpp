#include "ItemManager.h"
#include <iostream>
#include <cassert>
#include "../../Source/SystemProp/AreaProp.h"
#include "../../Source/SystemProp/GameSceneProp/GameSceneProp.h"
#include "../../Source/Object/Item/BitItem/BitItem.h"
#include "../../Source/Object/Item/GhostItem/GhostItem.h"
#include "../../Source/Object/Player/Player.h"
#include "../../Source/MassageHandle/MassageHandle.h"
#include "../../Source/Resource/ItemImage/ItemImage.h"
#include "../../Source/Helper/Helper.h"
#include "../../Source/Application/Sound/Sound.h"
#include "../../Source/Resource/SoundData/SoundData.h"
using namespace res;

namespace obj {
	std::vector<BitItem> ItemManager::m_Item;
	std::vector<GhostItem> ItemManager::m_Item_ghost;
	ItemManager::ItemManager() {
		m_Item.resize(1000);
		m_Item_ghost.resize(1000);
		for (int ite = 0; ite < m_Item.size(); ite++) {
			m_Item[ite].clear();
		}
		for (int ite = 0; ite < m_Item_ghost.size(); ite++) {
			m_Item_ghost[ite].clear();
		}
	}
	void ItemManager::dropBoss(int num, int type, int layer) {
		drop(AreaProp::deff_boss_x, AreaProp::deff_boss_y, num, type, layer);
	}
	void ItemManager::drop(float x, float y, int num, int type, int layer) {
		if (GameSceneProp::under_wear==1) {
			if (type == ITEM_TYPE::POWER_GHOST)num= num+(num/2);
		}
		for (int i = 0; i < num; i++) {
			int dist = 230;
			float rd_x = 0;
			float rd_y = 0;
			if (type != res::ITEM_TYPE::START_ROULETTE && num > 1) {
				rd_x = GET_SEED_RANDOM_F(dist);
				rd_y = GET_SEED_RANDOM_F(dist);
			}
			int k;
			if (type >= ITEM_TYPE::POWER_GHOST) {
				if (type >= ITEM_TYPE::ITEM_TYPE_MAX) {
					return;
				}
				if ((k = search(m_Item_ghost)) != -1) {
					m_Item_ghost[k].setFlag(true);
					m_Item_ghost[k].setX(x + rd_x);
					m_Item_ghost[k].setY(y + rd_y);
					m_Item_ghost[k].setType(type - ITEM_TYPE::POWER_GHOST);
					m_Item_ghost[k].setCount(0);
					m_Item_ghost[k].setRayer(layer);
				}
			}
			else {
				if ((k = search(m_Item)) != -1) {
					m_Item[k].setFlag(true);
					m_Item[k].setX(x + rd_x);
					m_Item[k].setY(y + rd_y);
					m_Item[k].setType(type);
					m_Item[k].setSpeed(-4.5);
					m_Item[k].setCount(0);
					m_Item[k].setRayer(layer);
				}
			}
		}
	}
	void ItemManager::update() {
		for (int num = 0; num < m_Item.size(); num++) {
			dropItemForPlayer(num);
		}
		for (int num = 0; num < m_Item_ghost.size(); num++) {
			dropItemGhostForPlayer(num);
		}
	}
	void ItemManager::draw(double crush_x, double crush_y) {
		for (int num = 0; num < m_Item.size(); num++) {
			m_Item[num].draw(crush_x, crush_y);
		}
		for (int num = 0; num < m_Item_ghost.size(); num++) {
			m_Item_ghost[num].draw(crush_x, crush_y);
		}
	}
	void ItemManager::dropItemForPlayer(int num) {
		if (!m_Item[num].isFlag())return;
		Player* ch;
		ch = &Player::PlayerObj;
		if (m_Item[num].getRayer() == 1)ch = &Player::PlayersObj[0];
		if (m_Item[num].getRayer() == 2)ch = &Player::PlayersObj[1];
		if (m_Item[num].getType() == res::ITEM_TYPE::START_ROULETTE)
			getDropItem(num);
		bool isGet = false;
		float x = ch->getX() - m_Item[num].getX(), y = ch->getY() - m_Item[num].getY();
		if ((ch->isSlow()&& x * x + y * y < ITEM_INDRAW_RANGE * ITEM_INDRAW_RANGE) ||
			(ch->getY() < ITEM_GET_BORDER_LINE)
			) {
			isGet = true;
		}
		m_Item[num].update(isGet, ch->getX(), ch->getY());
		if (x * x + y * y < ITEM_HIT_BOX * ITEM_HIT_BOX) {
			getDropItem(num);
		}
	}
	void ItemManager::dropItemGhostForPlayer(int num) {
		if (!m_Item_ghost[num].isFlag())return;
		Player* ch;
		ch = &Player::PlayerObj;
		if (m_Item_ghost[num].getRayer() == 1)ch = &Player::PlayersObj[0];
		if (m_Item_ghost[num].getRayer() == 2)ch = &Player::PlayersObj[1];
		m_Item_ghost[num].update(ch->isGraze(), ch->getX(), ch->getY());
		float x = ch->getX() - m_Item_ghost[num].getX(), y = ch->getY() - m_Item_ghost[num].getY();
		if (x * x + y * y < ITEM_HIT_BOX * ITEM_HIT_BOX) {
			getDropItemGhost(num);
		}
	}
	void ItemManager::getDropItem(int num) {
		int rayer = m_Item[num].getRayer();
		app::Sound::sound.playSE(res::SE::GOT_ITEM);
		if (m_Item[num].getType() == ITEM_TYPE::POWER) {
			MassageHandleItem(PLAYER::GetPower,  1, rayer);
			MassageHandleItem(PLAYER::GetScore, 10, rayer);
		}
		if (m_Item[num].getType() == ITEM_TYPE::POINT) {
			MassageHandleItem(PLAYER::GetPoint, 1, rayer);
			MassageHandleItem(PLAYER::GetScore, 6, rayer);
		}
		if (m_Item[num].getType() == ITEM_TYPE::LIFE_UP) {
			MassageHandleItem(PLAYER::GetLife, 1, rayer);
			MassageHandleItem(PLAYER::GetScore, 20, rayer);
		}
		if (m_Item[num].getType() == ITEM_TYPE::LIFE_PEACE) {
			MassageHandleItem(PLAYER::GetLifeFragment, 1, rayer);
			MassageHandleItem(PLAYER::GetScore, 15, rayer);
		}
		if (m_Item[num].getType() == ITEM_TYPE::BOM_PEACE) {
			MassageHandleItem(PLAYER::GetBomFragment, 1, rayer);
			MassageHandleItem(PLAYER::GetScore, 15, rayer);
		}
		if (m_Item[num].getType() == ITEM_TYPE::BOM_UP) {
			MassageHandleItem(PLAYER::GetBom, 1, rayer);
			MassageHandleItem(PLAYER::GetScore, 18, rayer);
		}
		if (m_Item[num].getType() == ITEM_TYPE::APPLE) {
			MassageHandleItem(PLAYER::GetApple, 1, rayer);
			MassageHandleItem(PLAYER::GetScore, 5, rayer);
		}
		if (m_Item[num].getType() == ITEM_TYPE::GOLDEN_APPLE) {
			MassageHandleItem(PLAYER::GetApple, 3, rayer);
			MassageHandleItem(PLAYER::GetScore, 15, rayer);
		}
		if (m_Item[num].getType() == ITEM_TYPE::START_ROULETTE) {
			MassageHandleItem(PLAYER::StartRoulette, 0, rayer);
		}
		if (m_Item[num].getType() == ITEM_TYPE::SCORE_DUST) {
			MassageHandleItem(PLAYER::GetScore, 20, rayer);
		}
		m_Item[num].clear();
	}
	void ItemManager::getDropItemGhost(int num) {
		int rayer = m_Item_ghost[num].getRayer();
		if (m_Item_ghost[num].getType() == ITEM_GHOST_TYPE::RED_GHOST) {
			MassageHandleItem(PLAYER::GetPower, 1, rayer);
			MassageHandleItem(PLAYER::GetScore, 10, rayer);
		}
		if (m_Item_ghost[num].getType() == ITEM_GHOST_TYPE::RED_GHOST) {
			MassageHandleItem(PLAYER::GetScore, 20, rayer);
		}
		m_Item_ghost[num].clear();
	}
	template <typename T>
	int ItemManager::search(T obj) {
		for (int i = 0; i < obj.size(); i++)
			if (obj[i].isFlag() == 0)return i;
		return -1;
	}
	ItemManager::~ItemManager() {

	}
}