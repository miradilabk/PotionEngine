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
	SpriteRenderer(const char* filePath);
	SpriteRenderer(const char * filePath, Shader & shader);
	~SpriteRenderer();
	void Update();
	void Start();
private:
	Shader& shader;
};
