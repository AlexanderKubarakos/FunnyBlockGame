#pragma once

#include "glad/glad.h"

// std
#include <iostream>
#include <memory>

namespace client
{
	class Mesh
	{
		// Doesn't generate it's self only stores
		unsigned int vertVBO, texVBO, EBO; // the vbos that hold the data for the mesh
		bool dirty = true; // if a mesh needs to be regend
		unsigned int lengthData;
	public:
		Mesh();
		~Mesh();
		// WAIT, regen vbos might not be nececary, just bind the vbo and then gen mesh and push in mesh gener
		unsigned int getVertexVBO();
		unsigned int getTextureVBO();
		unsigned int getEBO();
		void makeDirty(); // set the mesh as dirty
		bool isDirty(); // get dirty bool
		void clean();
		void regenMesh();
		void bindVBOs();
		unsigned int length();
		void setLength(int l);
	};
}