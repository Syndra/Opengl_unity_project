#pragma once


#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "ShadowMap.h"

class Transform;
/*
Maximum #light = 20, check shader's array initializer.
*/
class Light
{
public:

	// 0 : directed, 1 : pointed, 2 : spot
	int type;

	static int numofLight;
	static const int degree = 100;
	static float ambientStrength;
	float Power;

	int lightID;

	Transform * transform;

	ShadowMap *shadowMap;
	glm::mat4 depthBiasMVP;

	//float ambientStrengh  = 0.1f;
	float specularStrenth = 0.1f;
	glm::vec3 lightColor = glm::vec3(0.5f, 0.5f, 0.5f);
	glm::vec3 direction = glm::vec3(0,-1,0);
	glm::vec3 lookat = glm::vec3(0,-1,0);
	float FOV = 20.0f;

	Light(Transform *transform, int type);
	~Light();

	void setShadowMap(int type);
	void refresh();
};

