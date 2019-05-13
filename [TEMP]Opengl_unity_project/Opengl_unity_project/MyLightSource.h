#pragma once

#include "Renderer.h"
#include "Updatable.h"
#include "Gameobject.h"
#include "Light.h"
#include "Mesh.h"
#include "Model.h"
#include "MyobjectUpdatable.h"

class MyLightSource : public Gameobject
{
public:

	Renderer * renderer;
	MyobjectUpdatable * updatable;
	Model * model;
	Light * light;

	MyLightSource();
	~MyLightSource();
};

