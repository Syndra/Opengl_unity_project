#include "MyTerrain.h"
#include "Terrain.h"
#include "Scene.h"
#include "Shader.h"

MyTerrain::MyTerrain()
{
	this->transform = new Transform(0, 0, 0);
	this->renderer = new Renderer(this->transform);

	this->terrain = new Terrain("obj/heightmap.png", 240, 240, 0.25);
	this->renderer->set_model(this->terrain);

	Scene::renderer.push_back(this->renderer);

	this->renderer->shader = Shader::NoTextureShader;
}


MyTerrain::~MyTerrain()
{
}

void MyTerrain::set_terrain(const char * path, int width, int length)
{
	terrain = new Terrain(path, width, length, 0.25);
	this->renderer->set_model(terrain);
}
