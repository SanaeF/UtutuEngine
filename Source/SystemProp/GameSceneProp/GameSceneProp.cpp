#include "GameSceneProp.h"

int GameSceneProp::stage = 0;//���݂̃X�e�[�W
int GameSceneProp::difficulty=0;//�Q�[���̓�Փx(0�`2)
int GameSceneProp::outer_wear=0;
int GameSceneProp::under_wear=0;
bool GameSceneProp::is_practice = false;//���K���[�h���ǂ���
bool GameSceneProp::is_alice = false;//�A���X���[�h���ǂ���
bool GameSceneProp::is_extra = false;//�G�N�X�g�����[�h���ǂ���
bool GameSceneProp::is_use_camp = false;//�L�����v���g�����ǂ���
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