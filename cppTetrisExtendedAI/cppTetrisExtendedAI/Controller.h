#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "Board.h"
#include "Ghost.h"
//#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>

class Controller {
public:
	Controller();
	void gameInit(unsigned int seed);
	void playGame();
	bool collision();
	void scanKey();
	void stack();
	void timeControl();
	//static void gotoXY(unsigned short _x, unsigned short _y);

protected:
	Block block;
	Board board;
	Ghost ghost;
	unsigned int timeCnt;
	unsigned int speed;
	int key;

	enum controllerEnum
	{
		RIGHT = 77, LEFT = 75, UP = 72, DOWN = 80, QUIT = 27, SPACE = 32
	};
};

#endif // ifndef __CONTROLLER_H__