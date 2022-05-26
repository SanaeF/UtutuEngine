#pragma once
#include <vector>
namespace script {
	//�A�[�J�C�u�̃X�N���v�g�����[�h����N���X
	class ScriptLoader {
	private:
		void* m_Buffer = nullptr;
		char* m_Data = nullptr;
		int m_Read_size;
		int m_Count;
		bool m_Load_flag;
	public:
		ScriptLoader();
		~ScriptLoader();
		void openFile(char* file);
		void readFile(const char* file);
		char* getSource();
		void bufferDelete();
		//static ScriptLoader loader;
	};
}