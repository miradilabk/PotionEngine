#include "Component.h"

int Component::totalCnt = 0;
Component::Component() : isEnabled(true), id(++totalCnt)
{
}

Component::~Component()
{
}

bool Component::operator<(const Component& component)const
{
	return this->id < component.id;
}
