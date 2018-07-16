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

myGamemanager::myGamemanager()
{
	Scene::camera_in_scene->transform->position = glm::vec3(0, 10, 0);
	Scene::camera_in_scene->lookat = glm::vec3(0,11,0);

	//FloorObject *b = new FloorObject();
	//b->transform->position = glm::vec3(0, 1, 0);
	MyObject *c = new MyObject();
	c->transform->position = glm::vec3(1, 2, 0);
	MyObject *c1 = new MyObject();
	c1->transform->position = glm::vec3(4, 5, 0);
	MyObject *c2 = new MyObject();
	c2->transform->position = glm::vec3(1, 5, 0);
	MyObject *c3 = new MyObject();
	c3->transform->position = glm::vec3(2, 1, 0);
	FloorObject *d = new FloorObject();
	d->transform->scale = 20;
	//FloorObject *a = new FloorObject();
	//FloorObject *e = new FloorObject();

	//MyObject *a = new MyObject();
	//a->transform->scale = 0.2;
	//a->transform->position = glm::vec3(0, 2, 0);

	sunlight = new MyLightSource();
	sunlight->transform->position = glm::vec3(0,-10,-10);
	sunlight->light->lightColor = glm::vec3(1,1,1);
	sunlight->light->Power = 0.01;
	sunlight->light->type = 0;
	sunlight->light->direction = glm::vec3(1,1,0);
	//sunlight->renderer->onRenderTarget = false;

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
