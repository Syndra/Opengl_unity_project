#pragma once


#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "ShadowMap.h"

class LightTransform;
class Transform;

/*
Maximum #light = 20, check shader's array initializer.
*/
class Light
{
public:

	// 0 : directed, 1 : pointed, 2 : spot
	static int numofLight;
	static const int degree = 100;
	static float ambientStrength;
	float Power;

	int lightID;

	LightTransform * transform;

	ShadowMap *shadowMap;
	glm::mat4 depthBiasMVP;

	//float ambientStrengh  = 0.1f;
	float specularStrenth = 0.1f;
	glm::vec3 lightColor = glm::vec3(0.5f, 0.5f, 0.5f);

	Light(Transform *transform, int type);
	~Light();

	void setShadowMap(int type);
	void refresh();
};

