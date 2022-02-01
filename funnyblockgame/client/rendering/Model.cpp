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

		upSide.clear();
		downSide.clear();
		northSide.clear();
		southSide.clear();
		eastSide.clear();
		westSide.clear();
		allwaysRender.clear();

		// have all these verts in an array and then just push them with an iterator if needed

		// TODO: stop using push face and rather pushVert and pushIndicie
		pushFace(upSide, BackTopRight, BackTopLeft, FrontTopLeft);
		pushFace(upSide, BackTopRight, FrontTopLeft, FrontTopRight);
	}

	void Model::pushVert(std::vector<float>& vector, glm::vec3& vert)
	{
		vector.push_back(vert.x);
		vector.push_back(vert.y);
		vector.push_back(vert.z);
	}

	void Model::pushFace(std::vector<float>& vector, glm::vec3& vert1, glm::vec3& vert2, glm::vec3& vert3)
	{
		vector.push_back(vert1.x);
		vector.push_back(vert1.y);
		vector.push_back(vert1.z);

		vector.push_back(vert2.x);
		vector.push_back(vert2.y);
		vector.push_back(vert2.z);

		vector.push_back(vert3.x);
		vector.push_back(vert3.y);
		vector.push_back(vert3.z);
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

	int Model::getVertCount(Direction direction)
	{
		switch (direction)
		{
		case UP:
			return upSide.size();
		case DOWN:
			return downSide.size();
		case NORTH:
			return northSide.size();
		case SOUTH:
			return southSide.size();
		case EAST:
			return eastSide.size();
		case WEST:
			return westSide.size();
		}

		return -1;
	}

	std::vector<float>& Model::getSideVerts(Direction direction)
	{
		switch (direction)
		{
		case UP:
			return upSide;
		case DOWN:
			return downSide;
		case NORTH:
			return northSide;
		case SOUTH:
			return southSide;
		case EAST:
			return eastSide;
		case WEST:
			return westSide;
		}

		return upSide;
	}
}