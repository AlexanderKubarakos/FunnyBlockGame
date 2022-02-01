#include "DeltaTime.h"

namespace client
{
	void DeltaTime::genTime()
	{
		deltaTime = glfwGetTime() - lastFrameTime;
		lastFrameTime = glfwGetTime();
	}

	double DeltaTime::getDeltaTime()
	{
		return deltaTime;
	}
}