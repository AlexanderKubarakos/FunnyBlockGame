#include "Window.h"

namespace client
{
	Window::Window(int width, int height, const char* title, GLFWkeyfun keyCallBack, GLFWcursorposfun mouseCallBack)
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		window = glfwCreateWindow(width, height, title, NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			exit(2);
		}
		glfwMakeContextCurrent(window);
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			exit(3);
		}
		glViewport(0, 0, width, height);
		glEnable(GL_DEPTH_TEST);
		//glEnable(GL_CULL_FACE); // TODO: reenable face culling when done testing rendering
		//glEnable(GL_BACK);
		glfwSwapInterval(0);

		int nrAttributes;
		glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
		std::cout << "Maximum # of vertex attributes supported: " << nrAttributes << std::endl;

		glfwSetKeyCallback(window, keyCallBack);
		glfwSetCursorPosCallback(window, mouseCallBack);
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	bool Window::shouldClose()
	{
		return glfwWindowShouldClose(window);
	}

	void Window::pollEvents()
	{
		glfwPollEvents();
	}

	void Window::swapBuffers()
	{
		glfwSwapBuffers(window);
	}

}
