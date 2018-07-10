#pragma once

#include "Renderer.h"
#include "Mesh.h"
#include "Updatable.h"
#include "Gameobject.h"

class MyObject : public Gameobject
{
public:

	Renderer * renderer;
	Updatable * updatable;
	Mesh * mesh;

	MyObject();
	~MyObject();

};

