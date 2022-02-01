#include "BlockArray.h"

namespace client
{
	void BlockArray::setBlock(int x, int y, int z, unsigned int id)
	{
		blocks[16 * 256 * z + 16 * y + x].ID = id;
	}

	Block* BlockArray::getBlock(int x, int y, int z)
	{
		// add in exception here for out of bounds
		return &blocks[16 * 256 * z + 16 * y + x];
	}
}