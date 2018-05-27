#pragma once
#include <gl\glew.h>
#include <GLFW\glfw3.h>
#include "Camera.h"


class Input_check
{
public:

	Input_check();
	~Input_check();

	static void input_check(GLFWwindow * window, Camera * camera);
};

