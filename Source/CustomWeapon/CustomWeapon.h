#pragma once
#include <string>
namespace app {
	class CustomWeapon {
	private:
		static std::string name[100];
	public:
		static void creaateRookie();
		//�J�X�^��������폜
		static void dispose(int id);
		//�J�X�^������̐���
		static void create(int add_life, int add_bom, int add_strength);
		//���햼�̐���
		static void createName(int id);

		static std::string getName(int id);
	private:
		static int getParam(int add, int max);
	};
}