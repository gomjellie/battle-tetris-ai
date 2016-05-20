#ifndef __GHOST_H__
#define __GHOST_H__
#include "Block.h"
#include "Board.h"

class Ghost:public Block {
public:
	void show(const Block& block) const;
	void gen(const Block& block, const Board& board);
	void findPos(const Block& block, const Board& board);
	void setStartPos(int _y, int _x);
	bool collision(const Block& block, const Board& board);
private:
	COORD startPos;
};
#endif // !__GHOST_H__