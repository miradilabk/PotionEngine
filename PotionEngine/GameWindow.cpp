#include "GameWindow.h"
int GameWindow::width = 800;
int GameWindow::height = 600;
GameWindow::GameWindow(int width, int height) : currentSceneIndex(-1)
{
	GameWindow::width = width;
	GameWindow::height = height;
	Init(width, height);
}

GameWindow::GameWindow(int width, int height, Scene *scene) : currentSceneIndex(-1)
{
	GameWindow::width = width;
	GameWindow::height = height;
	Init(width, height);
	scenes.push_back(scene);
	currentSceneIndex = 0;
}

GameWindow::~GameWindow()
{
	for (auto scene : scenes) {
		delete scene;
	}
}

void GameWindow::Update()
{
	if (!scenes.empty() && currentSceneIndex != -1)
		scenes[currentSceneIndex]->Update();
}

void GameWindow::AddScene(Scene *scene)
{
	scenes.push_back(scene);
}