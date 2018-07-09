#include "MyobjectUpdatable.h"
#include <iostream>
#include <gl\glew.h>
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>
#include "Window.h"
#include "Timer.h"
#include "Transform.h"

MyobjectUpdatable::MyobjectUpdatable()
{
}


MyobjectUpdatable::~MyobjectUpdatable()
{
}

void MyobjectUpdatable::update()
{
	if (glfwGetKey(Window::window, GLFW_KEY_J) == GLFW_PRESS) {
		std::cout << "J";
	}
}
