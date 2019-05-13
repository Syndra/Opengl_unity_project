#pragma once

class Transform;

class Gameobject
{
public:

	//Transform
	Transform * transform;

	Gameobject();
	Gameobject(Transform *transform);
	~Gameobject();
};

