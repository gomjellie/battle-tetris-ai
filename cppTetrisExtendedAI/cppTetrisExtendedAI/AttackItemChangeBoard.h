#ifndef __ATTACK_ITEM_CHANGE_BOARD_H__
#define __ATTACK_ITEM_CHANGE_BOARD_H__

#include "Item.h"

class AttackItemChangeBoard :public Item {
public:
	void action(Controller* self, Controller* target);

private:

};
#endif // !__ATTACK_ITEM_CHANGE_BOARD_H__