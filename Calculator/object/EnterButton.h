#include "Button.h"
#include "Num.h"
class EnterButton : public Button {
public:
	EnterButton(char chr, int x1, int y1, int x2, int y2, HWND hwnd)
		:Button(chr, x1, y1, x2, y2,  hwnd) {
	}
	float onClick(int id) override {
		char oper = Num::oper;
		Num::oper = 'E';
		long* num = Num::num;

		switch (oper)
		{
		case '+':
			return static_cast<float>(num[0] + num[1]);
		case '-':
			return static_cast<float>(num[0] - num[1]);
		case '*':
			return static_cast<float>(num[0] * num[1]);
		case '/':
			return num[0] / static_cast<float>(num[1]);
		default:
			return static_cast<float>(num[0]);
		}
	}
};