#include "KeyCapture.h"

namespace app {
	KeyCapture::KeyCapture() :
		m_Count(0)
	{

	}
	void KeyCapture::checkInput(int frame, bool is_inputed_key) {
		int lsat_count = m_Count - 1;
		if (frame > 1) {
			if (m_Count == 0) {
				int a = 0;
			}
		}
		if (m_Count == 0) {
			CaptureData data = { frame, is_inputed_key };
			m_CapData.emplace_back(data);
			m_Count = 1;
		}
		else {
			if (m_CapData.size() == 0)return;
			if (m_CapData[lsat_count].trigger != is_inputed_key) {
				CaptureData data = { frame, is_inputed_key };
				m_CapData.emplace_back(data);
				m_Count++;
			}
		}
	}
	void KeyCapture::resizeData() {
		if (m_CapData.size() <= m_Count) {
			m_CapData.resize(m_CapData.size() + 1);
		}
	}
	void KeyCapture::setData(std::vector<KeyCapture::CaptureData> data) {
		m_CapData = data;
	}
	void KeyCapture::setDataSize(int size) {
		m_CapData.resize(size);
	}
	void KeyCapture::setCount(int count) {
		m_Count = count;
	}
	bool KeyCapture::isInputed(int frame) {
		if (m_CapData.size() == m_Count)return false;
		if (m_CapData[m_Count].frame == frame)m_Count++;
		int count = m_Count - 1;
		if (count >= 0)return m_CapData[count].trigger;
		return false;
	}
	std::vector<KeyCapture::CaptureData> KeyCapture::getData() {
		return m_CapData;
	}
}