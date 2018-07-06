#include "MyObject.h"
#include "Scene.h"
#include "Transform.h"

MyObject::MyObject()
{
	this->transform = new Transform(0,0,0);
	this->renderer = new Renderer(this->transform);
	this->updatable = new Updatable();

	Scene::renderer.push_back(this->renderer);
	Scene::updatable.push_back(this->updatable);
}


MyObject::~MyObject()
{
}
