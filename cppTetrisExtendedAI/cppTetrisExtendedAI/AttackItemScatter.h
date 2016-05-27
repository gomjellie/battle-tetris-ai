#ifndef __ATTACK_ITEM_SCATTER_H__
#define __ATTACK_ITEM_SCATTER_H__
#include "Item.h"

class AttackItemScatter :public Item{
public :
	void action(Controller* self, Controller* target);
private:

};
#endif // !__ATTACK_ITEM_SCATTER_H__