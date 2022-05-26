#pragma once
#include "FrameManager.h"
#include <iostream>

#include "../../Source/library/AppManager/AppManager.h"
#include "../../Source/library/Graphics/String/StringDX.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#include "../../Source/Resource/GUI/TextUIImage/TextUIImage.h"
namespace app {

	void FrameManager::update() {
		int term, i, gnt;
		static int t = 0;
		if (fps_count == 0) {//60フレームの1回目なら
			if (t == 0)//完全に最初ならまたない
				term = 0;
			else//前回記録した時間を元に計算
				term = count0t + 1000 - lib::AppManager::getNowCount();
		}
		else    //待つべき時間=現在あるべき時刻-現在の時刻
			term = (int)(count0t + fps_count * (1000.0 / mFrame)) - lib::AppManager::getNowCount();

		if (term > 0) {//待つべき時間だけ待つ

			lib::AppManager::sleep(term);
		}
		gnt = lib::AppManager::getNowCount();

		if (fps_count == 0)//60フレームに1度基準を作る
			count0t = gnt;
		mFrameData[fps_count] = gnt - t;//１周した時間を記録
		t = gnt;
		//平均計算
		if (fps_count == mFrame - 1) {
			ave = 0;
			for (i = 0; i < mFrame; i++)
				ave += mFrameData[i];
			ave /= mFrame;
		}
		fps_count = (++fps_count) % mFrame;
	}

	void FrameManager::draw(int x, int y) {
		if (ave != 0) {
			lib::StringDX::setFontSize(32);
			int FPS = 10000 / ave;
			
			for (int i = 0; i < 3; i++) {//ポイント表示
				if (i == 0)
					lib::Graphics2D::drawRota(
						x - i * 30,
						y + 5, 
						0.5f,
						0.0f, 
						res::TextUIImage::text_ui.number[0][FPS % 10],
						true
					);
				else 
					lib::Graphics2D::drawRota(
						x - i * 30, 
						y, 
						0.8f, 
						0.0f, 
						res::TextUIImage::text_ui.number[0][FPS % 10],
						true
					);
				FPS /= 10;
			}
		}
		return;
	}

	FrameManager::FrameManager(int FPS) :
		mFrame(FPS),
		fps_count(0),
		count0t(0),
		ave(0.f)
	{
		mFrameData = new int[FPS];
	}

}