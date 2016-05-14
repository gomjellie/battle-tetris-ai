#ifndef __INTERFACE_H__
#define __INTERFACE_H__
#include "Color.h"
#include "Sound.h"
#include "Windows.h"

class Interface :public Color {
public:
	void gotoXY(unsigned short _x, unsigned short _y);
	const char colour[7][4] = {
		"Ð¥",
		"çï",
		"¢Ã",
		"ù¦",
		"¡à",
		"ìí",
		"êÅ"
	};
	void setConsoleSize(HANDLE hBuffer,short y, short x);
};

#endif // !__INTERFACE_H__