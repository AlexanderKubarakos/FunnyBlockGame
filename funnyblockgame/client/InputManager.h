#pragma once

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

//std
#include <iostream>
#include <stdexcept> 
#include <unordered_map>

namespace client
{
	

	// A global static class to manage input with a GLFW window
	class InputManager
	{
	public:
		// Current state of the frame, NOSTATE is if no action has happened this frame
		enum KeyState
		{
			PRESSED,
			RELEASED,
			REPEAT,
			NOSTATE
		};

	private:
		// Map that holds current KeyStates, is cleared to NOSTATE at end of frame
		static inline std::unordered_map<int, KeyState> currentKeyState {};
		static inline double xoffset { 0.0 };
		static inline double yoffset { 0.0 };
		// TODO: make static floats work
		static inline double lastX { 0.0 };
		static inline double lastY { 0.0 };
	public:
		// Callbacks for GLFW to hook on to
		static void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void mouseCallBack(GLFWwindow* window, double xpos, double ypos);

		// Reset all key states to NOSTATE
		static void resetKeyState();

		// Get key state of given GLFW macro key
		static KeyState keyState(int key);

		// Is a key down this frame
		static bool keyDown(int key);

		// Get current mouse offset on x, y axis
		static glm::vec2 mouseOffset();
	};
}
