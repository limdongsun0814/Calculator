#include <Windows.h>
#include "object/NumButton.h"
#include "object/Button.h"
#include "object/Num.h"
#include "object/TextBox.h"
#include "object/OperButton.h"

int Button::btnId = 0;
std::wstring Button::btns[20];
std::wstring Num::oper=L"";
int Num::num[2] = {0,0};
int pos[4] = { 50,50,30,20 };
int operPos[4] = { 90,50,30,20 };
Button* btn1;
Button* btn2;
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
			btn1 = new NumButton(L"1", pos, hwnd);
			btn2 = new OperButton(L"+", operPos, hwnd);
			return 0;

		case WM_COMMAND:
			switch (LOWORD(wParam))	{
				case 1:
					btn1->onClick(LOWORD(wParam));
					InvalidateRect(hwnd, NULL, TRUE);
					return 0;
				case 2:
					btn2->onClick(LOWORD(wParam));
					InvalidateRect(hwnd, NULL, TRUE);
					return 0;
			}
			return 0;

		case WM_PAINT: 
			if (Num::oper==L"") {
				std::wstring data = std::to_wstring(Num::num[0]);
				new TextBox(hwnd, data, 10, 10, 300, 60);
			}
			else {
				std::wstring data = std::to_wstring(Num::num[0])+ Num::oper + std::to_wstring(Num::num[1]);
				new TextBox(hwnd, data, 10, 10, 300, 60);
			}

			return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR, int nCmdShow) {
	WNDCLASS wc{};
	MSG msg;


	wc.lpfnWndProc = WindowProc;
	wc.lpszClassName = L"Hello world";
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;

	RegisterClass(&wc);

	HWND hWnd = CreateWindow(L"Hello world", L"My First Win32 Program", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd) return -1;

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	while (GetMessage(&msg, nullptr, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}