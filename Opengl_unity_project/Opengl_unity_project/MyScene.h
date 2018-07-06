#pragma once

#include "Camera.h"
#include "Timer.h"
#include <vector>

class Timer;
class Renderer;
class Updatable;
class MyObject;

class MyScene
{
public:

	MyObject * cube;

	//Render&update vector.
	static std::vector<Renderer*> renderer;
	static std::vector<Updatable*> updatable;

	MyScene();
	~MyScene();

	//Camera object.
	Camera *camera_in_scene;

	//Timer
	Timer *timer;

	void init_scene();
	void start_scene();
};

