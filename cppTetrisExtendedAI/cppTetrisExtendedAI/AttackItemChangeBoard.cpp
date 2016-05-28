#include "AttackItemChangeBoard.h"
#include "Controller.h"
void AttackItemChangeBoard::action(Controller* self, Controller* target) {
	Board* targetBoard = target->getBoard();
	Board* selfBoard = self->getBoard();

	//swap 구현하면끝....!
	//아 근데 스왑하는도중에 
	//다른쓰레드에서 쓰고있던게 보드에 접근해서 기록중이면 
	//뭔가 큰일이 날 수도 있고
	//아닐 수도 잇고
}