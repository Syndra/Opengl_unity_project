#include "MyObject.h"
#include "Scene.h"
#include "Mesh.h"
#include "Shader.h"
#include "Transform.h"
#include <iostream>

MyObject::MyObject()
{
	this->transform = new Transform(0,0,0);
	this->renderer = new Renderer(this->transform);

	this->mesh = new Mesh("sujan.obj");
	this->mesh->set_texture("uvmap.DDS");

	this->renderer->set_mesh(this->mesh);
	this->updatable = new Updatable();

	Scene::renderer.push_back(this->renderer);
	Scene::updatable.push_back(this->updatable);

	this->renderer->shader = Shader::BasicLightShader;
}


MyObject::~MyObject()
{
}
