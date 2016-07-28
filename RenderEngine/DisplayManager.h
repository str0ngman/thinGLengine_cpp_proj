#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <string>
#include <GLFW/glfw3.h>

class DisplayManager{
public:
	DisplayManager(int w,int h,const std::string& title = "thinEngine window");
	virtual ~DisplayManager();
	
	bool IsWindowOpen();
	void UpdateDisplay();
	float& GetAspect();
private:
	GLFWwindow* m_window;
	float m_aspect;
};

#endif //DISPLAY_MANAGER_H