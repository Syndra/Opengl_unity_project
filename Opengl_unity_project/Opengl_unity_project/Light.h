#pragma once


#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "ShadowMap.h"

class Transform;

/*
Maximum #light = 20, check shader's array initializer.
*/
struct LightProperties 
{
	int type;
	float Power;
	float FOV;
	float specularStrenght;
	glm::vec3 lightColor;
};


class Light
{
public:

	// 0 : directed, 1 : pointed, 2 : spot
	static int numofLight;
	static const int degree = 100;
	static float ambientStrength;

	int lightID;

	Transform * transform;

	LightProperties * properties;

	ShadowMap *shadowMap;
	glm::mat4 depthBiasMVP;

	Light(Transform *transform, int type);
	~Light();

	void setShadowMap(int type);
	void refresh();
};

