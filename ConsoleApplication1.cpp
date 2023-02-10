#include <iostream>
#include <windows.h>
#include <stdio.h>

using namespace std;


//pasted this part
void MouseMove(int x, int y)
{
	double fScreenWidth = ::GetSystemMetrics(SM_CXSCREEN) - 1;
	double fScreenHeight = ::GetSystemMetrics(SM_CYSCREEN) - 1;
	double fx = x * (65535.0f / fScreenWidth);
	double fy = y * (65535.0f / fScreenHeight);
	INPUT  Input = { 0 };
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
	Input.mi.dx = fx;
	Input.mi.dy = fy;
	::SendInput(1, &Input, sizeof(INPUT));
}

//wrote this part
void main() {
	while(true) {
		if ((GetKeyState(VK_LBUTTON) & GetKeyState(VK_RBUTTON) & 0x8000) != 0) {
			POINT p;
			GetCursorPos(&p);
			MouseMove(p.x + 5, p.y + 5);
			Sleep(10);
		}
	}
	
}