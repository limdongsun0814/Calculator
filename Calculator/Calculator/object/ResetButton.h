#include "Button.h"
#include "Num.h"
class ResetButton : public Button {
public:
	ResetButton(char chr, int x1, int y1, int x2, int y2, HWND hwnd)
		:Button(chr, x1, y1, x2, y2,  hwnd) {
	}
	float onClick(int id) override {
		Num::oper=' ';
		Num::num[0] = 0;
		Num::num[1] = 0;
		return 0;
	}
};