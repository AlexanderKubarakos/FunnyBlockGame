#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace client
{
	class Window
	{
	public:
		GLFWwindow* window;

		Window(int width, int height, const char* title, GLFWkeyfun keyCallBack, GLFWcursorposfun mouseCallBack);
		~Window();
		bool shouldClose();
		void pollEvents();
		void swapBuffers();
	};
}