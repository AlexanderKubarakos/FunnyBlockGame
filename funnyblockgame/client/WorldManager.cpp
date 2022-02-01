#include "WorldManager.h"

namespace client
{
	WorldManager::WorldManager()
	{
		chunkManager = std::make_shared<ChunkManager>();
	}

	std::shared_ptr<ChunkManager> WorldManager::getChunkManager()
	{
		return chunkManager;
	}
}
