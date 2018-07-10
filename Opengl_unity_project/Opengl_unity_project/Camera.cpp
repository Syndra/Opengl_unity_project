#include "Camera.h"
#include "Window.h"
#include "Timer.h"
#include "CameraUpdatable.h"
#include "CameraTransform.h"
#include "Scene.h"
#include "Light.h"

Camera::Camera()
{
	this->transform = new CameraTransform();

	//set basic properties.
	transform->position = glm::vec3(0, 0, 5.f);
	transform->lookat = glm::vec3(0,0,0);
	transform->fovy = 45.0f;
	transform->aspect = (float)4 / (float)3;
	transform->near = 0.1f;
	transform->far = 100.0f;
	transform->v_angle = 0.0f;
	transform->h_angle = 3.14f;

	this->updatable = new CameraUpdatable(transform);

	cameraLight = new Light(this->transform);
	cameraLight->lightColor = glm::vec3(0.1,0.1,0.1);
	cameraLight->Power = 0.1f;
	Scene::light.push_back(cameraLight);

	Scene::updatable.push_back(updatable);
}


Camera::~Camera()
{
}

glm::mat4 Camera::get_projection_matrix()
{
	return glm::perspective(glm::radians(this->transform->fovy), this->transform->aspect, this->transform->near, this->transform->far);
}

glm::mat4 Camera::get_view_matrix()
{
	return glm::lookAt(this->transform->position, this->transform->lookat, this->transform->up);
}

