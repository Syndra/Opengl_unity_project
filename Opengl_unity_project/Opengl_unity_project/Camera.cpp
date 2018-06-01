#include "Camera.h"
#include "Window.h"
#include "Timer.h"


Camera::Camera()
{
	//set basic properties.
	this->position = glm::vec3(0,0,-6);
	this->lookat = glm::vec3(0,0,0);

	this->fovy = 45.0f;
	this->aspect = (float)4 / (float)3;
	this->near = 0.1f;
	this->far = 100.0f;

	v_angle = 0.0f;
	h_angle = 3.14f;
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

void Camera::update()
{
	double xpos, ypos;
	float mouseSpeed = 0.005f;

	glfwGetCursorPos(Window::window, &xpos, &ypos);
	glfwSetCursorPos(Window::window, 1024/2, 768/2);

	h_angle += mouseSpeed * Timer::deltatime * float(1024 / 2 - xpos);
	v_angle += mouseSpeed * Timer::deltatime * float(768 / 2 - ypos);

	glm::vec3 direction(
		cos(v_angle) * sin(h_angle),
		sin(v_angle),
		cos(v_angle) * cos(h_angle)
	);

	this->lookat = position + direction;

	if (glfwGetKey(Window::window, GLFW_KEY_1) == GLFW_PRESS)
	{
		position.x++;
	}
	if (glfwGetKey(Window::window, GLFW_KEY_2) == GLFW_PRESS)
	{
		position.x--;
	}
}
