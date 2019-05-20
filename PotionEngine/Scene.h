#pragma once
#include <vector>
#include <set>
#include "GameObject.h"
class Scene
{
public:
	Scene();
	~Scene();
	void AddGameObject(GameObject& gameObject);
	void RemoveGameObject(GameObject& gameObject);
	void Update();
protected:
	std::set<GameObject> gameObjects;
};
