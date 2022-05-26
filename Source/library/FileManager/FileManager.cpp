#include "FileManager.h"
#include "DxLib.h"
namespace lib {
	int FileManager::openArchive(const TCHAR* file_path) {
		return FileRead_open(file_path);
	}
	int FileManager::readString(int handle, char* result) {
		return FileRead_scanf(handle, "%s", &result);
	}
	LONGLONG FileManager::readArchiveSize(const TCHAR* file_path) {
		return FileRead_size(file_path);
	}
	int FileManager::readArchive(void* buffer, int read_size, int handle) {
		return FileRead_read(buffer, read_size, handle);
	}
	void FileManager::closeArchive(int handle) {
		FileRead_close(handle);
	}
}