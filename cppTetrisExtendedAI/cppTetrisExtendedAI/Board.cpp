#include "Board.h"

Board::Board() {
	std::memset(boardArr, 0, sizeof(int)*X_LEN*Y_LEN);
	for (int x = 0; x < X_LEN; x++) {
		for (int y = 0; y < Y_LEN; y++) {
			if ((x == 0 || x == X_LEN - 1) || (y == 0 || y == Y_LEN - 1))
				boardArr[y][x] = BLOCK;
		}
	}
	startPos.x = 0;
}

Board::Board(int startY, int startX) {
	std::memset(boardArr, 0, sizeof(int)*X_LEN*Y_LEN);
	for (int x = 0; x < X_LEN; x++) {
		for (int y = 0; y < Y_LEN; y++) {
			if ((x == 0 || x == X_LEN - 1) || (y == 0 || y == Y_LEN - 1)) {
				boardArr[y][x] = BLOCK;
			}
		}
	}
	startPos.y = startY; startPos.x = startX;
}

void Board::setBoard(int _y, int _x, int _val) {
	boardArr[_y][_x] = _val;
}

int Board::getBoard(int _y, int _x) {
	return boardArr[_y][_x];
}

void Board::drawBoard() {
	int boardVal;
	for (int y = 1; y < Y_LEN - 1; y++) {
		for (int x = 1; x < X_LEN - 1; x++) {
			if ((boardVal=boardArr[y][x]) != EMPTY) {
				gotoXY(x, y);
				setFontColor(boardVal + 3);
				puts("□");
				//printf("%s", colour[boardArr[y][x]-1]);
			}
			else if (boardVal == EMPTY) {
				gotoXY(x, y); std::cout << " ";
			}
		}
	}
	resetFontColor();
}

void Board::drawBoarder() {//테두리만 출력
	setFontColor(CC_RED);
	for (int y = 0; y < Y_LEN; y++) {
		for (int x = 0; x < X_LEN; x++) {
			if (boardArr[y][x] != EMPTY) {
				gotoXY(x, y); puts("□");
				//printf("%s", colour[boardArr[y][x]]);
			}
		}
	}
	resetFontColor();
}
//
//void Board::stack() {
//	//controller에 있음
//}

void Board::writeBlockOnBoard(Block &block) {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (block.getBlock(y, x) != EMPTY) {
				setBoard(block.getPos().y + y, block.getPos().x + x, block.getPos().z + 1);//0번째 블록 z+1로 해결
			}
		}
	}
}

void Board::eraseBlockOffBoard(Block &block) {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (block.getBlock(y, x) != EMPTY) {
				setBoard(block.getPos().y + y, block.getPos().x + x, EMPTY);
			}
		}
	}
}

void Board::clearLine() {
	int checkLine = 0;// f means field
	for (int y = Y_LEN - 2; y > 1; y--) {
		for (int x = 1; x < X_LEN - 1; x++) {
			if (boardArr[y][x] != EMPTY) {
				checkLine++;
			}
		}
		if (checkLine == X_LEN - 2) {
			for (int x = 1; x < X_LEN - 1; x++) {
				boardArr[y][x] = EMPTY;
			}
			gravity(y); score += 10; clearLine();
		}

		checkLine = 0;
	}
}

void Board::gravity(int _y) {
	for (; _y > 2; _y--) {
		for (int x = 1; x < X_LEN - 1; x++) {
			boardArr[_y][x] = boardArr[_y - 1][x];
		}
	}
}

//void Board::gotoXY(unsigned short _x, unsigned short _y) {
//	//COORD CursorPosition = { 10+ 2*_x,  2+_y };
//	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
//	printf("\033[%dd\033[%dG", 2+_y, 10+ 2 * _x);
//}