#pragma once
namespace obj {
	class Player;
	class Boss;
}
namespace app {
	//�ΐ탂�[�h�p�̃X�R�A�{�[�h
	class DuelScore {
	public:
		//�f���G���X�N���[������UI
		static void drawRoodModeUI(obj::Player player1, obj::Player player2);
		//���ڑΌ�����UI
		static void drawBomModeUI(obj::Player player1, obj::Player player2);
		//�X�R�A�{�[�h�ɂ��v���C���[�̈ʒu���{�X��d�l�ɂ���B
		static void changeBossMode(obj::Player& player1, obj::Player& player2, int& bom_type, int& rayer);
		//�X�R�A�{�[�h�ɂ��v���C���[�̈ʒu��ʏ�d�l�ɂ���B
		static void changeNormalMode(obj::Player& player1, obj::Player& player2, obj::Boss& boss);
	};
}