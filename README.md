# cppTetrisExtendedAI

Human vs Artificial Inteligence game runs on windows

how to run this software :find .sln file and open -> ctrl + F5  OR find .exe file and double click


2016 0522 cppTetrisExtendedAI

현재 지원 기능 

- 블록별 색깔 설정

- 음악재생(냔캣) 

- 다음 블록표시

- 고스트블록 표시

- 컴퓨터 인공지능 플레이

- 쓰레드 때문에 생기는 랜덤문제 해결함(srand함수가 thread safe하지 않음)

- 쓰레드 때문에 생기는 화면 깨지는 현상 해결함

- 죽으면 종료 (방법이 더러움 종료되면서 뜨는 쓰레드 오류가 있음)




status now

- block color

- play music(nyan cat) 

- display next block

- display ghost block

- computer Artificial Inteligence plays game on the right side

- fixed random problem due to srand(srand is not thread safe)

- fixed scattering pixel problem (mutex lock)

- game ends when it die (dirty way)



추가할 기능

- 아이템 클래스




TODO::

- make item class 

