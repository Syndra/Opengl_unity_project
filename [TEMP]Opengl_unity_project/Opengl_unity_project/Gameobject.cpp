#include "Gameobject.h"
#include "Transform.h"


Gameobject::Gameobject()
{
	this->transform = new Transform(0,0,0);
}

Gameobject::Gameobject(Transform * transform)
{
	this->transform = transform;
}

Gameobject::~Gameobject()
{
}
