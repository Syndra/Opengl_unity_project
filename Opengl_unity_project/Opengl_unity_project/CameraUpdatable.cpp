#include "CameraUpdatable.h"
#include "Window.h"
#include "CameraTransform.h"
#include "Timer.h"


CameraUpdatable::CameraUpdatable(Transform *transform)
{
	this->transform = transform;
}


CameraUpdatable::~CameraUpdatable()
{
}

void CameraUpdatable::update()
{
	if (Timer::runningtime > 1) {

		//if (foo)
		//{
		//	foo = false;
		//	glfwSetCursorPos(Window::window, 1024 / 2, 768 / 2);
		//	lastX = float(1024 / 2 - xpos);
		//	lastY = float(768 / 2 - ypos);
		//}

		//glfwGetCursorPos(Window::window, &xpos, &ypos);
		//float xoffset = float(1024 / 2 - xpos) - lastX;
		//float yoffset = float(768 / 2 - ypos) - lastY;
		//glfwSetCursorPos(Window::window, 1024 / 2, 768 / 2);

		//xoffset *= mouseSpeed;
		//yoffset *= mouseSpeed;

		//Yaw += xoffset;
		//Pitch += yoffset;

		//glm::vec3 ea = glm::normalize(glm::vec3(Yaw, Pitch, 0));
		//transform->euler_angle += ea;
		//transform->lookat = transform->get_Lookat();
		////transform->lookat = glm::vec3(glm::mat4_cast(glm::quat(ea)) * glm::vec4(transform->lookat , 0) );
		////transform->up = glm::vec3(glm::mat4_cast(glm::quat(ea)) * glm::vec4(transform->up, 0));
		//	/*if (Pitch > 89.0f)
		//		Pitch = 89.0f;
		//	if (Pitch < -89.0f)
		//		Pitch = -89.0f;*/

		//	// Calculate the new Front vector
		//	/*glm::vec3 front;
		//	front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
		//	front.y = sin(glm::radians(Pitch));
		//	front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
		//	transform->lookat = glm::normalize(front);
		//	glm::vec3 Right = glm::normalize(glm::cross(transform->lookat, transform->up));
		//	transform->up = glm::normalize(glm::cross(Right, transform->lookat));*/
		//	// Also re-calculate the Right and Up vector
		////
		double xpos, ypos;

		glfwGetCursorPos(Window::window, &xpos, &ypos);
		glfwSetCursorPos(Window::window, 1024 / 2, 768 / 2);

		this->h_angle += mouseSpeed * Timer::deltatime * float(1024 / 2 - xpos);
		this->v_angle += mouseSpeed * Timer::deltatime * float(768 / 2 - ypos);

		glm::vec3 direction(
			cos(this->v_angle) * sin(this->h_angle),
			sin(this->v_angle),
			cos(this->v_angle) * cos(this->h_angle)
		);

		glm::vec3 right = glm::vec3(
			sin(this->h_angle - 3.14f / 2.0f),
			0,
			cos(this->h_angle - 3.14f / 2.0f)
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
		/*if (glfwGetKey(Window::window, GLFW_KEY_EQUAL) == GLFW_PRESS) {
			this->fovy -= Timer::deltatime * speed;
		}
		if (glfwGetKey(Window::window, GLFW_KEY_MINUS) == GLFW_PRESS) {
			this->transform->fovy += Timer::deltatime * speed;
		}*/
		this->transform->lookat = this->transform->position + direction;
	}
}

void CameraUpdatable::start()
{
}
