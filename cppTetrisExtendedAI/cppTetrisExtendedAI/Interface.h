#ifndef __INTERFACE_H__
#define __INTERFACE_H__
#include "Color.h"

class Interface :public Color {
public:
	void gotoXY(unsigned short _x, unsigned short _y);
	const char colour[7][4] = {
		"Х",
		"��",
		"��",
		"��",
		"��",
		"��",
		"��"
	};
};

#endif // !__INTERFACE_H__