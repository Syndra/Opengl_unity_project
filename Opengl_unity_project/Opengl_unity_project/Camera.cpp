#include "Camera.h"



Camera::Camera()
{
	//set basic properties.
	this->position = glm::vec3(0,0,-6);
	this->lookat = glm::vec3(0,0,0);

	this->fovy = 45.0f;
	this->aspect = (float)4 / (float)3;
	this->near = 0.1f;
	this->far = 100.0f;
}


Camera::~Camera()
{
}

glm::mat4 Camera::get_projection_matrix()
{
	return glm::perspective(glm::radians(this->fovy), this->aspect, this->near, this->far);
}

glm::mat4 Camera::get_view_matrix()
{
	return glm::lookAt(this->position, this->lookat, this->up);
}
