#pragma once
#include "../Scene.h"
#include <string>
namespace app {
	//<Yes/No>の選択肢クラス
	enum SELECT_LR {
		LEFT_STATE,
		RIGHT_STATE,
		NONE_STATE
	};
	class SelectYN : Scene {
	private:
		bool m_Is_flag;//選択肢の表示フラグ
		int m_State;//選択肢
		int m_Num;//キーによる選択番号
	public:
		SelectYN();
		//初期の選択位置を指定して選択肢を表示
		void initialize(SELECT_LR state);
		void selectReset();
		int update();

		//選択肢の表示(1:タイトル,2:タイトルの色,3:左の文字,4:右の文字)
		void draw(std::string text, int color, std::string left, std::string right);

		void select()override;
		void cancel()override;

		//選択肢を表示しているかどうかを取得
		bool isFlag();

		//選択肢の結果を取得
		int getState();
	};
}