#include "Sound.h"

#include "../../Source/library/Sound/SoundDX.h"
#include "../../Source/Resource/SoundData/SoundData.h"

namespace app {
	Sound Sound::sound;
	void Sound::handleReset() {
		m_Playing_music = -1;
		initializeMemory();
		m_Is_input_pos = false;
		m_Is_input_pos = 0;
	}

	void Sound::freez() {
		lib::SoundDX::stop(res::SoundData::sound.bgm[m_Playing_music]);
		m_Stop = true;
	}

	void Sound::unFreez() {
		m_Stop = false;
		lib::SoundDX::play(res::SoundData::sound.bgm[m_Playing_music], lib::SOUND_TYPE::LOOP, false);
	}

	void Sound::initializeMemory() {
		for (int ite = 0; ite < 17; ite++)lib::SoundDX::stop(res::SoundData::sound.bgm[ite]);
		m_Playing_music = -1;
	}
	void Sound::drawDebugString() {
		//lib::SoundDX::drawCount(res::SoundData::sound.bgm[m_Playing_music]);
	}
	void Sound::setVolume(int bgm, int se) {
		m_Vol_bgm = bgm;
		m_Vol_se = se;
		lib::SoundDX::changeVolume(255 - m_Vol_bgm, res::SoundData::sound.bgm[m_Playing_music]);
		for (int num = 0; num < res::SE_MAX; num++) {
			lib::SoundDX::changeVolume(255 - m_Vol_se, res::SoundData::sound.se[num]);
		}
	}
	void Sound::playStageBGM(int stage_num) {
		if (stage_num == 0)playBGM(1);
		if (stage_num == 1)playBGM(3);
		if (stage_num == 2)playBGM(5);
		if (stage_num == 3)playBGM(7);
		if (stage_num == 4)playBGM(8);
		if (stage_num == 5)playBGM(10);
		if (stage_num == 6)playBGM(12);
		if (stage_num == 7)playBGM(13);
	}
	void Sound::setPosition(int count) {
		m_Is_input_pos = true;
		m_Play_pos = count;
	}
	int Sound::playSE(int number) {
		lib::SoundDX::play(res::SoundData::sound.se[number], lib::SOUND_TYPE::BACK);
		return 0;
	}

	int Sound::playBGM(int number) {
		if (m_Playing_music == number)return 0;
		lib::SoundDX::changeVolume(255 - m_Vol_bgm, res::SoundData::sound.bgm[number]);
		m_Stop = false;
		initializeMemory();
		if (res::SoundData::sound.bgm[number] != 0) {
			lib::SoundDX::setLoopPos(loop_time[number], res::SoundData::sound.bgm[number]);//ループ位置セット
			bool pos_flag = true;
			if (m_Is_input_pos) {
				lib::SoundDX::setSoundPosition(m_Play_pos, res::SoundData::sound.bgm[number]);//途中再生
				pos_flag = false;
				m_Is_input_pos = false;
			}
			lib::SoundDX::play(res::SoundData::sound.bgm[number], lib::SOUND_TYPE::LOOP, pos_flag);
			m_Playing_music = number;
		}
		return 0;
	}

	int Sound::getNowPlayBGM() {
		return m_Playing_music;
	}
	Sound::Sound() :
		m_Playing_music(-1) 
	{
	}
}