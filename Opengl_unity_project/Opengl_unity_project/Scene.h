#pragma once
#include "object.h"
#include "Camera.h"
#include "Input_check.h"
#include "Vertex_data.h"
#include "Gamemanager.h"
#include <iostream>
#include <vector>

class BaseObject;
class Tetris_block;
class Block;
class Timer;
class Renderer;
class Updatable;

class Scene
{
public:

	//Render&update vector.
	static std::vector<Renderer*> renderer;
	static std::vector<Updatable*> updatable;

	//Window properties.
	GLFWwindow * window;
	
	//control properties.
	bool current_in_window = true;

	//Camera object.
	Camera *camera_in_scene;

	//Timer
	Timer *timer;

	//Gamemanager
	Gamemanager *gamemanager;

	//All objects in this scene.
	std::vector<BaseObject*> object_in_scene;
	std::vector<Block*> object_render;
	//std::vector<Tetris_block*> object_render;

	Scene();
	Scene(Gamemanager * gamemanager);
	~Scene();

	void init_scene();
	void start_scene();
};

