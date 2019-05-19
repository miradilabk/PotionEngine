#pragma once
#include <set>
#include "Component.h"
#include "Transform.h"
class GameObject
{
public:
	Transform2D transform;
	bool isEnabled;
	GameObject();
	GameObject(Transform2D transform);
	GameObject(Transform2D transform, int layer);
	~GameObject();
	void Update();
	void RemoveComponent(Component* component);
	void AddComponent(Component* component);
	bool operator<(const GameObject& gameObject)const;
	template<typename T>
	Component* GetComponent() {
		for (int i = 0; i < components.size(); i++)
			if (typeid(T) == typeid(components[i]))
				return components[i];
		return NULL;
	}
	int id;
private:
	std::set<Component*> components;
	static int totalCnt;
};
