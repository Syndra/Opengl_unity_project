#include "myGamemanager.h"
#include "Window.h"
#include "Scene.h"
#include "Camera.h"
#include "MyObject.h"
#include "Transform.h"

myGamemanager::myGamemanager()
{
	MyObject *a = new MyObject();
	a->transform->position.x = 1;
	a->transform->scale = 0.5f;
	cubes.push_back(a);

	MyObject *b = new MyObject();
	b->transform->position.x = -1;
}


myGamemanager::~myGamemanager()
{
}

void myGamemanager::run()
{
}
