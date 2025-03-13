#include "Button.h"
#include "Num.h"
class NumButton : public Button{
	public:
		NumButton(char chr, int x1, int y1, int x2, int y2, HWND hwnd)
			:Button(chr,  x1,y1,x2,y2,  hwnd) {

		}
	float onClick(int id) override {
		long val = static_cast<long>(Button::btns[id]) - static_cast<long>('0');
		if (Num::oper ==' ') {
			Num::num[0] = Num::num[0] * 10 + val;
		}
		else {
			Num::num[1] = Num::num[1] * 10 + val;
		}
		return 0;
	}
};