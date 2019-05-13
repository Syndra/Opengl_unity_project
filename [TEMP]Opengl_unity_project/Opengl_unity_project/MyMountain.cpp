#include "MyMountain.h"
#include "Terrain.h"
#include "Scene.h"
#include "Shader.h"
#include "Mesh.h"
#include <ctime>

MyMountain::MyMountain()
{
	this->transform = new Transform(0, 0, 0);
	this->transform->scale = 1;
	this->renderer = new Renderer(this->transform);

	//this->terrain = new Terrain("obj/index.jpg", 225, 225, 0.3);
	this->terrain = new Terrain(7, 100, 0.007);
	this->renderer->set_model(this->terrain);

	Scene::renderer.push_back(this->renderer);

	this->renderer->shader = Shader::NoTextureShader;
	this->terrain->set_Transparency(1.f);
	this->terrain->set_Color(glm::vec3(0.5f, 0.5f, 0.5f));
	this->terrain->meshes.at(0).set_texture("rocky.jpg");
	//this->renderer->shader = Shader::BasicLightShader;
}


MyMountain::~MyMountain()
{
}

void MyMountain::set_terrain(const char * path, int width, int length)
{
	terrain = new Terrain(path, width, length, 0.25);
	this->renderer->set_model(terrain);
}
