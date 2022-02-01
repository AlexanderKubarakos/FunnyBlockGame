#include "InputManager.h"

namespace client
{
	// flip flop the states of being pressed and unpressed, then reaping gets put in there if press is there for the second frame?
	// get rid of the clear stage, instead at the end of frame remove all released states, leaving PRESSED and REAPTING
	// then in keycallBack if glfw_pressed check if the key is already pressed, if so then set it to repeating, if not then just make it pressed
	void InputManager::keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		KeyState state;
		// translate GLFW state to enum state, repeating calls are disregarded 
		switch(action)
		{
		case GLFW_PRESS:
			state = PRESSED;
			break;
		case GLFW_RELEASE:
			state = RELEASED;
			break;
		default:
			return;
		}

		// this might not be needed 
		if (keyState(key) == REPEAT && state == PRESSED)
		{
			return;
		}

		// Insert state into current key state map
		currentKeyState.insert_or_assign(key, state);
	}

	void InputManager::mouseCallBack(GLFWwindow* window, double xpos, double ypos)
	{
		xoffset = xpos - lastX;
		yoffset = lastY - ypos; // reversed since y-coordinates range from bottom to top
		
		lastX = xpos;
		lastY = ypos;
	}

	glm::vec2 InputManager::mouseOffset()
	{
		return {xoffset, yoffset};
	}

	InputManager::KeyState InputManager::keyState(int key)
	{
		try 
		{
			// Return the current state
			return currentKeyState.at(key);
		}
		catch (const std::out_of_range& oor)
		{
			// if the key doesn't have a state (Not in map) then just return not yet pressed
			return NOSTATE;
		}
	}

	bool InputManager::keyDown(int key)
	{
		auto state = keyState(key);
		return state == PRESSED || state == REPEAT;
	}

	void InputManager::resetKeyState()
	{
		xoffset = 0.0;
		yoffset = 0.0;
		// go through whole map chaning pressed into reapting
		// Clear map for next frame
		auto itertor = currentKeyState.begin();

		while (itertor != currentKeyState.end())
		{
			if (itertor->second == PRESSED)
			{
				itertor->second = REPEAT;
			}

			if (itertor->second == RELEASED)
			{
				itertor->second = NOSTATE;
			}

			itertor++;
		}
	}
}