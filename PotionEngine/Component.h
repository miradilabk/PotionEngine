#pragma once
#include <iostream>
#include "Transform.h"
class Component
{
public:
	Transform2D *transform;
	Component();
	virtual ~Component();
	bool isEnabled;
	virtual void Update() = 0;
	virtual void Start() = 0;
	bool operator<(const Component& component)const;
private:
	static int totalCnt;
	int id;
};
