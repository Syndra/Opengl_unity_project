#pragma once

#include <gl\glew.h>
#include <glm\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class ShadowMap
{
public:

	GLuint FrameBuffer = 1;
	GLuint shader;

	//glm::mat4 depthBiasMVP;
	GLuint depthTexture;

	ShadowMap(glm::vec3 location, glm::vec3 direction, int type);
	~ShadowMap();

	bool setupDirectedShadowMap(glm::vec3 direction);
	bool setupPointedShadowMap();
};

