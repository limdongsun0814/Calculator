#include <Windows.h>
#include <string>
class TextBox {
public:
	TextBox(HWND hwnd,std::wstring str,int x1, int y1, int x2, int y2) {
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);

		RECT rect;
		SetRect(&rect, x1, y1, x2, y2);

		LPCTSTR lpctstr = (LPCTSTR)str.c_str();

		DrawText(hdc, lpctstr, -1, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		EndPaint(hwnd, &ps);
	}
};