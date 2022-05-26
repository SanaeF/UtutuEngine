#pragma once
#include <vector>
namespace app {
	//キー入力一個分の記録と再生
	class KeyCapture {
	public:
		struct CaptureData {
			int frame;
			bool trigger;
		};
	private:
		std::vector<CaptureData> m_CapData;
		int m_Count;
	public:
		KeyCapture();

		//キーがどのフレームで入力されたかを判定する更新
		void checkInput(int frame, bool is_inputed_key);

		//キー入力のベクター配列カウンターに値を代入
		void setCount(int count);

		//ファイルから読み込んだら再生するためのセッター
		void setData(std::vector<CaptureData> data);

		void setDataSize(int size);

		//リプレイをするときにキーが押されているかを取得する。
		bool isInputed(int frame);

		//書き出すためのゲッター
		std::vector<CaptureData> getData();
	private:
		void resizeData();
	};
}