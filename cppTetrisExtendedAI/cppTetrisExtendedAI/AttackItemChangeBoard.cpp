#include "AttackItemChangeBoard.h"
#include "Controller.h"
#include <thread>

#define SWAP(a,b){int t=a;a=b;b=t;}

void AttackItemChangeBoard::action(Controller* self, Controller* target) {
	int t;
	Board* targetBoard = target->getBoard();
	Board* selfBoard = self->getBoard();
	Block* targetBlock = target->getBlock();
	Block* selfBlock = self->getBlock();
	
	std::thread tmpThread([&]() {
		target->setPause(true);

		selfBoard->eraseBlockOffBoard(*selfBlock);
		targetBoard->eraseBlockOffBoard(*targetBlock);

		for (int x = 1; x < Board::X_LEN - 1; x++) {
			for (int y = 1; y < Board::Y_LEN - 1; y++) {
				t = targetBoard->getBoard(y, x);
				targetBoard->setBoard(y, x, selfBoard->getBoard(y, x));
				selfBoard->setBoard(y, x, t);
			}
		}

		fprintf(stdin, "%d", 'r');
		self->setPause(false);
	});

	tmpThread.join();
	//self->pause();
	

	target->setPause(false);
	
}