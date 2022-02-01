#pragma once

#include "../utils/Direction.h"
#include "glm/glm.hpp"
#include "rendering/Model.h"
// std
#include <string>

namespace client
{
	class BlockData
	{
		// CREATE A VECTOR OF BLOCKSTATES<T>, ALL SO SUPER IMPORTANT TODO: IN BLOCK DATA YOU MUST DEFINE HOW YOUR BLOCK SHOULD BE RENDERED, somehow...
		// aka plants have a short age, age = 0 is just planted, age = 1 is one growth cycle
		// https://mcforge.readthedocs.io/en/latest/blocks/states/
		// texture(s), maybe isModel, allow to define vertexes for model

		// Add a way to change the quad that gets pushed on to the mesh depending on the state, can all be loaded from the resource location


		// MEGA TODO:
		// KEEP AN ARRAY OF BLOCK MESHES, THEN JUST HAVE THE ABILTY TO QUERY THE BLOCK MESH FOR THE MESHER TO USE

		std::string name;
		Model model;
		// maybe have a block mesh class, might slow performance

		// might want ID in here, don't know
	public:
		BlockData(const char* name, bool makeFullyTransparent);
		std::string getName();
		Model& getModel();
	};
}