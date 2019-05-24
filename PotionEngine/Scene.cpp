#include "Scene.h"



Scene::Scene()
{
}

Scene::~Scene()
{
	puts("destruct scene");
	for (auto gameObject : gameObjects) {
		delete gameObject;
	}
	gameObjects.clear();
}

void Scene::AddGameObject(GameObject *gameObject)
{
	gameObjects.insert(gameObject);
}

void Scene::RemoveGameObject(GameObject *gameObject)
{
	gameObjects.erase(gameObject);
}

void Scene::Update()
{
	int i = 0;
	for (auto gameObject : gameObjects)
		if (gameObject->isEnabled) {
			gameObject->Update();
		}
}
