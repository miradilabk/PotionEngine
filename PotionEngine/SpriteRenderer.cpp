#include "SpriteRenderer.h"
#include "ResourceManager.h"
#include <string.h>

bool isPNG(const char* filePath) {
	int lastIndex = strlen(filePath) - 1;
	return filePath[lastIndex - 2] == 'p' && filePath[lastIndex - 1] == 'n' && filePath[lastIndex] == 'g';
}

void SpriteRenderer::Start()
{
}

bool hasInited;

void SpriteRenderer::Init(const char* textureFilePath, glm::vec2 origin, glm::vec3 color, Shader& shader) 
{
	this->textureFilePath = textureFilePath;
	this->color = color;
	this->shader = shader;
	this->origin = origin;
	this->texture = ResourceManager::LoadTexture(textureFilePath, isPNG(textureFilePath), textureFilePath);
	hasInited = true;
}

void SpriteRenderer::Update()
{
	if (!hasInited) return;
	OpenglRenderer::DrawSprite(
		texture, shader,
		transform, color, origin
	);
}
