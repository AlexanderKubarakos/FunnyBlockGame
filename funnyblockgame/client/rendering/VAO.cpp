#include "VAO.h"



namespace client
{
	VAO::VAO()
	{
		glGenVertexArrays(1, &ID);
	}

	void VAO::bind()
	{
		glBindVertexArray(ID);
	}

	void VAO::addAttribute(const unsigned int layout, const int numOfElements, GLenum type, GLchar normalize, const int stride, const int offset)
	{
		glVertexAttribPointer(layout, numOfElements, type, normalize, stride, (void*)offset);
		glEnableVertexAttribArray(layout);
	}

}
