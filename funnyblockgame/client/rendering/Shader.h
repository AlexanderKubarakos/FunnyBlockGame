#pragma once

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <glm/fwd.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace client
{
	class Shader
	{
	public:
		unsigned int ID;

		Shader(const char* vertexPath, const char* fragmentPath);

		void use();

		void setBool(const std::string& uniform, bool value) const;
		void setInt(const std::string& uniform, int value) const;
		void setFloat(const std::string& uniform, float value) const;
		void setMatrix4f(const std::string& uniform, glm::mat4& matrix);
	};
}
