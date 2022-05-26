#pragma once
namespace text {
	class ClothText {
	private:
	public:
		static void drawText(int chara_type, int outer_type,int under_type);
	private:
		static void unlockOuterText(int type);
		static void unlockUnderText(int type);
		static void outerWearText(int chara_type, int wear_type);
		static void underWearText(int type);
		static void outerWearText(
			const char* msg0,
			const char* msg1,
			const char* msg2,
			const char* msg3,
			const char* msg4
		);
		static void underWearText(
			const char* msg0,
			const char* msg1,
			const char* msg2,
			const char* msg3,
			const char* msg4
		);
	};
}