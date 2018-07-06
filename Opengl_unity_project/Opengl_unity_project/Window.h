#pragma once
#define GLM_ENABLE_EXPERIMENTAL
#include <gl\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>

class Scene;
class MyScene;

class Window
{
public:

	static GLFWwindow *window;
	Scene *current_scene;
	//MyScene *current_my_scene;

	Window();
	~Window();
	
private:
	bool init_glfw();
	bool init_glew();
	void load_scene();
};

