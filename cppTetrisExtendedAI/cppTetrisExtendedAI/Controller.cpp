#include "Controller.h"

Controller::Controller() : block(), board(), ghost(this->block, this->board) {
	key = '\0';
	timeCnt = 0;
	speed = 50;
	itemDefensing = 0;
	board.setBoardStart(2, 10);
	block.setCoordStartPos(2, 10);
	ghost.setStartPos(2, 10);
	//default
}

void Controller::gameInit(unsigned int seed) {
	srand(seed);
	board.drawBoarder();
	block.changeShape();
	//Sound::playNyanNyanSong();
}

void Controller::setOpposite(Controller* _opposite){
	this->opposite=_opposite;
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
		ghost.gen();
		//ghost.findPos(block,board);
		//block.drawNextBlock();-> block.randomizeNextBlock에 삽입함 매번그리는것보다 그게 더 효율적이라서
		board.eraseBlockOffBoard(block);
	}
}

bool Controller::collision() {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (board.getBoard(block.getPos().y + y, block.getPos().x + x) != 0 &&
				block.getBlock(y, x) != 0) {
				if (block.getPos().y < 3 && block.getPos().x>1 && block.getPos().x < Board::X_LEN - 5)
					key = QUIT;
				else
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
	ghost.gen();
	board.clearLine();
	//board.gotoXY(13, 13); printf("%d", block.getPos().z);
	block.randomizeShape();
}

void Controller::timeControl() {
	while (true) {
		if (_kbhit()) {
			scanKey(); timeCnt += 10; break;
		}
		else {
			Sleep(1); timeCnt++;
		}
		if (timeCnt > speed) {
			timeCnt = 0; key = DOWN; break;
		}
	}
}

void Controller::useItem() {
	if (this->item == nullptr) {
		//there no Item!
	}
	else {
		this->item->action(this, this->opposite);
	}
}

bool Controller::isDefensing() {
	if (this->itemDefensing) {
		return true;
	}
	else {
		return false;
	}
}