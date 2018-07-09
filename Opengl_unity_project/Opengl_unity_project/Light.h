#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Transform;

class Light
{
public:

	Transform * transform;

	float ambientStrengh  = 0.1f;
	float specularStrenth = 0.5f;
	glm::vec3 lightColor = glm::vec3(0.5f, 0.5f, 0.5f);

	Light(Transform *transform);
	~Light();

	void refresh();
};

