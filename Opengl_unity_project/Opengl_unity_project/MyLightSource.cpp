#include "MyLightSource.h"
#include "Scene.h"
#include "Transform.h"
#include <iostream>
#include "Shader.h"


MyLightSource::MyLightSource()
{
	this->transform = new Transform(100, 40, 10);
	this->renderer = new Renderer(this->transform);

	this->model = new Model("obj/sphere.obj");
	this->renderer->set_model(this->model);

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
