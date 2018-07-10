#include "myGamemanager.h"
#include "Window.h"
#include "Scene.h"
#include "Camera.h"
#include "MyObject.h"
#include "MyLightSource.h"
#include "Transform.h"
#include "CameraTransform.h"
#include "Shader.h"

myGamemanager::myGamemanager()
{
	MyObject *a = new MyObject();
	a->transform->scale = 1;

	light = new MyLightSource();
	light->transform->position = glm::vec3(10,10,0);
}


myGamemanager::~myGamemanager()
{
}

void myGamemanager::run()
{
	if (glfwGetKey(Window::window, GLFW_KEY_A) == GLFW_PRESS) {
		light->transform->position.x -= 0.1;
	}
	if (glfwGetKey(Window::window, GLFW_KEY_D) == GLFW_PRESS) {
		light->transform->position.x += 0.1;
	}
	if (glfwGetKey(Window::window, GLFW_KEY_S) == GLFW_PRESS) {
		light->transform->position.y -= 0.1;
	}
	if (glfwGetKey(Window::window, GLFW_KEY_W) == GLFW_PRESS) {
		light->transform->position.y += 0.1;
	}
	if (glfwGetKey(Window::window, GLFW_KEY_R) == GLFW_PRESS) {
		light->transform->position.z -= 0.1;
	}
	if (glfwGetKey(Window::window, GLFW_KEY_F) == GLFW_PRESS) {
		light->transform->position.z += 0.1;
	}
}
