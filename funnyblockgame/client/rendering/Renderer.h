#pragma once
#include "../ChunkManager.h"
#include "Shader.h"
#include "Camera.h"
#include "../InputManager.h"
#include "../../utils/DeltaTime.h"
#include "Mesher.h"
#include "VAO.h"

// std
#include "memory"

namespace client
{
	class Renderer
	{
		std::shared_ptr<ChunkManager> chunkManager;
		std::shared_ptr<RessourceManager> resourceManager;

		glm::mat4 model;
		glm::mat4 view;
		glm::mat4 projection;
		glm::mat4 finalMatrix;
		VAO chunkVAO;
		std::unique_ptr<Camera> camera;
		std::unique_ptr<Shader> chunkShader;
		std::unique_ptr<Mesher> mesher;

	public:
		Renderer(std::shared_ptr<ChunkManager> chunkManager, std::shared_ptr<RessourceManager> resourceManager);
		void processCameraMovement();
		void renderChunks();
		void renderItems();
		void renderEntites();
		void renderModels();
		// have the ability to pass in fov and stuff to reconstruct the projection matrix
		//void setProjectionMatrix();
	};
}