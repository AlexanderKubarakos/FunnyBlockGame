#pragma once

#include "../../utils/Direction.h"
#include "glm/glm.hpp"
// std
#include <vector>

namespace client
{
	// a model is static, all changes to its rotation or pos is handled in higher up constructs, this is root0
	class Model
	{
		bool opaqueNorth, opaqueSouth, opaqueEast, opaqueWest, opaqueUp, opaqueDown;
		std::vector<float> upSide;
		std::vector<float> downSide;
		std::vector<float> northSide;
		std::vector<float> southSide;
		std::vector<float> eastSide;
		std::vector<float> westSide;
		std::vector<float> allwaysRender;

		void pushVert(std::vector<float>& vector, glm::vec3& vert);
		void pushFace(std::vector<float>& vector, glm::vec3& vert1, glm::vec3& vert2, glm::vec3& vert3);
	public:
		Model();
		bool isSideOpaque(Direction direction);
		void setModelToBlockModel();
		int getVertCount(Direction direction);
		std::vector<float>& getSideVerts(Direction direction);
	};
}