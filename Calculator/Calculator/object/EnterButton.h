#include "Button.h"
#include "Num.h"
class OperButton : public Button {
public:
	OperButton(std::wstring str, int* pos, HWND hwnd)
		:Button( str,  pos,  hwnd) {
	}
	float onClick(int id) override {
		std::wstring oper = Num::oper;
		int* num = Num::num;

		switch (oper)
		{
		case L"+":
			return num[0] + num[1];
		case L"-":
			return num[0] - num[1];
		case L"*":
			return num[0] * num[1];
		case L"/":
			return num[0] / static_cast<float>(num[1]);
		default:
			return num[0];
		}
	}
};