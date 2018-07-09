#pragma once

#include "Renderer.h"
#include "Updatable.h"
#include "Gameobject.h"
#include "Light.h"
#include "MyobjectUpdatable.h"

class MyLightSource : public Gameobject
{
public:

	Renderer * renderer;
	MyobjectUpdatable * updatable;
	Light * light;

	MyLightSource();
	~MyLightSource();
};

