#pragma once

//�w�肵�����Ԃ̊ԁA
//��������̃t�F�[�h�C���E�A�E�g���s���N���X
class TimeFader {
private:
	bool m_Is_Flag;
	float m_Size;
	float m_Size_max;
	int m_Count;
	int m_Time;
public:
	TimeFader();
	void start(int time, float max);
	void update();
	void stop();
	bool isFlag();
	float getSize();
};