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
		std::vector<float> upSideVertices;
		std::vector<float> downSideVertices;
		std::vector<float> northSideVertices;
		std::vector<float> southSideVertices;
		std::vector<float> eastSideVertices;
		std::vector<float> westSideVertices;
		std::vector<float> alwaysRenderVertices;

		std::vector<unsigned int> upSideIndices;
		std::vector<unsigned int> downSideIndices;
		std::vector<unsigned int> northSideIndices;
		std::vector<unsigned int> southSideIndices;
		std::vector<unsigned int> eastSideIndices;
		std::vector<unsigned int> westSideIndices;
		std::vector<unsigned int> alwaysRenderIndices;

		void pushVertex(std::vector<float>& vector, glm::vec3& vertex);
		void pushFace(std::vector<float>& vector, glm::vec3& vertex1, glm::vec3& vertex2, glm::vec3& vertex3);
	public:
		Model();
		bool isSideOpaque(Direction direction);
		void setModelToBlockModel();
		int getVertexCount(Direction direction);
		int getIndicesCount(Direction direction);
		const std::vector<float>& getSideVerts(Direction direction);
		const std::vector<unsigned int>& getSideIndices(Direction direction);
	};
}