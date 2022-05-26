#include"SoundData.h"
#include "../../Source/library/Sound/SoundDX.h"
namespace res {
	SoundData SoundData::sound;
	void SoundData::load() {
		sound.se[SE::BULLET01] = lib::SoundDX::load("./dat/SE/bullet00.wav");
		sound.se[SE::BULLET02] = lib::SoundDX::load("./dat/SE/bullet01.wav");
		sound.se[SE::LAZER01] = lib::SoundDX::load("./dat/SE/Laz00.wav");
		sound.se[SE::LAZER02] = lib::SoundDX::load("./dat/SE/Laz00.wav");//ÉåÅ[ÉUÅ[î≠éÀâπ
		sound.se[SE::KIRAN] = lib::SoundDX::load("./dat/SE/Kiran.wav");
		sound.se[SE::EXPLODE] = lib::SoundDX::load("./dat/SE/Explode.wav");
		sound.se[SE::CHARGE] = lib::SoundDX::load("./dat/SE/Charge.wav");
		sound.se[SE::BOOOOM] = lib::SoundDX::load("./dat/SE/Goooon.wav");
		sound.se[SE::BREAK] = lib::SoundDX::load("./dat/SE/Break.wav");
		sound.se[SE::BOSSBREAK] = lib::SoundDX::load("./dat/SE/ClearBonus.wav");
		sound.se[SE::GET_BONUS] = lib::SoundDX::load("./dat/SE/GetBonus.wav");
		sound.se[SE::GYUUUUUUN] = lib::SoundDX::load("./dat/SE/Gyun.wav");
		sound.se[SE::PLAYER_SHOT] = lib::SoundDX::load("./dat/SE/Shot.wav");
		sound.se[SE::GRAZE] = lib::SoundDX::load("./dat/SE/Graze.wav");
		sound.se[SE::GOT_ITEM] = lib::SoundDX::load("./dat/SE/GetItem.wav");
		sound.se[SE::BOMGET] = lib::SoundDX::load("./dat/SE/BomUp.wav");
		sound.se[SE::LIFEGET] = lib::SoundDX::load("./dat/SE/LifeUp.wav");
		sound.se[SE::SELECT] = lib::SoundDX::load("./dat/SE/Select.wav");
		sound.se[SE::SELECT_CANCEL] = lib::SoundDX::load("./dat/SE/Cancel.wav");
		sound.se[SE::SELECT_OK] = lib::SoundDX::load("./dat/SE/ok.wav");
		sound.bgm[0] = lib::SoundDX::load("./dat/bgm/0.ogg");
		sound.bgm[1] = lib::SoundDX::load("./dat/bgm/1.ogg");
		sound.bgm[2] = lib::SoundDX::load("./dat/bgm/2.ogg");
		sound.bgm[3] = lib::SoundDX::load("./dat/bgm/3.ogg");
		sound.bgm[4] = lib::SoundDX::load("./dat/bgm/4.ogg");
		sound.bgm[5] = lib::SoundDX::load("./dat/bgm/5.ogg");
		sound.bgm[6] = lib::SoundDX::load("./dat/bgm/6.ogg");
		sound.bgm[7] = lib::SoundDX::load("./dat/bgm/7.ogg");
		sound.bgm[8] = lib::SoundDX::load("./dat/bgm/8.ogg");
		sound.bgm[9] = lib::SoundDX::load("./dat/bgm/9.ogg");
		sound.bgm[10] = lib::SoundDX::load("./dat/bgm/10.ogg");
		sound.bgm[11] = lib::SoundDX::load("./dat/bgm/11.ogg");
		sound.bgm[12] = lib::SoundDX::load("./dat/bgm/12.ogg");
		sound.bgm[13] = lib::SoundDX::load("./dat/bgm/13.ogg");
		sound.bgm[14] = lib::SoundDX::load("./dat/bgm/14.ogg");
		sound.bgm[15] = lib::SoundDX::load("./dat/bgm/15.ogg");
		sound.bgm[16] = lib::SoundDX::load("./dat/bgm/16.ogg");
	}
}