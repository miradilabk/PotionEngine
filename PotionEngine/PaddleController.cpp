#include "PaddleController.h"
#include "Input.h"
#include "GameWindow.h"

float speed = 500;

void PaddleController::Update()
{
	if (Input::GetKeyDown(GLFW_KEY_LEFT) || Input::GetKeyDown(GLFW_KEY_A))
		transform->position.x -= speed * GameWindow::deltaTime;
	else if (Input::GetKeyDown(GLFW_KEY_RIGHT) || Input::GetKeyDown(GLFW_KEY_D))
		transform->position.x += speed * GameWindow::deltaTime;
}

void PaddleController::Start()
{
}
