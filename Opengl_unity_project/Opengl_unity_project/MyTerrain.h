#pragma once
#include "Renderer.h"
#include "Model.h"
#include "Gameobject.h"

class Terrain;

class MyTerrain : public Gameobject
{
public:

	Renderer * renderer;
	Terrain * terrain;

	MyTerrain();
	~MyTerrain();

	void set_terrain(const char *path, int width, int length);
};

