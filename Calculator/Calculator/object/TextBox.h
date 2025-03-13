#include <Windows.h>
#include <string>
class TextBox {
public:
	TextBox(HWND hwnd,std::wstring str,int x1, int y1, int x2, int y2) {
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);

		RECT rect = {x1,y1,x2,y2};
		//SetRect(&rect, x1, y1, x2, y2);

		//SetTextAlign(hdc, TA_RIGHT);

		LPCTSTR lpctstr = (LPCTSTR)str.c_str();

		//TextOut(hdc, 200, 70, lpctstr, 20);
		DrawText(hdc, lpctstr, -1, &rect, DT_RIGHT | DT_VCENTER | DT_SINGLELINE);

		//DrawText(hdc, lpctstr, -1, &rect, DT_RIGHT | DT_VCENTER | DT_SINGLELINE);
		EndPaint(hwnd, &ps);
	}
};