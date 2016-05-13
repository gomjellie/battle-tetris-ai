#ifndef __COLOR_H__
#define __COLOR_H__

#include <Windows.h>

class Color {
public:
	//생성자 그냥 디폴트로
	void setColor(int color, int bgColor);
	void setFontColor(int color);
	void setBgColor(int bgColor);
	__inline void resetColor() {
		setColor(CC_DEFAULT, CC_DEFAULT_BG);
	}
	__inline void resetFontColor() {
		setFontColor(CC_DEFAULT);
	}
	__inline void resetBgColor() {
		setBgColor(CC_DEFAULT_BG);
	}

public:
	enum ConsolColor {
		CC_BLACK,
		CC_DARKBLUE,
		CC_DARKGREEN,
		CC_DARKCYAN,
		CC_DARKRED,
		CC_DARKMAGENTA,
		CC_DARKYELLOW,
		CC_GRAY,
		CC_DARKGRAY,
		CC_BLUE,
		CC_GREEN,
		CC_CYAN,
		CC_RED,
		CC_MAGENTA,
		CC_YELLOW,
		CC_WHITE,
		CC_LIGHTGRAY = 7,
		CC_DEFAULT = 7,
		CC_DEFAULT_FONT = 7,
		CC_DEFAULT_BG = 0
	};
};

#endif //__COLOR_H__