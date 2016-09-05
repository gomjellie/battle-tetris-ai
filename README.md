# cppTetrisExtendedAI

Human vs Artificial Inteligence game runs on windows

#how to run this software 
```js
 1. find .sln file
 2. open it 
 3. press `ctrl + F5`  OR `double click .exe`
```

#현재 지원 기능 

```js
- 블록별 색깔 설정

- 음악재생(냔캣) 

- 다음 블록표시

- 고스트블록 표시

- 컴퓨터 인공지능 플레이

- 쓰레드 때문에 생기는 랜덤문제 해결함(srand함수가 thread safe하지 않음)

- 쓰레드 때문에 생기는 화면 깨지는 현상 해결함

- 죽으면 종료

- 아이템 추가(1번키 누르면 상대방 다음 블록이 안좋은 모양으로 바뀜)

- 아이템 추가(2번키 누르면 상대방과 보드를 바꾼다)

```




#current status

```js
- block color

- play music(nyan cat) 

- display next block

- display ghost block

- computer Artificial Inteligence plays game on the right side

- fixed random problem due to srand(srand is not thread safe)

- fixed scattering pixel problem (mutex lock)

- game ends when it die (dirty way)

- Item added ( press keyboard button 1 -> change opposite player's next block(8thblock) )

- Item BoardSwap ( press keyboard 2 -> swap board )

```

#추가할 기능

- `아이템 클래스들`


# TODO::

- make `item class`

