#pragma once

#include "../../includes/GLFW/glfw3.h"

namespace client
{
	class DeltaTime
	{
		static inline double lastFrameTime = 0.0;
		static inline double deltaTime = 0.0;
	public:
		static void genTime();
		static double getDeltaTime();
	};
}