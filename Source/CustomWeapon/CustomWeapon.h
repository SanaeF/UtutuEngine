#pragma once
#include <string>
namespace app {
	class CustomWeapon {
	private:
		static std::string name[100];
	public:
		static void creaateRookie();
		//カスタム武器を削除
		static void dispose(int id);
		//カスタム武器の生成
		static void create(int add_life, int add_bom, int add_strength);
		//武器名の生成
		static void createName(int id);

		static std::string getName(int id);
	private:
		static int getParam(int add, int max);
	};
}