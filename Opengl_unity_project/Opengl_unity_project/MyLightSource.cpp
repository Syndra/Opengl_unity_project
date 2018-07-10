#include "MyLightSource.h"
#include "Scene.h"
#include "Transform.h"
#include <iostream>
#include "Shader.h"


MyLightSource::MyLightSource()
{
	this->transform = new Transform(100, 40, 10);
	this->renderer = new Renderer(this->transform);

	this->mesh = new Mesh("cube.obj");
	this->renderer->set_mesh(this->mesh);

	this->light = new Light(this->transform);
	this->updatable = new MyobjectUpdatable();

	Scene::renderer.push_back(this->renderer);
	Scene::updatable.push_back(this->updatable);
	Scene::light.push_back(this->light);

	this->renderer->shader = Shader::NoLightShader;
}


MyLightSource::~MyLightSource()
{
}
