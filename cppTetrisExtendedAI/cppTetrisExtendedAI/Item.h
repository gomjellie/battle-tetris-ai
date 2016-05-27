#ifndef __ITEM_H__
#define __ITEM_H__
#include "Controller.h"

class Item {
public:
	Item(Block& _block, Board& _board);
	virtual void action(Controller* self, Controller* target);
private:
	Block block;
	Board board;

};
#endif // !__ITEM_H__