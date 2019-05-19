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
}

void GameObject::Update()
{
	for (auto component : components)
		component->Update();
}

void GameObject::AddComponent(Component* component)
{
	if (component->transform != NULL) {
		puts("this component already has a gameobject attached.");
		return;
	}
	component->transform = &transform;
	component->Start();
	components.insert(component);
}

bool GameObject::operator<(const GameObject & gameObject)const
{
	return this->id < gameObject.id;
}

void GameObject::RemoveComponent(Component* component) 
{
	components.erase(component);
	component->transform = NULL;
}