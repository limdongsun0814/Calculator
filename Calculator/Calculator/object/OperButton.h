#include "Button.h"
#include "Num.h"
class OperButton : public Button {
	public:
		OperButton(char chr, int x1, int y1, int x2, int y2, HWND hwnd)
			:Button(chr, x1, y1, x2, y2,  hwnd) {
		}
	float onClick(int id) override {
		char val = Button::btns[id];
		Num::oper = val;
		return 0;
	}
};