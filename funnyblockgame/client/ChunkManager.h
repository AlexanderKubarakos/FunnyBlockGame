#pragma once

#include "Chunk.h"

// std
#include <vector>

namespace client
{
	class ChunkManager
	{
		std::vector<Chunk> chunks;
		// FOR RENDER // generate on thread and then iterate through threads on main linking to vbo
	public:
		ChunkManager();
		void loadChunk(int x, int y, int z);
		void unloadChunk(int x, int y, int z);
		std::vector<Chunk> getLoadedChunks();
	};
}
