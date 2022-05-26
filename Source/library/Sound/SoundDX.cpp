#include "SoundDX.h"
#include "DxLib.h"

namespace lib {
	int SoundDX::check(
		int Handle
	) {
		return CheckSoundMem(Handle);
	}

	void SoundDX::play(
		int Handle,
		int PlayType,
		int Flag
	) {
		if (PlayType == SOUND_TYPE::NORMAL)PlaySoundMem(Handle, DX_PLAYTYPE_NORMAL, Flag);
		if (PlayType == SOUND_TYPE::BACK)PlaySoundMem(Handle, DX_PLAYTYPE_BACK, Flag);
		if (PlayType == SOUND_TYPE::LOOP)PlaySoundMem(Handle, DX_PLAYTYPE_LOOP, Flag);
	}
	void SoundDX::stop(
		int Handle
	) {
		StopSoundMem(Handle);
	}

	void SoundDX::changeVolume(
		int Volume,
		int Handle
	) {
		ChangeVolumeSoundMem(Volume, Handle);
	}

	void SoundDX::setLoopPos(
		int LoopTime,
		int Handle
	) {
		SetLoopPosSoundMem(LoopTime, Handle);
	}
	void SoundDX::setSoundPosition(int hz_count, int Handle) {
		SetCurrentPositionSoundMem(hz_count, Handle);
	}
	void SoundDX::drawCount(int Handle) {
		int time = GetStreamSoundCurrentPosition(Handle);
		DrawFormatString(500, 500, GetColor(255,255,255), "%d", time);
	}

	int SoundDX::load(
		const TCHAR* FileAdress
	) {
		return LoadSoundMem(FileAdress);
	}
	int SoundDX::getSoundPosition(int Handle) {
		return GetCurrentPositionSoundMem(Handle);
	}
	void SoundDX::clear(
		int Handle
	) {
		DeleteSoundMem(Handle);
	}

	void SoundDX::initialize() {
		InitSoundMem();
	}
}