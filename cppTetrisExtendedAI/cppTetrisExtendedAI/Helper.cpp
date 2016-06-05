#include "Helper.h"
#define STRT_Y 5

void Helper::showItemCost() {

}

void Helper::showGameInfo() {

}

void Helper::showHelp() {

}

void Helper::showHotKeys() {
	printXY(-2, STRT_Y+2, "-> right", Color::CC_GREEN);
	printXY(-2, STRT_Y + 3, "<- left", Color::CC_GREEN);
	printXY(-2, STRT_Y + 4, "top&bot ArrowKey", Color::CC_GREEN);
	printXY(-2, STRT_Y + 5, "also works same", Color::CC_GREEN);
	printXY(-2, STRT_Y + 6, "num1Key : blockAttack", Color::CC_GREEN);
	printXY(-2, STRT_Y + 7, "        : costs 200", Color::CC_GREEN);
	printXY(-2, STRT_Y + 8, "num2Key : swapItem", Color::CC_GREEN);
	printXY(-2, STRT_Y + 9, "        : costs 3000", Color::CC_GREEN);
	printXY(-2, STRT_Y + 10, "p : pause", Color::CC_GREEN);
	printXY(-2, STRT_Y + 11, "r : resume", Color::CC_GREEN);
	printXY(-2, STRT_Y + 14, "esc : suicide", Color::CC_MAGENTA);
	printXY(-2, STRT_Y + 15, "ctrl+c quitGame", Color::CC_MAGENTA);

}