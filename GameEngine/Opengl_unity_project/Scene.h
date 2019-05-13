#pragma once
#include "Camera.h"
#include <vector>

class Light;
class Timer;
class Renderer;
class Updatable;
class myGamemanager;

class Scene
{
public:

	//Render&update vector.
	static std::vector<Renderer*> renderer;
	static std::vector<Updatable*> updatable;
	static std::vector<Light*> light;

	//Camera object.
	static Camera *camera_in_scene;

	//Timer
	Timer *timer;

	//Gamemanager
	myGamemanager *gamemanager;

	Scene();
	~Scene();

	void init_scene();
	void start_scene();
};

