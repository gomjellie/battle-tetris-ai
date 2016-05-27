#ifndef __ITEM_H__
#define __ITEM_H__

class Controller;

class Item {
public:
	virtual void action(Controller* self, Controller* target)=0;
};
#endif // !__ITEM_H__