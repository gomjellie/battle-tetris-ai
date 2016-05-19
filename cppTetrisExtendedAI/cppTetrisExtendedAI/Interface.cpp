#include "Interface.h"
#include <stdio.h>

//#include <thread>
//#include <mutex>
//#include <chrono>
std::mutex m;
using namespace std::literals;
void Interface::gotoXY(unsigned short _x, unsigned short _y) const {
	//m.lock();
	COORD CursorPosition = { 10 + 2 * _x,  2 + _y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
	//printf("\033[%dd\033[%dG", 2 + _y, 10 + 2 * _x);

	//m.unlock();
	//std::this_thread::sleep_for(1ns);

}

void Interface::printXY(unsigned short _x, unsigned short _y, const char *string, int color) const {//colorµµ 
	m.lock();
	setFontColor(color);
	gotoXY(_x, _y); printf(string);
	m.unlock();
	std::this_thread::sleep_for(1ns);
}

void Interface::cursorInvisible() {
	CONSOLE_CURSOR_INFO Cinfo = { 0, };
	Cinfo.dwSize = 1;
	Cinfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Cinfo);
}

void Interface::setConsoleSize(HANDLE hBuffer, short cx, short cy) {
	enum EFlag {
		FlagNoChange,
		FlagWindowFirst,
		FlagScreenFirst
	};

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hBuffer, &csbi);
	csbi.srWindow.Right -= csbi.srWindow.Left;
	csbi.srWindow.Bottom -= csbi.srWindow.Top;
	csbi.srWindow.Left = 0;
	csbi.srWindow.Top = 0;
	SetConsoleWindowInfo(hBuffer, TRUE, &csbi.srWindow);

	COORD coordLargestSize = GetLargestConsoleWindowSize(hBuffer);
	COORD coordNewSize = { min(coordLargestSize.X, cx), min(coordLargestSize.Y, cy) };
	COORD coordWindowSize = { csbi.srWindow.Right + 1, csbi.srWindow.Bottom + 1 };
	SMALL_RECT srWindowRect = {};

	EFlag eFlag = FlagNoChange;

	if (coordWindowSize.Y > coordNewSize.Y) {
		if (coordWindowSize.X < coordNewSize.X) {
			SMALL_RECT srNewWindow = csbi.srWindow;
			srNewWindow.Bottom = coordNewSize.Y - 1;
			SetConsoleWindowInfo(hBuffer, TRUE, &srNewWindow);
			eFlag = FlagScreenFirst;
		}
		else {
			eFlag = FlagWindowFirst;
		}
	}
	else if (coordWindowSize.Y < coordNewSize.Y) {
		if (coordWindowSize.X > coordNewSize.X) {
			SMALL_RECT srNewWindow = csbi.srWindow;
			srNewWindow.Right = coordNewSize.X - 1;
			SetConsoleWindowInfo(hBuffer, TRUE, &srNewWindow);
		}
		eFlag = FlagScreenFirst;
	}
	else {
		if (coordWindowSize.X > coordNewSize.X) {
			eFlag = FlagWindowFirst;
		}
		else if (coordWindowSize.X < coordNewSize.X) {
			eFlag = FlagScreenFirst;
		}
	}

	if (eFlag != FlagNoChange) {
		srWindowRect.Right = coordNewSize.X - 1;
		srWindowRect.Bottom = coordNewSize.Y - 1;
		if (eFlag == FlagWindowFirst) {
			SetConsoleWindowInfo(hBuffer, TRUE, &srWindowRect);
			SetConsoleScreenBufferSize(hBuffer, coordNewSize);
		}
		else {
			SetConsoleScreenBufferSize(hBuffer, coordNewSize);
			SetConsoleWindowInfo(hBuffer, TRUE, &srWindowRect);
		}
	}
}