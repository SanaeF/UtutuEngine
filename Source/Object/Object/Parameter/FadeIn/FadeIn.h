#pragma once
namespace obj {
	class FadeIn {
	private:
		bool flag;
		int count;
		int count_max;
		float size;
	public:
		FadeIn();
		void initialize();
		//フェードインするフレーム
		void setParam(int count);
		void update();
		bool isFlag();
		int getCount();

		//最大値(num)になるまでのサイズを取得
		float getSize(float num);
	};
}