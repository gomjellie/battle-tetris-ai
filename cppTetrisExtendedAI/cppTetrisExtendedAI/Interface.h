#ifndef __INTERFACE_H__
#define __INTERFACE_H__
#include "Color.h"
#include "Sound.h"
#include "Windows.h"
#include <thread>
#include <mutex>
#include <chrono>

class Interface :public Color {
public:
	void printXY(unsigned short _x, unsigned short _y, const char *string, int color) const;
	void gotoXY(unsigned short _x, unsigned short _y) const;
	const char colour[7][4] = {
		"Ð¥",
		"çï",
		"¢Ã",
		"ù¦",
		"¡à",
		"ìí",
		"êÅ"
	};
	void setConsoleSize(HANDLE hBuffer, short y, short x);
	void Interface::cursorInvisible();
};

#endif // !__INTERFACE_H__