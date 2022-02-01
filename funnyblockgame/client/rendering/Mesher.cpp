#include "Mesher.h"

namespace client
{
	void Mesher::genMesh(Chunk& chunk, std::shared_ptr<Mesh> mesh , std::shared_ptr<RessourceManager> resourceManager)
	{
		auto blocks = chunk.getBlockArray();
		auto chunkPos = chunk.getPos();
		auto* verts = new float[100000];
		auto* indices = new unsigned int[100000];


		uint32_t totalVertCount = 0; // not vertices aka (x, y, z) is +3 not +1, so each float is +1
		uint32_t indicesCount = 0;

		// TODO: handle rotation, each block should hold a rotation on the x and y axis 0-360, maybe only certin increments aka 0 - 90 - 180 - 270 - 360

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
							addFace(UP, model, totalVertCount, verts, chunkPos, x, y, z);
						}
						if ((y > 0 && !blockMap[blocks->getBlock(x, y - 1, z)->ID].getModel().isSideOpaque(UP)) || y == 0)
						{
							addFace(DOWN, model, totalVertCount, verts, chunkPos, x, y, z);
						}

						if ((x < 15 && !blockMap[blocks->getBlock(x + 1, y, z)->ID].getModel().isSideOpaque(WEST)) || x == 15)
						{
							addFace(EAST, model, totalVertCount, verts, chunkPos, x, y, z);
						}
						if ((x > 0 && !blockMap[blocks->getBlock(x - 1, y, z)->ID].getModel().isSideOpaque(EAST)) || x == 0)
						{
							addFace(WEST, model, totalVertCount, verts, chunkPos, x, y, z);
						}

						// BUG: MIGHT WANT TO CHECK THAT Z IS CORRECT aka (- and + direction)
						if ((z < 15 && !blockMap[blocks->getBlock(x, y, z + 1)->ID].getModel().isSideOpaque(NORTH)) || z == 15)
						{
							addFace(SOUTH, model, totalVertCount, verts, chunkPos, x, y, z);
						}
						if ((z > 0 && !blockMap[blocks->getBlock(x, y, z - 1)->ID].getModel().isSideOpaque(SOUTH)) || z == 0)
						{

							addFace(NORTH, model, totalVertCount, verts, chunkPos, x, y, z);
						}
					}

		std::cout << "Total vertices count: " << totalVertCount << '\n';
		glBindBuffer(GL_ARRAY_BUFFER, mesh->getVertexVBO());
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * totalVertCount, verts, GL_STATIC_DRAW);

		delete[] verts;
		delete[] indices;
		//delete[] texArr;

		mesh->setLength(totalVertCount);
		mesh->clean();
	}

	// do a performance test about how much this function call drops 
	void Mesher::addFace(const Direction direction, Model& model, uint32_t& totalVertCount, float* verts, const glm::vec3& chunkPos, const int x, const int y, const int z)
	{
		auto& side = model.getSideVerts(direction);
		// TODO: apply rotation here
		for (int i = 0, sideVertCount = model.getVertCount(direction); i < sideVertCount; i += 3)
		{
			verts[totalVertCount] = side[i] + x + chunkPos.x * 16;
			verts[totalVertCount + 1] = side[i + 1] + y + chunkPos.y * 256;
			verts[totalVertCount + 2] = side[i + 2] + z + chunkPos.x * 16;
			totalVertCount += 3;
		}
	}
}