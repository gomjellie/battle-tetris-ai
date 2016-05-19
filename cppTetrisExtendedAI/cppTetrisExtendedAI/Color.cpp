#include "Color.h"

//텍스트, 배경색 모두 변경 함수
void Color::setColor(int color, int bgColor) const{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ((bgColor & 0xf) << 4) | (color & 0xf));
}

//텍스트 색상 변경 함수
void Color::setFontColor(int color) const{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (info.wAttributes & 0xf0) | (color & 0xf));
}

//배경 색상 변경 함수
void Color::setBgColor(int bgColor) {
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ((bgColor & 0xf) << 4) | (info.wAttributes & 0xf));
}