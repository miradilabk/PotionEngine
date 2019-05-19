#pragma once
#include <vector>
#include <set>
#include "GameObject.h"
class Scene
{
public:
	Scene();
	~Scene();
	void addGameObject(GameObject& gameObject);
	void removeGameObject(GameObject& gameObject);
	void Update();
protected:
	std::set<GameObject> gameObjects;
};
