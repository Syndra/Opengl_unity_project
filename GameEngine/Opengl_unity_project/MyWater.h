#pragma once
#include "Renderer.h"
#include "Model.h"
#include "Gameobject.h"

class Terrain;

class MyWater : public Gameobject
{
public:

	Renderer * renderer;
	Terrain * terrain;

	MyWater();
	~MyWater();

	void set_terrain(const char *path, int width, int length);
};

