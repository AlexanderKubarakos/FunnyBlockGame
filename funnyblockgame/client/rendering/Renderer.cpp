#include "Renderer.h"


namespace client
{
	Renderer::Renderer(std::shared_ptr<ChunkManager> chunkManager, std::shared_ptr<RessourceManager> resourceManager)
	{
		this->chunkManager = chunkManager;
		this->resourceManager = resourceManager;

		camera = std::make_unique<Camera>(glm::vec3(0.0f, 0.0f, 2.0f));
		chunkShader = std::make_unique<Shader>("../../../funnyblockgame/client/rendering/shaders/vertexShader.glsl", "../../../funnyblockgame/client/rendering/shaders/fragmentShader.glsl");
		mesher = std::make_unique<Mesher>();

		chunkShader->use(); // No idea how important this line is
		chunkVAO.bind();

		// layout 0, 3 length, float, MIGHT NEED (void*)
		glVertexAttribFormat(0, 3, GL_FLOAT, false, 0); // vertex
		glVertexAttribBinding(0, 0);
		glEnableVertexAttribArray(0);

		// Matricies
		model = glm::mat4(1.0f);

		// projection matrix, view from camera
		projection = glm::mat4(1.0f);
		projection = glm::perspective(glm::radians(45.0f), 800.0f / 800.0f, 0.1f, 1000.0f);

		// view matrix, from camera
		view = camera->GetViewMatrix();
	}

	void Renderer::processCameraMovement()
	{
		if (InputManager::keyState(GLFW_KEY_W) == InputManager::PRESSED || InputManager::keyState(GLFW_KEY_W) == InputManager::REPEAT)
		{
			camera->ProcessKeyboard(FORWARD);
		}

		if (InputManager::keyState(GLFW_KEY_S) == InputManager::PRESSED || InputManager::keyState(GLFW_KEY_S) == InputManager::REPEAT)
		{
			camera->ProcessKeyboard(BACKWARD);
		}

		if (InputManager::keyState(GLFW_KEY_A) == InputManager::PRESSED || InputManager::keyState(GLFW_KEY_A) == InputManager::REPEAT)
		{
			camera->ProcessKeyboard(LEFT);
		}

		if (InputManager::keyState(GLFW_KEY_D) == InputManager::PRESSED || InputManager::keyState(GLFW_KEY_D) == InputManager::REPEAT)
		{
			camera->ProcessKeyboard(RIGHT);
		}

		const auto vec = InputManager::mouseOffset();
		camera->ProcessMouseMovement(vec.x, vec.y);
	}

	void Renderer::renderChunks()
	{
		// TODO: add EBOs
		chunkVAO.bind();

		// Bind chunkShader and send in MVP matrix
		chunkShader->use();
		view = camera->GetViewMatrix();
		finalMatrix = projection * view * model;
		chunkShader->setMatrix4f("finalMatrix", finalMatrix);

		auto chunks = chunkManager->getLoadedChunks();
		for (Chunk& chunk : chunks)
		{
			auto mesh = chunk.getMesh();
			if (mesh == nullptr)
			{
				std::cout << "Mesh is nullptr!\n";
			}
			if (mesh->isDirty())
			{
				mesher->genMesh(chunk, mesh, resourceManager);
			}

			glBindVertexBuffer(0, mesh->getVertexVBO(), 0, sizeof(float) * 3);
			glDrawArrays(GL_TRIANGLES, 0, mesh->length());
		}
	}

	void Renderer::renderItems()
	{

	}

	void Renderer::renderEntites()
	{

	}

	void Renderer::renderModels()
	{
		
	}
}