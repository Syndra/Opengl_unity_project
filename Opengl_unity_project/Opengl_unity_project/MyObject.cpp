#include "MyObject.h"
#include "Scene.h"
#include "Transform.h"
#include <iostream>

MyObject::MyObject()
{
	this->transform = new Transform(0,0,0);
	this->renderer = new Renderer(this->transform);
	this->updatable = new Updatable();
	//this->updatable = new MyobjectUpdatable();

	Scene::renderer.push_back(this->renderer);
	Scene::updatable.push_back(this->updatable);
}


MyObject::~MyObject()
{
}
