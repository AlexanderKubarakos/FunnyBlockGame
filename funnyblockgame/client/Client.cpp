#include "Client.h"

namespace client
{
	// add an initialization phase
	Client::Client()
	{
		inputManager = std::make_unique<InputManager>();
		window = std::make_unique<Window>(800, 800, "A Title", &InputManager::keyCallBack, &InputManager::mouseCallBack);
	}

	int Client::initialization()
	{
		return 0;
	}

	void Client::run()
	{
		auto resourceManager = std::make_shared<RessourceManager>();
		resourceManager->addBlock(0, { "air", true}); // have path to data file here, right now all blocks are the same xd
		resourceManager->addBlock(1, { "stone", false});
		resourceManager->addBlock(2, { "dirt", false});

		auto worldManger = std::make_shared<WorldManager>();
		auto chunkManager = worldManger->getChunkManager();
		chunkManager->loadChunk(0, 0, 0);
		chunkManager->loadChunk(1, 0, 0);
		//chunkManager->loadChunk(2, 0, 0);
		//chunkManager->loadChunk(3, 0, 0);

		// Might want to make render near the top
		auto renderer = std::make_unique<Renderer>(chunkManager, resourceManager);

		// make this a render thing
		bool wireframe = false;

		while (!window->shouldClose())
		{
			// Frame Setup
			DeltaTime::genTime();
			window->pollEvents();

			if (InputManager::keyState(GLFW_KEY_X) == InputManager::PRESSED)
			{
				wireframe = !wireframe;
			}

			if (wireframe)
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			}
			else
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			}

			//Logic goes here

			// Rendering
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			// Ressource manager should be static

			// chunk manager make sure to keep track of chunks updates done (for debug)

			renderer->processCameraMovement();
			renderer->renderChunks();

			// worldManager we will load worlds through this, world manager soely manages world data,
			// will all so manage ticking of tile entities
			// chunk manger.tryLoad()
			// SPLIT CHUNKS INTO 16x16x16 visible chunks, if the chunk is all air then disregard it

			// Swap back and front buffers
			window->swapBuffers();
			// Frame cleanup
			InputManager::resetKeyState();
		}
	}
}
