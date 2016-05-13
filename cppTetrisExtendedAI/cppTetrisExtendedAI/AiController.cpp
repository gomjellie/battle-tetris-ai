#include "AiController.h"

void AiController::animationEffect(const double _time) {
	board.writeBlockOnBoard();
	board.drawBoard();
	board.eraseBlockOffBoard(block);
	Sleep(_time*speed);
}

void AiController::moveToBestPos() {
	int i,T;
	for (i = 0; i < posAi.rotation; i++) {
		block.moveUp();
		animationEffect(7);
	}
	while (block.getPos().x != posAi.x) {
		if (block.getPos().x > posAi.x) {
			block.moveLeft();
		}
		else if (block.getPos().x < posAi.x) {
			block.moveRight();
		}
	}
	animationEffect(4);
	while (!collision()) {
		animationEffect(0.5);
		block.moveDown();
		//block.moveUp("up");없어도 될듯
	}
	//block.stack();이것도
	return;
}

PosAi AiController::findIdealPosition() {
	int firstX = block.getPos().x, firstY = block.getPos().y;
	PosAi position[4] = { 0, };
	int highestScore = 0, plusScore = 0, minusScore = 0, totalScore = 0;
	int rotation = 0, bestRotation = 0;
	int i = 0;

	for (rotation = 0; rotation < 4; rotation++) {
		for (block.setPosX(0), i = 0; 1; block.moveRight()) {
			block.setPosX(1);

			if (i == 0 && collision()) {
				block.setPosX(1); i++;
			}
			else if (collision()) {
				break;
			}
			while (!collision()) {
				block.moveDown();
			}
			//block.moveUp("up");
			board.writeBlockOnBoard();
			plusScore = 4 * getIdealPoint() + 5 * getClearLinePoint() + 5 * getAdjacentPoint();
			minusScore = 17 * getMinusPoint();
			totalScore = plusScore - minusScore;
			board.eraseBlockOffBoard(block);

			if (highestScore <= totalScore) {
				highestScore = totalScore;
				position[rotation].x = block.getPos().x;
				position[rotation].y = block.getPos().y;
				position[rotation].rotation = rotation;
				position[rotation].score = totalScore;
			}
		}

		block.moveUp();
	}
	highestScore = 0;

	for (rotation = 0; rotation < 4; rotation++) {
		if (position[rotation].score > highestScore) {
			highestScore = position[rotation].score;
			bestRotation = rotation;
		}
	}

	block.setPosX(firstX); block.setPosX(firstY);
	return position[bestRotation];
}

