#pragma once

#include "Renderer.h"
#include "Updatable.h"
#include "Gameobject.h"


class MyObject : public Gameobject
{
public:

	Renderer * renderer;
	Updatable * updatable;

	MyObject();
	~MyObject();

};

