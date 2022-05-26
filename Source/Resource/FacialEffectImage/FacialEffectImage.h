#pragma once
namespace res {
	//立ち絵に付ける表情エフェクト
	enum FACIAL_EFFECT_TYPE {
		ACCENT, HAPPY, SWEAT, BLACK, ANGRY, STOP
	};
	class FacialEffectImage{
	private:
	public:
		int accent[2];//気が付いた時の反応
		int happy[2];//ウキウキしてるとき
		int sweat;
		int black;//暗い表情の時
		int angry;//怒りマーク
		static void load();
		static FacialEffectImage facial_eff;
	};
}