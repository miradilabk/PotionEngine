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
	virtual ~GameObject();
	void Update();
	bool operator<(const GameObject& gameObject)const;

	//component related methods
	template<class T> T* GetComponent() {
		for (auto component: components)
			if (typeid(T) == typeid(component))
				return (T*)component;
		return NULL;
	}

	template<class T> T* AddComponent() {
		Component* component = new T();
		component->transform = &transform;
		component->Start();
		components.insert(component);
		return (T*)component;
	}

	template<class T> void RemoveComponent() {
		Component* component = GetComponent<T>();
		components.erase(component);
		component->transform = NULL;
		delete component;
	}

	int id;
private:
	struct cmp {
		bool operator() (Component *a, Component *b)const {
			return a->id < b->id;
		}
	};
	std::set<Component*, cmp> components;
	static int totalCnt;
};
