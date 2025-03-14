#include <string>
#include <windows.h>
#include <list>
#pragma once

class Button{
	private:
		char val[1];
	public:
		static int btnId;
		static char btns[20];
		Button(char chr, int x1, int y1, int x2, int y2, HWND hwnd) {
			val[0] = chr;
			std::wstring wstr(val, &val[1]);
			btnId += 1;
			btns[btnId] = chr;
			CreateWindow(
				L"BUTTON", wstr.c_str(),
				WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
				x1, y1, x2, y2,
				hwnd,
				(HMENU)btnId,
				(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), 
				nullptr
			);
		}

		virtual float onClick(int id) = 0;
};

