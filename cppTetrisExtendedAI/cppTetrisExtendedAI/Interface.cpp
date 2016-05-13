#include "Interface.h"
#include <stdio.h>

void Interface::gotoXY(unsigned short _x, unsigned short _y) {
	//COORD CursorPosition = { 10+ 2*_x,  2+_y };
	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
	printf("\033[%dd\033[%dG", 2 + _y, 10 + 2 * _x);
}