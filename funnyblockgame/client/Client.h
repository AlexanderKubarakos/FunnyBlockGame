#pragma once

// client
#include "Window.h"
#include "WorldManager.h"
#include "RessourceManager.h"
#include "rendering/Renderer.h"
#include "InputManager.h"
#include "../utils/DeltaTime.h"

// std
#include "memory"
#include "unordered_map"

namespace client
{
	class Client
	{
		// window   
		// render, should the window own that?

		// chunk manager, loaded and loading chunk lists, we can generate the vertex and texture data multi threaded
		// but binding vao needs to be on main thread since opengl is state based

		// Might be worth making it so that there is no single player-just a server running in the background - not for now, too hard

		// render, chunk manager, ressource manager

		void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
		void mouseCallBack(GLFWwindow* window, double xpos, double ypos);

		std::unique_ptr<Window> window; // this might need to copyable aka shared_ptr
		std::unique_ptr<InputManager> inputManager;

	public:
		Client();
		int initialization();
		void run();

	};
}