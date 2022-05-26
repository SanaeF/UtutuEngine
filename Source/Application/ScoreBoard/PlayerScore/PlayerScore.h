#pragma once
namespace obj {
	class Player;
}
namespace app {
	class PlayerScore {
	private:
		static float m_P_y[8];
	public:
		static void drawLevel(int diff);
		//�v���C���[�̃X�R�A��`��
		static void drawScore(obj::Player player, int ID_y1, int ID_y2);
		//�v���C���[�̎c�@�⌇�Ђ̐���`��
		static void drawLife(obj::Player player, int ID_y);
		//�v���C���[�̃{���⌇�Ђ̐���`��
		static void drawBom(obj::Player player, int ID_y);
		//�v���C���[�̃p���[�l��`��
		static void drawPower(obj::Player player, int ID_y);
		//�v���C���[�̃|�C���g����`��
		static void drawPoint(obj::Player player, int ID_y);
		//�v���C���[�̃O���C�Y����`��
		static void drawGraze(obj::Player player, int ID_y);
		//�v���C���[�̃I�v�V������`��
		static void drawOption(obj::Player player, int ID_y);
		//�v���C���[�̃����S����`��(�덏�̃��[�e�B�I�Ŏg�p)
		static void drawApple(obj::Player player);

		static void drawCamp(obj::Player player);
		//�v���C���[�̃N���b�V���Q�[�W��`��(At��i�Ŏg�p)
		static void drawCrush(obj::Player player);
	};
}