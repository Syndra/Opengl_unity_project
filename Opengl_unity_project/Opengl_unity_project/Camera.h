#pragma once
#include <gl\glew.h>
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include "control.h"

class Camera
{
public:

	//basic properties.
	
	//transform properties.
	glm::vec3 position;
	glm::vec3 lookat;

	GLfloat fovy;
	GLfloat aspect;
	GLfloat near;
	GLfloat far;

	glm::vec3 up = glm::vec3(0,1,0);

	Camera();
	~Camera();
	glm::mat4 get_projection_matrix();
	glm::mat4 get_view_matrix();
};

