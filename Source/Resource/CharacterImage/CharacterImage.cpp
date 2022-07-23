#include "CharacterImage.h"
#include <iostream>
#include "../../Source/library/Graphics/Graphics2D/Graphics2D.h"
#pragma warning(disable : 4996)
namespace res {
	CharacterImage CharacterImage::TalkChara[CHARA_MAX];
	bool CharacterImage::m_loaded[CHARA_BS];
	int CharacterImage::no_image;
	void CharacterImage::load() {
		no_image= lib::Graphics2D::load("./dat/image/CharaModel/NoImage.png");
		char m_File[128];
		for (int num_c = 0; num_c < CHARA_PL; num_c++) {
			sprintf(m_File, "./dat/image/CharaModel/%d/body.png", num_c);
			TalkChara[num_c].body[0] = lib::Graphics2D::load(m_File);
			//顔パーツのロード
			for (int num_type = 0; num_type < CharacterImage::EYE_TYPE::EYE_MAX; num_type++) {
				sprintf(m_File, "./dat/image/CharaModel/%d/face/eye/%d.png", num_c, num_type);
				TalkChara[num_c].eye[num_type] = lib::Graphics2D::load(m_File);
			}
			for (int num_type = 0; num_type < CharacterImage::MOUTH_TYPE::MOUTH_MAX; num_type++) {
				sprintf(m_File, "./dat/image/CharaModel/%d/face/mouth/%d.png", num_c, num_type);
				TalkChara[num_c].mouth[num_type] = lib::Graphics2D::load(m_File);
			}
			for (int num_type = 0; num_type < CharacterImage::BROW_TYPE::BROW_MAX; num_type++) {
				sprintf(m_File, "./dat/image/CharaModel/%d/face/eyebrow/%d.png", num_c, num_type);
				TalkChara[num_c].eyebrow[num_type] = lib::Graphics2D::load(m_File);
			}
			////衣装のロード
			//sprintf(m_File, "./dat/image/CharaModel/%d/上着/null.png", num_c);
			//TalkChara[num_c].outer_wear[6] = lib::Graphics2D::load(m_File);
			//sprintf(m_File, "./dat/image/CharaModel/%d/腰辺り/null.png", num_c);
			//TalkChara[num_c].under_wear[6] = lib::Graphics2D::load(m_File);
			//for (int num_type = 0; num_type < 6; num_type++) {
			//	sprintf(m_File, "./dat/image/CharaModel/%d/腰辺り/%d.png", num_c, num_type);
			//	TalkChara[num_c].under_wear[num_type] = lib::Graphics2D::load(m_File);
			//	//実装しない衣装はパス
			//	if ((num_c == 1 && (num_type == 2 || num_type == 4 || num_type == 5)) ||
			//		(num_c == 2 && (num_type == 1 || num_type == 2 || num_type == 5)) ||
			//		(num_c == 3 && (num_type == 1 || num_type == 4 || num_type == 5)) ||
			//		(num_c == 4 && (num_type == 1 || num_type == 2 || num_type == 4))
			//		) {
			//		TalkChara[num_c].outer_wear[num_type] = TalkChara[num_c].outer_wear[6];
			//		continue;
			//	}
			//	sprintf(m_File, "./dat/image/CharaModel/%d/上着/%d.png", num_c, num_type);
			//	TalkChara[num_c].outer_wear[num_type] = lib::Graphics2D::load(m_File);
			//	sprintf(m_File, "./dat/image/CharaModel/%d/靴下/%d.png", num_c, num_type);
			//	TalkChara[num_c].socks_wear[num_type] = lib::Graphics2D::load(m_File);
			//}
		}
		for (int num_c = 0; num_c < CHARA_BS; num_c++) {
			m_loaded[num_c] = false;
		}
	}
	void CharacterImage::loadBoss(int stage) {
		if (stage == 0) {
			loadBossType(false, false, 3, 3, 3, 0);//マツミ
		}
		if (stage == 1) {
			loadBossType(true, true, 3, 3, 3, 1);//エレミラ
		}
		if (stage == 2) {
			loadBossType(true, false, 3, 3, 3, 2);//アリス・ショット
		}
		if (stage == 3) {
			loadBossType(false, false, 3, 3, 3, 3);//ナルシル
			loadBossType(true, true, 3, 4, 3, 4);//フェアトリア
		}
		if (stage == 4) {
			loadBossType(false, false, 3, 3, 3, 0);//マツミ
			loadBossType(true, true, 3, 4, 3, 4);//フェアトリア
		}
		if (stage == 5) {
			loadBossType(true, false, 3, 4, 3, 5);//シエナ
		}
		if (stage == 6) {
			loadBossType(false, true, 0, 0, 0, 6);//アリス・ショット(裏ボス)
		}
		if (stage == 7) {
			loadBossType(false, false, 3, 3, 3, 3);//ナルシル
			loadBossType(true, true, 3, 2, 3, 7);//クロ
		}
	}
	void CharacterImage::loadBossType(bool damaged, bool pose, int brow_num, int eye_num, int mouth_num, int type) {
		if (type >= CHARA_BS)return;
		if (m_loaded[type])return;
		char m_File[50];
		sprintf(m_File, "./dat/image/CharaModel/b%d/body.png", type);
		TalkChara[CHARA_PL + type].body[0] = lib::Graphics2D::load(m_File);
		if (damaged) {
			sprintf(m_File, "./dat/image/CharaModel/b%d/damage.png", type);
			TalkChara[CHARA_PL + type].body[POSE_TYPE::DAMAGE] = lib::Graphics2D::load(m_File);
		}
		if (pose) {
			sprintf(m_File, "./dat/image/CharaModel/b%d/pose.png", type);
			TalkChara[CHARA_PL + type].body[POSE_TYPE::SPECIAL] = lib::Graphics2D::load(m_File);
		}
		//顔パーツのロード
		for (int num_type = 0; num_type < eye_num; num_type++) {
			sprintf(m_File, "./dat/image/CharaModel/b%d/face/eye/%d.png", type, num_type);
			TalkChara[CHARA_PL + type].eye[num_type] = lib::Graphics2D::load(m_File);
		}
		for (int num_type = 0; num_type < mouth_num; num_type++) {
			sprintf(m_File, "./dat/image/CharaModel/b%d/face/mouth/%d.png", type, num_type);
			TalkChara[CHARA_PL + type].mouth[num_type] = lib::Graphics2D::load(m_File);
		}
		for (int num_type = 0; num_type < brow_num; num_type++) {
			sprintf(m_File, "./dat/image/CharaModel/b%d/face/eyebrow/%d.png", type, num_type);
			TalkChara[CHARA_PL + type].eyebrow[num_type] = lib::Graphics2D::load(m_File);
		}
		m_loaded[type] = true;
	}
}