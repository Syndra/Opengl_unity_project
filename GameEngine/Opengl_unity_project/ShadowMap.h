#pragma once

#include <gl\glew.h>
#include <glm\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Transform;
struct LightProperties;

class ShadowMap
{
public:

	//LightTransform * transform;
	Transform * transform;
	LightProperties * properties;

	GLuint FrameBuffer = 5;
	GLuint shader;

	glm::mat4 depthVP;
	glm::mat4 depthBiasVP;
	GLuint depthTexture;

	ShadowMap(Transform * transform, LightProperties * properties);
	~ShadowMap();

	bool setupDirectedShadowMap();
	bool setupSpotShadowMap();
	void drawShadowMap();
};

