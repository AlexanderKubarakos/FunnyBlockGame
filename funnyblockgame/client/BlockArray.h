#pragma once

#include "Block.h"

// std
#include <array>

namespace client
{
	class BlockArray
	{
		std::array<Block, 65536> blocks;

	public:
		void setBlock(int x, int y, int z, unsigned int id);
		Block* getBlock(int x, int y, int z);
	};
}