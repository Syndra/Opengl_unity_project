#pragma once

#include "Renderer.h"
#include "Model.h"
#include "Updatable.h"
#include "Gameobject.h"
#include "CubeMap.h"

class SkyBox : public Gameobject
{
public:

	CubeMap * cubemap;

	Renderer * renderer;
	Updatable * updatable;
	Model * model;

	SkyBox();
	~SkyBox();
	void usecubemap();
};
