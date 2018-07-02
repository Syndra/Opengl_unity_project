#pragma once

#include <glm\glm.hpp>

class Transform
{
public:

	glm::vec3 position;
	float scale;

	Transform(glm::vec3 position);
	Transform();
	Transform(float x, float y, float z);
	~Transform();
};

