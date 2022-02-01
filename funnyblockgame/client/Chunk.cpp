#include "Chunk.h"

namespace client
{
	Chunk::Chunk(int x, int y, int z)
	{
		blockArray = std::make_shared<BlockArray>();
		mesh = std::make_shared<Mesh>();
		pos = glm::vec3(x, y, z);
		for (int x = 0; x < 16; x++)
			for (int z = 0; z < 16; z++)
				for (int y = 0; y < 256; y++)
				{
					blockArray->setBlock(x, y, z, 1);
				}
	}

	Block* Chunk::BlockAt(int x, int y, int z)
	{
		return blockArray->getBlock(x, y, z);
	}

	glm::vec3 Chunk::getPos()
	{
		return pos;
	}

	std::shared_ptr<Mesh> Chunk::getMesh()
	{
		return mesh;
	}

	std::shared_ptr<BlockArray> Chunk::getBlockArray()
	{
		return blockArray;
	}
}