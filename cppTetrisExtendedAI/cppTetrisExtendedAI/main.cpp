#include <iostream>
#include "Controller.h"
#include "AiController.h"

//20150318 Soongsil Univ. Dept. Of SmartSystemsSoftware Oh Inkyu 

int main(void) {
	//Controller game;
	AiController comGame;

	comGame.gameInit();
	comGame.playGame();
	//game.gameInit();
	//game.playGame();

	return 0;
}