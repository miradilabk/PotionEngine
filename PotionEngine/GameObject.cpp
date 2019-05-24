#include "GameObject.h"

int GameObject::totalCnt = 0;
GameObject::GameObject() : isEnabled(true), id(++totalCnt)
{
}

GameObject::GameObject(Transform2D transform) : transform(transform), isEnabled(true), id(++totalCnt)
{
}

GameObject::GameObject(Transform2D transform, int layer) : transform(transform), isEnabled(true), id(layer)
{
}

GameObject::~GameObject()
{
	puts("destruct gameobject");
	for (auto component : components)
		delete component;
	components.clear();
}

void GameObject::Update()
{
	for (auto component : components)
		if (component->isEnabled) {
			component->Update();
		}
}
