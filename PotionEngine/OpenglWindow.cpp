#include "OpenglWindow.h"
#include <iostream>
using namespace std;

float OpenglWindow::deltaTime = 0;
float now = 0, lastTime = 0;
void initGLFW() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
}

bool initGlad() {
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cout << "failed to init GLAD" << endl;
		system("pause");
		return false;
	}
	return true;
}

GLFWwindow * OpenglWindow::Init(int width, int height)
{
	initGLFW();
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL) {
		cout << "failed to create window" << endl;
		system("pause");
		glfwTerminate();
		return NULL;
	}
	glfwInit();
	glfwMakeContextCurrent(window);
	this->window = window;

	if (!initGlad()) return NULL;

	glViewport(0, 0, width, height);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_CULL_FACE);

	return window;
}

void OpenglWindow::Start()
{
	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		lastTime = now;
		now = glfwGetTime();
		deltaTime = now - lastTime;
		Update();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
}
