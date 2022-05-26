#include "ScriptLoader.h"
#include <iostream>
#include "../../library/FileManager/FileManager.h"
namespace script {
	//ScriptLoader ScriptLoader::loader;
	ScriptLoader::ScriptLoader():
		m_Load_flag(false),
		m_Buffer(nullptr),
		m_Data(nullptr),
		m_Read_size(0)
	{
		m_Count = 0;
	}
	void ScriptLoader::openFile(char* file) {
		m_Buffer = nullptr;
		m_Buffer = new void* [0];
		m_Data = new char[0];
		auto size = lib::FileManager::readArchiveSize(file);
		auto handle = lib::FileManager::openArchive(file);
		if (size == -1)return;
		m_Buffer = new void* [size * size];
		m_Read_size = lib::FileManager::readArchive(m_Buffer, size * size, handle);
		m_Data = (char*)m_Buffer;
		lib::FileManager::closeArchive(handle);
	}
	void ScriptLoader::readFile(const char* file) {
		auto size = lib::FileManager::readArchiveSize(file);
		if (size == -1)return;
		m_Buffer = nullptr;
		m_Buffer = new void* [size * size*10];
		auto handle = lib::FileManager::openArchive(file);
		m_Read_size = lib::FileManager::readArchive(m_Buffer, size * size * 10, handle);
		m_Read_size = m_Read_size - size;
		lib::FileManager::closeArchive(handle);
		m_Data = (char*)m_Buffer;
	}
	void ScriptLoader::bufferDelete() {
		delete[] m_Buffer;
		m_Load_flag = true;
	}
	char* ScriptLoader::getSource() {
		return m_Data;
	}
	ScriptLoader::~ScriptLoader() {
		if(!m_Load_flag)delete[] m_Buffer;
	}
}