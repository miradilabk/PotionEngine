#pragma once
#include "Scene.h"
#include <glm/vec3.hpp>
class BreakOutScene :
	public Scene
{
public:
	BreakOutScene();
	~BreakOutScene();
private:
	void AddBrick(glm::vec2 size, glm::vec2 position, glm::vec3 color);
	void LoadLevel();
	void LoadBackground();
	void LoadPaddle();
};

