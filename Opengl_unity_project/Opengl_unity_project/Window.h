#pragma once
#define GLM_ENABLE_EXPERIMENTAL
#include <gl\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include "Scene.h"

class Window
{
public:

	//window properties.
	GLFWwindow *window;
	Scene *current_scene;

	Window();
	~Window();
	
private:
	bool init_glfw();
	bool init_glew();
	void load_scene();
};

