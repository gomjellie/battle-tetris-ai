#ifndef __HELPER_H__
#define __HELPER_H__
#include "Interface.h"

class Helper :public Interface{
public:
	void showItemCost();
	void showHotKeys();
	void showHelp();
	void showGameInfo();
private:

};

#endif // !__HELPER_H__