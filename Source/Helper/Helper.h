#pragma once
namespace helper {

#define FACT(r) r*r//２乗を計算する
#define BEDWEEN(value,num1,num2) helper_class::Helper::condition(value,num1,num2)
#define START_SCENE_COOLDOWN(time) helper_class::Helper::coolCounter(time)//シーンを切り替えた際にクールダウンを入れる
#define END_SCENE() helper_class::Helper::setTime(0)//シーンを切り替える前に必ず呼び出す
#define SET_SEED(num) helper_class::Helper::setSeed(num)
#define SET_RANDOM_SEED(num) helper_class::Helper::setRandomSeed(num)
#define GET_RANDOM(num) helper_class::Helper::getRand(num)
#define GET_SEED_RANDOM(num) helper_class::Helper::getSRand(num)
#define GET_RANDOM_F(num) (-num + num * 2 * GET_RANDOM(10000) / 10000.0)
#define GET_SEED_RANDOM_F(num) (-num + num * 2 * GET_SEED_RANDOM(10000) / 10000.0)
#define SEED_100 {int seed_100_rand = GET_RANDOM(100); SET_SEED(seed_100_rand);return seed_100_rand;}
}
#include <iostream>
#include <random>
namespace helper_class {
	class Helper {
	private:
		static int m_Time;
		static std::mt19937 m_Mt19937;
	public:

		static bool condition(int value, int num1, int num2);

		static bool coolCounter(int cooltime);

		static void setTime(int time);

		////シード値テスト
		//int seed = SET_RANDOM_SEED(100);
		//int val1[10];
		//int val2[10];
		//for (int i = 0; i < 10; i++) {
		//	val1[i] = GET_SEED_RANDOM(10);
		//}
		//SET_SEED(seed);
		//for (int i = 0; i < 10; i++) {
		//	val2[i] = GET_SEED_RANDOM(10);
		//}

		static void setSeed(int seed);//乱数のシード値を指定

		static int setRandomSeed(int max);

		static int getRand(int max);//乱数の取得

		static int getSRand(int max);//シード値を指定した乱数の取得

	};
}