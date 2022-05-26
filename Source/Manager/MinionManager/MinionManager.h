#pragma once
#include <vector>
namespace obj {
	class Minion;
}
namespace manager {
	class MinionManager {
	private:
		static MinionManager m_Instance;
		std::vector<obj::Minion>m_Minion_obj;
		MinionManager();
	public:
		static MinionManager* getInstance();
		void initialize();
		void update();
		void draw(double crush_x, double crush_y);
		//�G���G��S�̍폜(�����̓G�t�F�N�g�����邩�ǂ���)
		void clear(bool flag);

		std::vector<obj::Minion>& getMinion();
	};
}