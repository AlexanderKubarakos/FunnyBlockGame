#pragma once

#include "BlockData.h"

// std
#include "vector"

namespace client
{
	// Resource Manger manages lists of blocks, items and entites so that they can be referenced from one place
	class RessourceManager
	{
		std::vector<BlockData> blockRegistry;

	public:
		RessourceManager();
		void addBlock(int id, BlockData blockData);
		void addItem();
		BlockData* getBlockData(unsigned int id);
		std::vector<BlockData> getBlockRegistry();
	};
}