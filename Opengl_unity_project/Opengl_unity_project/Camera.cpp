#include "Camera.h"
#include "Window.h"
#include "Timer.h"
#include "CameraUpdatable.h"
#include "Transform.h"
#include "Scene.h"
#include "Light.h"

Camera::Camera()
{
	this->transform = new Transform();

	//set basic properties.
	fovy = 45.0f;
	aspect = (float)4 / (float)3;
	near = 0.01f;
	far = 1000.0f;

	this->updatable = new CameraUpdatable(transform);

	/*cameraLight = new Light(this->transform);
	cameraLight->lightColor = glm::vec3(1,0,0);
	cameraLight->Power = 0.1f;
	cameraLight->type = 1;
	cameraLight->lookat = this->transform->lookat;
	Scene::light.push_back(cameraLight);*/

	Scene::updatable.push_back(updatable);
}


Camera::~Camera()
{
}

glm::mat4 Camera::get_projection_matrix()
{
	return glm::perspective(glm::radians(fovy), aspect,near,far);
}

glm::mat4 Camera::get_view_matrix()
{
	return glm::lookAt(this->transform->position, this->transform->lookat, this->transform->up);
}

