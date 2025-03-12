#include "Button.h"
#include "Num.h"
class OperButton : public Button {
	public:
		OperButton(std::wstring str, int* pos, HWND hwnd)
			:Button( str,  pos,  hwnd) {
		}
	float onClick(int id) override {
		std::wstring val = Button::btns[id];
		Num::oper = val;
		return 0;
	}
};