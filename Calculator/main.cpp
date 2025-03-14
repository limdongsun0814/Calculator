#include <Windows.h>
#include <map>
#include "object/NumButton.h"
#include "object/Button.h"
#include "object/Num.h"
#include "object/TextBox.h"
#include "object/OperButton.h"
#include "object/EnterButton.h"
#include "object/ResetButton.h"
#include "limits"


int Button::btnId = 0;
char Button::btns[20];
char Num::oper=' ';
long Num::num[2] = {0,0};
std::map<char, Button*> btnMap;
float result = 0;
int cnt = 0;


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
		case WM_CLOSE: 
			PostQuitMessage(0);
			return 0;
		
		case WM_DESTROY: 
			DestroyWindow(hwnd);
			return 0;

		case WM_CREATE:

			btnMap['7'] = new NumButton('7', 10, 50, 30, 20, hwnd);
			btnMap['8'] = new NumButton('8', 50, 50, 30, 20, hwnd);
			btnMap['9'] = new NumButton('9', 90, 50, 30, 20, hwnd);
			btnMap['4'] = new NumButton('4', 10, 80, 30, 20, hwnd);
			btnMap['5'] = new NumButton('5', 50, 80, 30, 20, hwnd);
			btnMap['6'] = new NumButton('6', 90, 80, 30, 20, hwnd);
			btnMap['1'] = new NumButton('1', 10, 110, 30, 20, hwnd);
			btnMap['2'] = new NumButton('2', 50, 110, 30, 20, hwnd);
			btnMap['3'] = new NumButton('3', 90, 110, 30, 20, hwnd);
			btnMap['0'] = new NumButton('0', 50, 140, 30, 20, hwnd);
			btnMap['-'] = new OperButton('-', 130, 50, 30, 20, hwnd);
			btnMap['+'] = new OperButton('+', 130, 80, 30, 20, hwnd);
			btnMap['*'] = new OperButton('*', 130, 110, 30, 20, hwnd);
			btnMap['/'] = new OperButton('/', 130, 140, 30, 20, hwnd);
			btnMap['E'] = new EnterButton('E', 90, 140, 30, 20, hwnd);
			btnMap['R'] = new ResetButton('R', 10, 140, 30, 20, hwnd);
			return 0;

		case WM_COMMAND:
			switch (Button::btns[LOWORD(wParam)]) {
				case '0':
					btnMap['0']->onClick(LOWORD(wParam));
					InvalidateRect(hwnd, NULL, TRUE);
					return 0;
				case '1':
					btnMap['1']->onClick(LOWORD(wParam));
					InvalidateRect(hwnd, NULL, TRUE);
					return 0;
				case '2':
					btnMap['2']->onClick(LOWORD(wParam));
					InvalidateRect(hwnd, NULL, TRUE);
					return 0;
				case '3':
					btnMap['3']->onClick(LOWORD(wParam));
					InvalidateRect(hwnd, NULL, TRUE);
					return 0;
				case '4':
					btnMap['4']->onClick(LOWORD(wParam));
					InvalidateRect(hwnd, NULL, TRUE);
					return 0;
				case '5':
					btnMap['5']->onClick(LOWORD(wParam));
					InvalidateRect(hwnd, NULL, TRUE);
					return 0;
				case '6':
					btnMap['6']->onClick(LOWORD(wParam));
					InvalidateRect(hwnd, NULL, TRUE);
					return 0;
				case '7':
					btnMap['7']->onClick(LOWORD(wParam));
					InvalidateRect(hwnd, NULL, TRUE);
					return 0;
				case '8':
					btnMap['8']->onClick(LOWORD(wParam));
					InvalidateRect(hwnd, NULL, TRUE);
					return 0;
				case '9':
					btnMap['9']->onClick(LOWORD(wParam));
					InvalidateRect(hwnd, NULL, TRUE);
					return 0;

				case '+':
					btnMap['+']->onClick(LOWORD(wParam));
					InvalidateRect(hwnd, NULL, TRUE);
					return 0;

				case '-':
					btnMap['-']->onClick(LOWORD(wParam));
					InvalidateRect(hwnd, NULL, TRUE);
					return 0;

				case '/':
					btnMap['/']->onClick(LOWORD(wParam));
					InvalidateRect(hwnd, NULL, TRUE);
					return 0;

				case '*':
					btnMap['*']->onClick(LOWORD(wParam));
					InvalidateRect(hwnd, NULL, TRUE);
					return 0;

				case 'R':
					result = btnMap['R']->onClick(LOWORD(wParam));
					InvalidateRect(hwnd, NULL, TRUE);
					return 0;

				case 'E':
					result =btnMap['E']->onClick(LOWORD(wParam));
					std::wstring data = std::to_wstring(result);
					new TextBox(hwnd, data, 10, 10, 160, 35);
					InvalidateRect(hwnd, NULL, TRUE);
					return 0;
			}
			return 0;

		case WM_PAINT: 

			switch (Num::oper)
			{
				case ' ':{
					std::wstring data = std::to_wstring(Num::num[0]);
					new TextBox(hwnd, data, 10, 10, 160, 35);
					return 0;
				}
				case 'E': {
					std::wstring data = std::to_wstring(result);
					new TextBox(hwnd, data, 10, 10, 160, 35);
					return 0;
				}
				case 'e': {
					std::wstring data = L"Input value exceeded.";
					
					new TextBox(hwnd, data, 10, 10, 160, 35);
					return 0;
				}
				default:{
					char val[] = { Num::oper };
					std::wstring wstr(val, &val[1]);
					std::wstring data = std::to_wstring(Num::num[0]) + wstr + std::to_wstring(Num::num[1]);
					new TextBox(hwnd, data, 10, 10, 160, 35);
					return 0;
				}
			}
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR, int nCmdShow) {
	WNDCLASS wc{};
	MSG msg;


	wc.lpfnWndProc = WindowProc;
	wc.lpszClassName = L"Calculator";
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;

	RegisterClass(&wc);

	HWND hWnd = CreateWindow(L"Calculator", L"Calculator", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 190, 210, nullptr, nullptr, hInstance, nullptr);
	if (!hWnd) return -1;

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	while (GetMessage(&msg, nullptr, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}