#include "MyObject.h"
#include "Scene.h"
#include "Mesh.h"
#include "Model.h"
#include "Shader.h"
#include "Transform.h"
#include <iostream>

MyObject::MyObject()
{
	this->transform = new Transform(0,0,0);
	this->renderer = new Renderer(this->transform);

	this->model = new Model("obj/wall.obj");
	//this->model->meshes.at(0).set_texture("blending_transparent_window.png");
	this->model->set_DrawType(GL_TRIANGLES);

	this->renderer->set_model(this->model);
	this->updatable = new Updatable();

	Scene::renderer.push_back(this->renderer);
	Scene::updatable.push_back(this->updatable);

	///this->renderer->shader = Shader::AlphaTest;
	//this->renderer->shader = Shader::GeoTest;
	this->renderer->shader = Shader::NoTextureShader;
}


MyObject::~MyObject()
{
}

void MyObject::set_model(std::string path)
{
	this->model = new Model(path.c_str());
	this->renderer->set_model(this->model);
}
