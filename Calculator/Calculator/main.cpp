#include <Windows.h>

LRESULT OnPaint(HWND hwnd) {
	PAINTSTRUCT ps; 
	HDC hdc = BeginPaint(hwnd, &ps);
	LPCTSTR str = L"aaaaa";
	RECT rt = { 50,20,350,220 };

	for (int i = 0; i <= 700 / 50; i++) { 
		MoveToEx(hdc, i * 50 + 100, 100, nullptr); 
		LineTo(hdc, i * 50 + 100, 500);
		DrawText(hdc, str, lstrlen(str), &rt,DT_CENTER);
	}
	for (int i = 0; i <= 400 / 50; i++) {
		MoveToEx(hdc,  100, i * 50 + 100, nullptr);
		LineTo(hdc, 800,i * 50+100 );
	}
	return EndPaint(hwnd, &ps); 
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
		case WM_CLOSE: {
			PostQuitMessage(0);
			return 0;
		}
		case WM_DESTROY: {
			DestroyWindow(hwnd);
			return 0;
		}
	}
	switch (uMsg) {
		case WM_PAINT: {
			return OnPaint(hwnd);
		}
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