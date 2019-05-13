#pragma once

#include <glm\glm.hpp>
#include "Transform.h"

class LightTransform :  public Transform
{
public:

	int type;	

	glm::vec3 direction = glm::vec3(0.5, 2, 2);
	glm::vec3 lookat = glm::vec3(0, -1, 0);

	float FOV = 20.0f;

	LightTransform();
	~LightTransform();
};