#include "myGamemanager.h"
#include "Window.h"
#include "Scene.h"
#include "Camera.h"
#include "MyObject.h"
#include "FloorObject.h"
#include "MyLightSource.h"
#include "Transform.h"
#include "CameraTransform.h"
#include "Shader.h"
#include "LightTransform.h"

myGamemanager::myGamemanager()
{
	Scene::camera_in_scene->transform->position = glm::vec3(0, 10, 10);
	Scene::camera_in_scene->transform->lookat = glm::vec3(0, 0, 0);

	MyObject *c = new MyObject();
	c->transform->position = glm::vec3(0, 0, 0);

	spotlight = new MyLightSource();
	spotlight->transform->position = glm::vec3(0, 10, 0);
	spotlight->light->properties->lightColor = glm::vec3(1, 1, 1);
	spotlight->light->transform->euler_angle = glm::vec3(92, 0, 0);
	spotlight->light->transform->position = glm::vec3(0, 10, 0);
	spotlight->light->properties->Power = 0.1;
	spotlight->light->properties->type = 1;
	spotlight->light->properties->FOV = 0.2f;

	MyLightSource *spotlight2 = new MyLightSource();
	spotlight2->transform->position = glm::vec3(0, 10, 0);
	spotlight2->light->properties->lightColor = glm::vec3(1, 1, 1);
	spotlight2->light->transform->euler_angle = glm::vec3(0.5f, 2.f, 2.f);
	spotlight2->light->transform->position = glm::vec3(0, 10, 0);
	spotlight2->light->properties->Power = 0.001;
	spotlight2->light->properties->type = 0;
	spotlight2->light->properties->FOV = 0.2f;

	//spotlight->renderer->onRenderTarget = true;


	/*pointedlight = new MyLightSource();
	pointedlight->transform->position = glm::vec3(2, 2, 0);
	pointedlight->light->lightColor = glm::vec3(1,1,1);
	pointedlight->light->Power = 1;
	pointedlight->light->type = 1;*/
}


myGamemanager::~myGamemanager()
{
}

void myGamemanager::run()
{
	if (glfwGetKey(Window::window, GLFW_KEY_A) == GLFW_PRESS) {
		spotlight->transform->euler_angle.x -= 0.01;
	}
	if (glfwGetKey(Window::window, GLFW_KEY_D) == GLFW_PRESS) {
		spotlight->transform->euler_angle.x += 0.01;
	}
	if (glfwGetKey(Window::window, GLFW_KEY_S) == GLFW_PRESS) {
		spotlight->transform->position.y -= 0.1;
	}
	if (glfwGetKey(Window::window, GLFW_KEY_W) == GLFW_PRESS) {
		spotlight->transform->position.y += 0.1;
	}
	if (glfwGetKey(Window::window, GLFW_KEY_R) == GLFW_PRESS) {
		spotlight->transform->position.z -= 0.1;
	}
	if (glfwGetKey(Window::window, GLFW_KEY_F) == GLFW_PRESS) {
		spotlight->transform->position.z += 0.1;
	}
}
