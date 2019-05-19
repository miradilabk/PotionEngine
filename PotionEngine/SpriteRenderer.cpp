#include "SpriteRenderer.h"
#include "ResourceManager.h"
#include <string.h>

SpriteRenderer::SpriteRenderer(const char* filePath): textureFilePath(filePath), shader(Shader::GetDefaultShader())
{
}

SpriteRenderer::SpriteRenderer(const char* filePath, Shader& shader) : textureFilePath(filePath), shader(shader)
{
}

SpriteRenderer::~SpriteRenderer()
{
}

bool isPNG(const char* filePath) {
	int lastIndex = strlen(filePath) - 1;
	return filePath[lastIndex - 2] == 'p' && filePath[lastIndex - 1] == 'n' && filePath[lastIndex] == 'g';
}

void SpriteRenderer::Start()
{
	texture = ResourceManager::LoadTexture(textureFilePath, isPNG(textureFilePath), textureFilePath);
}

void SpriteRenderer::Update()
{
	OpenglRenderer::DrawSprite(
		texture, shader,
		transform, glm::vec3(1.0f)
	);
}
