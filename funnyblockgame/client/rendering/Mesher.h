#pragma once

#include "../Chunk.h"
#include "Mesh.h"
#include "../RessourceManager.h"

// std
#include "memory"

namespace client
{
	class Mesher
	{
		void addFace(const Direction direction, Model& model, uint32_t& totalVertCount, float* verts, const glm::vec3& chunkPos, const int x, const int y, const int z);
	public:
		void genMesh(Chunk& chunk, std::shared_ptr<Mesh> mesh, std::shared_ptr<RessourceManager> resourceManager);
	};
}