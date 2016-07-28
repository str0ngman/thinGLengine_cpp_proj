
#include <iostream>
#include <GL\glew.h>
#include "GameManager.h"
#include "../RenderEngine/Loader.h"
#include "../RenderEngine/Renderer.h"
#include "../Models/RawModel.h"
#include "../Models/TexturedModel.h"
#include "../Textures/ModelTexture.h"
#include "../Shaders/StaticShader.h"
#include "../Entities/Entity.h"
#include "../Entities/Camera.h"


//init glfw and glew
GameManager::GameManager(){
	//Initialize GLFW
	if (glfwInit()) {
		std::cout << "GLFW init : OK\n";

		//set minimum Opengl version and options
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

		//Create the the display manager(pointers must be deleted
		m_displayManager = new DisplayManager(640, 480, "thinEngine GL Test Programme");

		//Init glew using experimental
		glewExperimental = GL_TRUE;
		GLenum status = glewInit();
		if (status == GLEW_OK)	{
			std::cout << "GLEW init : ok\n";
		}
		else {
			std::cerr << "GLEW init : failed\n";
		}
	}
	else {

	}
}

//release displaymanager, release glfw
GameManager::~GameManager(){
	delete m_displayManager;
	glfwTerminate();
}

//Game loop
void GameManager::Start(){

	std::cout << "Game loop is now running.\n";

	Loader loader;
	StaticShader staticShader("basicShader");

	Renderer renderer(staticShader, m_displayManager->GetAspect());

	float vertices[] = {
		-0.5f, 0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, -0.5f,
		0.5f, 0.5f, -0.5f,

		-0.5f, 0.5f, 0.5f,
		-0.5f, -0.5f, 0.5f,
		0.5f, -0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,

		0.5f, 0.5f, -0.5f,
		0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,

		-0.5f, 0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f, 0.5f,
		-0.5f, 0.5f, 0.5f,

		-0.5f, 0.5f, 0.5f,
		-0.5f, 0.5f, -0.5f,
		0.5f, 0.5f, -0.5f,
		0.5f, 0.5f, 0.5f,

		-0.5f, -0.5f, 0.5f,
		-0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, 0.5f
	};

	int indices[] = {
		0, 1, 3,
		3, 1, 2,
		4, 5, 7,
		7, 5, 6,
		8, 9, 11,
		11, 9, 10,
		12, 13, 15,
		15, 13, 14,
		16, 17, 19,
		19, 17, 18,
		20, 21, 23,
		23, 21, 22
	};

	float texCoords[] = {
		0, 0,
		0, 1,
		1, 1,
		1, 0,
		0, 0,
		0, 1,
		1, 1,
		1, 0,
		0, 0,
		0, 1,
		1, 1,
		1, 0,
		0, 0,
		0, 1,
		1, 1,
		1, 0,
		0, 0,
		0, 1,
		1, 1,
		1, 0,
		0, 0,
		0, 1,
		1, 1,
		1, 0
	};

	

	//RawModel model = loader.LoadToVAO(vertices, sizeof(vertices) / sizeof(vertices[0]));
	RawModel model = loader.LoadToVAO(vertices, indices, texCoords,
		sizeof(vertices) / sizeof(vertices[0]),
		sizeof(indices) / sizeof(indices[0]),
		sizeof(texCoords) / sizeof(texCoords[0]));

	ModelTexture texture(loader.LoadTexture("image"));
	TexturedModel texturedModel(model, texture);

	Entity entity(texturedModel,
		glm::vec3(0, 0, -5), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1)
		);

	Camera camera;

	float x = -0.001f;
	//start the game loop
	while (m_displayManager->IsWindowOpen()) {

		//Rotate Cube
		entity.ChangeRotation(glm::vec3(0.001f, 0.001f, 0.001f));
		camera.Move();
		renderer.Prepare();
		staticShader.Use();
		staticShader.LoadViewMatrix(camera);

		renderer.Render(entity, staticShader);
		staticShader.UnUse();

		m_displayManager->UpdateDisplay();
	}
}

