#pragma once
#include "object.h"
#include "Camera.h"
#include "Input_check.h"
#include "Vertex_data.h"
#include <iostream>
#include <vector>

class BaseObject;
class Tetris_block;
class Block;
class Timer;

class Scene
{
public:

	//Window properties.
	GLFWwindow * window;
	
	//control properties.
	bool current_in_window = true;

	//Camera object.
	Camera *camera_in_scene;

	//Timer
	Timer *timer;

	//All objects in this scene.
	std::vector<BaseObject*> object_in_scene;
	std::vector<Block*> object_render;
	//std::vector<Tetris_block*> object_render;

	Scene(GLFWwindow *window);
	~Scene();

	void init_scene(GLFWwindow *window);
	void render_scene();
};

