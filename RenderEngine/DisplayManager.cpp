#include <iostream>
#include "DisplayManager.h"

//constructor: create a window
//arg1,arg2 window dimension, 
//arg3 window title
DisplayManager::DisplayManager(int width, int height, const std::string& title){

	//1. Create Opengl window using GLFW
	m_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

	if (m_window != NULL){
		std::cout << "window created successfully" << std::endl;

		//2.set context
		glfwMakeContextCurrent(m_window);

		//3.setViewport 
		glViewport(0, 0, width, height);

		//4.Enable vsync
		glfwSwapInterval(1);
	}
	else{
		std::cerr << "ERROR:failed to create window" << std::endl;
	}
	m_aspect = (float)width / (float)height;
}
DisplayManager::~DisplayManager(){
	glfwDestroyWindow(m_window);
}

bool DisplayManager::IsWindowOpen(){
	return !glfwWindowShouldClose(m_window);
}
void DisplayManager::UpdateDisplay(){
	
	glfwPollEvents();
	glfwSwapBuffers(m_window);

}
float& DisplayManager::GetAspect(){
	return m_aspect;
}