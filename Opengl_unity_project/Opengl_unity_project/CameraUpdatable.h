#pragma once

#include "Updatable.h"

class CameraTransform;

class CameraUpdatable : public Updatable
{
public:

	CameraTransform * transform;

	CameraUpdatable(CameraTransform *transform);
	~CameraUpdatable();
	void update();
	void start();
};

