#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "Board.h"
#include "Ghost.h"
#include "Item.h"
#include "AttackItemScatter.h"
#include "AttackItemChangeBoard.h"

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
	void setOpposite(Controller* _opposite);
	void useItem();
	bool isDefensing();
	Block* getBlock() {return &this->block;};
	Board* getBoard() {return &this->board;};
	void pause();
	void setPause(bool _bool) {
		bPause = _bool;
	}
	//static void gotoXY(unsigned short _x, unsigned short _y);

protected:
	Block block;
	Board board;
	Ghost ghost;
	Controller* opposite;
	Item* item = nullptr;
	
	unsigned int timeCnt;
	unsigned int speed;
	int itemDefensing;
	int key;

	bool bPause;

	enum controllerEnum
	{
		RIGHT = 77, LEFT = 75, UP = 72, DOWN = 80, QUIT = 27, SPACE = 32, 
		KEY_1 = 49, KEY_2 = 50, KEY_3 = 51, KEY_4 = 52
	};
};

#endif // ifndef __CONTROLLER_H__