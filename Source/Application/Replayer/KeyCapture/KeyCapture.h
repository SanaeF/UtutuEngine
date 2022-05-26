#pragma once
#include <vector>
namespace app {
	//�L�[���͈���̋L�^�ƍĐ�
	class KeyCapture {
	public:
		struct CaptureData {
			int frame;
			bool trigger;
		};
	private:
		std::vector<CaptureData> m_CapData;
		int m_Count;
	public:
		KeyCapture();

		//�L�[���ǂ̃t���[���œ��͂��ꂽ���𔻒肷��X�V
		void checkInput(int frame, bool is_inputed_key);

		//�L�[���͂̃x�N�^�[�z��J�E���^�[�ɒl����
		void setCount(int count);

		//�t�@�C������ǂݍ��񂾂�Đ����邽�߂̃Z�b�^�[
		void setData(std::vector<CaptureData> data);

		void setDataSize(int size);

		//���v���C������Ƃ��ɃL�[��������Ă��邩���擾����B
		bool isInputed(int frame);

		//�����o�����߂̃Q�b�^�[
		std::vector<CaptureData> getData();
	private:
		void resizeData();
	};
}