#include <iostream>
#include <Windows.h>
#include <cmath>
using namespace std;
int main() {
	HWND hWnd = GetConsoleWindow();
	HDC hDC = GetDC(hWnd);
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hDC, Pen);
	MoveToEx(hDC, 0, 100, NULL);
	LineTo(hDC, 700, 100);
	MoveToEx(hDC, 350, 0, NULL);
	LineTo(hDC, 350, 210);
	for (float x = -20.0f; x <= 20.0f; x += 0.01f) {
		MoveToEx(hDC, 18 * x + 350, -20 * sin(x) + 100, NULL);
		LineTo(hDC, 18 * x + 350, -20 * sin(x) + 100);
	}
	ReleaseDC(hWnd, hDC);
	cin.get();
	Sleep(3000);
}