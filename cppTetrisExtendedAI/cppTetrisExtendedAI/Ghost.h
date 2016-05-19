#ifndef __GHOST_H__
#define __GHOST_H__
#include "Block.h"
#include "Board.h"

class Ghost:public Block {
public:
	void show() const;
	void gen(const Block& block, const Board& board);
	void findPos(const Block& block, const Board& board);
	bool collision(const Block& block, const Board& board);
private:

};
#endif // !__GHOST_H__