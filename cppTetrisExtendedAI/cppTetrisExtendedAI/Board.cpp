#include "Board.h"
//#include <thread>
//#include <mutex>
//#include <chrono>
std::mutex n;

Board::Board() {
	std::memset(boardArr, 0, sizeof(int)*X_LEN*Y_LEN);
	for (int x = 0; x < X_LEN; x++) {
		for (int y = 0; y < Y_LEN; y++) {
			if ((x == 0 || x == X_LEN - 1) || (y == 0 || y == Y_LEN - 1))
				boardArr[y][x] = BLOCK;
		}
	}
	startPos.x = 1, startPos.y = 1;
	setConsoleSize(GetStdHandle(STD_OUTPUT_HANDLE), 160, 40);
	cursorInvisible();
}

void Board::setBoardStart(int startY, int startX) {
	startPos.y = startY; startPos.x = startX;
}

void Board::setBoard(int _y, int _x, int _val) {
	boardArr[_y][_x] = _val;
}

int Board::getBoard(int _y, int _x) const{
	return boardArr[_y][_x];
}

void Board::drawBoard() {
	n.lock();
	int boardVal;
	for (int y = 1; y < Y_LEN - 1; y++) {
		for (int x = 1; x < X_LEN - 1; x++) {
			if ((boardVal = boardArr[y][x]) != EMPTY) {
				printXY(startPos.x + x, startPos.y + y, "□", boardVal + 3);//used printXY to fix display scaterring problem comes from thread
				//gotoXY(startPos.x + x, startPos.y + y);
				//setFontColor(boardVal + 3);
				//printf("□");

			}
			else if (boardVal == EMPTY) {
				printXY(startPos.x + x, startPos.y + y, " ", boardVal + 3);
				//gotoXY(startPos.x + x, startPos.y + y); printf(" ");
			}
		}
	}
	resetFontColor();
	n.unlock();

}

void Board::drawBoarder() {//테두리만 출력
	setFontColor(CC_RED);
	for (int y = 0; y < Y_LEN; y++) {
		for (int x = 0; x < X_LEN; x++) {
			if (boardArr[y][x] != EMPTY) {
				printXY(startPos.x + x, startPos.y + y, "□", CC_RED);
				//gotoXY(startPos.x + x, startPos.y + y); printf("□");
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