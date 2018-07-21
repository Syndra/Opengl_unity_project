#pragma once

#include "Renderer.h"
#include "Model.h"
#include "Updatable.h"
#include "Gameobject.h"

class MyObject : public Gameobject
{
public:

	Renderer * renderer;
	Updatable * updatable;
	Model * model;

	MyObject();
	~MyObject();
	void set_model(std::string path);
};

