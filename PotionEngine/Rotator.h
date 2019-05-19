#pragma once
#include "Component.h"
class Rotator :
	public Component
{
public:
	Rotator();
	void Start();
	void Update();
	~Rotator();
};

