#pragma once
#include "Component.h"
#include "Texture.h"
#include "OpenglRenderer.h"
#include "Shader.h"

class SpriteRenderer : public Component
{
public:
	Texture2D texture;
	const char* textureFilePath;
	void Init(
		const char* textureFilePath,
		glm::vec2 origin = glm::vec2(0),
		glm::vec3 color = glm::vec3(1),
		Shader& shader = Shader::GetDefaultShader()
	);
	virtual void Update();
	virtual void Start();
private:
	Shader& shader = Shader::GetDefaultShader();
	glm::vec3 color;
	glm::vec2 origin;
};
