#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include "Controller.h"
#include "AiController.h"

/*20150318 Soongsil Univ. Dept. Of SmartSystemsSoftware Oh Inkyu
gomjellie@gmail.com
gomjellie@naver.com
https://github.com/gomjellie
License follows MIT License
2016년 5월 오인규에 의해 작성됨

#include <thread>

int wmain(void) {
	//Sound::playNyanNyanSong();


	AiController comController;
	Controller humController;

	
	std::thread computerThread([&]() {
		comController.setOpposite(&humController);
		comController.gameInit((unsigned int)time(NULL) ^ 0b101010101);
		comController.playGame();
	});
	std::thread humanThread([&]() {
		humController.setOpposite(&comController);
		humController.gameInit((unsigned int)time(NULL) ^ 0b11111111);
		humController.playGame();
	});
	
	humanThread.join();
	computerThread.join();
	
	return 0;
}
