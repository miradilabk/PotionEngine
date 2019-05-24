#pragma once
#include <GLFW/glfw3.h>
class Input
{
public:
	static void Init(GLFWwindow *window);
	static bool GetKeyDown(int keyCode);
	bool GetKeyUp(int keyCode);
private:
	static GLFWwindow* window;
};
