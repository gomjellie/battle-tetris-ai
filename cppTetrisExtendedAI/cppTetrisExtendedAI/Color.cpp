#include "Color.h"

//�ؽ�Ʈ, ���� ��� ���� �Լ�
void Color::setColor(int color, int bgColor) const{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ((bgColor & 0xf) << 4) | (color & 0xf));
}

//�ؽ�Ʈ ���� ���� �Լ�
void Color::setFontColor(int color) const{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (info.wAttributes & 0xf0) | (color & 0xf));
}

//��� ���� ���� �Լ�
void Color::setBgColor(int bgColor) {
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ((bgColor & 0xf) << 4) | (info.wAttributes & 0xf));
}