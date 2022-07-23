#include "PlayerScore.h"

#include "../../Source/SystemProp/GameSceneProp/GameSceneProp.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/Object/Player/Player.h"
#include "../../Source/SystemProp/AreaProp.h"
#include "../../Source/Resource/GUI/GameUIImage/GameUIImage.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"
#include "../../Source/Resource/SaveData/SaveData.h"

namespace app {
	float PlayerScore::m_P_y[8] = {
			95 * 2,
			135 * 2,
			409,
			566,
			355 * 2,
			410 * 2,
			460 * 2,
			0
	};
	void PlayerScore::drawLevel(int diff) {
		lib::Graphics2D::draw(
			AreaProp::max_x,
			0,
			res::GameUIImage::game_ui.diff[diff],
			true
		);
	}
	void PlayerScore::drawScore(obj::Player player, int ID_y1, int ID_y2) {
		lib::Graphics2D::drawMode(lib::DRAW_MODE::BILINEAR);
		auto data = player.getItemStack();
		auto high_score = res::SaveData::save_data.clear.highScore[GameSceneProp::difficulty];
		auto score = data.score;
		for (int i = 0; i < 10; i++) {
			//ハイスコア表示
			lib::Graphics2D::drawRota(
				(900 - 15 * i) * 2,
				m_P_y[ID_y1],
				0.8f,
				0.0f,
				res::TextUIImage::text_ui.number[0][high_score % 10],
				true
			);
			//スコア表示
			lib::Graphics2D::drawRota(
				(900 - 15 * i) * 2,
				m_P_y[ID_y2],
				0.8f,
				0.0f,
				res::TextUIImage::text_ui.number[0][score % 10],
				true
			);
			high_score /= 10;
			score /= 10;
		}
		lib::Graphics2D::drawMode(lib::DRAW_MODE::NEAREST);
	}
	void PlayerScore::drawLife(obj::Player player, int ID_y) {
		lib::Graphics2D::drawMode(lib::DRAW_MODE::BILINEAR);
		auto data = player.getItemStack();
		if (data.life < 0)data.life = 0;
		//残機数を表示
		for (int i = 0; i < data.life; i++) {
			lib::Graphics2D::draw(
				1321 + 52 * i,
				m_P_y[ID_y],
				res::GameUIImage::game_ui.life[3], 
				true
			);
		}
		//残機のかけら数を表示
		if (data.life_fragument > 0)lib::Graphics2D::draw(
			1321 + 52 * data.life,
			m_P_y[ID_y],
			res::GameUIImage::game_ui.life[data.life_fragument - 1],
			true
		);
		lib::Graphics2D::drawMode(lib::DRAW_MODE::NEAREST);
	}
	void PlayerScore::drawBom(obj::Player player, int ID_y) {
		lib::Graphics2D::drawMode(lib::DRAW_MODE::BILINEAR);
		auto data = player.getItemStack();
		//ボム数を表示
		for (int i = 0; i < data.bom; i++) {
			lib::Graphics2D::draw(
				1320 + 53 * i,
				m_P_y[ID_y],
				res::GameUIImage::game_ui.bom[7],
				true
			);
		}
		//ボムのかけら数を表示
		if (data.bom_fragument > 0)lib::Graphics2D::draw(
			1320 + 53 * data.bom,
			m_P_y[ID_y],
			res::GameUIImage::game_ui.bom[data.bom_fragument - 1],
			true
		);
		lib::Graphics2D::drawMode(lib::DRAW_MODE::NEAREST);
	}
	void PlayerScore::drawPower(obj::Player player, int ID_y) {
		lib::Graphics2D::drawMode(lib::DRAW_MODE::BILINEAR);
		auto data = player.getItemStack();
		//パワー数を表示
		int power = data.power;
		for (int i = 0; i < 3; i++) {
			lib::Graphics2D::drawRota(
				(830 - 14 * i) * 2,
				m_P_y[ID_y],
				0.8f,
				0.0f,
				res::TextUIImage::text_ui.number[0][power % 10],
				true
			);
			power /= 10;
		}
		lib::Graphics2D::drawMode(lib::DRAW_MODE::NEAREST);
	}
	void PlayerScore::drawPoint(obj::Player player, int ID_y) {
		lib::Graphics2D::drawMode(lib::DRAW_MODE::BILINEAR);
		auto data = player.getItemStack();
		//ポイント数を表示
		int point = data.point;
		for (int i = 0; i < 3; i++) {
			lib::Graphics2D::drawRota(
				(830 - 14 * i) * 2,
				m_P_y[ID_y],
				0.8f,
				0.0f,
				res::TextUIImage::text_ui.number[0][point % 10],
				true
			);
			point /= 10;
		}
		lib::Graphics2D::drawMode(lib::DRAW_MODE::NEAREST);
	}
	void PlayerScore::drawGraze(obj::Player player, int ID_y) {
		lib::Graphics2D::drawMode(lib::DRAW_MODE::BILINEAR);
		auto data = player.getItemStack();
		//グレイズ数を表示
		int graze = data.graze;
		for (int i = 0; i < 4; i++) {
			lib::Graphics2D::drawRota(
				(830 - 14 * i) * 2,
				m_P_y[ID_y],
				0.8f,
				0.0f,
				res::TextUIImage::text_ui.number[0][graze % 10],
				true
			);
			graze /= 10;
		}
		lib::Graphics2D::drawMode(lib::DRAW_MODE::NEAREST);
	}
	void PlayerScore::drawOption(obj::Player player, int ID_y) {

	}
	void PlayerScore::drawApple(obj::Player player) {
		auto data = player.getItemStack();
		for (int i = 0; i < data.apple; i++) {
			lib::Graphics2D::draw(
				1252 + 99 * i,
				957,
				res::GameUIImage::game_ui.special.apple,
				true
			);
		}
	}
	void PlayerScore::drawCamp(obj::Player player) {
		lib::Graphics2D::drawRota(1350, 1170, 1.f, 0.0f, res::GameUIImage::game_ui.special.camp[0], true);
		const float camp_max = player.getItemStack().camp_max;
		float camp_num = player.getItemStack().camp_fragument;
		lib::Graphics2D::circleGauge(1350, 1170, 100.f - ((100.f * camp_num) / camp_max), res::GameUIImage::game_ui.special.camp[1], 0);
	}
	void PlayerScore::drawCrush(obj::Player player) {
		lib::Graphics2D::drawRota(AreaProp::min_x - 200, AreaProp::max_y - 250, 1.f, 0.0f, res::GameUIImage::game_ui.special.crush_back, true);
		const float bomMax = 140;
		float bomNum = player.getItemStack().graze;
		lib::Graphics2D::circleGauge(AreaProp::min_x - 200, AreaProp::max_y - 250, 100.f - ((100.f * bomNum) / bomMax), res::GameUIImage::game_ui.special.crush_front, 0);
	}
}