#pragma once
namespace res {
	const int CHARA_PL = 5;
	const int CHARA_BS = 8;
	const int CHARA_MAX = CHARA_PL + CHARA_BS;
	class CharacterImage{
	private:
		static bool m_loaded[CHARA_BS];
	public:
		enum POSE_TYPE {
			STAND, DAMAGE, SPECIAL, POSE_MAX
		};
		enum EYE_TYPE {
			EYE_OPEN, EYE_CLOSE, EYE_SMILE, EYE_ORIGINAL, EYE_MAX
		};
		enum MOUTH_TYPE {
			MOUTH_CLOSE, MOUTH_OPEN, MOUTH_ORIGINAL, MOUTH_MAX
		};
		enum BROW_TYPE {
			BROW_NORMAL, BROW_SAD, BROW_ANGLY, BROW_ORIGINAL, BROW_MAX
		};
		static int no_image;
		int body[POSE_MAX];
		int eye[EYE_MAX];
		int mouth[MOUTH_MAX];
		int eyebrow[BROW_MAX];
		int outer_wear[7];
		int under_wear[7];
		int socks_wear[6];
		static void load();
		static void loadBoss(int stage);
		static CharacterImage TalkChara[CHARA_PL + CHARA_BS];
	private:
		static void loadBossType(bool damaged, bool pose, int brow_num, int eye_num, int mouth_num, int type);
	};
}