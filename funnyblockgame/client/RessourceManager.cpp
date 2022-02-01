#include "RessourceManager.h"

namespace client
{
	RessourceManager::RessourceManager()
	{
		
	}

	void RessourceManager::addBlock(int id, BlockData blockData)
	{
		// TODO add an error here for overwriting an allready defined
		// TODO THIS ITERATOR IS SUS AS FUCK
		blockRegistry.insert(blockRegistry.begin()+id, blockData);
	}

	void RessourceManager::addItem()
	{
		
	}

	std::vector<BlockData> RessourceManager::getBlockRegistry()
	{
		return blockRegistry;
	}
}