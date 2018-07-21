#include "CameraUpdatable.h"
#include "Window.h"
#include "CameraTransform.h"
#include "Timer.h"


CameraUpdatable::CameraUpdatable(CameraTransform *transform)
{
	this->transform = transform;
}


CameraUpdatable::~CameraUpdatable()
{
}

void CameraUpdatable::update()
{
	double xpos, ypos;
	float mouseSpeed = 0.015f;
	float speed = 5.0f;

	glfwGetCursorPos(Window::window, &xpos, &ypos);
	glfwSetCursorPos(Window::window, 1024 / 2, 768 / 2);

	this->transform->h_angle += mouseSpeed * Timer::deltatime * float(1024 / 2 - xpos);
	this->transform->v_angle += mouseSpeed * Timer::deltatime * float(768 / 2 - ypos);

	glm::vec3 direction(
		cos(this->transform->v_angle) * sin(this->transform->h_angle),
		sin(this->transform->v_angle),
		cos(this->transform->v_angle) * cos(this->transform->h_angle)
	);

	glm::vec3 right = glm::vec3(
		sin(this->transform->h_angle - 3.14f / 2.0f),
		0,
		cos(this->transform->h_angle - 3.14f / 2.0f)
	);

	this->transform->up = glm::cross(right, direction);

	// Move forward
	if (glfwGetKey(Window::window, GLFW_KEY_UP) == GLFW_PRESS) {
		this->transform->position += direction * Timer::deltatime * speed;
	}
	// Move backward
	if (glfwGetKey(Window::window, GLFW_KEY_DOWN) == GLFW_PRESS) {
		this->transform->position -= direction * Timer::deltatime * speed;
	}
	// Strafe right
	if (glfwGetKey(Window::window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
		this->transform->position += right * Timer::deltatime * speed;
	}
	// Strafe left
	if (glfwGetKey(Window::window, GLFW_KEY_LEFT) == GLFW_PRESS) {
		this->transform->position -= right * Timer::deltatime * speed;
	}
	if (glfwGetKey(Window::window, GLFW_KEY_EQUAL) == GLFW_PRESS) {
		this->transform->fovy -= Timer::deltatime * speed;
	}
	if (glfwGetKey(Window::window, GLFW_KEY_MINUS) == GLFW_PRESS) {
		this->transform->fovy += Timer::deltatime * speed;
	}
	this->transform->lookat = this->transform->position + direction;
}

void CameraUpdatable::start()
{
}
