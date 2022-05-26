#pragma once
#include <memory>
#include "../../Source/Application/GameFlow/Scene/Scene.h"
#include "../../Source/Object/Player/Data/CharaCustom.h"
namespace app {
	class CharaImgManager;
	class DressRoom : public Scene {
	private:
		enum SELECT_TYPE {
			CHARA,
			OUTER_WEAR,
			SKIRT
		};
		char m_Locked_name[128] = "未開放の服です";
		char m_No_name[128] = "枠なし";
		char* m_Check_unlocked[2];
		//体験版は、標準、私服、ロングコート
		MenuText m_Outer_wear_name[6][5] = {//綾乃、みさと、赤城、媛、庵子
			//綾乃のみ、ホーミング鶴オプションが付く
			{{ 0, 0, "標準" },				{ 0, 1, "標準" },		{ 0, 2, "標準" },		{ 0, 3, "標準" },				{ 0, 4, "標準" }		},
			//綾乃と赤城のみ、チャージオプションが付く
			{{ 1, 0, "セーラー服" },		{ 1, 1, "セーラー服" },	{ 1, 2, "枠なし" },		{ 1, 3, "枠なし" },				{ 1, 4, "枠なし" }		},
			//綾乃のみ、レーザーオプションが付く
			{{ 2, 0, "ブレザー&セーター" },	{ 2, 1, "枠なし" },		{ 1, 2, "枠なし" },		{ 2, 3, "ブレザー&セーター" },	{ 2, 4, "枠なし" }		},
			//綾乃、みさとにホーミング鶴オプションが付く
			{{ 3, 0, "私服" },				{ 3, 1, "私服" },		{ 3, 2, "私服" },		{ 3, 3, "私服" },				{ 3, 4, "私服" }		},
			//綾乃のみ、ホーミング鶴オプションが付く
			{{ 4, 0, "赤ずきん" },			{ 4, 1, "枠なし" },		{ 1, 2, "赤ずきん" },		{ 4, 3, "枠なし" },				{ 4, 4, "枠なし" }	},
			//綾乃と庵孤のみ、ホーミング鶴オプションが付く
			{{ 5, 0, "ロングコート" },		{ 5, 1, "枠なし" },		{ 1, 2, "枠なし" },		{ 5, 3, "枠なし" },				{ 5, 4, "ロングコート" }},
		};
		MenuText m_Under_wear_name[6] = {
			//特になし
			{ 0, 0, "標準" },
			//敵から落ちるパワーアイテムが増える(+1～5)//綾乃のみ
			{ 2, 0, "プリーツスカート(ライン)" },
			//ボムを使わずに弾幕を攻略すると、残機の欠片を落す。そのかわりに持っているボムの欠片がすべて消失する
			{ 3, 0, "プリーツスカート(長め)" },
			//基礎火力を少しだけ上げる//綾乃のみ
			{ 4, 0, "短パン" },
			//低速でないとき、上下の移動が速くなるが、発射されたショットの威力がだんだん下がる
			{ 5, 0, "赤いスカート" },
			//キャンプを設置することはできないが、ボムを使うとアイテムバルーンが登場する
			{ 6, 0, "バグったプリーツスカート" },
		};
		SELECT_TYPE m_Select_type;
		std::shared_ptr<CharaImgManager>m_Img;
		int m_Select_num[5][2];
		int m_Chara_type;
		int m_Count;
	public:
		DressRoom();
		~DressRoom();
		int update()override;
		void draw()override;
		int getCharaType();
	private:
		void initialize();
		void outerText();
		void underText();
		void selectText();
		void select()override;
		void cancel()override;
		void unlock();
		void checkAndReset();
	};
}