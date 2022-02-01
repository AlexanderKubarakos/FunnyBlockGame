#pragma once

#include "glad/glad.h"

namespace client
{
	class VAO
	{
		unsigned int ID;

	public:
		VAO();

		void bind();
		void addAttribute(const unsigned int layout, const int numOfElements, GLenum type, GLchar normalize, const int stride, const int offset);
	};
}