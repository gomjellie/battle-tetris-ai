#include "Controller.h"

Controller::Controller() {
	key = '\0';
	timeCnt = 0;
	speed = 125;
	board.setBoardStart(2, 10);
	block.setCoordStartPos(2, 10);
	ghost.setStartPos(2, 10);
	//default
}

void Controller::gameInit() {
	srand((unsigned int)time(NULL));
	board.drawBoarder();
	block.changeShape();
	//Sound::playNyanNyanSong();
}

void Controller::scanKey() {
	key = _getch();
}

void Controller::playGame() {
	block.randomizeShape();
	while (key != QUIT) {
		timeControl();

		switch (key)
		{
		case RIGHT:
			block.moveRight();
			if (collision())
				block.moveLeft();
			break;
		case LEFT:
			block.moveLeft();
			if (collision())
				block.moveRight();
			break;
		case UP:
			block.moveUp();
			if (collision()) {
				block.moveUp(); block.moveUp(); block.moveUp();
			}
			break;
		case DOWN:
			block.moveDown();
			if (collision())
				stack();
			break;
		case SPACE:
			while (!collision()) {
				block.moveDown();
			}stack();
			break;
		default:
			break;
		}
		board.writeBlockOnBoard(block);
		board.drawBoard();
		ghost.gen(block, board);
		ghost.findPos(block,board);
		//block.drawNextBlock();-> block.randomizeNextBlock에 삽입함 매번그리는것보다 그게 더 효율적이라서
		board.eraseBlockOffBoard(block);
	}
}

bool Controller::collision() {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (board.getBoard(block.getPos().y + y, block.getPos().x + x) != 0 &&
				block.getBlock(y, x) != 0) {
				return true;
			}
		}
	}

	return false;
}

void Controller::stack() {
	block.moveUp("up");
	board.writeBlockOnBoard(block);
	block.changeShape();
	ghost.gen(block, board);
	board.clearLine();
	//board.gotoXY(13, 13); printf("%d", block.getPos().z);
	block.randomizeShape();
}

void Controller::timeControl() {
	while (true) {
		if (_kbhit()) {
			scanKey(); timeCnt += 3; break;
		}
		else {
			Sleep(1); timeCnt++;
		}
		if (timeCnt > speed) {
			timeCnt = 0; key = DOWN; break;
		}
	}
}


//
//void Controller::gotoXY(unsigned short _x, unsigned short _y){
//	//COORD CursorPosition = { 10+ 2*_x,  2+_y };
//	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
//	printf("\033[%dd\033[%dG", 2+_y, 10+2*_x);
//}