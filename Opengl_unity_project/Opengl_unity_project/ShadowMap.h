#pragma once

#include <gl\glew.h>
#include <glm\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class LightTransform;

class ShadowMap
{
public:

	LightTransform * transform;

	GLuint FrameBuffer = 5;
	GLuint shader;

	glm::mat4 depthVP;
	glm::mat4 depthBiasVP;
	GLuint depthTexture;

	ShadowMap(LightTransform * transform);
	~ShadowMap();

	bool setupDirectedShadowMap();
	bool setupSpotShadowMap();
	void drawShadowMap();
};

