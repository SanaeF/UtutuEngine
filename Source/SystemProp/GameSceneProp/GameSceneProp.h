#pragma once
class GameSceneProp {
public:
	static int stage;//���݂̃X�e�[�W
	static int difficulty;//�Q�[���̓�Փx(0�`2)
	static int outer_wear;
	static int under_wear;
	static bool is_practice;//���K���[�h���ǂ���
	static bool is_alice;//�A���X���[�h���ǂ���
	static bool is_extra;//�G�N�X�g�����[�h���ǂ���
	static bool is_use_camp;//�L�����v���g�����ǂ���
	static bool is_replay;//���v���C�����ǂ���
	static void initialize();
};