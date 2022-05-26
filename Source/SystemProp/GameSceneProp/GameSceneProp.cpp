#include "GameSceneProp.h"

int GameSceneProp::stage = 0;//現在のステージ
int GameSceneProp::difficulty=0;//ゲームの難易度(0～2)
int GameSceneProp::outer_wear=0;
int GameSceneProp::under_wear=0;
bool GameSceneProp::is_practice = false;//練習モードかどうか
bool GameSceneProp::is_alice = false;//アリスモードかどうか
bool GameSceneProp::is_extra = false;//エクストラモードかどうか
bool GameSceneProp::is_use_camp = false;//キャンプを使うかどうか
bool GameSceneProp::is_replay = false;
void GameSceneProp::initialize() {
	stage = 0;
	difficulty = 0;
	outer_wear = 0;
	under_wear = 0;
	is_practice = false;
	is_alice = false;
	is_extra = false;
	is_use_camp = false;
	is_replay = false;
}