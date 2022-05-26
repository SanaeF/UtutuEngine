#include "ItemRoulette.h"
#include <iostream>
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/library/Graphics/String/StringDX.h"
#include "../../Source/Application/Replayer/Replayer.h"
#include "../../Source/Helper/Helper.h"
#include "../../Source/Manager/ItemManager/ItemManager.h"
#include "../../Source/Resource/ItemImage/ItemImage.h"
#include "../../Source/Resource/GUI/GameUIImage/GameUIImage.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"
#include "../../Source/Object/Player/Player.h"
#include "../../Source/SystemProp/AreaProp.h"
#include "../../Source/SystemProp/AliceProp/AliceProp.h"
#include "../../Source/Resource/SaveData/SaveData.h"
#pragma warning(disable : 4996)
namespace app {
	int item_table[4][4] = {
		{ res::ITEM_TYPE::POINT, res::ITEM_TYPE::POWER, res::ITEM_TYPE::LIFE_PEACE, res::ITEM_TYPE::BOM_PEACE },//一番ハズレテーブル
		{ res::ITEM_TYPE::POINT, res::ITEM_TYPE::BOM_PEACE, res::ITEM_TYPE::POWER, res::ITEM_TYPE::LIFE_PEACE },//ハズレテーブル
		{ res::ITEM_TYPE::LIFE_PEACE, res::ITEM_TYPE::BOM_PEACE, res::ITEM_TYPE::POWER, res::ITEM_TYPE::BOM_PEACE },//普通テーブル
		{ res::ITEM_TYPE::BOM_PEACE, res::ITEM_TYPE::LIFE_PEACE, res::ITEM_TYPE::POWER, res::ITEM_TYPE::LIFE_PEACE},//アタリテーブル
	};


	ItemRoulette::ItemRoulette():
		m_Flag(false),
		m_Item_table{0,0,0,0},
		m_Item_type(0),
		m_Table_id(0),
		m_Roulette_start_num(0),
		m_State(0),
		m_Count(0)
	{
	}
	void ItemRoulette::draw() {
		if (!m_Flag)return;
		int x = (AREA::FMIN_X + AREA::FMAX_X) / 2;
		int y = AREA::FMIN_Y + 171;
		int blend = 255;
		if (m_State == BOX_STATE::ROATION && m_Count < 10)blend = 255 / 10 * m_Count;
		lib::Graphics2D::setBlend(lib::BLEND_MODE::ALPHA, blend);
		lib::Graphics2D::drawRota(
			x, y,
			1.f, 0,
			res::GameUIImage::game_ui.special.roulette, true
		);
		lib::Graphics2D::drawRota(
			x - 45, y,
			1.5f, 0,
			res::ItemImage::item.bit[m_Item_type], true
		);
		lib::StringDX::draw(x + 80, y + 10, "x ", lib::StringDX::color(255, 255, 255), res::TextUIImage::text_ui.font[res::FONT::FONT_SB_ROULETTE]);
		lib::Graphics2D::drawRota(
			x + 160, y + 20,
			2.f,
			0.f,
			res::TextUIImage::text_ui.number[0][m_Bounus],
			true
		);
		lib::Graphics2D::setBlend(lib::BLEND_MODE::NONE, 0);
	}
	void ItemRoulette::update(obj::Player& player, std::shared_ptr<obj::ItemManager> item) {
		if (!m_Flag && player.isRoulette()) {
			spawn();
		}
		if (!m_Flag)return;
		player.setRoulette(false);
		const int stop_time = 500;
		if (m_State == BOX_STATE::ROATION) {
			setBounus(player.getItemStack().roulette_bounus);
			int id = (m_Roulette_start_num + m_Count / 5) % 4;
			if (m_Count > stop_time - 180)id = (m_Roulette_start_num + m_Count / 10) % 4;
			if (m_Count > stop_time - 120)id = (m_Roulette_start_num + m_Count / 25) % 4;
			m_Item_type = item_table[m_Table_id][id];
			m_Count++;
			if (m_Count > stop_time) {
				m_State = BOX_STATE::STOP;
				m_Count = 0;
			}
		}
		if (m_State == BOX_STATE::STOP) {
			player.getItemStack().roulette_bounus = 0;
			m_Count++;
			if (m_Count > 60)m_State = BOX_STATE::DROP;
		}
		if (m_State == BOX_STATE::DROP) {
			int item_num = m_Bounus;
			if (m_Item_type == res::ITEM_TYPE::POINT)item_num = item_num * 13;
			if (m_Item_type == res::ITEM_TYPE::POWER)item_num = item_num * 7;
			item->drop(
				(AREA::FMAX_X - AREA::FMIN_X) / 2,
				AREA::FMIN_Y + 171,
				item_num,
				m_Item_type,
				0
			);
			m_Flag = false;
			m_State = BOX_STATE::ROATION;
		}
	}
	void ItemRoulette::spawn() {
		Replayer::GameRecorder.callSeedProcess(50);
		m_Table_id = GET_SEED_RANDOM(3);
		m_Roulette_start_num = GET_SEED_RANDOM(3);
		m_State = BOX_STATE::ROATION;
		m_Count = 0;
		m_Flag = true;
	}
	void ItemRoulette::setBounus(int bounus_num) {
		if (BEDWEEN(bounus_num, 0, 210))m_Bounus = 1;
		if (BEDWEEN(bounus_num, 210, 450))m_Bounus = 2;
		if (BEDWEEN(bounus_num, 450, 680))m_Bounus = 3;
		if (BEDWEEN(bounus_num, 680, 950))m_Bounus = 4;
		if (bounus_num >= 950)m_Bounus = 5;
		if (AliceProp::flag) {
			if (res::SaveData::save_data.weapon[AliceProp::weapon_type].ex_type == 4) {
				m_Bounus += 2;
			}
		}
	}
}