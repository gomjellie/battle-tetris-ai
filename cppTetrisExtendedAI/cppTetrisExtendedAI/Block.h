#ifndef __BLOCK_H__
#define __BLOCK_H__

#include <iostream>
#include <cstdlib>
#include "Interface.h"

typedef struct _Pos {
	int x, y, z, k;
}Pos;


class Block :public Interface {
public:
	Block();
	void moveLeft();
	void moveRight();
	void moveUp();//rotate
	void moveUp(char *up);
	void moveDown();
	void changeShape();
	void randomizeShape();
	int getBlock(int _y, int _x);
	Pos getPos();
	void setPosX(int _x);
	void setPosY(int _y);

	void setBlock(int _y, int _x, int _val);
	void drawNextBlock();
	//void gotoXY(unsigned short _x, unsigned short _y);

private:
	Pos blockPos;
	int blockArr[4][4];
	const int blockShapeArr[7][4][4] = {
		{
			{ 0,0,1,0 },
			{ 0,0,1,0 },
			{ 0,0,1,0 },
			{ 0,0,1,0 }
		},
		{
			{ 0,0,0,0 },
			{ 0,0,2,0 },
			{ 0,2,2,0 },
			{ 0,0,2,0 }
		},
		{
			{ 0,0,0,0 },
			{ 0,3,0,0 },
			{ 0,3,3,3 },
			{ 0,0,0,0 }
		},
		{
			{ 0,0,0,0 },
			{ 0,0,4,0 },
			{ 4,4,4,0 },
			{ 0,0,0,0 },
		},
		{
			{ 0,0,0,0 },
			{ 0,5,5,0 },
			{ 5,5,0,0 },
			{ 0,0,0,0 },
		},
		{
			{ 0,0,0,0 },
			{ 0,6,6,0 },
			{ 0,0,6,6 },
			{ 0,0,0,0 },
		},
		{
			{ 0,0,0,0 },
			{ 0,7,7,0 },
			{ 0,7,7,0 },
			{ 0,0,0,0 }
		}
	};
};

#endif // __BLOCK_H__