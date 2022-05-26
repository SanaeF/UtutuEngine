#pragma once
#include <string>
enum KeyboardResult {
	INPUT_NONE,
	INPUT_END,
	INPUT_CHANCEL
};
class TextInputer {
private:
	bool m_Is_flag;
	int m_Input_result;
	char m_Text[21];
	std::string m_Inputed_text;
public:
	TextInputer();
	void initialize();
	void update();
	void draw(std::string title);
	bool isFlag();
	int getInputResult();
	char* getCharText();
	std::string getText();
private:
};