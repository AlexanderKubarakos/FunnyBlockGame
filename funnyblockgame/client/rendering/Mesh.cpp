#include "Mesh.h"

namespace client
{
	// Might be worth doing this in render and haing viusal chunks
	// 4 - 16 visual chunks per chunk
	Mesh::Mesh()
	{
		std::cout << "Making mesh\n";
		glGenBuffers(1, &vertVBO);
		glGenBuffers(1, &texVBO);
		glGenBuffers(1, &EBO);
	}

	Mesh::~Mesh()
	{
		std::cout << "Destroying mesh\n";
		glDeleteBuffers(1, &vertVBO);
		glDeleteBuffers(1, &texVBO);
		glDeleteBuffers(1, &EBO);
	}

	unsigned int Mesh::getVertexVBO()
	{
		return vertVBO;
	}

	unsigned int Mesh::getTextureVBO()
	{
		return texVBO;
	}

	unsigned int Mesh::getEBO()
	{
		return EBO;
	}


	void Mesh::makeDirty()
	{
		dirty = true;
	}

	bool Mesh::isDirty()
	{
		return dirty;
	}

	void Mesh::clean()
	{
		dirty = false;
	}

	// DEPERCATED
	void Mesh::regenMesh()
	{
		
	}

	void Mesh::bindVBOs()
	{
		glBindVertexBuffer(0, vertVBO, 0, sizeof(float) * 3);
		glBindVertexBuffer(1, texVBO, 0, sizeof(float) * 2);
	}

	unsigned int Mesh::length()
	{
		return lengthData;
	}

	void Mesh::setLength(int l)
	{
		lengthData = l;
	}
}