#pragma once
#include <gl\glew.h>
#include <GLFW\glfw3.h>
#include "Camera.h"
#include <vector>

class Input_check
{
public:

	Input_check();
	~Input_check();

	static void input_check(std::vector <BaseObject *> baseobjects);
};

