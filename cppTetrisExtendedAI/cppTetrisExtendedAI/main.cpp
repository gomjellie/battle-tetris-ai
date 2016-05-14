#include <iostream>
#include "Controller.h"
#include "AiController.h"

/*20150318 Soongsil Univ. Dept. Of SmartSystemsSoftware Oh Inkyu
gomjellie@gmail.com
gomjellie@naver.com
License follows MIT License
2016년 5월 오인규에 의해 작성됨
*/
/*The MIT License(MIT)

Copyright(c) 2016 Jacky Vincent

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.*/

#include <thread>

void thread1() {
	Controller humGame;
	Sleep(1000);
	humGame.gameInit();

	humGame.playGame();
}
void thread2() {
	AiController* comGame= new AiController();

	comGame->gameInit();
	Sleep(1000);
	comGame->playGame();
}
	
int main(void) {
	Sound::playNyanNyanSong();
	//Controller* humGame = new Controller();
	std::thread t1(thread1);
	std::thread t2(thread2);
	//humGame->gameInit();
	//humGame->playGame();
	t1.join();
	t2.join();


	//AiController comGame;

	//comGame.gameInit();
	//comGame.playGame();


	//std::thread t1(thread1);
	
	//t1.join();

	return 0;
}