#include "Model.h"

namespace client
{
	Model::Model()
	{
		opaqueNorth = true;
		opaqueSouth = true;
		opaqueEast = true;
		opaqueWest = true;
		opaqueUp = true;
		opaqueDown = true;
	}

	void Model::setModelToBlockModel()
	{
		glm::vec3 FrontTopRight(0.5f, 0.5f, 0.5f);
		glm::vec3 FrontTopLeft(-0.5f, 0.5f, 0.5f);
		glm::vec3 FrontBottomRight(0.5f, -0.5f, 0.5f);
		glm::vec3 FrontBottomLeft(-0.5f, -0.5f, 0.5f);

		glm::vec3 BackTopRight(0.5f, 0.5f, -0.5f);
		glm::vec3 BackTopLeft(-0.5f, 0.5f, -0.5f);
		glm::vec3 BackBottomRight(0.5f, -0.5f, -0.5f);
		glm::vec3 BackBottomLeft(-0.5f, -0.5f, -0.5f);

		upSideVertices.clear(); upSideIndices.clear();
		downSideVertices.clear(); upSideIndices.clear();
		northSideVertices.clear(); upSideIndices.clear();
		southSideVertices.clear(); upSideIndices.clear();
		eastSideVertices.clear(); upSideIndices.clear();
		westSideVertices.clear(); upSideIndices.clear();
		alwaysRenderVertices.clear(); upSideIndices.clear();

		// Add up side of block                        Indices
		pushVertex(upSideVertices, BackTopRight); // 0
		pushVertex(upSideVertices, BackTopLeft); // 1
		pushVertex(upSideVertices, FrontTopLeft); // 2
		pushVertex(upSideVertices, FrontTopRight); // 3

		upSideIndices.push_back(0);
		upSideIndices.push_back(1);
		upSideIndices.push_back(2);

		upSideIndices.push_back(0);
		upSideIndices.push_back(2);
		upSideIndices.push_back(3);

		// Add bottom side of block
		pushVertex(downSideVertices, BackBottomRight); // 0
		pushVertex(downSideVertices, BackBottomLeft); // 1
		pushVertex(downSideVertices, FrontBottomLeft); // 2
		pushVertex(downSideVertices, FrontBottomRight); // 3

		downSideIndices.push_back(0);
		downSideIndices.push_back(2);
		downSideIndices.push_back(1);

		downSideIndices.push_back(0);
		downSideIndices.push_back(3);
		downSideIndices.push_back(2);

		// Add east side of block
		pushVertex(eastSideVertices, BackTopRight); // 0
		pushVertex(eastSideVertices, BackBottomRight); // 1
		pushVertex(eastSideVertices, FrontBottomRight); // 2
		pushVertex(eastSideVertices, FrontTopRight); // 3

		eastSideIndices.push_back(0);
		eastSideIndices.push_back(2);
		eastSideIndices.push_back(1);

		eastSideIndices.push_back(0);
		eastSideIndices.push_back(3);
		eastSideIndices.push_back(2);

		// Add west side of block
		pushVertex(westSideVertices, BackTopLeft); // 0
		pushVertex(westSideVertices, BackBottomLeft); // 1
		pushVertex(westSideVertices, FrontBottomLeft); // 2
		pushVertex(westSideVertices, FrontTopLeft); // 3

		westSideIndices.push_back(0);
		westSideIndices.push_back(1);
		westSideIndices.push_back(2);

		westSideIndices.push_back(0);
		westSideIndices.push_back(2);
		westSideIndices.push_back(3);

		pushVertex(northSideVertices, BackTopLeft);
		pushVertex(northSideVertices, BackTopRight);
		pushVertex(northSideVertices, BackBottomLeft);
		pushVertex(northSideVertices, BackBottomRight);

		northSideIndices.push_back(0);
		northSideIndices.push_back(1);
		northSideIndices.push_back(3);

		northSideIndices.push_back(0);
		northSideIndices.push_back(3);
		northSideIndices.push_back(2);

		pushVertex(southSideVertices, FrontTopLeft);
		pushVertex(southSideVertices, FrontTopRight);
		pushVertex(southSideVertices, FrontBottomLeft);
		pushVertex(southSideVertices, FrontBottomRight);

		southSideIndices.push_back(0);
		southSideIndices.push_back(3);
		southSideIndices.push_back(1);

		southSideIndices.push_back(0);
		southSideIndices.push_back(2);
		southSideIndices.push_back(3);
	}

	void Model::pushVertex(std::vector<float>& vector, glm::vec3& vertex)
	{
		vector.push_back(vertex.x);
		vector.push_back(vertex.y);
		vector.push_back(vertex.z);
	}

	void Model::pushFace(std::vector<float>& vector, glm::vec3& vertex1, glm::vec3& vertex2, glm::vec3& vertex3)
	{
		vector.push_back(vertex1.x);
		vector.push_back(vertex1.y);
		vector.push_back(vertex1.z);

		vector.push_back(vertex2.x);
		vector.push_back(vertex2.y);
		vector.push_back(vertex2.z);

		vector.push_back(vertex3.x);
		vector.push_back(vertex3.y);
		vector.push_back(vertex3.z);
	}

	bool Model::isSideOpaque(Direction direction)
	{
		switch (direction)
		{
		case UP:
			return opaqueUp;
		case DOWN:
			return opaqueDown;
		case NORTH:
			return opaqueNorth;
		case SOUTH:
			return opaqueSouth;
		case EAST:
			return opaqueEast;
		case WEST:
			return opaqueWest;
		}

		return false;
	}

	int Model::getVertexCount(Direction direction)
	{
		switch (direction)
		{
		case UP:
			return upSideVertices.size();
		case DOWN:
			return downSideVertices.size();
		case NORTH:
			return northSideVertices.size();
		case SOUTH:
			return southSideVertices.size();
		case EAST:
			return eastSideVertices.size();
		case WEST:
			return westSideVertices.size();
		}

		return -1;
	}

	int Model::getIndicesCount(Direction direction)
	{
		switch (direction)
		{
		case UP:
			return upSideIndices.size();
		case DOWN:
			return downSideIndices.size();
		case NORTH:
			return northSideIndices.size();
		case SOUTH:
			return southSideIndices.size();
		case EAST:
			return eastSideIndices.size();
		case WEST:
			return westSideIndices.size();
		}

		return -1;
	}

	const std::vector<float>& Model::getSideVerts(Direction direction)
	{
		switch (direction)
		{
		case UP:
			return upSideVertices;
		case DOWN:
			return downSideVertices;
		case NORTH:
			return northSideVertices;
		case SOUTH:
			return southSideVertices;
		case EAST:
			return eastSideVertices;
		case WEST:
			return westSideVertices;
		}

		return upSideVertices;
	}

	const std::vector<unsigned int>& Model::getSideIndices(Direction direction)
	{
		switch (direction)
		{
		case UP:
			return upSideIndices;
		case DOWN:
			return downSideIndices;
		case NORTH:
			return northSideIndices;
		case SOUTH:
			return southSideIndices;
		case EAST:
			return eastSideIndices;
		case WEST:
			return westSideIndices;
		}

		return upSideIndices;
	}
}