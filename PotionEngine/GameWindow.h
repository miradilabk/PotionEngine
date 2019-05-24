#pragma once
#include <vector>
#include "Scene.h"
#include "OpenglWindow.h"

class GameWindow : public OpenglWindow
{
public:
	GameWindow(int width, int height);
	GameWindow(int width, int height, Scene *scene);
	void AddScene(Scene *scene);
	~GameWindow();
	static int width;
	static int height;
	int currentSceneIndex;

protected:
	std::vector<Scene*> scenes;
private:
	void Update();
};
