#include "TimeFader.h"

TimeFader::TimeFader():
m_Is_Flag(false),
m_Size(0.f),
m_Size_max(0.f),
m_Count(0),
m_Time(0)
{

}
void TimeFader::start(int time, float max) {
	m_Is_Flag = true;
	m_Time = time;
	m_Size_max = max;
}
void TimeFader::update() {
	if (m_Is_Flag) {
		m_Count++;
		m_Size = (m_Size_max / m_Time) * (m_Count);
		if (m_Time < m_Count)stop();
	}
}
void TimeFader::stop() {
	m_Is_Flag = false;
	m_Time = 0;
	m_Count = 0;
	m_Size = 0.f;
	m_Size_max = 0.f;
}
bool TimeFader::isFlag() {
	return m_Is_Flag;
}
float TimeFader::getSize() {
	if (m_Is_Flag)return m_Size;
	return m_Size_max;
}