#include "Button.h"
#include "Num.h"
#include "limits"
class NumButton : public Button{
	public:
		NumButton(char chr, int x1, int y1, int x2, int y2, HWND hwnd)
			:Button(chr,  x1,y1,x2,y2,  hwnd) {

		}
	float onClick(int id) override {
		long val = static_cast<long>(Button::btns[id]) - static_cast<long>('0');

		if (Num::oper ==' ') {
			if ((LONG_MAX - val) / 10L < Num::num[0]) {
				Num::oper = 'e';
				return 0;
			}
			Num::num[0] = Num::num[0] * 10L + val;
		}
		else {
			if ((LONG_MAX - val) / 10L < Num::num[1]) {
				Num::oper = 'e';
				return 0;
			}
			Num::num[1] = Num::num[1] * 10L + val;
		}
		return 0;
	}
};