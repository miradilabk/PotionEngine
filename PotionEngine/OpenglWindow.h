#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
class OpenglWindow
{
public:
	static float deltaTime;
	GLFWwindow* Init(int width, int height);
	void Start();
private:
	GLFWwindow* window;
	virtual void Update() = 0;
};

