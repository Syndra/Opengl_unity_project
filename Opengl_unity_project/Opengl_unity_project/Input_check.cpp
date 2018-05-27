#include "Input_check.h"


Input_check::Input_check()
{
}


Input_check::~Input_check()
{
}

void Input_check::input_check(GLFWwindow * window, Camera * camera)
{
	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
	{
		camera->position.x++;
	}
	if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
	{
		camera->position.x--;
	}
}

