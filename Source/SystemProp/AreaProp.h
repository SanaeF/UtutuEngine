#pragma once
//�Q�[���g���̃I�u�W�F�N�g�̐����Ə����ʒu
class AreaProp {
private:
	struct ResizeAreaProp {
		int min_x;//�t���[�������̍ŏ����W
		int max_x;//�t���[�������̍ő���W
		int min_y;//�t���[�������̍ŏ����W
		int max_y;//�t���[�������̍ő���W
	};
public:
	static const int frame_width = 1200;//����
	static const int frame_hight = 1400;//����

	static const int min_x = (2560 / 2) - (frame_width / 2);//�t���[�������̍ŏ����W
	static const int max_x = (2560 / 2) + (frame_width / 2);//�t���[�������̍ő���W
	static const int min_y = (1440 / 2) - (frame_hight / 2);//�t���[�������̍ŏ����W
	static const int max_y = (1440 / 2) + (frame_hight / 2);//�t���[�������̍ő���W

	static const int def_player_x = (max_x - min_x) / 2;
	static const int def_player_y = max_y * 3 / 4;

	static const int deff_boss_x = (max_x - min_x) / 2;
	static const int deff_boss_y = 450;

	static const int p1_min_x = 30;
	static const int p1_max_x = 946;
	static const int p2_min_x = 974;
	static const int p2_max_x = 1890;

	static ResizeAreaProp resizeFrame(float size_w, float size_h) {
		ResizeAreaProp result;
		result.min_x = (2560 / 2) - (size_w / 2);//�t���[�������̍ŏ����W
		result.max_x = (2560 / 2) + (size_w / 2);//�t���[�������̍ő���W
		result.min_y = (1440 / 2) - (size_h / 2);//�t���[�������̍ŏ����W
		result.max_y = (1440 / 2) + (size_h / 2);//�t���[�������̍ő���W
		return result;
	}
};