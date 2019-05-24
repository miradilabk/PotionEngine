#include "Input.h"

GLFWwindow* Input::window = NULL;

void Input::Init(GLFWwindow * window)
{
	Input::window = window;
}

bool Input::GetKeyDown(int keyCode)
{
	return glfwGetKey(window, keyCode) == GLFW_PRESS;
}

bool Input::GetKeyUp(int keyCode) {
	return glfwGetKey(window, keyCode) == GLFW_RELEASE;
}
