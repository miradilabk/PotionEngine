#pragma once
#include "Shader.h"
#include "Texture.h"
#include "Transform.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
class OpenglRenderer
{
public:
	static void DrawSprite(
		Texture2D &texture,
		Shader &shader,
		Transform2D *transform,
		glm::vec3 color,
		glm::vec2 origin);
private:
	static GLuint quadVAO;
	static bool hasInited;
	static void initRenderData();
};

