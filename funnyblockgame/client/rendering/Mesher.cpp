#include "Mesher.h"

namespace client
{
	void Mesher::genMesh(Chunk& chunk, std::shared_ptr<Mesh> mesh , std::shared_ptr<RessourceManager> resourceManager)
	{
		auto blocks = chunk.getBlockArray();
		auto chunkPos = chunk.getPos();
		auto* verts = new float[1000000];
		auto* indices = new unsigned int[1000000];

		uint32_t verticesCount = 0; // not vertices aka (x, y, z) is +3 not +1, so each float is +1
		uint32_t indicesCount = 0;

		// TODO: handle rotation, each block should hold a rotation on the x and y axis 0-360, maybe only certain increments aka 0 - 90 - 180 - 270 - 360

		auto blockMap = resourceManager->getBlockRegistry();
		for (int_fast16_t z = 0; z < 16; z++)
				for (int_fast16_t y = 0; y < 256; y++)
					for (int_fast16_t x = 0; x < 16; x++)
					{
						// TODO: might be worth checking what sides we need to render then ad the sides all at the same time
						auto block = blocks->getBlock(x, y, z);

						// TODO: find a way to cache models to reduce indirection

						BlockData& blockData = blockMap[block->ID];
						Model& model = blockData.getModel();
						if ((y < 255 && !blockMap[blocks->getBlock(x, y + 1, z)->ID].getModel().isSideOpaque(DOWN)) || y == 255)
						{
							addFace(UP, model, verticesCount, indicesCount, verts, indices, chunkPos, x, y, z);
						}
						if ((y > 0 && !blockMap[blocks->getBlock(x, y - 1, z)->ID].getModel().isSideOpaque(UP)) || y == 0)
						{
							addFace(DOWN, model, verticesCount, indicesCount, verts, indices, chunkPos, x, y, z);
						}

						if ((x < 15 && !blockMap[blocks->getBlock(x + 1, y, z)->ID].getModel().isSideOpaque(WEST)) || x == 15)
						{
							addFace(EAST, model, verticesCount, indicesCount, verts, indices, chunkPos, x, y, z);
						}
						if ((x > 0 && !blockMap[blocks->getBlock(x - 1, y, z)->ID].getModel().isSideOpaque(EAST)) || x == 0)
						{
							addFace(WEST, model, verticesCount, indicesCount, verts, indices, chunkPos, x, y, z);
						}

						// BUG: MIGHT WANT TO CHECK THAT Z IS CORRECT aka (- and + direction)
						if ((z < 15 && !blockMap[blocks->getBlock(x, y, z + 1)->ID].getModel().isSideOpaque(NORTH)) || z == 15)
						{
							addFace(SOUTH, model, verticesCount, indicesCount, verts, indices, chunkPos, x, y, z);
						}
						if ((z > 0 && !blockMap[blocks->getBlock(x, y, z - 1)->ID].getModel().isSideOpaque(SOUTH)) || z == 0)
						{

							addFace(NORTH, model, verticesCount, indicesCount, verts, indices, chunkPos, x, y, z);
						}
					}

		std::cout << "Total vertices count: " << verticesCount/3 << '\n';
		std::cout << "Total indices count: " << indicesCount << '\n';
		std::cout << "Total triangle count: " << indicesCount / 3 << '\n';
		glBindBuffer(GL_ARRAY_BUFFER, mesh->getVertexVBO());
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * verticesCount, verts, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->getEBO());
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indicesCount, indices, GL_STATIC_DRAW);
		
		delete[] verts;
		delete[] indices;
		//delete[] texArr;

		mesh->setLength(indicesCount);
		mesh->clean();
	}

	// do a performance test about how much this function call drops 
	void Mesher::addFace(const Direction direction, Model& model, uint32_t& verticesCount, uint32_t& indicesCount, float* verts, unsigned int* indices, const glm::vec3& chunkPos, const int x, const int y, const int z)
	{
		auto& sideVertices = model.getSideVerts(direction);
		auto& sideIndices = model.getSideIndices(direction);
		uint32_t indiceOffset = verticesCount/3;
		// TODO: apply rotation here
		// Add are vertices to the array, each is three elements aka we add x, y, z

		for (int i = 0, sideVertexCount = model.getVertexCount(direction); i < sideVertexCount; i += 3)
		{
			verts[verticesCount] = sideVertices[i] + x + chunkPos.x * 16;
			verts[verticesCount + 1] = sideVertices[i + 1] + y + chunkPos.y * 256;
			verts[verticesCount + 2] = sideVertices[i + 2] + z + chunkPos.z * 16;
			verticesCount += 3;
		}

		// Push indices in batches of 3 since 3 make up one face
		// TODO: add assertion that the count is (count % 3 == 0)
		for (int i = 0, sideIndiceCount = model.getIndicesCount(direction); i < sideIndiceCount; i+=3)
		{
			indices[indicesCount] = sideIndices[i] + indiceOffset;
			indices[indicesCount + 1] = sideIndices[i + 1] + indiceOffset;
			indices[indicesCount + 2] = sideIndices[i + 2] + indiceOffset;
			indicesCount += 3;
		}
	}
}