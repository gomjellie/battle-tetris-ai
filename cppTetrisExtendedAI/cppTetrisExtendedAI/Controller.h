#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "Block.h"
#include "Board.h"
//#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>

class Controller {
public:
	Controller();
	void gameInit();
	void playGame();
	bool collision();
	void scanKey();
	void stack();
	void timeControl();
	//static void gotoXY(unsigned short _x, unsigned short _y);

private:
	Block block;
	Board board;
	unsigned int timeCnt;
	unsigned int speed;
	int key;

	enum controllerEnum
	{
		RIGHT = 77, LEFT = 75, UP = 72, DOWN = 80, QUIT = 27, SPACE = 32
	};
};

#endif // ifndef __CONTROLLER_H__