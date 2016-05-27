#include "Ghost.h"


Ghost::Ghost(Block& block, Board& board) : block(block), board(board) {
}

void Ghost::gen() {
	setPosX(block.getPos().x);
	setPosY(block.getPos().y + 4);
	setPosZ(block.getPos().z);

	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			if (block.getBlock(y, x) != 0) {
				//if (block.getBlockShape(getPos().z, y, x)!=0) {
				setBlock(y, x, getPos().z + 1);
			}
			else {
				setBlock(y, x, 0);
			}
		}
	}

	findPos();

}

void Ghost::findPos() {
	setPosX(block.getPos().x);
	setPosZ(block.getPos().z);

	while (!collision()) {
		moveDown();
	}

	moveUp("up");
	show();
}
bool Ghost::collision() {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (board.getBoard(getPos().y + y, getPos().x + x) != 0 &&
				getBlock(y, x) != 0) {
				return true;
			}
		}
	}

	return false;
}

void Ghost::show() {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if ((getPos().y > block.getPos().y + 3) && getBlock(y, x)) {
				printXY(getPos().x + x + startPos.X, getPos().y + startPos.Y + y, "H", getPos().z + 4);
				printXY(getPos().x + x + startPos.X, getPos().y + startPos.Y + y, "H", getPos().z + 4);
			}
		}
	}
}

Block& Ghost::getBlockRef() {
	return this->block;
}

void Ghost::setStartPos(int _y, int _x) {
	startPos.Y = _y;
	startPos.X = _x;


}