#include"PlayerImage.h"
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
namespace res {
	PlayerImage PlayerImage::Player;
	void PlayerImage::load() {
		Player.hitbox = lib::Graphics2D::load("./dat/image/Player/hitbox.png");
		lib::Graphics2D::loadSplit("./dat/image/Player/00.png", 12, 4, 3, 210, 210, Player.type[PLAYER_TYPE::EREMIRA]);
		lib::Graphics2D::loadSplit("./dat/image/Player/01.png", 12, 4, 3, 160, 160, Player.type[PLAYER_TYPE::MAI]);
		lib::Graphics2D::loadSplit("./dat/image/Player/02.png", 12, 4, 3, 160, 160, Player.type[PLAYER_TYPE::MEGU]);
		lib::Graphics2D::loadSplit("./dat/image/Player/03.png", 12, 4, 3, 160, 160, Player.type[PLAYER_TYPE::SARA]);
		lib::Graphics2D::loadSplit("./dat/image/Player/04.png", 12, 4, 3, 160, 160, Player.type[PLAYER_TYPE::KANA]);
		//lib::Graphics2D::loadSplit("./dat/image/Player/05.png", 6, 2, 3, 160, 160, Player.type[PLAYER_TYPE::UZUKI]);
		//lib::Graphics2D::loadSplit("./dat/image/Player/06.png", 6, 2, 3, 160, 160, Player.type[PLAYER_TYPE::MANIWA]);
		//lib::Graphics2D::loadSplit("./dat/image/Player/07.png", 6, 2, 3, 160, 160, Player.type[PLAYER_TYPE::URANA]);
	}
}