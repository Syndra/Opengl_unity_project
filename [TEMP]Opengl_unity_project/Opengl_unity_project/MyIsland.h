#pragma once
#include "Renderer.h"
#include "Model.h"
#include "Gameobject.h"

class Terrain;

class MyIsland : public Gameobject
{
public:

	Renderer * renderer;
	Terrain * terrain;

	MyIsland();
	~MyIsland();

	void set_terrain(const char *path, int width, int length);
};

