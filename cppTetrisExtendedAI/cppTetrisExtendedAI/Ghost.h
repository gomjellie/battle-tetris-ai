#ifndef __GHOST_H__
#define __GHOST_H__
#include "Block.h"
#include "Board.h"

class Ghost:public Block {
public:
	Ghost(Block& block, Board& board);

	void show();
	void gen();
	void findPos();
	void setStartPos(int _y, int _x);
	bool collision();

	Block& getBlockRef();
private:
	COORD startPos;
	Block& block;
	Board& board;
};
#endif // !__GHOST_H__