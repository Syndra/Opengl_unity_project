#pragma once
#include "Renderer.h"
#include "Model.h"
#include "Gameobject.h"

class Terrain;

class MyMountain : public Gameobject
{
public:

	Renderer * renderer;
	Terrain * terrain;

	MyMountain();
	~MyMountain();

	void set_terrain(const char *path, int width, int length);
};

