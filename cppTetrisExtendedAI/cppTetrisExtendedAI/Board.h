#ifndef __BOARD_H__
#define __BOARD_H__

#include <iostream>
#include <Windows.h>
#include "Block.h"
#include "Color.h"
#include "Interface.h"

class Board :public Interface {
public:
	Board();
	void setBoardStart(int startY, int startX);
	void setBoard(int _y, int _x, int _val);
	int getBoard(int _y, int _x) const;
	//void gotoXY(unsigned short _x, unsigned short _y);
	//void stack();
	void drawBoard();
	void drawBoarder();//테두리만 출력
	void clearLine();
	void gravity(int _y);
	void writeBlockOnBoard(Block &block);
	void eraseBlockOffBoard(Block &block);
	void showScore(char buf[]);
	void showMessage(char _message[]);
	unsigned int getScore() const ;
	unsigned int buyItem(unsigned int _price);

	enum boardEnum
	{
		EMPTY = 0,
		BLOCK = 1,
		X_LEN = 14,
		Y_LEN = 30
	};

private:
	int boardArr[Y_LEN][X_LEN];
	int idx;
	unsigned int score;
	Pos startPos;


	//Color color;
};

#endif //__BOARD_H__