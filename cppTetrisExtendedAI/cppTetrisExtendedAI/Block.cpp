#include "Block.h"

Block::Block() {
	blockPos.x = 5; blockPos.y = 1; blockPos.z = 2; blockPos.k = 1;
	std::memset(blockArr, 0, sizeof(int) * 4 * 4);
}

void Block::moveLeft() {
	blockPos.x--;
}

void Block::moveRight() {
	this->blockPos.x++;
}

void Block::moveUp(char *up) {
	this->blockPos.y--;
}

void Block::moveUp() {
	int tmpBlockArr[4][4] = { 0, };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			tmpBlockArr[i][j] = blockArr[i][j];
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			blockArr[i][3 - j] = tmpBlockArr[j][i];
		}
	}
}

void Block::moveDown() {
	this->blockPos.y++;
}

void Block::changeShape() {
	blockPos.x = 5; blockPos.y = 1;
	blockPos.z = blockPos.k;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			blockArr[i][j] = blockShapeArr[blockPos.z][i][j];
		}
	}
}

void Block::randomizeShape() {
	blockPos.k = rand() % 7;
	drawNextBlock();
}

int Block::getBlock(int _y, int _x) {
	return blockArr[_y][_x];
}

void Block::setBlock(int _y, int _x, int _val) {
	blockArr[_y][_x] = _val;
}

Pos Block::getPos() {
	return blockPos;
}

void Block::drawNextBlock() {
	int t;
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			gotoXY(16 + x, 4 + y); puts((t = blockShapeArr[blockPos.k][y][x]) ? "бр" : " ");
		}
	}
	resetFontColor();
}

//void Block::gotoXY(unsigned short _x, unsigned short _y) {
//	//COORD CursorPosition = { 10+ 2*_x,  2+_y };
//	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
//	printf("\033[%dd\033[%dG", 2 + _y, 40 + 2 * _x);
//}