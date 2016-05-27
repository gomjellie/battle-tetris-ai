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
	int getBlock(int _y, int _x) const;
	Pos getPos() const;
	int getBlockShape(int _z,int _y, int _x) const;
	void setPosX(int _x);
	void setPosY(int _y);
	void setPosZ(int _z);
	void setBlock(int _y, int _x, int _val);
	void drawNextBlock();
	void setCoordStartPos(int _y, int _x);
	//void gotoXY(unsigned short _x, unsigned short _y);

private:
	Pos blockPos;
	COORD coordStartPos;
	int blockArr[4][4];
	const int blockShapeArr[8][4][4] = {
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
		},
		{
			{ 8,0,8,0},
			{ 0,8,0,8},
			{ 8,0,8,0 },
			{ 0,8,0,8 },
		}
	};
};

#endif // __BLOCK_H__