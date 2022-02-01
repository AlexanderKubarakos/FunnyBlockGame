#pragma once

#include "glm/glm.hpp"
#include "Block.h"
#include "rendering/Mesh.h"
#include "BlockArray.h"

// std
#include <array>

namespace client
{
	// Maybe make this "Client Chunk" so that when a server exists, it sends a server chunk
	// which is the same but without a mesh object, then we gen a client chunk with the server chunk
	class Chunk
	{
		
		// Chunk cords, [x, y, z]
		glm::vec3 pos;
		// Holds all block data with helper function
		std::shared_ptr<BlockArray> blockArray;
		// The visual mesh used for rendering
		std::shared_ptr<Mesh> mesh;
	public:
		// Create a new chunk with id [x, y, z]
		Chunk(int x, int y, int z);
		// Returns a reference to the block at [x, y, z] in chunk 0, 0, 0 -> 15, 255 , 15
		Block* BlockAt(int x, int y, int z); // this might be the right pointer return type
		// Returns chunk cords
		glm::vec3 getPos();
		// Returns reference to chunk mesh
		std::shared_ptr<Mesh> getMesh();
		// Returns the array of blocks in chunk
		std::shared_ptr<BlockArray> getBlockArray();
	};
}