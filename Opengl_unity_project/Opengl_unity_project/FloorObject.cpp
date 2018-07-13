#include "FloorObject.h"
#include "Scene.h"
#include "Mesh.h"
#include "Model.h"
#include "Shader.h"
#include "Transform.h"
#include <iostream>


FloorObject::FloorObject()
{
	this->transform = new Transform(0, 0, 0);
	this->renderer = new Renderer(this->transform);
	this->transform->scale = 1;

	this->model = new Model("obj/sujan.obj");
	//this->model->meshes.at(0).set_texture("solmarbre1.png");

	this->renderer->set_model(this->model);
	this->updatable = new Updatable();

	Scene::renderer.push_back(this->renderer);
	Scene::updatable.push_back(this->updatable);

	this->renderer->shader = Shader::NoTextureShader;
}


FloorObject::~FloorObject()
{
}
