#pragma once

#include "Renderer.h"
#include "Updatable.h"
#include "Gameobject.h"
#include "MyobjectUpdatable.h"

class MyObject : public Gameobject
{
public:

	Renderer * renderer;
	Updatable * updatable;
	//MyobjectUpdatable * updatable;

	MyObject();
	~MyObject();

};

