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
	int speed;//�ʱ�ȭ ����ߵ�!! ��� ������ �𸣰���
};
#endif // !__AI_CONTROLLER_H__