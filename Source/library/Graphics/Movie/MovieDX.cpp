#include "MovieDX.h"
#include "DxLib.h"

namespace lib {
	int MovieDx::load(const TCHAR* FileAdress) {
		return LoadGraph(FileAdress);
	}
	int MovieDx::setVolume(int volume, int handle) {
		return SetMovieVolumeToGraph(volume, handle);
	}
	int MovieDx::play(int handle) {
		return PlayMovieToGraph(handle);
	}
	void MovieDx::draw(
		int x,
		int y,

		int Handle,
		int TransFlag
	) {
		DrawGraph(x, y, Handle, TransFlag);
	}
	int MovieDx::getState(int handle) {
		return GetMovieStateToGraph(handle);
	}
	int MovieDx::clear(
		int GrHandle,
		int LogOutFlag
	) {
		return DeleteGraph(GrHandle);
	}
}