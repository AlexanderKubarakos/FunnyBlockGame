#pragma once

#include "ChunkManager.h"

//std
#include "memory"

namespace client
{
	class WorldManager
	{
	private:
		std::shared_ptr<ChunkManager> chunkManager;
		//std::shared_ptr<EntityManager> entityManager;

	public:
		WorldManager();
		std::shared_ptr<ChunkManager> getChunkManager();
	};
}