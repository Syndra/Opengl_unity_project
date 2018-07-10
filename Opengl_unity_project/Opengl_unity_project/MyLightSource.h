#pragma once

#include "Renderer.h"
#include "Updatable.h"
#include "Gameobject.h"
#include "Light.h"
#include "Mesh.h"
#include "MyobjectUpdatable.h"

class MyLightSource : public Gameobject
{
public:

	Renderer * renderer;
	MyobjectUpdatable * updatable;
	Mesh * mesh;
	Light * light;

	MyLightSource();
	~MyLightSource();
};

