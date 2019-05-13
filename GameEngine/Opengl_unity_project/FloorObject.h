#pragma once

#include "Renderer.h"
#include "Updatable.h"
#include "Gameobject.h"

class Model;

class FloorObject : public Gameobject
{
public:

	Renderer * renderer;
	Updatable * updatable;
	Model * model;

	FloorObject();
	~FloorObject();
};

