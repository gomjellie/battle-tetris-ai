#include "AttackItemScatter.h"
#include "Controller.h"

void AttackItemScatter::action(Controller* self, Controller* target) {
	Block* block = target->getBlock();
	block->setPosK(7+rand()%2);
	block->drawNextBlock();
}