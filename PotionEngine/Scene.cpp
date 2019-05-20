#include "Scene.h"



Scene::Scene()
{
}


Scene::~Scene()
{
}

void Scene::AddGameObject(GameObject& gameObject)
{
	gameObjects.insert(gameObject);
}

void Scene::RemoveGameObject(GameObject& gameObject)
{
	gameObjects.erase(gameObject);
}

void Scene::Update()
{
	for (auto gameObject : gameObjects)
		if (gameObject.isEnabled)
			gameObject.Update();
}
