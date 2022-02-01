#include "Block.h"

namespace client
{
	// Every block needs a reference to a blockstateholder, for later
	Block::Block(unsigned int blockID)
	{
		ID = blockID;
	}

	// have this also store it's required block state here, and then have it send it over with the blockdata interogations, meaning the individual blocks
	// store the data that effects them and the block data of their block can handle the specfic actions that come from the changed data

	Block::Block()
	{
		ID = 0;
	}
}