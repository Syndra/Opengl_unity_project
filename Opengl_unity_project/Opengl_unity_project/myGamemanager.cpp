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
	Scene::camera_in_scene->transform->position = glm::vec3(0, 5, 5);
	Scene::camera_in_scene->lookat = glm::vec3(-5,-10,20);

	MyObject *c = new MyObject();
	c->transform->position = glm::vec3(0, 0, 0);

	MyObject *panel = new MyObject();
	panel->transform->position = glm::vec3(0, 0, -10);
	panel->transform->scale = 10;
	panel->renderer->shader = Shader::panel;
	panel->set_model("obj/panel.obj");


	/*sunlight = new MyLightSource();
	sunlight->transform->position = glm::vec3(0,10,10);
	sunlight->light->lightColor = glm::vec3(1,1,1);
	sunlight->light->Power = 0.01;
	sunlight->light->transform->type = 0;
	sunlight->light->transform->direction = glm::vec3(1,1,-1);
	sunlight->renderer->onRenderTarget = false;*/

	MyLightSource *spotlight = new MyLightSource();
	spotlight->transform->position = glm::vec3(0, 10, 0);
	spotlight->light->lightColor = glm::vec3(1, 1, 1);
	spotlight->light->transform->lookat = glm::vec3(1, 1, 1);
	spotlight->light->Power = 1.f;
	spotlight->light->transform->type = 1;
	spotlight->light->transform->FOV = 0.3f;
	spotlight->renderer->onRenderTarget = true;


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
	/*if (glfwGetKey(Window::window, GLFW_KEY_A) == GLFW_PRESS) {
		pointedlight->transform->position.x -= 0.1;
	}
	if (glfwGetKey(Window::window, GLFW_KEY_D) == GLFW_PRESS) {
		pointedlight->transform->position.x += 0.1;
	}
	if (glfwGetKey(Window::window, GLFW_KEY_S) == GLFW_PRESS) {
		pointedlight->transform->position.y -= 0.1;
	}
	if (glfwGetKey(Window::window, GLFW_KEY_W) == GLFW_PRESS) {
		pointedlight->transform->position.y += 0.1;
	}
	if (glfwGetKey(Window::window, GLFW_KEY_R) == GLFW_PRESS) {
		pointedlight->transform->position.z -= 0.1;
	}
	if (glfwGetKey(Window::window, GLFW_KEY_F) == GLFW_PRESS) {
		pointedlight->transform->position.z += 0.1;
	}*/
}
