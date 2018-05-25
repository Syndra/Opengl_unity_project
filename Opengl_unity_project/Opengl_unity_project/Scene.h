#pragma once
#include "object.h"
#include "Camera.h"
#include "Vertex_data.h"
#include <iostream>
#include <vector>
class Scene
{
public:

	//Window properties.
	GLFWwindow * window;
	
	//control properties.
	bool current_in_window = true;

	//Camera object.
	Camera *camera_in_scene;

	//All objects in this scene.
	std::vector<object*> object_in_scene;

	Scene(GLFWwindow *window);
	~Scene();

	void init_scene(GLFWwindow *window);
	void render_scene();
};

