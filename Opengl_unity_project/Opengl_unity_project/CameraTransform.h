#pragma once

#include <glm\glm.hpp>
#include "Transform.h"

class CameraTransform : public Transform
{
public:

	glm::vec3 position;
	glm::vec3 lookat;

	float fovy;
	float aspect;
	float near;
	float far;

	float v_angle;
	float h_angle;

	glm::vec3 up = glm::vec3(0, 1, 0);

	CameraTransform();
	~CameraTransform();
};

