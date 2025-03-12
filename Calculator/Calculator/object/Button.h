#include <string>
#include <windows.h>
#include <list>
#pragma once

class Button{
	private:
		std::wstring val;
	public:
		static int btnId;
		static std::wstring btns[20];
		Button(std::wstring str, int* pos, HWND hwnd) {
			val = str;
			btnId += 1;
			btns[btnId] = str;
			CreateWindow(
				L"BUTTON",val.c_str(),
				WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
				pos[0], pos[1], pos[2], pos[3],
				hwnd,
				(HMENU)btnId,
				(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), 
				nullptr
			);
		}
		std::wstring getVal() {
			return val;
		}
		void setVal(std::wstring str) {
			val = str;
		}
		virtual float onClick(int id) = 0;
};

