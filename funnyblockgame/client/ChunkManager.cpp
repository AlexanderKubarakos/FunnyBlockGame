#include "ChunkManager.h"

namespace client
{
	ChunkManager::ChunkManager()
	{
		
	}

	void ChunkManager::loadChunk(int x, int y, int z)
	{
		// THIS IS WHERE LOADING FROM A FILE WOULD TAKE PLACE
		for (Chunk& chunk : chunks)
		{
			glm::vec3 chunkPos = chunk.getPos();
			if (chunkPos.x == x && chunkPos.y == y && chunkPos.z == z)
			{
				// trying to load an already loaded chunk
				return;
			}
		}

		chunks.emplace_back(Chunk(x, y, z));
	}

	void ChunkManager::unloadChunk(int x, int y, int z)
	{
		// SAVE TO A FILE
	}

	std::vector<Chunk> ChunkManager::getLoadedChunks()
	{
		return chunks;
	}
}