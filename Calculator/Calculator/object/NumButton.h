#include "Button.h"
#include "Num.h"
class NumButton : public Button{
	public:
		NumButton(std::wstring str, int* pos, HWND hwnd)
			:Button(str,  pos,  hwnd) {

		}
	float onClick(int id) override {
		int val = std::stoi(Button::btns[id]);
		if (Num::oper ==L"") {
			Num::num[0] = Num::num[0] * 10 + val;
		}
		else {
			Num::num[1] = Num::num[1] * 10 + val;
		}
		return 0;
	}
};