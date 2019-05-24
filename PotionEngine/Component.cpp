#include "Component.h"

int Component::totalCnt = 0;
Component::Component() : isEnabled(true), id(++totalCnt)
{
}

Component::~Component()
{
}
