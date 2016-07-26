
#include <iostream>
#include <GL\glew.h>
#include "GameManager.h"


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
		displayManager = new DisplayManager(640, 480, "thinEngine GL Test Programme");

		//Init glew using experimental
		glewExperimental = GL_TRUE;
		GLenum status = glewInit();
		if (status == GLEW_OK)	{
			std::cout << "GLEW init : ok\n";
		} else {
			std::cerr << "GLEW init : failed\n";
		}
	} else {

	}
}

//release displaymanager, release glfw
GameManager::~GameManager(){
	delete displayManager;
	glfwTerminate();
}

//Game loop
void GameManager::Start(){
	std::cout << "Game loop is now running.\n";
	//start the game loop;

	while (displayManager->IsWindowOpen()) {
		displayManager->UpdateDisplay();
	}

}

