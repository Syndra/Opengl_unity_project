#pragma once
#include "Camera.h"
#include <vector>

class Timer;
class Renderer;
class Updatable;

class Scene
{
public:

	//Render&update vector.
	static std::vector<Renderer*> renderer;
	static std::vector<Updatable*> updatable;

	//Camera object.
	Camera *camera_in_scene;

	//Timer
	Timer *timer;

	//Gamemanager

	Scene();
	~Scene();

	void init_scene();
	void start_scene();
};

