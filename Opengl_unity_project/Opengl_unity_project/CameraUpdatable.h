#pragma once

#include "Updatable.h"

class Transform;

class CameraUpdatable : public Updatable
{
public:

	Transform * transform;

	double xpos;
	double ypos;

	float lastX;
	float lastY;

	float v_angle = 0;
	float h_angle = 0;

	float Yaw = -90.0f;
	float Pitch = 0.0f;

	float mouseSpeed = 0.01f;
	float speed = 5.0f;

	CameraUpdatable(Transform *transform);
	~CameraUpdatable();
	void update();
	void start();

	bool foo = true;
};

