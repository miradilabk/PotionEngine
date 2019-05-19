#include "Scene.h"



Scene::Scene()
{
}


Scene::~Scene()
{
}

void Scene::addGameObject(GameObject& gameObject)
{
	gameObjects.insert(gameObject);
}

void Scene::removeGameObject(GameObject& gameObject)
{
	gameObjects.erase(gameObject);
}

void Scene::Update()
{
	for (auto gameObject : gameObjects)
		if (gameObject.isEnabled)
			gameObject.Update();
}
