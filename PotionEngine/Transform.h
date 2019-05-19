#pragma once
#include <glm/vec2.hpp>
struct Transform2D {
	glm::vec2 position;
	float rotation;
	glm::vec2 size;
	Transform2D() : position(0), rotation(0), size(100)
	{
	}
	Transform2D(glm::vec2 position) 
		: position(position), rotation(0), size(100)
	{
	}
	Transform2D(glm::vec2 position, glm::vec2 size)
		: position(position), rotation(0), size(size)
	{
	}
	Transform2D(glm::vec2 position, glm::vec2 size, float rotation)
		: position(position), rotation(rotation), size(size)
	{
	}
};