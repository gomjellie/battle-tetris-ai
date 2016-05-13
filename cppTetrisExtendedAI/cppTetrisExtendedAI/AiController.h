#ifndef __AI_CONTROLLER_H__
#define __AI_CONTROLLER_H__
#include "Controller.h"

typedef struct _PosAi {
	int x, y;
	int rotation;
	int score;
}PosAi;

class AiController :public Controller {
public:
	void moveToBestPos();
	void animationEffect(const double _time);
	PosAi findIdealPosition();
	int getIdealPoint();
	int getClearLinePoint();
	int getAdjacentPoint();
	int getMinusPoint();

private:
	PosAi posAi;
	int speed;//초기화 해줘야됨!! 어디에 넣을지 모르겠음
};
#endif // !__AI_CONTROLLER_H__