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
		//�t�F�[�h�C������t���[��
		void setParam(int count);
		void update();
		bool isFlag();
		int getCount();

		//�ő�l(num)�ɂȂ�܂ł̃T�C�Y���擾
		float getSize(float num);
	};
}