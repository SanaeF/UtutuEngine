#pragma once
namespace lib {
	class FileManager {
	private:
		typedef char TCHAR;
		typedef __int64 LONGLONG;
	public:
		static int openArchive(const TCHAR* file_path);

		static int readString(int handle, char* result);
		static LONGLONG readArchiveSize(const TCHAR* file_path);
		static int readArchive(void* buffer, int read_size, int handle) ;
		static void closeArchive(int handle);
		static void reloadImageFile();
		//int openRead(char* FilePath);
		//int close(int FileHandle);

		//LONGLONG pGetFile(int FileHandle);

		//void setFileArchive(char* name);
	};
}