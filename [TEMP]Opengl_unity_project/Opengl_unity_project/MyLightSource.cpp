#include "MyLightSource.h"
#include "Scene.h"
#include "Transform.h"
#include <iostream>
#include "Shader.h"


MyLightSource::MyLightSource()
{
	this->transform = new Transform(-5, 200, 20);
	this->transform->scale = 10;
	this->renderer = new Renderer(this->transform);

	this->model = new Model("obj/sphere.obj");
	//this->model->set_DrawType(GL_LINES);
	this->renderer->set_model(this->model);

	this->light = new Light(this->transform, 0);
	this->updatable = new MyobjectUpdatable();

	Scene::renderer.push_back(this->renderer);
	Scene::updatable.push_back(this->updatable);
	Scene::light.push_back(this->light);

	this->renderer->shader = Shader::NoLightShader;
}


MyLightSource::~MyLightSource()
{
}
