#pragma once
#include <vector>
#include <set>
#include "GameObject.h"

class Scene
{
public:
	Scene();
	virtual ~Scene();
	void AddGameObject(GameObject *gameObject);
	void RemoveGameObject(GameObject *gameObject);
	void Update();
protected:
	struct cmp {
		bool operator()(GameObject *a, GameObject *b)const {
			return a->id < b->id;
		}
	};
	std::set<GameObject*, cmp> gameObjects;
};
