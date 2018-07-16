#pragma once

#include <gl\glew.h>
#include <glm\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class ShadowMap
{
public:

	GLuint FrameBuffer = 0;
	GLuint shader;

	int type;
	glm::vec3 direction;
	glm::vec3 location;

	glm::mat4 depthVP;
	glm::mat4 depthBiasVP;
	GLuint depthTexture;

	ShadowMap(glm::vec3 location, glm::vec3 direction, int type);
	~ShadowMap();

	bool setupDirectedShadowMap();
	bool setupPointedShadowMap();
	void drawShadowMap();
};

