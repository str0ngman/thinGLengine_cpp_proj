#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <string>
#include <GLFW/glfw3.h>

class DisplayManager{
public:
	DisplayManager(int,int,const std::string& title = "thinEngine window");
	virtual ~DisplayManager();
	
	bool IsWindowOpen();
	void UpdateDisplay();
private:
	GLFWwindow* m_window;
};

#endif //DISPLAY_MANAGER_H